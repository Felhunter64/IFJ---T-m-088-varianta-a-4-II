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


//delete
int sendIdToSEA(tToken token){
    return 0;
}

//delete
int sendBinaryOperatorRuleToSEA(int leftRule, int operator, int rightRule){
    return 0;
}

//delete
void sendEndOfExpToSEA(){
    return;
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

    unitStack->prev = stack->last;
    unitStack->position = position;
    unitStack->numToken = EX_RULE;
    stack->last = unitStack;
}

//for the first time it adds token that is not id to stack
void addToStackTopUnit(tStackStart stack, int numToken, int expOption){
    tStackUnit unitStack = xMalloc(sizeof(struct sStackUnit), htable);

    if(expOption != RULE_FUNC && numToken == COMMA){
        deleteHtable(htable);
        exit(SYN_ERROR);
    }

    unitStack->prev = stack->last;
    unitStack->position = 0;
    unitStack->numToken = numToken;
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
    enumEquality reduceOption;

    if(checkIfId(token))
        reduceOption = precTable[stack->top->numToken][EX_RULE];
    else
        reduceOption = precTable[stack->top->numToken][token->numToken];

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
            int position = sendBinaryOperatorRuleToSEA(topStack->prev->position, topStack->numToken, lastStack->position);
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

void showStack(tStackStart stack){
    tStackUnit last = stack->last;
    printf("stack(from the last token):\n");
    while(last != NULL){
        printf("position: %d    numToken: %d\n", last->position, last->numToken);
        last = last->prev;
    }
}

//in case of end, the function returns 1
int chceckIfEndToken(tToken token, int* counterOfBrackets, int expOption){
    switch(expOption){
        case RULE_ASSIGN :
            //if there is ';' expression ends
            if(token->numToken == DOT_COMMA) {
                sendEndOfExpToSEA();
                return 1;
            }
            return 0;
        case RULE_IF :
            //if there is the same count of right and left
            //brackets, the expression ends
            if(*counterOfBrackets == 0) {
                sendEndOfExpToSEA();
                return 1;
            }
            return 0;
        case RULE_FUNC :
            if(*counterOfBrackets == 0) {
                sendEndOfExpToSEA();
                return 1;
            }
            return 0;
        default :
            deleteHtable(htable);
            exit(INTERNAL_ERROR);

    }

    return 1;
}



int processExp(int expOption){
    tToken token;
    tStackStart stack = exCreateStack();
    int* counterOfBrackets = xMalloc(sizeof(int), htable);
    *counterOfBrackets = 1;

    while((token = getNextToken()) && token->numToken!= END){

        //if token cannot be in an expression at all,
        //the programm ends
        if(token->numToken < PLUS || token->numToken > COMMA){
            deleteHtable(htable);
            exit(SYN_ERROR);
        }

        printf("%d : %s\n", token->numToken, token->stringToken);

        //counts a number of brackets
        //left bracket increases the number and right decreases
        if(expOption == RULE_IF || expOption == RULE_FUNC){
            if(token->numToken == L_BRACKET)
                (*counterOfBrackets)++;
            if(token->numToken == R_BRACKET)
                (*counterOfBrackets)--;
        }

        //if tehre is no valid token just the EX_END token,
        //the while cycle is stopped and only reduction is allowed
        if(chceckIfEndToken(token, counterOfBrackets, expOption))
            break;

        //delete
        //printf("check: %d\n", checkIfReduceStack(stack, token));

        switch(checkIfReduceStack(stack, token)){
            case LES :
                if(checkIfId(token))
                    addToStackIdRule(stack, token);
                else
                    addToStackTopUnit(stack, token->numToken, expOption);
                break;
            case GRE :
                //delete
                //showStack(stack);
                reduceUnitStack(stack);
                //delete
                //showStack(stack);
                exit(77);
                break;
            case EQU :
                ;
                break;
            case BAD :
                deleteHtable(htable);
                exit(SYN_ERROR);
            default :
                deleteHtable(htable);
                exit(INTERNAL_ERROR);
        }


    }

    if(token == NULL){
        deleteHtable(htable);
        exit(INTERNAL_ERROR);
    }

    //reduce till top of stack is EX_END token
    do{
        reduceUnitStack(stack);
    }while(stack->top->numToken != EX_END);


    //free all used resources
    xFree(counterOfBrackets, htable);
    exDeleteStack(stack);

    return 0;
}







