//
// Created by oldo on 5.10.16.
//

#ifndef IFJ_88_SCANNER_H
#define IFJ_88_SCANNER_H

typedef struct sToken {
    char *stringToken;
    int numToken;
}tToken;

typedef enum {
    KEY_BOOLEAN=10,
    KEY_BREAK,
    KEY_CLASS,
    KEY_CONTINUE,
    KEY_DO,
    KEY_DOUBLE,
    KEY_ELSE,
    KEY_FALSE,
    KEY_FOR,
    KEY_IF,
    KEY_INT,
    KEY_RETURN,
    KEY_STRING,
    KEY_STATIC,
    KEY_TRUE,
    KEY_VOID,
    KEY_WHILE
}keywords;

typedef enum{
    IDENT1=0,     //Jednoduchý identifikátor
    IDENT2,     //Plně kvalifikovaný identifikátor
}ident;

typedef enum{
    PLUS = 30,               // +
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
    ROVNA_SA,           // =
    PICNA_ZATVORKA_L,   // {
    PICNA_ZATVORKA_R,   // }
    CIARKA              // ,
}operators;

typedef enum{
    INTEGER=50,
    DOUBLE,
    STRING,
}numbers;

typedef enum{

}states;

int getNextToken();


#endif //IFJ_88_SCANNER_H

/*koniec hlavickoveho suboru*/