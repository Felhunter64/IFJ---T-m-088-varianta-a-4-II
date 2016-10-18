//
// Created by chronos on 10/11/16.
//

#ifndef IFJ_88_VYRAZY_H
#define IFJ_88_VYRAZY_H

#define POCET_VYRAZOV 15

/*
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
 */

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

    RULE_PLUS,               // x + y
    RULE_MINUS,              // x - y
    RULE_MULTIPLY,           // x * y
    RULE_DIVIDE,             // x / y
    RULE_LESS,               // x < y
    RULE_GREATER,            // x > y
    RULE_LESS_EQUAL,         // x <= y
    RULE_GREATER_EQUAL,      // x >= y
    RULE_EQUAL,              // x == y
    RULE_NOT_EQUAL,          // x != y
    RULE_BRACKETS,           // (x)
    RULE_END                 // koniec
}expressionRules;


void spustiVyrazy();
void processExp();

#endif //IFJ_88_VYRAZY_H