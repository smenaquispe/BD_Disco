#ifndef FILE_H
#define FILE_H

#include<iostream>
#include<fstream>
#include<regex>
#include<cstring>

using namespace std;

class File
{

private:
    string csv;
    int lenBuffer = 256; // tolerancia maxima del buffer
    char * buffer;
    int numberColumns = 0;
    int totalRegisterBytes = 0;
public:
    File(string csv) {
        this->csv = csv;
        buffer = new char[lenBuffer];
    }  

    ~File(){
        delete buffer;
    }

    void extractSchema();
    void toFile();

};

#include"extractSchema.h"
#include"toFile.h"

#endif