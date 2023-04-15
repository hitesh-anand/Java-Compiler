#pragma once
#include <bits/stdc++.h>

/*
Type 0: Normal arithmetic statements
Type 1: IfThen Statements



*/

class Quadruple
{
public:
    int type;
    // int pos;
    std::string op;
    std::string arg1;
    std::string arg2;
    std::string result;
    std::string label;
    static int pos;
    Quadruple(std::string op, std::string arg1, std::string arg2, std::string result);
    Quadruple(std::string op, std::string arg1, std::string result);
    Quadruple(int type, std::string op, std::string arg1, std::string arg2, std::string result);
    Quadruple(int type, std::string op, std::string arg1, std::string result);
    Quadruple(int type, std::string arg1, std::string arg2);
    Quadruple(int type, std::string arg1);
    Quadruple(int type);
    Quadruple(std::string label);
    void print();
    std::string get_op();
    std::string get_arg1();
    std::string get_arg2();
    void set_result(std::string res);
    int get_type();
};

class IRcode
{
public:
    Quadruple *q;
    IRcode *next = NULL;
    IRcode(Quadruple *);
    IRcode(Quadruple *, IRcode *);
};