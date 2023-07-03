#ifndef EXTRACT_SCHEMA_H
#define EXTRACT_SCHEMA_H

#include"File.h"

void File::extractSchema() {
    
    ifstream schema("./docs/schema");
    ofstream schema_output("./docs/schema_output");

    // regex para extraer los pesos
    regex numberRegex(R"(\d+)");
   
    if (schema.is_open()) {
        while (schema.getline(buffer, lenBuffer))
        {
            const char* input = buffer;
            const char* end = buffer + strlen(buffer);

            std::regex_iterator<const char*> iterator(input, end, numberRegex);
            std::regex_iterator<const char*> endIterator;
           
            while (iterator != endIterator) {
                cmatch match = *iterator;
                schema_output<<match.str()<<endl;
                cout<<match.str()<<endl;
                this->totalRegisterBytes += atoi(match.str().c_str());
                ++iterator;
            }
        }

        schema.close();
    } else {
        cout<<"No se puede abrir"<<endl;
    }

}

#endif