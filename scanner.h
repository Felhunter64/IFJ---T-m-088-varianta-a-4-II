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
    KEY_BOOLEAN = 30,
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
    IDENT1 = 25,     //Jednoduchý identifikátor
    IDENT2,     //Plně kvalifikovaný identifikátor
}ident;

typedef enum{
    PLUS = 0,          // + hotovo
    MINUS,              // - hotovo
    MULTIPLY,               // * hotovo
    DIVINE,             // /  //divine znamena bozsky :D
    LESS,           // <
    GREATER,           // >
    LESS_EQUAL,   // <=
    GREATER_EQUAL,   // >=
    EQUAL,           // ==
    NOT_EQUAL,          // !=
    L_BRACKET,          // ( hotovo
    R_BRACKET,          // ) hotovo
    EX_RULE,                //pre expression.c //identifikator(premenna, funkcia, objekt(premenna), objekt(funkcia), literal)
    EX_END,               //pre expression.c //koniec
    COMMA = 14,             // , hotovo
    L_PI_BRACKET,   // { hotovo
    R_PI_BRACKET,   // } hotovo
    DOT_COMMA,        // ; hotovo
    ASSIGN           // =

}operators;

typedef enum{
    INTEGER = 50,
    DOUBLE,
    SIMPLE_IDENTIFIKATOR_BRACKET,
    SIMPLE_IDENTIFIKATOR,
    FULLY_IDENTIFIKATOR,
    FULLY_IDENTIFIKATOR_BRACKET,
    STRING = 56,

}values;

typedef enum{
    START = 80,
    END,
    CMP,
    LESS_STATE,
    GREATER_STATE,
    NOT,
    DIV_OR_COM,
    IDENTIFY,
    NUMBER,
    MAYBE_STRING, //maybe string?? :D....what about certainly :D
    LINE_COMMENT,
    END_COMMENT,
    MULTI_LINE_COMMENT,
    EXPONENT,
    DEC,
    DOUB,
    EXP,
    FUNC //added, example: foo(
}states;

tToken getNextToken();

extern tTableOfAddress * htable;

#endif //IFJ_88_SCANNER_H

/*koniec hlavickoveho suboru*/