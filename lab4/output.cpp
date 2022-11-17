//
// Created by shan on 2022/11/17.
//

#include "output.h"

output::output() {
    equal = std::ofstream("../output/equal.csv", std::ios::out);
    if (equal.is_open()) {
        equal << "file1" << ',' << "file2"  << endl;
    } else debug("euqal.csv creation failed")
    inequal = std::ofstream("../output/inequal.csv", std::ios::out);
    if (inequal.is_open()) {
        inequal << "file1" << ',' << "file2" << endl;
    } else debug("ineuqal.csv creation failed")
}

output::~output() {
    equal.close();
    inequal.close();
}

void output::add(bool e, pair<string, string> p) {
    if (e) { equal << p.first << ',' << p.second << endl; }
    else { inequal << p.first << ',' << p.second << endl; }
}
