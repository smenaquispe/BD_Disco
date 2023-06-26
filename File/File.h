#ifndef FILE_H
#define FILE_H

#include<fstream>
#include<iostream>
using namespace std;

class File
{
private:
    int numberColumns = 0;
public:
    File(/* args */){}
    ~File(){}
    void extractSchema();
    void loadFile();
};

#include "extractSchema.h"
#include "loadFile.h"

#endif