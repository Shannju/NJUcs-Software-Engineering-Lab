//
// Created by shan on 2022/11/17.
//
#include "executor.h"

string eg::generate() {
    switch (t) {
        case Int:
            return randInt(a, b);
        case Char:
            return randChar() + "";
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

executor::executor(Input *input) : input(input) {
    tstfile = input->getFolderPath() + "/tstfile.txt";
}

void executor::refreshTst() {
    ofstream ofs(tstfile, ios::out);
    if (!ofs) {
        debug("fail to open " + input->getFormat())
        return;
    }
    ofs << makeTst();
    ofs.close();

}

void executor::testAll() {
    for (int i =0;i<input->filenames.size();i++)
    {
        for (int j=0;j<i;j++)
        {
            exeUnit e (input->filenames[i],input->filenames[j]);
            if (e.manyTst()==1)

        }

    }


}

exeUnit::exeUnit(const string &f0, const string &f1) : f0(f0), f1(f1) {}

bool exeUnit::test() {
    return false;
}

string exeUnit::randomIns() {
    return std::string();
}

bool exeUnit::manyTst() {
    return false;
}
