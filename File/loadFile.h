#include"File.h"

void File::loadFile() {
    std::ifstream inputFile("./input/titanic.csv", std::ios::binary);   // Abre el archivo de entrada en modo de lectura binaria
    std::ofstream outputFile("./Data/file", std::ios::binary);   // Abre el archivo de salida en modo de escritura binaria

    if (!inputFile) {
        std::cerr << "Error al abrir el archivo de entrada." << std::endl;
        return;
    }

    if (!outputFile) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return;
    }

    ifstream auxInputFile("./input/titanic.csv");
    int i = 0;
    streampos initial = inputFile.tellg();
    while(inputFile.ignore(numeric_limits<streamsize>::max(), ',')) {
        streampos pos = inputFile.tellg();
        auxInputFile.seekg(pos);
        char buffer[pos - initial];
        auxInputFile.read(buffer, pos - initial);
        cout.write(buffer, pos - initial);
        initial = pos;
    } 

    inputFile.close();    // Cierra el archivo de entrada
    outputFile.close();   // Cierra el archivo de salida

}
