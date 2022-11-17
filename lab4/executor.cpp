//
// Created by shan on 2022/11/17.
//
#include "executor.h"

string eg::generate() {
    switch (t) {
        case Int:
            return randInt(a, b);
        case Char: {
            string s = "";
            return randChar() + s;
        }

        case String:
            return randString(a, b);
    }
}

void executor::makeList() {
    ifstream ifs = std::ifstream(input->getFormat(), std::ios::out);
    if (!ifs) {
        debug("fail to open " + input->getFormat())
        return;
    }
    string tmp;
    while (ifs >> tmp) {
        if (tmp.compare("char") == 0) {
            egList.push_back(eg(Char, 0, 0));
        } else if (tmp.find("int") != -1) {
            int floor, ceiling;
            int lbracket = tmp.find('(');
            int comma = tmp.find(',');
            int rbracket = tmp.find(')');
            floor = stoi(tmp.substr(lbracket + 1, comma - lbracket - 1));
            ceiling = stoi(tmp.substr(comma + 1, rbracket - comma - 1));
            egList.push_back(eg(Int, floor, ceiling));
        } else if (tmp.find("string") != -1) {
            int floor, ceiling;
            int lbracket = tmp.find('(');
            int comma = tmp.find(',');
            int rbracket = tmp.find(')');
            floor = stoi(tmp.substr(lbracket + 1, comma - lbracket - 1));
            ceiling = stoi(tmp.substr(comma + 1, rbracket - comma - 1));
            egList.push_back(eg(String, floor, ceiling));
        }
    }
    ifs.close();
}

string executor::makeTst() {
    string ans;
    for (int i = 0; i < egList.size(); i++) {
        ans += egList[i].generate() + " ";
    }
    return ans;
}


executor::executor(Input *input, output *o) : input(input), o(o) {
    tstfile = input->getFolderPath() + "/tstfile.txt";
    debug ("!folder path :" +input->getFolderPath())
    makeList();
    refreshTst();
}


void executor::testA() {
    for (int i = 0; i < input->filenames.size(); i++) {
        string a = input->filenames[i];

        for (int j = 0; j < i; j++) {
            refreshTst();
            string b = input->filenames[j];
            exeUnit e(a, b, input);
            o->add(manyTst(e), a, b);
        }
    }
}

void executor::refreshTst() {
    ofstream ofs(tstfile, ios::out);
    debug("!tstfile is "+tstfile)
    if (!ofs) {
        debug("fail to open " + input->getFormat())
        return;
    }
    ofs << makeTst();
    ofs.close();

}

bool executor::manyTst(exeUnit e) {

    int i = 10;
    bool ans = 1;
    while (i != 0) {
        ans &= e.test();
        i--;
    }
    return ans;


}


void execute(string f) {
    string cmd = "g++ " + f + " -o " + f.substr(0, f.size() - 4);
    system(cmd.c_str());
}

bool exeUnit::test() {
    execute(f0);
    execute(f1);
    string cmd;
    cmd = f0.substr(0, f0.size() - 4) + " <" + input->getFolderPath() + "/tstfile.txt " + input->getFolderPath() +
          "/output0.txt";
    system(cmd.c_str());
    cmd = f1.substr(0, f0.size() - 4) + " <" + input->getFolderPath() + "/tstfile.txt " + input->getFolderPath() +
          "/output1.txt";
    system(cmd.c_str());
    ifstream ifs0 = std::ifstream(input->getFolderPath() + "/output0.txt", std::ios::in);
    ifs0.unsetf(ios::skipws);
    if (!ifs0) {
        debug("fail to open " + input->getFormat())
        return 0;
    }

    ifstream ifs1 = std::ifstream(input->getFolderPath() + "/output1.txt", std::ios::out);
    ifs1.unsetf(ios::skipws);
    if (!ifs1) {
        debug("fail to open " + input->getFormat())
        return 0;
    }
    string s0, s1;
    ifs0 >> s0;
    ifs1 >> s1;
    if (strcmp(s0.c_str(), s1.c_str()) != 0)
        return 0;
    else
        return 1;
}


exeUnit::exeUnit(const string &f0, const string &f1, Input *input) : f0(f0), f1(f1), input(input) {}
