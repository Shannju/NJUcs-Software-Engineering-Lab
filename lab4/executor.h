//
// Created by shan on 2022/11/17.
//

#ifndef LAB4_EXECUTOR_H
#define LAB4_EXECUTOR_H

#include "Input.h"
#include "rand.h"

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
    string f0, f1;
    bool test();//执行一次随机tst 返回结果是否一样
    string randomIns();//生成一条shell指令
public:

};

//对于一个文件夹执行测试
class executor {
    Input *i;
    vector<string> ls;
    vector<eg> egList;
    string tstfile;
public:
    void makeList();//初始化eglist
    string makeTst();//生成测试用例文件
    explicit executor(Input *i);
};


#endif //LAB4_EXECUTOR_H
