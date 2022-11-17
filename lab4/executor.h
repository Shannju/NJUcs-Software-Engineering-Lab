//
// Created by shan on 2022/11/17.
//

#ifndef LAB4_EXECUTOR_H
#define LAB4_EXECUTOR_H
#include "Input.h"
#include "rand.h"

enum type{Int,Char,String};
struct eg{
    type t;
    int a,b;
    string generate();
    eg(type t, int a, int b) : t(t), a(a), b(b) {}


};


class exeUnit{
    pair<string,string >p;
    string format;
    bool test ();
    string randomIns();

};

//对于一个文件夹执行测试
class executor {
    Input * i;
    vector<string>ls;



};


#endif //LAB4_EXECUTOR_H
