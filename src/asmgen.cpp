/*
Function naming convention: <className>.<functionName> as is in 3ac




*/

#include "reg.h"
#include "asm_utils.h"
#include <bits/stdc++.h>
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
#define DBG if(DEBUG)
using namespace std;

reg r[16];

string consOrVar(string);
int temporary_size;            //hold the size of temporary variable used in a given fucntion
vector<char> ops = {'+', '-', '*', '/', '^', '&', '%'};
vector<string> relOps = {"<=", ">=", "==" ,"!=", ">", "<"};

map<string,int> sizes;

map<char, string> opConv;
map<string,vector<int>> var;    //it keeps the data 
                                // its struct is map<var_name,{type,isarg,w1,w2,w3}>
map<string, string> relConv;

map<string, int> addressRegDes; // address descriptor
map<string, int> addressDes;    // describes the address relative to rbp for a given variable
map<string, bool> mem;          // whether value in memory is correct value of the variable
map<string, int> classSize;     // size of a class object assuming size of int as 8 bytes

string currClassName;   // current class being handled
string currFuncName;        // current function being dealt with in the code

vector<int> genregs = {0,1,2,3,8,9,10,11,12,13,14,15};

vector<bool> islabel(2e5+1, false);



void func_call(vector<string>a,vector<string>&funcCode);

/*********************************UTILITY FUNCTIONS********************************************/

int getAddressDes(string varname)
{
    if(addressDes.find(currClassName + "::" + currFuncName+ "::" + varname) != addressDes.end()) return addressDes[currClassName + "::" + currFuncName+ "::" + varname];
    else return addressDes[currClassName + "::" + varname];
}

bool is_number(const std::string& s)
{
    static const std::regex re("-?[0-9]+(\\.[0-9]*)?");
    return std::regex_match(s, re);
}

// get line no of 3ac instruction
int getLineNo(string instr)
{
    int i=0;
    int lineNo = 0;
    while(i < instr.size() && isdigit(instr[i])) {
        lineNo = lineNo * 10 + (instr[i] - '0');
        i++;
    }
    return lineNo;
}   

// check if the passed string is a constant or a variable
string consOrVar(string x){
    if(x.rfind("pushparam",0)!=0){
        cout<<"Error the instruction not start with pushparam\n";
    }
    string temp;
    int f=0;
    for(int j=0;j<x.size();j++){
        if(x[j]==' '){
            f=1;
        }
        else{
            if(f==1){
                temp.push_back(x[j]);
            }
        }
    }
    f=0;
    for(int j=0;j<temp.size();j++){
        if((x[j]<48||x[j]>59)&&x[j]!=45){
            f=1;
            break;
        }
    }
    string ans;
    if(f==1){
        ans=to_string(getAddressDes(x))+"(%rbp)";
    }
    else{
        ans="$"+x;
    }
    return ans;
}


vector<vector<string> > read_csv(string filename)
{
    vector<vector<string>> data;
    ifstream file(filename);
    //vector<string> funcCode;

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        vector<string> row;

        string cell;
        while (getline(ss, cell, ','))
        {
            row.push_back(cell);
        }

        data.push_back(row);
    }
    file.close();
    return data;

}
/*
General tips:
- %rsi and %rdi are used for passing function arguments



*/

// class for a register












// return move instruction 
string genMove(string src, string dest) 
{
    // check if src is a number
    cout << src << " in genMove\n";
    if(is_number(src)) {
        // int val = stoi(src);
        src = string("$") + src;
    }
    else if(src[0] !='%') {
        src = to_string(getAddressDes(src)) + string("(%rbp)");
    }
    if(dest[0] != '%') {
        dest = to_string(getAddressDes(dest)) + string("(%rbp)");
    } 
    
    // else {
    //     src = to_string(addressDes[src]) + string("(%rbp)");
    // }
    return MOVQ + src + ", " + dest;
}

string genArithmetic(string op, string src, string dest)
{
    if(op.size() == 0) return string("error");
    return opConv[op[0]] + src + ", "+ dest;
}






vector<string> cmpOps = {"==", "<=", ">=", ">", "<", "!="};


