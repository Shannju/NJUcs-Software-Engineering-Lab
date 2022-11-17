//
// Created by shan on 2022/11/17.
//

#include "output.h"

void output::add(bool e, string a, string b) {
    equal = std::ofstream("../output/equal.csv", std::ios::out | std::ios::app);
    if (equal.is_open()) {
        equal << "file1" << ',' << "file2" << endl;
    } else debug("euqal.csv creation failed")
    inequal = std::ofstream("../output/inequal.csv", std::ios::out | std::ios::app);
    if (inequal.is_open()) {
        inequal << "file1" << ',' << "file2" << endl;
    } else debug("ineuqal.csv creation failed")
    if (e) { equal << a << ',' << b << endl; }
    else { inequal << a << ',' << b << endl; }
    equal.close();
    inequal.close();
}
