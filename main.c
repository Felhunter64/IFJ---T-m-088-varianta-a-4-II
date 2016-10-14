#include <stdlib.h>
#include <stdio.h>


#include "vyrazy.h"
#include "scanner.h"
#include "memory.h"
#include "errors.h"

int main() {

    tTableOfAddress * htable;

    if((htable = createHtable(100)) == NULL)
        return printErrors(INTERNA_CHYBA);

    //printf("Hello, World asdasfssgfsafasfaq g!");

    deleteHtable(htable);

    return 0;


}


