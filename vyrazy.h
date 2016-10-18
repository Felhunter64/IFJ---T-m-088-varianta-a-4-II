//
// Created by chronos on 10/11/16.
//

#ifndef IFJ_88_VYRAZY_H
#define IFJ_88_VYRAZY_H

#define POCET_VYRAZOV 15


typedef enum{
    PLUS,              // +
    MINUS,             // -
    MULTIPLY,          // *
    DIVIDE,            // /
    LESS,              // <
    GREATER,           // >
    LESS_EQUAL,        // <=
    GREATER_EQUAL,     // >=
    EQUAL,             // ==
    NOT_EQUAL,         // !=
    L_BRACKET,         // (
    R_BRACKET,         // )
    ID,                // identifikator(premenna, funkcia, objekt(premenna), objekt(funkcia), literal)
    END,               // koniec
    COMMA              // ,
}enumExpressions;

typedef enum{
    GRE,    // >
    LES,    // <
    EQU,    // ==
    BAD     // syntakticka chyba
}enumEquality;

typedef enum{
    RULE_ASSIGN,    // = Pouzit tu?
    RULE_RETURN,    // return Pouzit tu?
    RULE_IF,        // if Pouzit tu?

    RULE_FUNC,      // zacina pouzitie nejakej funkcie - foo()
    RULE_VAR,       // pouzitie premennej

    RULE_PLUS,               // +
    RULE_MINUS,              // -
    RULE_MULTIPLY,           // *
    RULE_DIVIDE,             // /
    RULE_LESS,               // <
    RULE_GREATER,            // >
    RULE_LESS_EQUAL,         // <=
    RULE_GREATER_EQUAL,      // >=
    RULE_EQUAL,              // ==
    RULE_NOT_EQUAL,          // !=
    RULE_END                 // koniec
}expressionRules;

typedef struct sToken {
    char *stringToken;
    int numToken;
}tToken;

void spustiVyrazy();

#endif //IFJ_88_VYRAZY_H