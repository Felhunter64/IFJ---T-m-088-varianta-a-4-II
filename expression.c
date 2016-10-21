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

//delete
int sendIdToSEA(tToken token){
    return 0;
}

//delete
int sendBinaryRuleToSEA(int leftRule, int operator, int rightRule){
    return 0;
}


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


//check if token can be added as idRule
inline int checkIfId(tToken token){
    if(token->numToken >= 50 && token->numToken <= 56)
        return 1;
    else
        return 0;
}

//for the first time. It converts id immediately to rule
void addToStackIdRule(tStackStart stack, tToken token){
    tStackUnit unitStack = xMalloc(sizeof(struct sStackUnit), htable);


    int position = sendIdToSEA(token);

    //todo dorobit
    if(token->numToken == FUNC)
        //SA_ActionForFun();
        ;

    unitStack->prev = stack->last;
    unitStack->position = position;
    unitStack->numToken = EX_RULE;
    stack->last = unitStack;
}

//for the first time it adds sign that is not id to stack
void addToStackTopUnit(tStackStart stack, int rule){
    tStackUnit unitStack = xMalloc(sizeof(struct sStackUnit), htable);

    unitStack->prev = stack->last;
    unitStack->position = 0;
    unitStack->numToken = rule;
    stack->last = unitStack;
    stack->top = unitStack;
}

//add rule to stack after reduction
void addToStackRule(tStackStart stack, int position, tStackUnit unitStack){

    unitStack->position = position;
    unitStack->numToken = EX_RULE;
    stack->last = unitStack;
    stack->top = unitStack->prev;

}

inline int checkIfReduceStack(tStackStart stack, tToken token){
    enumEquality reduceOption = precTable[stack->top->numToken][token->numToken];
    //delete
    //printf("top:%d %d\n", stack->top->numToken, token->numToken);

    return reduceOption;
}

int reduceUnitStack(tStackStart stack){
    tStackUnit lastStack = stack->last;
    tStackUnit topStack = stack->top;

    //binary operator on top
    //has to be rule on both sides
    if(topStack->numToken >= PLUS && topStack->numToken <= NOT_EQUAL)
        if(lastStack->numToken != EX_RULE || stack->top->prev->numToken != EX_RULE){
            return 1;
        }else{
            int position = sendBinaryRuleToSEA(topStack->prev->position, topStack->numToken, lastStack->position);
            addToStackRule(stack, position, topStack->prev);
            xFree(lastStack, htable);
            xFree(topStack, htable);
        }

    //todo all 3
    //right bracket on top
    if(lastStack->numToken == R_BRACKET)
        ;

    //left bracket on top
    if(lastStack->numToken == L_BRACKET)
        ;

    //EX_END on top
    if(lastStack->numToken == EX_END)
        ;

    return 0;
}

//todo
void showStack(tStackStart stack){

}

//todo
int chceckIfEndSign(tToken token){

}

int processExp(){
    tToken token;
    tStackStart stack = exCreateStack();

    while((token = getNextToken()) && token->numToken!= END){

        printf("%d : %s\n", token->numToken, token->stringToken);

        if(checkIfId(token)){
            addToStackIdRule(stack, token);
            //delete
            //printf("ok\n");
            continue;
        }

        //delete
        //printf("check: %d\n", checkIfReduceStack(stack, token));

        switch(checkIfReduceStack(stack, token)){
            case LES :
                addToStackTopUnit(stack, token->numToken);
                break;
            case GRE :
                reduceUnitStack(stack);
                exit(77);
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







