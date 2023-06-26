#include<limits>
#include"File.h"

void File::extractSchema() {
    ifstream schema_input("./input/schema");

    const int MAX_LINE_LENGTH = 1000;

    // fase de conteo de bytes
    if(!schema_input) {
        cerr<<"Error open schema file"<<endl;
        return;
    }

    while (schema_input.ignore(numeric_limits<streamsize>::max(), '\n')) {
        this->numberColumns++;
    }
    
    schema_input.close();

    // número de columnas
    this->numberColumns -= 2;
    cout<<numberColumns<<endl;

    schema_input.open("./input/schema");
    ofstream schema_output("./Data/schema");

    if(!schema_output) {
        cerr<<"Error open schema output"<<endl;
        return;
    }

    if(!schema_input) {
        cerr<<"Error open schema file"<<endl;
        return;
    }

    int number;
    int lineLength;
    int currentDigit;
    int lineNumber = 1;

    while (schema_input.good())
    {
        int lineLength;
        schema_input.read(reinterpret_cast<char*>(&lineLength), sizeof(int));

        if (lineLength == 0) {
            break;  // Fin del archivo
        }

        for (int i = 0; i < lineLength; i++) {
            char currentChar;
            schema_input.read(&currentChar, sizeof(char));

            if (currentChar >= '0' && currentChar <= '9') {
                currentDigit = currentChar - '0';
                number = number * 10 + currentDigit;
            } else if (number != 0) {
                schema_output << number << std::endl;
                number = 0;
            }
        }

        lineNumber++;
    }
   
}