#ifndef DISK_H
#define DISK_H

#include<vector>
using namespace std;
#include"Sector.h"
#include"File.h"

class Disk
{
private:
    File * f;
    vector<Sector> sectors;
    int cantPlatos, cantPistas, cantSectores, sizeSector;
    int bigSizev = 0;
public:
    Disk(File * f, int cantPlatos, int cantPistas, int cantSectores, int sizeSector) {
        this->f = f;
        this->cantPlatos = cantPlatos;
        this->cantPistas = cantPistas;
        this->cantSectores = cantSectores;
        this->sizeSector = sizeSector;
    }
    ~Disk() {

    }

    void init() {
        int currentPos = 0;
        int sizeTotal = 0;

        int contadorSectores = 0;
        int contadorPista = 0;
        int contadorSuperficie = 0;
        int contadorPlato = 0;

        Sector * s = new Sector;
        for(int i = 0, j = 1; i < f->ids.size(); i++, j++) {
            // significa que aun entra al sector
            sizeTotal += f->ids[j].posStart - f->ids[i].posStart;
            bigSizev += sizeTotal;
            if(sizeTotal <= sizeSector) {
                s->idsRecords.push_back(f->ids[i].id);
            } else {
                s->id = sectors.size();
                s->tamanio = sizeTotal;
                s->numPlato = contadorPlato;
                s->numSuperficie = contadorSuperficie;
                s->numPista = contadorPista;

                sizeTotal = 0;
                sectors.push_back(*s);
                delete s;

                s = new Sector;
            }

            contadorSectores++;

            cout<<contadorPlato<<endl;

            if(contadorPlato == this->cantPlatos) {
                cout<<"Disco lleno"<<endl;
                return;
            }

            if(contadorSuperficie == 2) {
                contadorPlato++;
                contadorSuperficie = 0;
            }

            if(contadorPista == this->cantPistas) {
                contadorSuperficie++;
                contadorPista = 0;
            }

            if(contadorSectores == this->cantSectores) {
                contadorPista++;
                contadorSectores = 0;
            }
        }

/*
        for(auto &o : sectors) {
            o.show();
        }
*/
    }

    void printInfo() {
        cout<<"Numero de platos: "<<cantPlatos<<endl;
        cout<<"Numero de pistas: "<<cantPistas<<endl;
        cout<<"Tamño total: "<<this->bigSizev<<endl;
    }

    void printSector(int id) {
        for(int i = 0; i < sectors.size(); i++) {
            if(sectors[i].id == id) {
                for(int j = 0; j < sectors[i].idsRecords.size(); j++) {
                    f->dynamicGet(sectors[i].idsRecords[j]);
                }
            }
        }
    }

    void printInfoSector(int id) {
        for(int i = 0; i < sectors.size(); i++) {
            if(sectors[i].id == id) {
                sectors[i].show();
                return;
            }
        }
    }

};

#endif