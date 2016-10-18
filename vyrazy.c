//
// Created by chronos on 10/11/16.
//

// TODO ked dostanes v tokene END tak uvolnis strukturu (token)
#include <stdlib.h>
#include <stdio.h>

#include "vyrazy.h"
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

int processExp(){
    tToken x;
    while((x = getNextToken()) && x->numToken!= END){

        printf("%d : %s\n", x->numToken, x->stringToken);
    }

   return 0;


}







