//
// Created by chronos on 10/11/16.
//


#include <stdlib.h>
#include <stdio.h>

#include "vyrazy.h"

void main(){printf("%d\n",MEN);}

/*
 * precedencna tabulka
*/

const enumRovnost precTabulkaPreIf[POCET_VYRAZOV_PRE_IF][POCET_VYRAZOV_PRE_IF]={
             //+  ,  -  ,  *  ,  /  ,  <  ,  >  ,  <= ,  >= ,  == ,  != ,  (  ,  )  ,  id ,  $
 /*  +  */   {VAC , VAC , MEN , MEN , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC},
 /*  -  */   {VAC , VAC , MEN , MEN , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC},
 /* \*  */   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC},
 /*  /  */   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC},
 /*  <  */   {MEN , MEN , MEN , MEN , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC},
 /*  >  */   {MEN , MEN , MEN , MEN , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC},
 /* <=  */   {MEN , MEN , MEN , MEN , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC},
 /* >=  */   {MEN , MEN , MEN , MEN , VAC , VAC , VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC},
 /* ==  */   {MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , VAC , VAC , MEN , VAC , MEN , VAC},
 /* !=  */   {MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , VAC , VAC , MEN , VAC , MEN , VAC},
 /*  (  */   {MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , ROV , MEN , ZLE},
 /*  )  */   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , ZLE , VAC , ZLE , VAC},
 /* id  */   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , ZLE , VAC , ZLE , VAC},
 /*  $  */   {MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , MEN , ZLE , MEN , ZLE},
};

const enumRovnost precTabulkaPreFun[POCET_VYRAZOV_PRE_FUN][POCET_VYRAZOV_PRE_FUN]={
                    //+  ,  -  ,  *  ,  /  ,  (  ,  )  ,  id ,  \, ,  $
        /*  +  */   {VAC , VAC , MEN , MEN , MEN , VAC , MEN , VAC , VAC},
        /*  -  */   {VAC , VAC , MEN , MEN , MEN , VAC , MEN , VAC , VAC},
        /* \*  */   {VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC , VAC},
        /*  /  */   {VAC , VAC , VAC , VAC , MEN , VAC , MEN , VAC , VAC},
        /*  (  */   {MEN , MEN , MEN , MEN , MEN , ROV , MEN , ROV , ZLE},
        /*  )  */   {VAC , VAC , VAC , VAC , ZLE , VAC , ZLE , VAC , VAC},
        /* id  */   {VAC , VAC , VAC , VAC , ZLE , VAC , ZLE , VAC , VAC},
        /*  ,  */   {MEN , MEN , MEN , MEN , MEN , ROV , MEN , ROV , ZLE},
        /*  $  */   {MEN , MEN , MEN , MEN , MEN , ZLE , MEN , ZLE , ZLE},
};