vector<string> identifyInstr(string instr)
{
    /*

    
    assume nstruction starts immediately after colon
    */
    // string instr = lines[0];
    vector<string> ans;
    if(DEBUG) cout << "hey there\n";
    size_t colpos= instr.find(":");

    int line_num = getLineNo(instr);

    // put label if required
    if(islabel[line_num]) {
        string ins = ".L" + to_string(line_num) + ":";
        ans.push_back(ins);
    }

    // consider instr only after colon, line no already dealt with
    instr = instr.substr(colpos+1);
    DBG cout << "hey\n";
    size_t eqpos = instr.find('=');
    if(eqpos != string::npos) {
        //     
        DBG cout << "hey here\n";
        string s = instr.substr(eqpos+1);
        int flag = 0;           // to check for arithmetic ops
        string x = instr.substr(0, eqpos);
        if(DEBUG) cout << "x = " << x << "\n";
        for(auto op: ops) {
            if(s.find(op)  != string::npos) {
                string y = s.substr(0, s.find(op));
                string z = s.substr(s.find(op) + 1);
                if(DEBUG) cout << "y, z = " << y << ", " << z << "\n";
                // move to rbx and rcx
                string ins1 = genMove(y, "%rbx");
                string ins2 = genMove(z, "%rcx");
                string ins3 = genArithmetic(s.substr(s.find(op), 1), "%rbx", "%rcx");
                string ins4 = genMove("%rcx", x);
                ans.push_back(ins1);
                ans.push_back(ins2);
                ans.push_back(ins3);
                ans.push_back(ins4);
                // add code 
                // let x, y, x be st x = y + z
                flag = 1;
                break;

            }
        }
        if(flag == 0) {
            // copy instruction
            
            string s = instr.substr(eqpos+1);
            string var1 = instr.substr(0, eqpos);
            if(s.size() && isdigit(s[0])) {
                // rhs is a number
                // string var2 = instr.substr(0, eqpos);
                
                string ins = MOVQ + string("$") + s +string(", ")+ to_string(getAddressDes(var1)) + string("(%rbp)");
                ans.push_back(ins);
            }
            else {
                // rhs is a variable
                // move rhs to %rbx
                
                string ins = MOVQ + to_string(getAddressDes(s)) + string("(%rbp), %rbx");
                ans.push_back(ins);
                ins = MOVQ + string("%rbx, ") + to_string(getAddressDes(var1)) + string("(%rbp");
                ans.push_back(ins);

            }
        }
    }
    else {
        // if then else, goto, call, pushparam, popparam
        // case 1: if then else 
        // if(instr.substr(0, 2) == "if") {
        //     size_t pos = instr.find("then");
        //     string compInstr = instr.substr(3, pos-2-3+1);

        // }
        // if(instr.fins("pushparam") != string::npos) {

        // }
        if(instr.find("if") != string::npos) {
            string t = instr.substr(instr.find("if"));
            string var1, var2, gotoloc;
            int gotopos = t.find("goto");

            int relpos = 0;
            for(auto ch: relOps) {
                if(t.find(ch ) != string::npos) {
                    relpos = t.find(ch);
                    break;
                }

            }
            var1 = t.substr(3, relpos-3);
            int relEnd = relpos;
            if(!isalnum(t[relpos + 1]) ) relEnd++;
            var2 = t.substr(relEnd+1, gotopos-relEnd-2 );

            DBG cout << var1 << " " << var2 <<  "\n";
            string ins1 = genMove(var1, "%rax");
            string ins2 = genMove(var2, "%rcx");

            string ins = "cmpq\t%rcx, %rax";
            string ins_ = relConv[t.substr(relpos, relEnd-relpos+1 )] + " .L" + t.substr(gotopos+5);
            DBG cout << ins_ << "\n";
            ans.push_back(ins1);
            ans.push_back(ins2);
            ans.push_back(ins);
            ans.push_back(ins_);
            gotoloc = t.substr(gotopos + 5);
            int gotoval = stoi(gotoloc);
            islabel[gotoval] = true;
	    
        }
        else if(instr.find("goto") != string::npos) {
            // pure goto instruction with no if
            int gotoval = stoi(instr.substr(5));
            islabel[gotoval] = true;
            string ins = string("jmp .L") + to_string(gotoval);
            ans.push_back(ins); 
        }
        else if(instr.substr(0, 5) == "print") {
            string ins1 = MOVQ + string("$0, %rax");
            string varName = instr.substr(6);
            //cout << line << "\n";
            if(DEBUG) cout << varName << " heree var name\n";
            string t;
            t=to_string(getAddressDes(varName)) + string("(%rbp)");
            string ins2 = MOVQ + string("$printfmt, %rdi");
            string ins3 = MOVQ + t+ string(", %rsi");
            ans.push_back(ins1);
            ans.push_back(ins2);
            ans.push_back(ins3);
            ans.push_back("call printf");

        }
   
    }
    return ans;
}



