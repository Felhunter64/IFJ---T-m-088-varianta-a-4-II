//
// Created by chronos on 10/13/16.
//

#include <stdlib.h>
#include <stdio.h>

#include "memory.h"



tTableOfAddress* createHtable(int size){

    tTableOfAddress *htable;

    if((htable = malloc(sizeof(tTableOfAddress))) == NULL)
        return NULL;

    if((htable->arr = malloc(sizeof(tAddress*) * size)) == NULL)
        return NULL;

    for(int i = 0; i < size; i++)
        htable->arr[i] = NULL;

    htable->size = size;

    return htable;
}

tAddress* insertAddress(int addressNum, tTableOfAddress *htable){
    tAddress* newAddress;
    int hashKey = addressNum % htable->size;

    if((newAddress = malloc(sizeof(tAddress))) == NULL)
        return NULL;

    newAddress->address = addressNum;
    newAddress->nextAddress = NULL;

    if(htable->arr[hashKey] == NULL){
        htable->arr[hashKey] = newAddress;
        return newAddress;
    }

    tAddress *tmpAddress = htable->arr[hashKey];

    while(tmpAddress->nextAddress != NULL)
        tmpAddress = tmpAddress->nextAddress;

    tmpAddress->nextAddress = newAddress;

    return newAddress;
}


//odstrani tAdresu z hesovacej tabulky a vrati jej adresu
tAddress* retrieveAddress(int addressNum, tTableOfAddress *htable){
    int hashKey = addressNum % htable->size;

    if(htable->arr[hashKey] == NULL){
        return NULL;
    }

    tAddress *tmpAddress = htable->arr[hashKey];

    if(tmpAddress->address == addressNum){
        htable->arr[hashKey] = tmpAddress->nextAddress;
        free(tmpAddress);
    }

    if(tmpAddress->nextAddress == NULL)
        return NULL;

    while(tmpAddress->nextAddress->address != addressNum) {
        tmpAddress = tmpAddress->nextAddress;
        if(tmpAddress->nextAddress == NULL)
            return NULL;
    }

    tAddress *tmp2Address = tmpAddress->nextAddress;
    tmpAddress = tmpAddress->nextAddress->nextAddress;

    return tmp2Address;
}

void deleteHtable(tTableOfAddress *htable){
    tAddress* tmpAddress;

    for(int i = 0; i < htable->size; i++){
        while(htable->arr[i] != NULL){
            tmpAddress = htable->arr[i]->nextAddress;
            free(htable->arr[i]);
            htable->arr[i] = tmpAddress;
        }
    }

    return;
}