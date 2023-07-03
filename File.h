#ifndef FILE_H
#define FILE_H

#include<iostream>
#include<fstream>
#include<regex>
#include<cstring>
#include<vector>

using namespace std;

struct Node {
    int id;
    int posStart;
};

class File
{

private:
    string csv;
    int lenBuffer = 256; // tolerancia maxima del buffer
    char * buffer;
    int numberColumns = 0;
    int totalRegisterBytes = 0;


    // vectores para seguimiento sequencial
    vector<Node> ids;
    vector<Node> deleteds;

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
    void fixedLoadFile();
    void fixedGet(int id);
    

    // Dynamic functions
    void dynamicToFile();

};

#include"extractSchema.h"

#include"Fixed/fixedToFile.h"
#include"Fixed/fixedLoadFile.h"
#include"Fixed/fixedGet.h"

#include"Dynamic/dynamicToFile.h"

#endif