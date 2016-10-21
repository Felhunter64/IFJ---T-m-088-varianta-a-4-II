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

    stack->last->numToken = END;
    stack->last->position = 0;
    stack->last->prev = NULL;

    return stack;
}

tStackStart exDeleteStack(tStackStart stack){
    xFree(stack->last, htable);
    xFree(stack, htable);
}

void sendIdToSEA(tToken token){
    return;
}

void addToStackIdRule(tStackStart stack, int position, tToken token){
    tStackUnit unitStack = xMalloc(sizeof(struct sStackUnit), htable);


    sendIdToSEA(token);

    if(token->numToken == FUNC)
        //SA_ActionForFun();
        ;

    unitStack->prev = stack->last;
    unitStack->position = position;
    unitStack->numToken = RULE;
    stack->last = unitStack;
}

void addToStackTopUnit(tStackStart stack, expressionRules rule, int position){
    tStackUnit unitStack = xMalloc(sizeof(struct sStackUnit), htable);

    unitStack->prev = stack->last;
    unitStack->position = position;
    unitStack->numToken = rule;
    stack->last = unitStack;
    stack->top = unitStack;
}

void checkIfReduceStack(tStackStart stack, tToken token){
    enumEquality reduceOption = precTable[stack->top->numToken][token->numToken];
}

void reduceUnitStack(){

}



int processExp(){
    tToken token;
    tStackStart stack = exCreateStack();

    while((token = getNextToken()) && token->numToken!= END){

        printf("%d : %s\n", token->numToken, token->stringToken);



    }

    exDeleteStack(stack);

    return 0;
}







