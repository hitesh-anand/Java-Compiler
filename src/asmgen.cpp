#include<bits/stdc++.h>
#define PUSHQ "pushq\t"
#define MOVL "movl\t"
#define MOVQ "movq\t"
#define SUBQ "subq\t"
#define RBP "%rbp"
#define RSP "%rsp"
using namespace std;

vector<char> ops = {'+', '-', '*', '/', '^', '&', '%'};

map<string, int> addressRegDes;    // address descriptor
map<string, int> addressDes;    // describes the address relative to rbp for a given variable

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
        void addRegDes(string s);
        void rmRegDes(string s);
        bool getRegDes(string s);
    
}r[16];

vector<int> genregs = {0, 1, 2, 3, 8, 9, 10, 11, 12, 13, 14, 15};

reg::reg(int id, string regName)
{
    this->id = id;
    this->regName = regName;
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




// get a free register for calculations
vector<int> getreg(string res, string a, string b)
{
    // check in address descriptor
    vector<int> ans;
    if(addressDes.find(res) != addressDes.end()) {
        ans.push_back(addressDes[res]);
    }
    else {
        int flag = 0;
        for(auto it: genregs) {
            if(r[it].getRegDes(res) == 1) {
                ans.push_back(it);
                flag = 1;
                break;
            }
            else if(r[it]) {

            }
        }
    }
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
    int numVariables = data.size() - 1;
    // assuming all int variables

    int stackSpace = numVariables << 2;
    // standard code at beginning of function
    funcCode.push_back("main:");
    funcCode.push_back(string(PUSHQ) + string(RBP));
    funcCode.push_back(string(MOVQ) + string(RSP) + string(",") + string(RBP));

    funcCode.push_back(string(SUBQ) + string(RSP) + string(",") + to_string(stackSpace));


    // opening the 3ac file
    ifstream file(funcName + string(".3ac"));

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return ;
    }

    string line;
    while (getline(file, line)) {
        if(line.find("=") != string::npos) {
            // processing arithmetic ops 
            for(auto ch: ops) {
                if(line.find(ch) != string::npos) {

                    size_t eqpos = line.find("=");
                    size_t oppos = line.find(ch);
                    string res = line.substr(0,eqpos);  // variabel storing the result
                    string t = line.substr(eqpos+1);
                    string a = t.substr(0, oppos);      // first operand
                    string b = t.substr(oppos+1);       // second operand
                    vector<int> rs = getreg(res, a, b);
                    int resReg = rs[0], aReg = rs[1], bReg = rs[2];


                    
                }
            }
        }
    }

    file.close();


    // closing the function code
    funcCode.push_back("leave");
    funcCode.push_back("ret");



    // Access the data by index
    //cout << data[0][0] << endl; // Print the first cell of the first row

    
}



void read3ac(string fileName)
{

}

int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Wrong input format\n";
        return 0;
    }
    ifstream f;
    f.open(argv[1], ios::in);

}