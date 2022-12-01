//
// Created by shan on 2022/12/1.
//

#include "input.h"

input::input() {
    equal = std::ifstream("../output/equal.csv", std::ios::in);
    if (!equal.is_open()) {
        debug("equal.csv open failed")
        return;
    }
    inequal = std::ifstream("../output/equal.csv", std::ios::in);
    if (!inequal.is_open()){
        debug("inequal.csv open failed")
        return;
    }

    string tmp;
    getline(equal,tmp);
    debug("equal first line : "+tmp )
    getline(inequal,tmp);
    debug("inequal first line : "+tmp )

}

input::~input() {
    equal.close();
    inequal.close();
}

fPair input::next() {
    string s0,s1;
    if (getline(equal,s0 ,','))
    {
        getline(equal,s1);
        debug("read euqal line : "+s0+"     "+s1)
        return fPair(s0,s1,info0);
    }
    else if (getline(inequal,s0 ,','))
    {
        getline(inequal,s1);
        debug("read ineuqal line : "+s0)
        return fPair(s0,s1,info1);
    }
    else{
        debug("end of two files")
        return fPair();
    }

}

fPair::fPair(const string &s0, const string &s1, const string &info) : s0(s0), s1(s1), info(info) {}

fPair::fPair() {}
