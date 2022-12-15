//
// Created by shan on 2022/11/17.
//

#ifndef LAB4_EXECUTOR_H
#define LAB4_EXECUTOR_H

#include "rand.h"
#include "output.h"
#include <string>
using namespace std;

enum type {
    Int, Char, String
};

struct eg {
    type t;
    int a, b;

    string generate();

    eg(type t, int a, int b) : t(t), a(a), b(b) {};
};


class exeUnit {

public:
    string f0, f1;
    Input *input;
    output * o;

    exeUnit(const string &f0, const string &f1, Input *input, output *o);

    int test();//执行一次随机tst 返回结果是否一样

};

//对于一个文件夹执行测试
class executor {
public:
    Input *input;
    vector<string> ls;

    vector<eg> egList;
    string tstfile;
    output * o;
public:
    void makeList();//初始化eglist
    string makeTst();//生成测试用例内容
    void refreshTst();//刷新测试文件内容
    void testAll();

    executor(Input *input, output *o);

    bool manyTst(exeUnit e,int n); //  多次执行指令判断
};

bool execute(string f);
#endif //LAB4_EXECUTOR_H
