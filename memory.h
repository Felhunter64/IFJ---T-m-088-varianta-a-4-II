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


//vracia adresu na ktorej je malokovane miesto o velkosti size a zapise ju do hes tabulky htable
//v pripade neuspechu ukonci program s navratovou hodnotou INTERNA_CHYBA
void* xMalloc(int size, tTableOfAddress *htable);
//uvolni adresu ptr z hes tabulky htable, v pripade neuspechu
// ukonci program s navratovou hodnotou INTERNA_CHYBA
int xFree(void *ptr, tTableOfAddress *htable);
void deleteHtable(tTableOfAddress *htable);
tTableOfAddress* createHtable(int size);

void* retrieveAddress(int addressNum, tTableOfAddress *htable);
tAddress* insertAddress(int addressNum, tTableOfAddress *htable);


#endif //IFJ_88_GARBAGE_COLLECTOR_H
