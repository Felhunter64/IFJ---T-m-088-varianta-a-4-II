//
// Created by chronos on 10/11/16.
//

// TODO ked dostanes v tokene END tak uvolnis strukturu (token)
// todo zistit foo medzera ()   ci je paltne?
#include <stdlib.h>
#include <stdio.h>

#include "expression.h"
#include "memory.h"
#include "scanner.h"
#include "errors.h"


//void main(){printf("ajajaaaj %d\n",BAD);}

/*
 * precedencna tabulka
 *
*/

const enumEquality precTable[POCET_VYRAZOV][POCET_VYRAZOV]={
             //+  ,  -  ,  *  ,  /  ,  <  ,  >  ,  <= ,  >= ,  == ,  != ,  (  ,  )  ,  id ,  $  ,  \,
 /*  +  */   {GRE , GRE , LES , LES , GRE , GRE , GRE , GRE , GRE , GRE , LES , GRE , LES , GRE , GRE},
 /*  -  */   {GRE , GRE , LES , LES , GRE , GRE , GRE , GRE , GRE , GRE , LES , GRE , LES , GRE , GRE},
 /* \*  */   {GRE , GRE , GRE , GRE , GRE , GRE , GRE , GRE , GRE , GRE , LES , GRE , LES , GRE , GRE},
 /*  /  */   {GRE , GRE , GRE , GRE , GRE , GRE , GRE , GRE , GRE , GRE , LES , GRE , LES , GRE , GRE},
 /*  <  */   {LES , LES , LES , LES , GRE , GRE , GRE , GRE , GRE , GRE , LES , GRE , LES , GRE , BAD},
 /*  >  */   {LES , LES , LES , LES , GRE , GRE , GRE , GRE , GRE , GRE , LES , GRE , LES , GRE , BAD},
 /* <=  */   {LES , LES , LES , LES , GRE , GRE , GRE , GRE , GRE , GRE , LES , GRE , LES , GRE , BAD},
 /* >=  */   {LES , LES , LES , LES , GRE , GRE , GRE , GRE , GRE , GRE , LES , GRE , LES , GRE , BAD},
 /* ==  */   {LES , LES , LES , LES , LES , LES , LES , LES , GRE , GRE , LES , GRE , LES , GRE , BAD},
 /* !=  */   {LES , LES , LES , LES , LES , LES , LES , LES , GRE , GRE , LES , GRE , LES , GRE , BAD},
 /*  (  */   {LES , LES , LES , LES , LES , LES , LES , LES , LES , LES , LES , EQU , LES , BAD , EQU},
 /*  )  */   {GRE , GRE , GRE , GRE , GRE , GRE , GRE , GRE , GRE , GRE , BAD , GRE , BAD , GRE , GRE},
 /* id  */   {GRE , GRE , GRE , GRE , GRE , GRE , GRE , GRE , GRE , GRE , BAD , GRE , BAD , GRE , GRE},
 /*  $  */   {LES , LES , LES , LES , LES , LES , LES , LES , LES , LES , LES , BAD , LES , BAD , BAD},
 /*  ,  */   {LES , LES , LES , LES , BAD , BAD , BAD , BAD , BAD , BAD , LES , EQU , LES , BAD , EQU},
};


//todo sendId(), sendRule(), counter, stack(push, pop, create)

tStackStart exCreateStack(){
    tStackStart stack;
    stack = xMalloc(sizeof(struct sStackUnit), htable);

    stack->last = xMalloc(sizeof(struct sStackUnit), htable);
    stack->top = stack->last;

    stack->last->rule = RULE_END;
    stack->last->position = 0;
    stack->last->prev = NULL;

    return stack;
}

//todo premenit id na pravidlo
void addToStackIdRule(tStackStart stack, int position){
    tStackUnit unitStack = xMalloc(sizeof(struct sStackUnit), htable);

    unitStack->prev = stack->last;
    unitStack->position = position;
    unitStack->rule = RULE_RULE;
    stack->last = unitStack;
}

//todo pridat prvok ktory nie je pravidlo na zaciatku(nie je id)
void addToStackTopUnit(tStackStart stack, expressionRules rule, int position){
    tStackUnit unitStack = xMalloc(sizeof(struct sStackUnit), htable);

    unitStack->prev = stack->last;
    unitStack->position = position;
    unitStack->rule = rule;
    stack->last = unitStack;
}

int processExp(){
    tToken token;
    tStackStart stack = exCreateStack();

    while((token = getNextToken()) && token->numToken!= END){

        printf("%d : %s\n", token->numToken, token->stringToken);



    }


    xFree(stack, htable);

    return 0;
}







