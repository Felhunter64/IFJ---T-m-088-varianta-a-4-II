#include <stdlib.h>
#include <stdio.h>


#include "expression.h"
#include "scanner.h"
#include "memory.h"
#include "errors.h"

tTableOfAddress * htable;
FILE *sourceFile;

int main(char **argv,int argc) {

    if((sourceFile = fopen(argv, "r")) == NULL)
        return printErrors(INTERNA_CHYBA);

    if((htable = createHtable(100)) == NULL)
        return printErrors(INTERNA_CHYBA);

    //printf("Hello, World asdasfssgfsafasfaq g!");

    deleteHtable(htable);

    return 0;


}


