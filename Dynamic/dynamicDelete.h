#ifndef DYNAMIC_DELETE_H
#define DYNAMIC_DELETE_H

#include"../File.h"

void File::dynamicDelete(int id) {
    
    for(Node & node : ids) {
        
        if(node.id == id) {           
            deleteds.push_back(&node);
            break;
        }
    }
}

#endif