#ifndef SECTOR_H
#define SECTOR_H

struct Sector
{
    int tamanio; // bytes maximo que alamcena el secto
    int id; // id del sector

    vector<int> idsRecords;

    int numPlato;
    int numSuperficie;
    int numPista;

    void show() {
        cout<<"Informacion del sector: "<<id<<endl;
        cout<<"Numero de Plato: "<<numPlato<<endl;
        cout<<"Numero de Superficie: "<<numSuperficie<<endl;
        cout<<"Numero de Pista: "<<numPista<<endl;
    }
};


#endif