#ifndef FIXED_DELETE_H
#define FIXED_DELETE_H

#include"../File.h"

void File::fixedDelete(int id) {

    int position;
    for(Node & node : ids) {
        
        if(node.id == id) {            
            deleteds.push_back(&node);
            break;
        }
    }

}

#endif