#ifndef FIXED_GET_H
#define FIXED_GET_H

#include"../File.h"

void File::fixedGet(int id) {
    int number;
    ifstream file("./disk/file2");

    int position;
    for(const auto & node : ids) {
        
        if(node.id == id) {
            position = node.posStart;
            
            break;
        }
    }

    file.seekg(position);
    string output;
    int count = 0;

    cout<<" | ";
    while (getline(file, output))
    {
        //cout<<output<<endl;
        count++;
        
        std::size_t primer_caracter_no_espacio = output.find_first_not_of(" \t\n\r");
    
        if (primer_caracter_no_espacio != std::string::npos) {
            std::string texto_sin_espacios_izquierda = output.substr(primer_caracter_no_espacio);
            std::cout << texto_sin_espacios_izquierda;
        } 

        cout<<" | ";

    
        if(count == numberColumns) {
            cout<<endl;
            break;
        }
    }
    
}

#endif