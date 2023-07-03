#ifndef FIXED_TO_FILE
#define FIXED_TO_FILE

#include<iomanip>
#include"Utils/myStrtok.h"
#include"File.h"

void File::fixedToFile() {
 
    ifstream csvFile(this->csv);
    ifstream schema("./docs/schema_output");
    fstream file("./disk/file", std::ios::in | std::ios::out);

    if(!csvFile.is_open()) {
        cout<<"Error openning csv file"<<endl;
        return;
    }

    int count = 0;
    int totalSize = 0, prevTotalSize = 0;
    int position = 1;
    long long int lastWord = 0;

    int size;
    bool isHeader = true;
    bool isCompleted = true;
    bool prevIsCompleted = true;
 
    while (csvFile){
        
        // comenzamos a leer a partir de la ultima posicion
        csvFile.seekg(position - 1);
        // se lee en el buffer
        csvFile.read(buffer, lenBuffer - 1);
        
        //  cambiamos el ultimo caracter del buffer como fin de linea
        buffer[lenBuffer - 1] = '\0';

        // tokenizamos el buffer
        char * token = myStrtok(buffer, ",");
        
        while (token != nullptr)
        {
            // si el contador alzanca el numero de columnas, reiniciamos el contador
            if(count % 12 == 0 && isCompleted) {
                
                if(count == 12) isHeader = false;
                
                count = 0;
                totalSize++;

                schema.clear();
                schema.seekg(0);

            }

            if(isCompleted) schema >> size;
    
            // seteamos el complete como true
            else {
                prevIsCompleted = isCompleted;
                isCompleted = true;
            }
    
            // last word, es la longitud de la  ultima palabra 
            lastWord = strlen(token);

            // escribimos las palabras
            if(!isHeader) {
                
                // si previamente no estaba completo
                if(!prevIsCompleted) {
                    file.seekp(-size - 2, ios::cur);
                    prevIsCompleted = true;
                }

                if(lastWord != 0) {
                    file<<setw(size)<<token<<endl;
                } 
                else file<<setw(size)<<"-"<<endl;
        
            }

            // el prevtotalsize, toma el valor anterior de la longitud total
            prevTotalSize = totalSize;
            totalSize += strlen(token) + 1;
                    
            token = myStrtok(nullptr, ",");
            count++;
        }
        
        // en caso el token no es completo
        if(buffer[lenBuffer - lastWord - 1] == '\"' || buffer[lenBuffer - 1] != ',') {
            totalSize = prevTotalSize;
            count--;
            prevIsCompleted = isCompleted;
            isCompleted = false;
        }
        
        // la posicion ahora toma la sumatoria
        position = totalSize;

    }
    
    csvFile.close();
}

#endif