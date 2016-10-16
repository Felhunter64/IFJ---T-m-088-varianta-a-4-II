//
// Created by oldo on 5.10.16.
//

#ifndef IFJ_88_SCANNER_H
#define IFJ_88_SCANNER_H

typedef struct sToken {
    char *stringToken;
    int numToken;
}*tToken;

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
    PLUS = 30,          // + hotovo
    MINUS,              // - hotovo
    KRAT,               // * hotovo
    DELENO,             // /
    MENSITKO,           // <
    VACSITKO,           // >
    MENSITKO_ROVNASA,   // <=
    VACSITKO_ROVNASA,   // >=
    ROVNASA2,           // ==
    NEROVNASA,          // !=
    LZATVORKA,          // ( hotovo
    PZATVORKA,          // ) hotovo
    ROVNA_SA,           // =
    PICNA_ZATVORKA_L,   // { hotovo
    PICNA_ZATVORKA_R,   // } hotovo
    CIARKA,             // , hotovo
    BODKO_CIARKA        // ; hotovo

}operators;

typedef enum{
    INTEGER=50,
    DOUBLE,
    STRING,
}numbers;

typedef enum{
    START=80,
    END,
    CMP,
    LESS,
    GREATHER,
    NOT,
    DIV_OR_COM,
    IDENTIFY,
    NUMBER,
    MAYBE_STRING,

}states;

tToken getNextToken();


#endif //IFJ_88_SCANNER_H

/*koniec hlavickoveho suboru*/