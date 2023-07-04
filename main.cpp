#include<iostream>
using namespace std;

#include"File.h"
#include"Disk.h"

int main() {

/*
    File f("./titanic.csv");
    f.extractSchema("./schema_titanic");
    f.fixedToFile();
    f.fixedLoadFile();

*/

    int type;
    cout<<"0. Dinamico"<<endl;
    cout<<"1. Estatico"<<endl;
    cin>>type;


    if(type == 0) {
        File f("./titanic.csv");
        f.extractSchema("./schema_titanic");
        f.dynamicToFile();
        f.dynamicLoadFile();
        Disk d(&f, 4, 20, 10, 1000);
        d.init();

        int opc, number;    
        do
        {
            cout<<"-------DISCO-------"<<endl;
            cout<<"1. Imprimir todos los registros"<<endl;
            cout<<"2. Imprimir un registro"<<endl;
            cout<<"3. Calcular la capacidad del disco"<<endl;
            cout<<"4. Imprimir un sector"<<endl;
            cout<<"5. Informacion de un sector"<<endl;
            cout<<"6. Agregar registro"<<endl;
            cout<<"7. Remover registro"<<endl;
            cout<<"8. Salir"<<endl;       
            cout<<"Digite su opcion: ";
            cin>>opc;


            switch (opc)
            {
            case 1: {
                f.dynamicGet();
            }; break;
            case 2: {
                cout<<"Nunero de registro: "; 
                cin>>number;
                f.dynamicGet(number);
                cout<<endl;
            } break;
            case 3: d.printInfo(); break;
            case 4: {
                cout<<"Nombre de sector: ";
                cin>>number;
                d.printSector(number);
            } break;
            case 5: {
                cout<<"Nombre de sector: ";
                cin>>number;
                d.printInfoSector(number);
            } break;
            case 6: {
                f.dynamicAdd("./docs/input1");
            } break;
            case 7: {
                cout<<"Numero de registro: ";
                cin>>number;
                f.dynamicDelete(number);
            } break;
            case 8: break;
            default:
                cout<<"No es una opcion valida"<<endl;
                break;
            }

        } while (opc != 8);

    }

    


    return 0;
}