// generate the assembly code for a function
vector<string> genfunc(string funcName)
{
    // open the csv corresponding to the function name

    ifstream file(funcName + ".csv");

    vector<vector<string>> data;

    vector<string> funcCode;

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        vector<string> row;

        string cell;
        while (getline(ss, cell, ','))
        {
            row.push_back(cell);
        }

        data.push_back(row);
    }
    file.close();
    for (int i = 1; i < data.size(); i++)
    {
        if (DEBUG)
            cout << "hello" << data[i][2] << "var name \n";
        addressDes[currClassName + "::" + currFuncName + "::" + data[i][2]] = -(i * 8);
        // if (DEBUG)
        //     cout << addressDes[data[i][2]] << "\n";
    }
    int numVariables = data.size() - 1;
    if (DEBUG)
        cout << numVariables << " num var \n";
    // assuming all int variables

    int stackSpace = numVariables << 3;
    // standard code at beginning of function
    funcCode.push_back(currClassName + "-" + funcName + ":");
    funcCode.push_back(string(PUSHQ) + string(RBP));
    funcCode.push_back(string(MOVQ) + string(RSP) + string(",") + string(RBP));

    funcCode.push_back(string(SUBQ) + string("$") + to_string(stackSpace) + string(",") + string(RSP));

    // opening the 3ac file
    ifstream file2(funcName + string(".txt"));

    if (!file2.is_open())
    {
        cout << "Error opening file" << endl;
        return funcCode;
    }

    // string line;
    cout << "file opened!\n";
    int linecnt = 0;
    
    while (getline(file2, line)) {
        if(DEBUG) cout << linecnt++ << "\n";
        vector<string> lines= {line};
        int isfunc = 0;
        while(line.find("pushparam") != string::npos) {
            isfunc=1;
            getline(file2, line);
            lines.push_back(line);
        }

        if(isfunc) {
            getline(file2, line);
            getline(file2, line);
            func_call(lines, funcCode);
            getline(file2, line);
            continue;
        }
        if(line.substr(0, 4)=="call") {
            func_call(lines, funcCode);
            continue;
        }
        
        vector<string> t = identifyInstr(line);
        for (auto it: t) {
            DBG cout << it <<"\n";
        }
        if(t.size()) { DBG cout << "ret\n";funcCode.insert(funcCode.end(), t.begin(), t.end()); DBG cout << "done\n";}
        
    }

    file2.close();

    // closing the function code
    funcCode.push_back("leave");
    funcCode.push_back("ret");

    return funcCode;

    // Access the data by index
    // cout << data[0][0] << endl; // Print the first cell of the first row
}

