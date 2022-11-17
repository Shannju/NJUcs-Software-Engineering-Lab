#include <iostream>


#include <unistd.h>
#include "Input.h"
#include "executor.h"

int main() {
    InputFolder inFolder("../input");
    output o;
    for (int i =0;i<inFolder.ls.size();i++)
    {
        executor e(&inFolder.ls[i],&o);
        e.testA();
    }
    pause();
    return 0;
}
