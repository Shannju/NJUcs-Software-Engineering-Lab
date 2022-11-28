#include <iostream>


#include <unistd.h>
#include "Input.h"
#include "executor.h"

int main() {
    InputFolder inFolder("../input");
    output o;
    o.init();
    for (int i =0;i<inFolder.ls.size();i++)
    {
        executor e(&inFolder.ls[i],&o);
        e.testAll();
    }
    pause();
    return 0;
}
