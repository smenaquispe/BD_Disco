#ifndef FIXED_DELETE_H
#define FIXED_DELETE_H

#include"../File.h"

void File::fixedDelete(int id) {

    int position;
    for(const auto & node : ids) {
        
        if(node.id == id) {
            position = node.posStart;            
            break;
        }
    }

    deleteds.push_back({id, position});
}

#endif