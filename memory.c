//
// Created by chronos on 10/13/16.
//

#include <stdlib.h>
#include <stdio.h>

#include "memory.h"


typedef struct{
    struct sAdresa **pole;
    int size;
}tTabulkaAdries;

typedef struct sAdresa{
    int adresa;
    struct sAdresa *dalsiaAdresa;
}tAdresa;

tTabulkaAdries createHtable(int size){

    tTabulkaAdries htable;

    if((htable = (tTabulkaAdries) malloc(sizeof(tTabulkaAdries))) == NULL)
        return NULL;

}