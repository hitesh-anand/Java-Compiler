#include<bits/stdc++.h>
#define PUSHQ "pushq\t"
#define MOVL "movl\t"
#define MOVQ "movq\t"
#define SUBQ "subq\t"
#define RBP "%rbp"
#define RSP "%rsp"
#define ADDQ "addq\t"
#define SUBQ "subq\t"
#define MULQ "mulq\t"
#define DIVQ "divq\t"
#define XORQ "xorq\t"
#define DEBUG 1
using namespace std;

vector<char> ops = {'+', '-', '*', '/', '^', '&', '%'};

map<char, string> opConv;


map<string, int> addressRegDes;    // address descriptor
map<string, int> addressDes;    // describes the address relative to rbp for a given variable
map<string, bool> mem;  // whether value in memory is correct value of the variable
/*
General tips:
- %rsi and %rdi are used for passing function arguments



*/

// class for a register
class reg {
    int id;
    string regName;
    map<string, int> regDes;    // register descriptor, as in slides, assuming a reg
    public:
        reg() {};
        void init(int id, string regName);
        reg(int id, string regName);
        string getname();
        void addRegDes(string s);
        void rmRegDes(string s);
        bool getRegDes(string s);
        int getRegDesSize();
        bool isEmpty();
        vector<string> storeall();
    
}r[16];




vector<int> genregs = {0, 1, 2, 3, 8, 9, 10, 11, 12, 13, 14, 15};

string reg::getname()
{
    return regName;
}



int reg::getRegDesSize()
{
    int cnt = 0;
    for(auto it: regDes) {
        if(it.second == true) cnt++;
    }
    return cnt;
}


reg::reg(int id, string regName)
{
    this->id = id;
    this->regName = regName;
}
// store all the variables pointing to this register in memory
vector<string> reg::storeall()
{
    vector<string> ans;
    for(auto it: regDes)
    {
        if(mem[it.first] == true) continue;
        else {
            ans.push_back(string(MOVQ) + regName + string(",") + to_string(addressDes[it.first]) + string("(%rbp)") );
            mem[it.first] = true;

        }
    }
    regDes.clear();
    return ans;

}

bool reg::isEmpty()
{
    if(regDes.empty()) return true;
    return false;
}

void reg::init(int id, string regName)
{
    this->id = id;
    this->regName = regName;
}


void reg::addRegDes(string s)
{
    regDes[s] = 1;
    return;
}

void reg::rmRegDes(string s)
{
    regDes[s] = 0;
    return;
}

bool reg::getRegDes(string s)
{
    if(regDes[s] == 1) return true;
    return false;
}

int checkRegsForVar(string varName)
{
    int i;
    for(i = 0; i < 16; i++) {
        if(r[i].getRegDes(varName)) return i;
    }
    return -1;
}

int checkRegsForOnlyVar(string varName)
{
    int i;
    for(i = 0; i < 16; i++) {
        if(r[i].getRegDes(varName) && r[i].getRegDesSize() == 1) return i;
    }
    return -1;
}


void declareRegs()
{
    // %rax, %rbx, %rcx, %rdx: 64 bit regs any purpose
    // %rax is used for 1st argument of syscall
    r[0].init(0, "%rax");
    r[1].init(1, "%rbx");
    r[2].init(2, "%rcx");
    r[3].init(3, "%rdx");
    r[4].init(4, "%rsi");
    r[5].init(5, "%rdi");
    r[6].init(6, "%rbp");
    r[7].init(7, "%rsp");
    r[8].init(8, "%r8");
    r[9].init(9, "%r9");
    r[10].init(10, "%r10");
    r[11].init(11, "%r11");
    r[12].init(12, "%r12");
    r[13].init(13, "%r13");
    r[14].init(14, "%r14");
    r[15].init(15, "%r15");
    
    
}




