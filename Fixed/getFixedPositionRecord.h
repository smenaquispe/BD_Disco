#ifndef GET_FIXED_POSITION_RECORD_H
#define GET_FIXED_POSITION_RECORD_H

#include"../File.h"

int File::getFixedPositionRecord(int id) {

    for(const auto & node : ids) {
        if(node.id == id) {
            return node.posStart;
        }
    }

    return -1;

}

#endif