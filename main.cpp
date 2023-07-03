#include<iostream>
using namespace std;

#include"File.h"

int main() {
    File f("./titanic.csv");
    f.extractSchema();
    f.dynamicToFile();

    return 0;
}