// get a free register for calculations, need only two regs as result is stored in the second register
vector<int> getreg(string res, string a, string b, vector<string>& funcCode)
{
    // check in address descriptor
    vector<int> ans;
    // ans.push_back(0);
    int t = checkRegsForVar(a);
    if(t >= 0) {
        if(DEBUG) cout << "1here\n";
        ans.push_back(t);
    }
    else {
         if(DEBUG) cout << "1here\n";
        int flag = 0;
        for(auto it: genregs) {
            if(DEBUG) cout << "regn " << it << "\n";
            if(r[it].getRegDes(a) == 1) {
                if(DEBUG) cout << "1here\n";
                ans.push_back(it);
                flag = 1;
                funcCode.push_back(string(MOVQ) + to_string(addressDes[a]) + "(%rbp)" + r[it].getname() );
                r[it].addRegDes(a);
                break;
            }
            else if(r[it].getRegDesSize() == 0) {
                ans.push_back(it);
                if(DEBUG) cout << "2here\n";
                flag = 1;
                funcCode.push_back(string(MOVQ) + to_string(addressDes[a]) + "(%rbp), " + r[it].getname() );
                r[it].addRegDes(a);
                break;
            }
            else {
                cout << r[it].getRegDesSize() << "\n";
            }
        }
        if(flag == 0) {
            // allot %rbx to the s
            vector<string>t = r[1].storeall();
            
            funcCode.insert(funcCode.end(), t.begin(), t.end());
            funcCode.push_back(string(MOVQ) + to_string(addressDes[a]) + "(%rbp), " + ", %rbx" );
            r[1].addRegDes(a);
            // addressRegDes[a] = 1;
            if(DEBUG) cout << "1here\n";
            ans.push_back(1);
            // r[1]
        }
    }
    if(DEBUG)cout << ":o\n";
    t = checkRegsForVar(b);
    if(t >= 0) {
        ans.push_back(t);
    }
    else {
        int flag = 0;
        for(auto it: genregs) {
            if(r[it].getRegDes(b) == 1) {
                ans.push_back(it);
                flag = 1;
                funcCode.push_back(string(MOVQ) + to_string(addressDes[b]) + "(%rbp), " + r[it].getname() );
                r[it].addRegDes(b);
                break;
            }
            else if(r[it].getRegDesSize() == 0) {
                ans.push_back(it);
                flag = 1;
                funcCode.push_back(string(MOVQ) + to_string(addressDes[b]) + "(%rbp), " + r[it].getname() );
                r[it].addRegDes(b);
                break;
            }
            
        }
        if(flag == 0) {
            // allot %rbx to the s
            vector<string>t = r[2].storeall();
            if(DEBUG) cout << t.size() << "aa\n";
            if(t.size() > 0)
                funcCode.insert(funcCode.end(), t.begin(), t.end());
            funcCode.push_back(string(MOVQ) + to_string(addressDes[b]) + "(%rbp)" + ", %rcx" );
            r[2].addRegDes(res);
            // addressRegDes[b] = 2;
            ans.push_back(2);
            // r[1]
        }
       

    }
    mem[res] = false ;
    r[ans.back()].addRegDes(res);
    return ans;
    
}

// function to translate a print statement to generate the assembly file
void print()
{

}
// generate the .data section of the assembly code
void data()
{

}

// generate the .text section of the assembly code
void textgen()
{

}

