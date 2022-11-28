//
// Created by shan on 2022/11/17.
//

#include "output.h"

void output::add(bool e, string a, string b) {
//    debug("!!!!add!" +a+b)
//    equal = std::ofstream("../output/equal.csv", std::ios::out | std::ios::app);
//
//    inequal = std::ofstream("../output/inequal.csv", std::ios::out | std::ios::app);
    if (e) { equal << a.substr(2) << ',' << b.substr(2) << endl; }
    else { inequal << a.substr(2) << ',' << b.substr(2) << endl; }

}

void output::writeAb() {
    for (int i = 0; i < abnormalList.size(); i++)
        addAbnormal(abnormalList[i]);
}

void output::addAb(string s) {
    for (int i = 0; i < abnormalList.size(); i++) {
        if (abnormalList[i] == s)
            return;
    }
    abnormalList.push_back(s);
}

void output::init() {
    equal = std::ofstream("../output/equal.csv", std::ios::out | std::ios::app);
    if (equal.is_open()) {
        equal << "file1" << ',' << "file2" << endl;
    } else debug("euqal.csv creation failed");
    inequal = std::ofstream("../output/inequal.csv", std::ios::out | std::ios::app);
    if (inequal.is_open()) {
        inequal << "file1" << ',' << "file2" << endl;
    } else debug("ineuqal.csv creation failed");
    abnormal = std::ofstream("../output/abnormal.csv", std::ios::out | std::ios::app);
    if (abnormal.is_open()) {
    } else debug("abnormal.csv creation failed")

}

void output::addAbnormal(string a) {
//    abnormal = std::ofstream("../output/abnormal.csv", std::ios::out | std::ios::app);
    abnormal << a.substr(2) << endl;
}

output::~output() {
    equal.close();
    inequal.close();
    writeAb();
    abnormal.close();
}
