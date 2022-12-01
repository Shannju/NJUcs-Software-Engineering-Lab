//
// Created by shan on 2022/11/17.
//

#include "output.h"

void output::add(bool e, string a, string b) {
    if (e) { equal << a.substr(2) << ',' << b.substr(2) << endl; }
    else { inequal << a.substr(2) << ',' << b.substr(2) << endl; }

}

output::~output() {
    equal.close();
    inequal.close();
}

output::output() {
    equal = std::ofstream(path+"/output/human_equal.csv", std::ios::out | std::ios::app);
    if (equal.is_open()) {
        equal << "file1" << ',' << "file2" << endl;
    } else debug("human_equal.csv creation failed");
    inequal = std::ofstream(path+"/output/human_inequal.csv", std::ios::out | std::ios::app);
    if (inequal.is_open()) {
        inequal << "file1" << ',' << "file2" << endl;
    } else debug("human_ineuqal.csv creation failed");

}
