//
// Created by chronos on 10/11/16.
//

#ifndef IFJ_88_VYRAZY_H
#define IFJ_88_VYRAZY_H

#define POCET_VYRAZOV_PRE_IF 14



typedef enum{
    PLUS,               // +
    MINUS,              // -
    KRAT,               // *
    DELENO,             // /
    MENSITKO,           // <
    VACSITKO,           // >
    MENSITKO_ROVNASA,   // <=
    VACSITKO_ROVNASA,   // >=
    ROVNASA,            // ==
    NEROVNASA,          // !=
    LZATVORKA,          // (
    PZATVORKA,          // )
    ID,                 // identifikator(premenna, funkcia, objekt(premenna), objekt(funkcia), literal)
    CIARKA              // ,
}enumVyrazy;

typedef enum{
    VAC,    // >
    MEN,    // <
    ROV,    // ==
    ZLE     // syntakticka chyba
}enumRovnost;

void spustiVyrazy();

#endif //IFJ_88_VYRAZY_H