//
// Created by oldo on 14.10.16.
//
#include "errors.h"
#include <stdlib.h>
#include <stdio.h>


int printErrors(int error) {
    /* local variable definition */
    int  state = error;

    switch(state) {
        case 0 :
            break;
        case 1 :
            printf("chyba v programu v rámci lexikální analýzy (chybná struktura aktuálního lexé-\n"
                           "mu).\n" );
            break;
        case 2 :
            printf("chyba v programu v rámci syntaktické analýzy (chybná syntaxe programu).\n");
            break;
        case 3 :
            printf("sémantická chyba v programu – nedefinovaná třída/funkce/proměnná, pokus o re-\n"
                           "definici třídy/funkce/proměnné, atd.\n" );
            break;
        case 4 :
            printf("sémantická chyba typové kompatibility v aritmetických, řetězcových a relačních\n"
                           "výrazech, příp. špatný počet či typ parametrů u volání funkce.\n" );
            break;
        case 6 :
            printf("ostatní sémantické chyby.\n" );
            break;
        case 7 :
            printf("běhová chyba při načítání číselné hodnoty ze vstupu.\n");
            break;
        case 8 :
            printf("běhová chyba při práci s neinicializovanou proměnnou.\n" );
            break;
        case 9 :
            printf("běhová chyba dělení nulou.\n" );
            break;
        case 10 :
            printf("ostatní běhové chyby.\n" );
            break;
        case 99 :
            printf("interní chyba interpretu tj. neovlivněná vstupním programem (např. chyba a-\n"
                           "lokace paměti, chyba při otvírání souboru s řídicím programem, špatné parametry\n"
                           "příkazové řádky atd.).\n" );
            break;
        default :
            printf("Unknown Error\n" );
    }


    return error;
}

/*  delete
    int main () {
    int error ;
    return printErrors (error);
}
 */