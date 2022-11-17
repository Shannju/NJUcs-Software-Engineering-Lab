//
// Created by shan on 2022/11/16.
//

#ifndef LAB4_INPUT_H
#define LAB4_INPUT_H
#define enable_debug

#ifdef enable_debug
#define debug(s) {cerr<< s<<endl;}
#else
#define debug(...){}
#endif

#include <fstream>
#include <string>
#include <iostream>
#include <dirent.h>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

class Input {

    vector<std::string> filenames;

public:
    string format;
    string folderPath;
    explicit Input(const string &folderPath);
};

class InputFolder {
    　
private:
    string folderPath;
    vector<Input> ls;
public:
    ~InputFolder() = default;

    explicit InputFolder(const string &folderPath);


};

void GetFileNames(std::string path, std::vector<std::string> &filenames);


#endif //LAB4_INPUT_H
