#ifndef FIXED_ADD_H
#define FIXED_ADD_H

#include"../File.h"
#include<regex>
using namespace std;


void File::fixedAdd(string inputFile) {
    
    ifstream input(inputFile);
    ifstream schema("./docs/schema_output");
    
    fstream file("./disk/file2", ios::in | ios::out);

    ofstream auxiliar("./docs/auxiliar");
    
    string line;
    int number;

    regex pattern("\\((.*?)\\)");
    smatch matches;
    
    int totalSize = 0;
    while (getline(input, line))
    {
        if(regex_search(line, matches, pattern)) {
            if(matches.size() > 1) {
                schema >> number;
                auxiliar<<setw(number)<<matches.str(1)<<endl;
                totalSize += number;
            }
        }
    }
    
    auxiliar.close();

    ifstream auxiliar_input("./docs/auxiliar");

    int pos = 0;    
    if(deleteds.size() != 0) {
        // obtenemos cual es ultimo nodo que  elminamos
        Node * last = deleteds.at(deleteds.size() - 1);
        pos = getFixedPositionRecord(last->id);
        deleteds.pop_back();
    } else {
        Node last = ids.back();
        pos = last.posStart;
    }

    cout<<"Pos: "<<pos<<endl;

    totalSize += pos;
    file.seekg(pos);
    // convertimos el input en auxiliar
    int count = 0;

    int id;
    while (getline(auxiliar_input, line))
    {
        file<<line<<endl;
        
        if(count == 0) {
            id = stoi(line);
        }
        
        count++;
        if(count % numberColumns == 0) break;
    }

    ids.push_back({id, pos});

}

#endif