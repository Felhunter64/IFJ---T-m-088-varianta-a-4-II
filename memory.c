//
// Created by chronos on 10/13/16.
//

#include <stdlib.h>
#include <stdio.h>

#include "memory.h"
#include "errors.h"



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
    printf("ok\n");
    return newAddress;
}


//odstrani tAdresu z hesovacej tabulky a vrati jej adresu
void* retrieveAddress(int addressNum, tTableOfAddress *htable){
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

//malokuje pamat o velkosti size a zaroven adresu prida dao hes tabulky,
//v pripade neuspechu vrati hodnotu NULL
void* malokuj(int size, tTableOfAddress *htable){
    void* ptr;

    if((ptr = malloc(sizeof(size))) == NULL)
        return NULL;

    if(insertAddress(ptr, htable) == NULL)
        NULL;

    return ptr;
}


int uvolni(void* ptr, tTableOfAddress *htable){
    tAddress *address = retrieveAddress(ptr, htable);
    if(address == NULL)
        return INTERNA_CHYBA;

    free(address);

    return 0;
}

int main(){
    tTableOfAddress* htable = createHtable(100);
    char* aha;
    aha = malokuj(4, htable);
    if(aha == NULL)
        return INTERNA_CHYBA;

    uvolni(aha, htable);
    aha = malokuj(4, htable);
    if(aha == NULL)
        return INTERNA_CHYBA;
    aha = malokuj(4, htable);
    if(aha == NULL)
        return INTERNA_CHYBA;
    aha = malokuj(4, htable);
    if(aha == NULL)
        return INTERNA_CHYBA;
    deleteHtable(htable);

}