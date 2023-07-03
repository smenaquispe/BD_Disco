#include<iostream>
using namespace std;

#include"File.h"

int main() {
    File f("./titanic.csv");
    f.extractSchema();
    f.fixedToFile();
    f.fixedLoadFile();
    f.fixedGet(90);
    f.fixedGet(190);
    f.fixedGet(678);
    f.fixedGet(2);


    return 0;
}