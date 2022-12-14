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
    string format;
    string folderPath;
public:
    string getFormat();
    string getFolderPath();
    vector<std::string> filenames;
    explicit Input(const string &folderPath);
};

class InputFolder {
private:
    string folderPath;
public:
    ~InputFolder() = default;
    vector<Input> ls;
    explicit InputFolder(const string &folderPath);

};

void GetFileNames(std::string path, std::vector<std::string> &filenames);


#endif //LAB4_INPUT_H
