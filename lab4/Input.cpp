//
// Created by shan on 2022/11/16.
//

#include "Input.h"


void GetFileNames(std::string path, std::vector<std::string> &filenames) {
    DIR *pDir;
    struct dirent *ptr;
    if (!(pDir = opendir(path.c_str()))) {
        std::cout << "Folder doesn't Exist!" << std::endl;
        debug("!!! path is "+path)
        return;
    }
    while ((ptr = readdir(pDir)) != 0) {
        if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0) {
            filenames.push_back(path + "/" + ptr->d_name);
        }
    }
    closedir(pDir);
}


InputFolder::InputFolder(
        const string &folderPath) : folderPath(folderPath) {
    vector<string> subFolder;
    GetFileNames(folderPath, subFolder);
    for (int i = 0; i < subFolder.size(); i++) {
        if (subFolder[i].find("DS_Store") == subFolder[i].npos) {
            ls.push_back(Input(subFolder[i]));
            debug("subFolders " + subFolder[i]);
        }
    }
}
Input::Input(const string &folderPath) : folderPath(folderPath) {
    GetFileNames(folderPath, filenames);
    for (int i = 0; i < filenames.size(); i++) {
        if (filenames[i].find("txt") != filenames[i].npos) {
            filenames.erase(filenames.begin() + i);
            break;
        }
    }
    format = folderPath + "/stdin_format.txt";
    debug(format);
}

string Input::getFormat() {
    return format;
}

string Input::getFolderPath() {
    return folderPath;
}
