//
// Created by shan on 2022/11/17.
//

#ifndef LAB4_OUTPUT_H
#define LAB4_OUTPUT_H
#include <iostream>
#include <fstream>
using namespace std;
#define enable_debug
#ifdef enable_debug
#define debug(s) {cerr<< s<<'/n';}
#else
#define debug(...){}
#endif

using namespace std;

const string path= "/Users/shan/Desktop/Software-Engineering/NJUcs-Software-Engineering-Lab/lab5_qt";


class output {
    ofstream equal;
    ofstream inequal;

public:
    void add (bool e,string a,string b);

    output();

    virtual ~output();
};


#endif //LAB4_OUTPUT_H
