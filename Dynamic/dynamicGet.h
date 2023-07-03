#ifndef DYNAMIC_GET_H
#define DYNAMIC_GET_H

#include"../File.h"

void File::dynamicGet(int id) {
    
    ifstream file("./disk/file");
    ifstream aux_file("./disk/file");
    
    ifstream schema("./docs/schema_output");

    int position;
    for(const Node n: ids) {
        if(n.id == id) {
            position = n.posStart;
            break;
        }
    }

    file.seekg(position);

    file.ignore(std::numeric_limits<std::streamsize>::max(), '|');
    file.ignore(std::numeric_limits<std::streamsize>::max(), '|');

    cout<<" | ";

    int a, b;
    char c;
    for(int i = 0; i < numberColumns; i++) {
        file >> a;
        file >> b;

        aux_file.seekg(a);
        for(int i = 0; i < b; i++) {
            aux_file.get(c);
            cout<<c;
        }

        if(b == 0) cout<<"-";

        cout<<" | ";
    }

    cout<<endl;
    schema.close();
    file.close();
    aux_file.close();

}

#endif