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

    // both functions
    void extractSchema();
    
    // Fixed Functions
    void fixedToFile();

    // Dynamic functions
    void dynamicToFile();

};

#include"extractSchema.h"
#include"fixedToFile.h"
#include"dynamicToFile.h"

#endif