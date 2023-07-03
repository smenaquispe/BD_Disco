#ifndef FIXED_LOAD_FILE_H
#define FIXED_LOAD_FILE_H

#include"../File.h"
#include<limits>

void File::fixedLoadFile() {
    ifstream file("./disk/file2");
    ifstream schema("./docs/schema_output");

    int number;
    int size;
    int totalSize = 0;

    int count = 0;
    int countIds = 0;
    while (file)
    {

        schema >> size;

        if(count % numberColumns == 0) {
           
            int position = totalSize + (count * 2);
            file >> number;

            ids.push_back({number, position});  // guardamos todos los ids;
        
            schema.clear();
            schema.seekg(0);
        
            //totalSize -= size;
            countIds++;
        }

        totalSize += size;

        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        count++;
    }

    file.close();   
}

#endif