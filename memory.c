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
    int hashKey = (int) addressNum % htable->size;
    //delete printf("h %d\n", hashKey);

    if((newAddress = malloc(sizeof(tAddress))) == NULL)
        return NULL;

    newAddress->address = addressNum;
    newAddress->nextAddress = NULL;

    if(htable->arr[hashKey] == NULL){
        htable->arr[hashKey] = newAddress;
        //delete printf("%u\n", addressNum);
        return newAddress;
    }

    tAddress *tmpAddress = htable->arr[hashKey];

    while(tmpAddress->nextAddress != NULL)
        tmpAddress = tmpAddress->nextAddress;

    tmpAddress->nextAddress = newAddress;

    return newAddress;
}


//odstrani tAdresu z hesovacej tabulky a vrati jej hodnotu premennej address
void* retrieveAddress(int addressNum, tTableOfAddress *htable){
    int hashKey = (int) addressNum % htable->size;
    void* address;
    //delete printf("%u\n", addressNum);
    //delete printf("h %d\n", hashKey);
    if(htable->arr[hashKey] == NULL){
        return NULL;
    }

    tAddress *tmpAddress = htable->arr[hashKey];
    //delete printf("f%u\n", tmpAddress->address);
    if(tmpAddress->address == addressNum){
        htable->arr[hashKey] = tmpAddress->nextAddress;
        address = tmpAddress->address;
        free(tmpAddress);
        return address;
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

    address = tmp2Address->address;
    free(tmpAddress);
    return address;
}

void deleteHtable(tTableOfAddress *htable){
    tAddress* tmpAddress;

    for(int i = 0; i < htable->size; i++){
        while(htable->arr[i] != NULL){
            tmpAddress = htable->arr[i]->nextAddress;
            free(htable->arr[i]->address);
            free(htable->arr[i]);
            htable->arr[i] = tmpAddress;
        }
    }

    free(htable->arr);
    free(htable);

    return;
}

//malokuje pamat o velkosti size a zaroven adresu prida dao hes tabulky,
//v pripade neuspechu ukonci program s navratovou hodnotou INTERNA_CHYBA
void* xMalloc(int size, tTableOfAddress *htable) {
    void *ptr;

    if ((ptr = malloc(size)) == NULL){
        deleteHtable(htable);
        exit(INTERNA_CHYBA);
    }
    //delete printf("%u\n", ptr);
    if (insertAddress(ptr, htable) == NULL){
        deleteHtable(htable);
        exit(INTERNA_CHYBA);
    }

    return ptr;
}


int xFree(void* ptr, tTableOfAddress *htable){
    void *address = retrieveAddress(ptr, htable);
    //delete printf("free %u\n", address);
    if(address == NULL) {
        deleteHtable(htable);
        exit(INTERNA_CHYBA);
    }

    //delete printf("super%u\n", address);
    free(address);

    return 0;
}

/*delete
int main(){
    tTableOfAddress* htable = createHtable(2);
    char* aha;
    aha = xMalloc(4, htable);
    if(aha == NULL)
        return INTERNA_CHYBA;

    //delete printf("%u\n", aha);

    if((xFree(aha, htable)) == INTERNA_CHYBA)
        return INTERNA_CHYBA;

    aha = xMalloc(4, htable);
    if(aha == NULL)
        return INTERNA_CHYBA;
    aha = xMalloc(4, htable);
    if(aha == NULL)
        return INTERNA_CHYBA;
    aha = xMalloc(4, htable);
    if(aha == NULL)
        return INTERNA_CHYBA;
    aha = xMalloc(4, htable);
    if(aha == NULL)
        return INTERNA_CHYBA;
    deleteHtable(htable);

    return 0;

}
 */