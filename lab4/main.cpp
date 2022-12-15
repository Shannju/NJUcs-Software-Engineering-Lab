#include <iostream>


#include <unistd.h>
#include "Input.h"
#include <stdlib.h>
#include "executor.h"
#include "gtest/gtest.h"

int main() {
    InputFolder inFolder("../input");
    output o;
    o.init();
    for (int i =0;i<inFolder.ls.size();i++)
    {
        executor e(&inFolder.ls[i],&o);
        e.testAll();
    }
    o.writeAb();

    return 0;
}
