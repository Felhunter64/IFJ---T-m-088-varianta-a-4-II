//
// Created by chronos on 10/13/16.
//

#ifndef IFJ_88_GARBAGE_COLLECTOR_H
#define IFJ_88_GARBAGE_COLLECTOR_H

typedef struct{
    struct sAddress **arr;
    int size;
}tTableOfAddress;

typedef struct sAddress{
    int address;
    struct sAddress *nextAddress;
}tAddress;



#endif //IFJ_88_GARBAGE_COLLECTOR_H
