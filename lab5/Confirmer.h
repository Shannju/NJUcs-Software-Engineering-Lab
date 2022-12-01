//
// Created by shan on 2022/12/1.
//

#ifndef LAB5_CONFIRMER_H
#define LAB5_CONFIRMER_H
#include <cstring>
#include <fstream>
#include "qdebug.h"
#include <iostream>
#include <vector>
#include "output.h"
using namespace std;
#define enable_debug
#ifdef enable_debug
#define debug(s) {cerr<< s<<'/n';}
#else
#define debug(...){}
#endif


class ufs{
    ufs * p;
    string content;
    string filename;
public:
    explicit ufs(const string &filename) : filename(filename) {
        std::ifstream ifs (".."+filename,ios::in);
        string tmp;
        if (ifs.is_open()) {
            while (getline(ifs,tmp)) {
                content += tmp;
                content += '\n';
            }
        } else debug("euqal.csv creation failed");
        ifs.close();
    }
    void setParnet(ufs * parent){
        while (!parent->isRoot())
            parent=parent->getParent();
        this->p=parent;
    }
    bool isRoot(){return p == this;}
    ufs* getParent (){return p;}
    string getContent(){return content;}
};



class Confirmer {
    vector<ufs> ufset;
    output o;
    int i;
public:
    Confirmer();


};


#endif //LAB5_CONFIRMER_H
