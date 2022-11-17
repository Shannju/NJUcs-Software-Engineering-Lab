//
// Created by shan on 2022/11/17.
//

#ifndef LAB4_RAND_H
#define LAB4_RAND_H

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


int randInt(int a, int b)
// eg: a=1 b=3 b-a =2  123
{
    srand(time(NULL));
    return rand() % (b - a + 1) + a;
}

char randChar() {
    srand(time(NULL));
    if (rand() % 2) { return rand() % (26) + 'a'; }
    else {
        return rand() % (26) + 'A';
    }

}
char randString(int a, int b) {
    srand(time(NULL));
    if (rand() % 2) { return rand() % (26) + 'a'; }
    else {
        return rand() % (26) + 'A';
    }

}

#endif //LAB4_RAND_H
