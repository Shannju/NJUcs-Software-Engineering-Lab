//
// Created by shan on 2022/12/1.
//

#include "input.h"

input::input() {
    equal = std::ifstream("../output/equal.csv", std::ios::in);
    if (!equal.is_open())
        debug("equal.csv open failed")
    inequal = std::ifstream("../output/equal.csv", std::ios::in);
    if (!inequal.is_open())
    debug("inequal.csv open failed");
}

input::~input() {
    equal.close();
    inequal.close();

}
