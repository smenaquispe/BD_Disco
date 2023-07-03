#ifndef DYNAMIC_LOAD_FILE_H
#define DYNAMIC_LOAD_FILE_H

#include"../File.h"

void File::dynamicLoadFile() {
    
    ifstream file("./disk/file");
    ifstream aux_file("./disk/file");
    
    ifstream schema("./docs/schema_output");

    while (file)
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '|');
        file.ignore(std::numeric_limits<std::streamsize>::max(), '|');

        int a, b;
        char c;
        
        file >> a;
        file >> b;
        
        aux_file.seekg(a);

        string id = "";
        for(int i = 0; i < b; i++) {
            aux_file.get(c);
            id += c;
        }
        
        ids.push_back({stoi(id), a});
        if(ids.size() == numberRecords) break;

    }
    
    schema.close();
    file.close();
    aux_file.close();
}

#endif