//
// Created by shan on 2022/12/1.
//

#ifndef LAB5_INPUT_H
#define LAB5_INPUT_H
#include <fstream>
#include<iostream>
#include <vector>
#include"output.h"
using namespace std;

const string info0 = "测试判断等价：该程序对测试结果完全一致";
const string info1 = "测试判断不等价：该程序对测试结果不一致";
const string info2 = "由人工判断推导不等价：您曾经将该程序对所属的两个等价集合判断为不等";

struct fPair{
    string s0,c0,s1,c1;
    string info;

    fPair();
    fPair(const string &s0, const string &s1, const string &info);
};


class input {
    ifstream equal ,inequal;
public:
    input();
    ~input();
    fPair next();
};

#endif //LAB5_INPUT_H
