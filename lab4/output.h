//
// Created by shan on 2022/11/17.
//

#ifndef LAB4_OUTPUT_H
#define LAB4_OUTPUT_H
#include "Input.h"
#include "executor.h"
using namespace std;


class output {
    ofstream equal;
    ofstream inequal;
public:
    explicit output();
    void add (bool e,pair<string,string>p);
     ~output();
};


#endif //LAB4_OUTPUT_H
