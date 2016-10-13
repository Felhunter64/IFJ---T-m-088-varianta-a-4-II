//
// Created by chronos on 10/11/16.
//


#include <stdlib.h>
#include <stdio.h>

#include "vyrazy.h"
#include "memory.h"

void main(){printf("ajajaaaj %d\n",ZLE);}

/*
 * precedencna tabulka
*/

const enumRovnost precTabulkaPreIf[POCET_VYRAZOV][POCET_VYRAZOV]={
             //+  ,  -  ,  *  ,  /  ,  <  ,  >  ,  <= ,  >= ,  == ,  != ,  (  ,  )  ,  id ,  $  ,  \,
 /*  +  */   {VAC , VAC , MEN , MEN , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC , VAC},
 /*  -  */   {VAC , VAC , MEN , MEN , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC , VAC},
 /* \*  */   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC , VAC},
 /*  /  */   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC , VAC},
 /*  <  */   {MEN , MEN , MEN , MEN , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC , ZLE},
 /*  >  */   {MEN , MEN , MEN , MEN , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC , ZLE},
 /* <=  */   {MEN , MEN , MEN , MEN , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC , ZLE},
 /* >=  */   {MEN , MEN , MEN , MEN , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC , ZLE},
 /* ==  */   {MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , VAC , VAC , MEN , VAC , MEN , VAC , ZLE},
 /* !=  */   {MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , VAC , VAC , MEN , VAC , MEN , VAC , ZLE},
 /*  (  */   {MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , ROV , MEN , ZLE , ROV},
 /*  )  */   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , ZLE , VAC , ZLE , VAC , VAC},
 /* id  */   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , ZLE , VAC , ZLE , VAC , VAC},
 /*  $  */   {MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , ZLE , MEN , ZLE , ZLE},
 /*  ,  */   {MEN , MEN , MEN , MEN , ZLE , ZLE , ZLE , ZLE , ZLE , ZLE , MEN , ROV , MEN , ZLE , ROV},
};






