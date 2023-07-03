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

    int numberRecords = 0;

    // vectores para seguimiento sequencial
    vector<Node> ids;
    vector<Node*> deleteds;

public:
    File(string csv) {
        this->csv = csv;
        buffer = new char[lenBuffer];
    }  

    ~File(){
        delete buffer;
    }

    // both functions
    void extractSchema(string schemaFile);
    
    // Fixed Functions
    void fixedToFile();
    void fixedLoadFile();
    void fixedGet(int id);
    int getFixedPositionRecord(int id);
    void fixedDelete(int id);
    void fixedSwap(int a, int b);
    void fixedAdd(string inputFile);

    // Dynamic functions
    void dynamicToFile();
    void dynamicLoadFile();
    void dynamicGet(int id);

};

#include"extractSchema.h"

#include"Fixed/fixedToFile.h"
#include"Fixed/fixedLoadFile.h"
#include"Fixed/fixedGet.h"
#include"Fixed/fixedDelete.h"
#include"Fixed/fixedSwap.h"
#include"Fixed/getFixedPositionRecord.h"
#include"Fixed/fixedAdd.h"

#include"Dynamic/dynamicToFile.h"
#include"Dynamic/dynamicGet.h"
#include"Dynamic/dynamicLoadFile.h"

#endif