#ifndef FIXED_SWAP_H
#define FIXED_SWAP_H

#include"../File.h"

void File::fixedSwap(int a, int b) {
    int posA = getFixedPositionRecord(a);
    int posB = getFixedPositionRecord(b);

    fstream file1("./disk/file2", std::ios::in | std::ios::out);
    fstream file2("./disk/file2", std::ios::in | std::ios::out);

    ofstream auxliar("./docs/auxiliar");
    ofstream auxliar2("./docs/auxiliar2");

    file1.seekg(posA);
    file2.seekg(posB);

    string aux, aux2;
    int count = 0;
 
    while (getline(file1, aux))
    {
        auxliar<<aux<<endl;
        count++;
        if(count == numberColumns) {
            break;
        }
    }

    count = 0;
    while (getline(file2, aux))
    {
        auxliar2<<aux<<endl;
        count++;
        if(count == numberColumns) {
            break;
        }
    }
    
    auxliar.close();
    auxliar2.close();

    ifstream output_auxliar("./docs/auxiliar");
    ifstream output_auxliar2("./docs/auxiliar2");

    file1.seekg(posA);
    file2.seekg(posB);

    while (getline(output_auxliar2, aux))
    {
        file1<<aux<<endl;
    }

    while (getline(output_auxliar, aux))
    {
        file2<<aux<<endl;
    }
    
    
    // cambiamos en la lista en lazada
    
    for(Node & node : ids) {
        if(node.id == a) {
            node.posStart = posB;
        }

        if(node.id == b) {
            node.posStart = posA;
        }
    }

}

#endif