#ifndef DYNAMIC_TO_FILE_H
#define DYNAMIC_TO_FILE_H

#include<limits>
#include"../File.h"

void File::dynamicToFile() {

 
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

    string nullBitMap = "";
    string posLen = "";

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
            if(count % this->numberColumns == 0 && isCompleted) {
                
                numberRecords++;

                totalSize++;

                schema.clear();
                schema.seekg(0);

                // colocamo el null bit map
                if(!isHeader)
                    file<<" | "<<nullBitMap<<" | ";
                nullBitMap = "";

                // colocamos la cadena de posicion y longitudes
                file<<posLen;
                posLen = "";

                if(!isHeader)
                    file<<endl;
            
            
                if(count == this->numberColumns) isHeader = false;
                
                count = 0;
            }

            if(isCompleted) schema >> size;
    
            // seteamos el complete como true
            else {
                prevIsCompleted = isCompleted;
                isCompleted = true;
            }


            // escribimos las palabras
            if(!isHeader) {
                
                // si previamente no estaba completo
                if(!prevIsCompleted) {
                    file.seekp(-lastWord, ios::cur);
                    prevIsCompleted = true;

                }
                
                posLen += to_string(file.tellp());

                if(strlen(token) != 0) {
                    file<<token;
                    nullBitMap += "1";
                } 
                else {
                    file<<"-";
                    nullBitMap += "0";
                }
                
                if(prevIsCompleted) {
                    posLen += " ";
                    posLen += to_string(strlen(token));
                    posLen += " ";
                }
            }

            // last word, es la longitud de la  ultima palabra 
            lastWord = strlen(token);

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

            int i;
            int a = 0;
            for(i = posLen.size() - 1; i >= 0; i--) {
                if(posLen[i] == ' ')
                    a++;
                if(a == 3) break;
            }

            string auxPosLen = "";
            for(int j = 0; j < posLen.size(); j++) {
                auxPosLen += posLen[j];
                if(j == i) break;
            }

            posLen = auxPosLen;
            
            if(count == 0) posLen = "";
        
        }
        
        // la posicion ahora toma la sumatoria
        position = totalSize;

    }

    file<<" | "<<nullBitMap<<" | ";
    file<<posLen;

    numberRecords--;    

    csvFile.close();
}
#endif