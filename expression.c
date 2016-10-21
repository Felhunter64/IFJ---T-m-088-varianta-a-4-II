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

    stack->last->numToken = EX_END;
    stack->last->position = 0;
    stack->last->prev = NULL;

    return stack;
}

tStackStart exDeleteStack(tStackStart stack){
    xFree(stack->last, htable);
    xFree(stack, htable);
}

//todo dorobit
void sendIdToSEA(tToken token){
    return;
}

inline int chceckIfId(tToken token){
    if(token->numToken >= 50 && token->numToken <= 56)
        return 1;
    else
        return 0;
}

void addToStackIdRule(tStackStart stack, int position, tToken token){
    tStackUnit unitStack = xMalloc(sizeof(struct sStackUnit), htable);


    sendIdToSEA(token);

    //todo dorobit
    if(token->numToken == FUNC)
        //SA_ActionForFun();
        ;

    unitStack->prev = stack->last;
    unitStack->position = position;
    unitStack->numToken = EX_RULE;
    stack->last = unitStack;
}

void addToStackTopUnit(tStackStart stack, int rule){
    tStackUnit unitStack = xMalloc(sizeof(struct sStackUnit), htable);

    unitStack->prev = stack->last;
    unitStack->position = 0;
    unitStack->numToken = rule;
    stack->last = unitStack;
    stack->top = unitStack;
}

inline int checkIfReduceStack(tStackStart stack, tToken token){
    enumEquality reduceOption = precTable[stack->top->numToken][token->numToken];

    return reduceOption;
}

void reduceUnitStack(tStackStart stack){
    int lastStack = stack->last;
    int topStack = stack->top;

    //binary operator on top
    if(topStack >= PLUS && topStack <= NOT_EQUAL)
        if(lastStack != EX_RULE || stack->top->prev->numToken != EX_RULE);

    //EX_END on top
    if(lastStack == EX_END)
        ;

    //left bracket on top
    if(lastStack == L_BRACKET)
        ;

    //right bracket on top
    if(lastStack == R_BRACKET)
        ;
}
//delete
/*
int checkSyntax(tStackStart stack, tToken token){
    int numToken = token->numToken;
    int lastStack = stack->last;
    if(lastStack == EX_END)
        if()
    switch(numToken){
        case numT :
            stack->last token->numToken;
            break;
    }
}*/

int processExp(){
    tToken token;
    tStackStart stack = exCreateStack();

    while((token = getNextToken()) && token->numToken!= END){

        printf("%d : %s\n", token->numToken, token->stringToken);

        int reduceOption = checkIfReduceStack(stack, token);

        switch(reduceOption){
            case GRE :
                ;
                break;
            case LES :
                ;
                break;
            case EQU :
                ;
                break;
            case BAD :
                ;
                break;
        }


    }

    exDeleteStack(stack);

    return 0;
}







