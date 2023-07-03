#include<iostream>
using namespace std;

#include"File.h"

int main() {

/*
    File f("./titanic.csv");
    f.extractSchema("./schema_titanic");
    f.fixedToFile();
    f.fixedLoadFile();

    f.fixedDelete(3);
    f.fixedDelete(6);
    f.fixedDelete(4);

    f.fixedAdd("./docs/input1");
    f.fixedAdd("./docs/input1");
    f.fixedAdd("./docs/input1");
    
    f.fixedGet(892);
*/

    File f("./titanic.csv");
    f.extractSchema("./schema_titanic");
    f.dynamicToFile();
    f.dynamicLoadFile();

    //f.dynamicDelete(1);
    f.dynamicAdd("./docs/input1");

    f.dynamicGet(892);
/*
    ifstream f("./disk/file2");
    f.seekg(193350);

    string line;
    for(int i = 0; i < 12; i++){
        getline(f, line);
        cout<<line<<endl;
    }

*/
    return 0;
}