void handleClassDec(string filename)
{
    string line;
    ifstream fp(filename);
    getline(fp, line);
    if(line.substr(0, 10) == "beginclass") {
            currClassName = line.substr(11);
            getline(fp, line);
            while(line.find("endclass") != string::npos) {
                // getline(file2, line);
                // two things, integer variable or array declaration, or even class declaration
                // addressDes[currClassName + "::" + line.substr()]
                // assuming there is a csv file having variable info, type of variable and name of variable
                vector<vector<string> > data = read_csv(currClassName + ".csv");
                int pos = -8;
                for(int i = 1; i < data.size(); i++) {
                    string var = data[i][2];
                    
                    string typeName = data[i][3];
                    if(sizes.find(typeName) != sizes.end()) {
                        classSize[currClassName] += sizes[typeName];
                        addressDes[currClassName + "::" + var] = pos;
                        pos-=8;
                    }
                    else if(classSize.find(data[i][2]) != classSize.end()) {
                        classSize[currClassName] += classSize[data[i][3]];
                        addressDes[currClassName + "::" + var] = pos;
                        pos = pos - classSize[data[i][3]];
                    
                    }
                    else {
                        //array type
                        int dim = 0;
                        int w1=0, w2=0, w3=0;
                        if(data[i][3].length() < 5) {cout<< "symbol table type undefined\n";}
                        else dim++;
                        w1 = data[i][3][4] - '0';
                        if(data[i][3].length() > 7) {w2 = data[i][3][7]- '0'; dim++;}
                        if(data[i][3].length() > 10) {w3 = data[i][3][10] - '0'; dim++;}
                        // only int arrays assumed of size 8 bytes
                        addressDes[currClassName + "::" + data[i][2]] = pos;
                        if(dim == 1) {
                            pos = pos - 8 * w1;
                        }
                        else if(dim == 2) {
                            pos = pos - 8 * w1 * w2;
                        }
                        else {
                            pos = pos - 8 * w1 * w2 * w3;
                        }
                    }
                }
                getline(fp, line);
 
            }
        }
}

void finalCodeGen(vector<string> &funcCode)
{
    cout << ".text\n";
    cout << ".globl main\n";
    for (auto s : funcCode)
    {
        cout << s << "\n";
    }
    cout << "movq $60, %rax\n";
    cout << "xorq %rbx, %rbx\n";
    cout << "syscall\n";

    cout << "printfmt: \n";
    cout << ".string \"%d\"";
    return;
}

