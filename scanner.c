//
// Created by oldo on 5.10.16.
//
//todo funkcia na prevod stringu na cislo pre EDKA
//todo ked dostanem EOF tak freeujem string ....
//todo namallocovanie stringu

#define dlzka_tokenu=50


#include "scanner.h"
#include <ctype.h>
#include <stdio.h>
#include "memory.h"
#include "errors.h"

FILE *sourceFile;
int main(int argc,char *argv[]){
    if((sourceFile = fopen(argv, "r")) == NULL)
        return printErrors(INTERNA_CHYBA);



    tTableOfAddress * htable;

    if((htable = createHtable(100)) == NULL)
        return printErrors(INTERNA_CHYBA);



    xMalloc(sizeof(struct sToken),htable);

    getNextToken();

    deleteHtable(htable);
}