// generate the assembly code for a function
vector<string> genfunc(string funcName)
{
    // open the csv corresponding to the function name

    ifstream file(funcName + ".csv");

    vector<vector<string>> data;

    vector<string> funcCode;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;

        string cell;
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        data.push_back(row);
    }
    file.close();
    for(int i = 1; i < data.size(); i++) {
        if(DEBUG) cout <<"hello" <<  data[i][2] << "var name \n"; 
        addressDes[data[i][2]] = -(i * 8);
        if(DEBUG) cout << addressDes[data[i][2]] << "\n";
    }
    int numVariables = data.size() - 1;
    if(DEBUG) cout << numVariables << " num var \n";
    // assuming all int variables

    int stackSpace = numVariables << 3;
    // standard code at beginning of function
    funcCode.push_back("main:");
    funcCode.push_back(string(PUSHQ) + string(RBP));
    funcCode.push_back(string(MOVQ) + string(RSP) + string(",") + string(RBP));

    funcCode.push_back(string(SUBQ) + string("$")+to_string(stackSpace)  + string(",") + string(RSP));


    // opening the 3ac file 
    ifstream file2(funcName + string(".txt"));

    if (!file2.is_open()) {
        cout << "Error opening file" << endl;
        return funcCode;
    }

    // string line;
    int linecnt = 0;
    
    while (getline(file2, line)) {
        if(DEBUG) cout << linecnt++ << "\n";
        if(line.find("=") != string::npos) {
            // processing arithmetic ops 
            int flag = 0;
            for(auto ch: ops) {
                if(line.find(ch) != string::npos) {
                    // cout << "here\n";
                    size_t eqpos = line.find("=");
                    
                    string res = line.substr(0,eqpos);  // variabel storing the result
                    string t = line.substr(eqpos+1);
                    size_t oppos = t.find(ch);
                    string a = t.substr(0, oppos);      // first operand
                    
                    string b = t.substr(oppos+1);       // second operand
                    if(DEBUG) cout << a << " " << b << "\n";
                    if(DEBUG) cout << "calling getreg\n";
                    vector<int> rs = getreg(res, a, b, funcCode);
                    if(DEBUG) cout << "getreg return " << rs.size() << "\n";
                    int aReg = rs[0], bReg = rs[1];

                    string instr = opConv[t[oppos]] + r[aReg].getname() + string(", " ) + r[bReg].getname();
                    // string instr2 = MOVQ + 
                    funcCode.push_back(instr);
                    if(DEBUG) cout << "done\n";
                    flag = 1;
                    break;
                }
            }
            if(!flag) {
                // assuming variable initialization
                size_t eqpos = line.find("=");
                string varName = line.substr(0, eqpos);
                string val = line.substr(eqpos + 1);
                string instr = MOVQ + string("$") + val + string(", ") + to_string(addressDes[varName]) + string("(%rbp)");
                funcCode.push_back(instr);
            }


        }
        if(line.substr(0, 5) == "print") {
            string instr = MOVQ + string("$0, %rax");
            string varName = line.substr(6);
            cout << line << "\n";
            if(DEBUG) cout << varName << " heree var name\n";
            string t;
            if(checkRegsForVar(varName) >= 0) t=r[checkRegsForVar(varName)].getname();
            else t=to_string(addressDes[varName]) + string("(%rbp)");
            string instr2 = MOVQ + string("$printfmt, %rdi");
            string instr3 = MOVQ + t+ string(", %rsi");
            funcCode.push_back(instr);
            funcCode.push_back(instr2);
            funcCode.push_back(instr3);
            funcCode.push_back("call printf");

        }
    }

    file2.close();


    // closing the function code
    funcCode.push_back("leave");
    funcCode.push_back("ret");



    // Access the data by index
    //cout << data[0][0] << endl; // Print the first cell of the first row

    
}

void finalCodeGen(vector<string>& funcCode)
{
    cout << ".text\n";
    cout << ".globl main\n";
    for(auto s: funcCode) {
        cout << s << "\n";
    }
    cout << "movq $60, %rax\n";
    cout << "xorq %rbx, %rbx\n"; 
    cout << "syscall\n";

    cout<< "printfmt: \n";
    cout << ".string \"%d\"";
    return;
}




int main(int argc, char* argv[])
{
    
    // if(argc < 2) {
    //     cout << "Wrong input format\n";
    //     return 0;
    // }
    declareRegs();
    opConv['+'] = ADDQ;
    opConv['-'] = SUBQ;
    opConv['*'] = MULQ;
    opConv['/'] = DIVQ;
    opConv['^'] = XORQ;

    vector<string> code=genfunc("main");
    finalCodeGen(code);
}