string getfuncName(string x){
    if(x.rfind("call",0)!=0){
        cout<<"Error the instruction not start with call\n";
    }
    string temp = x.substr(5);
    if(temp.find(".") != string::npos ) {
        // a class object's function is being called
        // need to consult the symbol table for this current function, or class
        string filename = currClassName + "-" + currFuncName + ".csv";

    }
    // int f=0;
    // for(int j=0;j<x.size();j++){
    //     if(f==1&&x[j]==','){
    //         break;
    //     }
    //     if(x[j]==' '){
    //         f=1;
    //     }
    //     else{
    //         if(f==1){
    //             temp.push_back(x[j]);
    //         }
    //     }
    // }
    return temp;
}
string smplPush(string x){
    if(x.rfind("pushparam",0)!=0){
        cout<<"Not a push instruction";
    }
    string ans;
    int f=0;
    for(int j=0;j<x.size();j++){
        if(x[j]==' '){
            f=1;
        }
        else
        if(f==1){
            ans.push_back(x[j]);
        }
    }
    return ans;
}
vector<int> var_info(string x){
    string y;
    vector<int>ans;
    if(var.find(y)==var.end()){
        return ans;
    }
    return var[y];
}
void checkForArray(string x,vector<int>&wdt){
    vector<int>ans=var_info(x);
    if(ans.size()==0){
        cout<<"No such variable exist";
    }
    if(ans[1]==0){
        if(ans[0]>=100){
            wdt.push_back(ans[2]);
        }
        if(ans[0]>=200){
            wdt.push_back(ans[3]);
        }
        if(ans[0]>=300){
            wdt.push_back(ans[4]);
        }
    }
    else{
        
    }
}
int sz_func(){
    int ans=0;
    for(auto it:var){
        if(it.second[0]==1){//int
            ans+=8;
        }
        if(it.second[1]==0){//array def in side the func
            if(it.second[0]==100){//array
                ans+=it.second[2]*8;
            }
            if(it.second[0]==200){//2darray
                ans+=it.second[2]*it.second[3]*8;
            }
            if(it.second[0]==300){//3darray
                ans+=it.second[2]*it.second[3]*it.second[4]*8;
            }
        }
        else{   //array coming as argument
            if(it.second[0]==100){//array
                ans+=16;
            }
            if(it.second[0]==200){//2darray
                ans+=24;
            }
            if(it.second[0]==300){//3darray
                ans+=32;
            }
        }
    }
    ans+=temporary_size*8+8;
    return ans;
}
int string_to_int(string x){// replacement for stoi
    return stoi(x);
}
void fill_var_temp_sz(string x){
    ifstream file;
    file.open(currClassName +"-"+ x+".3ac");
    string line;
    getline(file, line);
    file.close();
    temporary_size=string_to_int(line);
    vector<string>v;
    file.open(currClassName + "-" + x+".csv");
    getline(file, line);
    while (getline(file, line)) {
        v.push_back(line);
    }
    file.close();
    var.clear();
    for(int j=0;j<v.size();j++){
        int cnt=0;
        int k=0;
        for(k=0;k<v[j].size();k++){
            if(v[j][k]==','){
                cnt++;
            }
            if(cnt==2){
                break;
            }
        }
        k++;
        string nm;
        for(;k<v[j].size();k++){
            if(v[j][k]==',')break;
            nm.push_back(v[j][k]);
        }
        vector<int>temp;
        k++;
        string tp;
        for(;k<v[j].size();k++){
            if(v[j][k]==',')break;
            tp.push_back(v[j][k]);
        }
        if(tp=="int"){
            temp={1,0};
        }
        else{
            int w=0;
            int cnt=0;
            for(int k=0;k<tp.size();k++){
                if(tp[k]=='w'){
                    w=1;
                }
                if(tp[k]==']'){
                    cnt++;
                }
            }
            if(w==1){
                if(cnt==1){
                    temp={100,1};
                }
                if(cnt==2){
                    temp={200,1};
                }
                if(cnt==3){
                    temp={300,1};
                }
            }
            else{
                vector<int>u={cnt*100,0};
                w=0;
                string p;
                for(int k=0;k<tp.size();k++){
                    if(tp[k]=='['){
                        w=1;
                    }
                    else
                    if(w==1){
                        if(tp[k]==']'){
                            u.push_back(string_to_int(p));
                            w=0;
                            p="";
                        }
                        else{
                            p.push_back(tp[k]);
                        }
                    }
                }
                temp=u;
            }
        }
        var[nm]=temp;
    }
}
void insert_arg(vector<string>arg,vector<string>&funCode){
    int cnt=0;
    vector<string>arg_name;
    for(int j=0;j<arg.size();j++){
        arg.push_back(arg_name[j]);
        vector<int>info=var_info(arg_name[j]);
        if(info.size()==0){
            cout<<"No such variable exist\n";
        }
        if(info[0]==100){
            arg_name.push_back("_w1"+arg[j]);
        }
        if(info[0]==200){
            arg_name.push_back("_w1"+arg[j]);
            arg_name.push_back("_w2"+arg[j]);
        }
        if(info[0]==300){
            arg_name.push_back("_w1"+arg[j]);
            arg_name.push_back("_w2"+arg[j]);
            arg_name.push_back("_w3"+arg[j]);
        }
    }
    vector<string>rg={"%rdi", "%rsi", "%rdx", "%rcx", "%r8","%r9"};
    for(int j=0;j<arg_name.size();j++){
        cnt++;
        vector<int>info=var_info(arg_name[j]);
        if(info.size()==0){
            cout<<"No such variable exist\n";
        }
        else{
            if(cnt<=6){
                funCode.push_back("movq "+rg[cnt-1]+", -"+to_string(cnt*8)+"(%rbp)");
                addressDes[currClassName + "::" + currFuncName + "::" + arg_name[j]]=-cnt*8;
            }
            else{
                funCode.push_back("movq "+to_string(16+((arg_name.size()-6)-(cnt-6))*8)+"(%rbp)"+", %rdx");
                funCode.push_back("movq %rdx, -"+to_string(cnt*8)+"(%rbp)");
                addressDes[currClassName + "::" + currFuncName + "::" + arg_name[j]]=-cnt*8;
            }
        }
    }
}
void beg_func(string x,vector<string>&funCode){
    if(x.rfind("beginfunc",0)!=0){
        cout<<"Not a start of the function\n";
    }
    int f=0;
    string func_nm;
    int pos;
    for(int j=0;j<x.size();j++){
        if(x[j]==' '){
            f=1;
        }
        else
        if(f==1){
            if(x[j]==' '){
                pos=j+1;
                break;
            }
            func_nm.push_back(x[j]);
        }
    }
    currFuncName = func_nm;
    fill_var_temp_sz(func_nm);
    vector<string>arg_name;
    string temp;
    for(int j=pos;j<x.size();j++){
        if(x[j]==','){
            arg_name.push_back(temp);
            temp="";
        }
        else{
            temp.push_back(x[j]);
        }
    }
    string instr=func_nm+":";
    funCode.push_back(instr);
    instr="pushq %rbp";
    funCode.push_back(instr);
    instr="movq %rsp, %rbp";
    funCode.push_back(instr);
    instr="subq $"+to_string(sz_func())+", %rsp";
    funCode.push_back(instr);
    insert_arg(arg_name,funCode);
}
void func_call(vector<string>a,vector<string>&funcCode){
    vector<string>ans_reg;//keep all the register instruction
    vector<string>ans_st;//keep all the pushq instruction
    vector<string>things;
    for(int j=a.size()-2;j>=0;j--){
        string y=consOrVar(a[j]);
        if(y[0]=='$'){
            things.push_back(y);
        }
        else{
            string x=smplPush(a[j]);
            if(var_info(x).size()==0){
                cout<<"No such variable exist\n";
            }
            else{
                vector<int>info=var_info(x);
                if(info[0]==1){ //int
                    things.push_back(y);
                }
                if(info[0]>=100){   //array
                    if(info[1]==0){// the size of array is in var 
                        if(info[0]==100){//1darray
                            things.push_back('$'+to_string(info[2]));
                        }
                        if(info[0]==200){//2darray
                            things.push_back('$'+to_string(info[2]));
                            things.push_back('$'+to_string(info[3]));
                        }
                        if(info[0]==300){//3darray
                            things.push_back('$'+to_string(info[2]));
                            things.push_back('$'+to_string(info[3]));
                            things.push_back('$'+to_string(info[4]));
                        }
                    }
                    else{       // for this array we have width in stack
                        if(info[0]==100){//1darray
                            things.push_back(to_string(addressDes["_w1"+x])+"(%rbp)");
                        }
                        if(info[0]==200){//2darray
                            things.push_back(to_string(addressDes["_w1"+x])+"(%rbp)");
                            things.push_back(to_string(addressDes["_w2"+x])+"(%rbp)");
                        }
                        if(info[0]==300){//3darray
                            things.push_back(to_string(addressDes["_w1"+x])+"(%rbp)");
                            things.push_back(to_string(addressDes["_w2"+x])+"(%rbp)");
                            things.push_back(to_string(addressDes["_w3"+x])+"(%rbp)");
                        }
                    }
                }
            }
        }
    }
    vector<string>rg={"%rdi", "%rsi", "%rdx", "%rcx", "%r8","%r9"};
    for(int j=0;j<things.size();j++){
        if(j<6){
            ans_reg.push_back("movq  "+things[j]+", "+rg[j]);
        }
        else{
            ans_st.push_back("movq  "+things[j]+", %rdx");
            ans_st.push_back("pushq  %rdx");
        }
    }
    string instr;
    
    instr="call "+getfuncName(a[a.size()-1]);
    ans_reg.push_back(instr);
    for(auto y:ans_st){
        funcCode.push_back(y);
    }
    for(auto y:ans_reg){
        funcCode.push_back(y);
    }
}

int main(int argc, char *argv[])
{

    // if(argc < 2) {
    //     cout << "Wrong input format\n";
    //     return 0;
    // }
    
    declareRegs(r);
    opConv['+'] = ADDQ;
    opConv['-'] = SUBQ;
    opConv['*'] = MULQ;
    opConv['/'] = DIVQ;
    opConv['^'] = XORQ;
    relConv["<"] = "jl";
    relConv[">"] = "jg";
    relConv[">="] = "jge";
    relConv["<="] = "jle";
    relConv["!="] = "jne";
    relConv["=="] = "je";
    sizes["int"] = sizes["byte"] = sizes["short"] = sizes["long"] = 8;
    
    

    vector<string> code = genfunc("main");
    finalCodeGen(code);
}