#include "utils.h"

using namespace std;

int v=0;
int cnt=1;
int isarrayinit=0;
// map<string, pair<int, int>> typeroot->typewidth;
map<string,SymNode*> list_class;
string otpt;

int startPos = 0;

int temp = 0;

int varCnt = 0;
int labelCnt = 0;
int importflag = 0;

string condvar;
int isCond = 0;
TypeHandler* typeroot = new TypeHandler();

vector<Quadruple*> residualCode;

vector<string> castName(20);
void defineCastNames() {
    castName[BYTE_NUM] = "byte";
    castName[SHORT_NUM] = "short";
    castName[INT_NUM] = "int";
    castName[LONG_NUM] = "long";
    castName[FLOAT_NUM] = "float";
    castName[DOUBLE_NUM] = "double";
    castName[BOOL_NUM] = "boolean";
    castName[CHAR_NUM] = "char";
    castName[VOID_TYPE] ="void";
}

int whilepos = 0;
SymGlob* root = new SymGlob();
SymGlob* orig_root = root;
SymNode* magic_ptr=root->currNode;


void ir_gen(vector<Quadruple*> ircode, string fln)
{
    ofstream myFile;
    myFile.open(fln);
    int cnt = 0;
    for(auto it: ircode) {
        myFile << cnt++ << "\t:\t";

    if(it->type == 1) {
        myFile << "if" << it->arg1 << "then ";
        continue;
    }
    if(it->type == 2)
    {
        myFile<<"if "<<it->arg1<< it->op << it->arg2<<" goto "<<it->result<<"\n";
        continue;
    }
    if(it->type == 3)
    {
        myFile<<"goto "<<it->result<<"\n";
        continue;
    }
    else if(it->type == 4) {
        if(it->result == "")
            myFile << "call " << it->arg1 << ", " << it->arg2 << "\n";
        else 
            myFile << it->result << "=call " << it->arg1 << ", " << it->arg2 << "\n";
        continue;
    }
    else if(it->type == 5) {
        myFile << "pushparam " << it->arg1 << "\n"; continue;
    }
    else if(it->type == 6) {
        myFile << "beginfunc " << it->arg1 << "\n"; continue;
    }
    else if(it->type == 7) {
        myFile << it->arg1 << " " << it->arg2 <<"\n"; continue;
    }
    else if(it->type==8)
    {
        myFile << "sub  "<<it->arg1<<", "<<it->arg2<<"\n"; continue;
    }
    else if(it->type==9)
    {
        myFile << "push  "<<it->arg1<<"\n"; continue;
    }
    else if(it->type==10)
    {
        myFile << "mov  "<<it->arg1<<", "<<it->arg2<<"\n"; continue;
    }
    else if(it->type==11)
    {
        myFile << "pop  "<<it->arg1<<"\n"; continue;
    }
    else if(it->type==12)
    {
        myFile << "ret  "<<"\n"; continue;
    }
    
    if(it->label != "")
    {
        myFile<<it->label<<": ";
    }
    if(it->arg2 != "")
        myFile << it->result << "=" << it->arg1 << it->op << it->arg2 << "\n";
    else 
        myFile << it->result << "=" << it->arg1<< "\n";

    }
    myFile.close();
}

void backpatch(vector<int>& lst, int n)
{
    for(auto it: lst) {
        ircode[it]->print();
        ircode[it]->set_result(to_string(n));
        
    }
}


void processFieldDec(Node* n, Node* n1, int type)
{
    if(n1->isCond == 1) return;
    string resName = n1->children[1]->varName;
    if(type != n1->children[1]->type) {
        resName = string("t") + to_string(varCnt++);
        Quadruple* q = new Quadruple("", "cast_to_" + castName[type] + " ", n1->children[1]->varName, resName);
        n->code.push_back(q);
        ircode.push_back(q);
    }
    
    
    Quadruple* q = new Quadruple("=", resName, n1->children[0]->varName); 
    n->code.push_back(q);
    ircode.push_back(q);
    n->last = ircode.size() - 1;
}

int getmethodtype(SymNode* n)
{
    SymNode* temp = n;
    while(temp->name != "method")
    {
        temp = temp->parent;
    }
    return temp->returntype;
}

// n is the VariableDeclarator node, 
void init1DArray(Node* n, string type)
{
    Node* arrayName = n->children[0];
    Node* arrayInit = n->children[1];   //ArrayInitializer node 
    int sizeArray = arrayInit->children.size();
    for(int i = 0; i < sizeArray; i++) {
        Quadruple* q = new Quadruple("",arrayInit->children[i]->varName, "", arrayName->varName + "[" + to_string((i*(typeroot->typewidth[type].second))) + "]");
        ircode.push_back(q);
        n->code.push_back( q );
    }

    n->last = ircode.size() - 1;
}

void init2DArray(Node* n,string type)
{
    Node* arrayName = n->children[0];
    Node* arrayInit = n->children[1];   //ArrayInitializer node 
    int sizeArray = arrayInit->children.size();
    int n2= arrayInit->children[0]->children.size();
    for(int i = 0; i < sizeArray; i++) {
        for(int j = 0; j < n2; j++) {
            Quadruple* q = new Quadruple("",arrayInit->children[i]->children[j]->varName, "", arrayName->varName + "[" + to_string(((n2*i + j)*typeroot->typewidth[type].second)) + "]");
            ircode.push_back(q);
            n->code.push_back( q );
        }
    }

    n->last = ircode.size() - 1;
}

