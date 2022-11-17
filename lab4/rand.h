//
// Created by shan on 2022/11/17.
//

#ifndef LAB4_RAND_H
#define LAB4_RAND_H

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

string randInt(int a, int b)
// eg: a=1 b=3 b-a =2  123
{
    srand(time(NULL));
    int ans = rand() % (b - a + 1) + a;
    return to_string(ans);
}

char randChar() {
    srand(time(NULL));
    if (rand() % 2) { return rand() % (26) + 'a'; }
    else {
        return rand() % (26) + 'A';
    }

}

string randString(int a, int b) {
    srand(time(NULL));
    int len = rand() % (b - a + 1) + a;
    string ans;
    for (int i = 0; i < len; i++) { ans += randChar(); }
    return ans;
}

#endif //LAB4_RAND_H
