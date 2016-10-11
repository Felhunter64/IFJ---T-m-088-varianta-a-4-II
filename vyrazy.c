//
// Created by chronos on 10/11/16.
//




#include <stdlib.h>
#include <stdio.h>

#include "vyrazy.h"

void main(){}

/*
 * precedencna tabulka
*/

const enumRovnost precTabulka[POCET_VYRAZOV][POCET_VYRAZOV]={
            //+  ,  -  ,  *  ,  /  ,  <  ,  >  ,  <= ,  >= ,  == ,  != ,  (  ,  )  ,  id ,  $
    /*+*/   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC},
    /*-*/   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC},
    /*-*/   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC},
    /*-*/   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC},
    /*-*/   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC},
    /*-*/   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC},
    /*-*/   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC},
    /*-*/   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC},
    /*-*/   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC},
    /*-*/   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC},
    /*-*/   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC},
    /*-*/   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC},
    /*-*/   {VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC , VAC},
};