void init3DArray(Node* n, string type)
{
    Node* arrayName = n->children[0];
    Node* arrayInit = n->children[1];   //ArrayInitializer node 
    int sizeArray = arrayInit->children.size();
    int n2= arrayInit->children[0]->children.size();
    int n3 = arrayInit->children[0]->children[0]->children.size();
    for(int i = 0; i < sizeArray; i++) {
        for(int j = 0; j < n2; j++) {
            for(int k = 0; k < n3; k++) {
                Quadruple* q = new Quadruple("",arrayInit->children[i]->children[j]->children[k]->varName, "", arrayName->varName + "[" + to_string(((i*n2*n3 + j*n3 + k)*typeroot->typewidth[type].second)) + "]");
                ircode.push_back(q);
                n->code.push_back( q );
            }
        }
    }

    n->last = ircode.size() - 1;
}

void processPostIncre(Node* n)
{
    if(residualCode.size() == 0 ) return;
    if(n == NULL) return;
    ircode.insert(ircode.end(), residualCode.begin(), residualCode.end());
    n->code.insert(n->code.end(), residualCode.begin(), residualCode.end());
    residualCode.clear();
    n->last = ircode.size() - 1;
}

void processAssignment(Node* n1, Node* n2, Node* n3, Node* n)
{
    char oper = n2->attr[0];
    cout << oper<< " dsad\n";
    Quadruple* q = new Quadruple(string(1, oper), n1->varName, n3->varName, n1->varName);
    n->code.push_back(q);
    ircode.push_back(  q );
    n->last = ircode.size() - 1;
    n->varName = n1->varName;
    return;
}

int spacestripind(string s)
{
    int n = s.length();
    int i = n-1;
    while(i>=0 && s[i]!='.')
        i--;
    return i;
}

string spacestrip(string s)
{
    int n = s.length();
    int i = n-1;
    while(i>=0 && s[i]!='.')
        i--;
    return s.substr(i+1, n-i-1);
}

void processRelational(vector<Node*> nodes, string op)
{
        nodes[0]->truelist.push_back(ircode.size());
        nodes[0]->falselist.push_back(ircode.size() + 1);
        
        Quadruple* q = new Quadruple(2, op, nodes[1]->varName, nodes[2]->varName, "");
        nodes[0]->code.push_back(q);
        ircode.push_back(q);
        q = new Quadruple(3, "", "", "", "");
        nodes[0]->code.push_back(q);
        ircode.push_back(q);
        
        nodes[0]->last = ircode.size() - 1;
        nodes[0]->last = ircode.size() - 1;
        
}

void processArithmetic(vector<Node*> nodes, string op)
{
    string resName = string("t") + to_string(varCnt);
    varCnt++;        
    int type1 = typeroot->categorize(nodes[1]->type);
    int type2 = typeroot->categorize(nodes[2]->type);
    int flag = 1;
    if(type1 == FLOATING_TYPE && type2 == INTEGER_TYPE) {
        string resName = string("t") + to_string(varCnt++);
        Quadruple* q = new Quadruple("", "cast_to_float ", nodes[2]->varName, resName);
        nodes[0]->code.push_back(q);
        ircode.push_back(q);
        flag = 2;
    }
    else if(type1 == INTEGER_TYPE && type2 == FLOATING_TYPE) {
        string resName = string("t") + to_string(varCnt++);
        Quadruple* q = new Quadruple("", "cast_to_float", nodes[1]->varName, resName);
        nodes[0]->code.push_back(q);
        ircode.push_back(q);
        flag = 2;
    }
    if(type1 == FLOATING_TYPE || type2 == FLOATING_TYPE) flag=2;
    Quadruple* q = new Quadruple(op + (flag == 1?string("int "): string("float ")), nodes[1]->varName, nodes[2]->varName, resName);
    nodes[0]->varName = resName;
    nodes[0]->code.push_back(q );
    ircode.push_back(q);
    nodes[0]->last = ircode.size() - 1;
}

void processDoWhile(Node* n, Node* n1, Node* n2)
{
    backpatch(n2->nextlist, n2->last + 1 );
    backpatch(n1->truelist, n1->last + 1);
    n->nextlist = n1->falselist;
    Quadruple* q = new Quadruple(3, "", "", "", to_string( n2->last + 1 - n2->code.size() ));
    ircode.push_back(q);
    n->code.push_back(q);
    n->last = ircode.size() - 1;
}

void processWhile(Node* n, Node* n1, Node* n2)
{
    backpatch(n2->nextlist, n1->last + 1 - n1->code.size());
    backpatch(n1->truelist, n1->last + 1);
    n->nextlist = n1->falselist;
    Quadruple* q = new Quadruple(3, "", "", "", to_string( n1->last + 1 - n1->code.size() ));
    ircode.push_back(q);
    n->code.push_back(q);
    n->last = ircode.size() - 1;
}

void generateArgumentList(vector<Node*> nodes, Node* n)
{
    for(auto node: nodes) {
        Quadruple* q = new Quadruple(5, node->varName);
        n->code.push_back(q);
        ircode.push_back(q);
    }
    n->last = ircode.size() - 1;
}


void verbose(int v,string h){
    if(v==1){
        cout<<cnt<<") "<<h<<"\n";
        cnt++;
    }
}
