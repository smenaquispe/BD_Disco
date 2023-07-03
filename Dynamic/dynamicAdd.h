#ifndef DYNAMIC_ADD_H
#define DYNAMIC_ADD_H

#include"../File.h"

void File::dynamicAdd(string inputFile) {
    
    ifstream input(inputFile);
    ifstream schema("./docs/schema_output");
    
    fstream file("./disk/file", ios::in | ios::out);

    ofstream auxiliar("./docs/auxiliar");
    
    string line;
    int number;

    regex pattern("\\((.*?)\\)");
    smatch matches;
    
    int totalSize = 0;
    

    int pos = 0;    
    if(deleteds.size() != 0) {
        // obtenemos cual es ultimo nodo que  elminamos
        Node * last = deleteds.at(deleteds.size() - 1);
        pos = getFixedPositionRecord(last->id);
        deleteds.pop_back();

        file.seekg(pos);

    } else {
        file.seekg(0, ios::end);
        file<<endl;
        pos = file.tellg();
    }


    string nullBitMap = "";
    string lenPos = "";
    int id;
    int count = 0;

    while (getline(input, line))
    {
        if(regex_search(line, matches, pattern)) {
            if(matches.size() > 1) {

                lenPos += to_string(pos + auxiliar.tellp());

                if(matches.str(1) != "-") {
                    cout<<matches.str(1)<<endl;
                    
                    auxiliar<<matches.str(1);
                    if(count == 0) id = stoi(matches.str(1));
                    
                    nullBitMap += "1";
                } else {
                    nullBitMap += "0";
                }

                lenPos += " ";
                lenPos += to_string(matches.str(1).size());
                lenPos += " ";

                totalSize += number;
            }
            count++;
        }
    }

    auxiliar<<" | "<<nullBitMap<<" | "<<lenPos<<endl;
    auxiliar.close();

    ifstream auxiliar_input("./docs/auxiliar");
    getline(auxiliar_input, line);
    file<<line;

    ids.push_back({id, pos});

}

#endif