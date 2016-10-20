//
// Created by oldo on 5.10.16.
//

#include "memory.h"

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
    MULTIPLY,               // * hotovo
    DIVINE,             // /
    LESS,           // <
    GREATER,           // >
    LESS_EQUAL,   // <=
    GREATER_EQUAL,   // >=
    EQUAL,           // ==
    NOT_EQUAL,          // !=
    L_BRACKET,          // ( hotovo
    R_BRACKET,          // ) hotovo
    ASSIGN,           // =
    L_PI_BRACKET,   // { hotovo
    R_PI_BRACKET,   // } hotovo
    COMMA,             // , hotovo
    DOT_COMMA        // ; hotovo

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
    LESS_STATE,
    GREATER_STATE,
    NOT,
    DIV_OR_COM,
    IDENTIFY,
    NUMBER,
    MAYBE_STRING,
    LINE_COMMENT,
    END_COMMENT,
    MULTI_LINE_COMMENT,
    EXPONENT,
    DEC,
    DOUB,
    EXP,

}states;

tToken getNextToken();

extern tTableOfAddress * htable;

#endif //IFJ_88_SCANNER_H

/*koniec hlavickoveho suboru*/