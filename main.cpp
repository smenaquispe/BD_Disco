#include<iostream>
using namespace std;

#include"File.h"

int main() {
    File f("./titanic.csv");
    f.extractSchema();
    f.fixedToFile();
    f.fixedLoadFile();
    f.fixedSwap(1,2);

    return 0;
}