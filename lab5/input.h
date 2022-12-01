//
// Created by shan on 2022/12/1.
//

#ifndef LAB5_INPUT_H
#define LAB5_INPUT_H
#include <fstream>
#include<iostream>
using namespace std;
#define enable_debug
#ifdef enable_debug
#define debug(s) {cerr<< s<<'/n';}
#else
#define debug(...){}
#endif


class input {
    ifstream equal ,inequal;
public:
    input();

    virtual ~input();
};


#endif //LAB5_INPUT_H
