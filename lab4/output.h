//
// Created by shan on 2022/11/17.
//

#ifndef LAB4_OUTPUT_H
#define LAB4_OUTPUT_H
#include "Input.h"
using namespace std;


class output {
    ofstream equal;
    ofstream inequal;
    ofstream abnormal;
public:
    void add (bool e,string a,string b);
    void addAbnormal(string a);
    void init();

    virtual ~output();
};


#endif //LAB4_OUTPUT_H
