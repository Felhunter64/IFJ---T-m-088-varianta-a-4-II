//
// Created by oldo on 5.10.16.
//
//todo funkcia na prevod stringu na cislo pre EDKA
//todo ked dostanem EOF tak freeujem string ....
//todo namallocovanie stringu
//todo prepisat enumVyrazy z knihovne vyrazy.h do anglictiny


#define dlzka_tokenu=50


#include "scanner.h"
#include <ctype.h>
#include <stdio.h>
#include "memory.h"
#include "errors.h"
#include <string.h>

FILE *sourceFile;
tTableOfAddress * htable;
int main(int argc,char *argv[]){
    if((sourceFile = fopen(argv[1], "r")) == NULL)
        return printErrors(13);





    if((htable = createHtable(100)) == NULL)
        return printErrors(INTERNA_CHYBA);





getNextToken();





    deleteHtable(htable);
    return 0;
}

tToken getNextToken(){
    int c;
    int countChar=0;
    int  state = START;
    char *tmpStr=xMalloc(sizeof(char)*50,htable);
    tToken token = (tToken)xMalloc(sizeof(struct sToken),htable);
    /*if (getc(sourceFile)==EOF){
        xFree(token,htable);
    }*/
    while((c=getc(sourceFile)) != EOF){

        switch (state) {
            case START:
                if (isspace(c)) {
                    state = START;
                }
                else if (c=='+'){
                    token->numToken=PLUS;
                    return token;

                }
                else if (c=="-") {
                    token->numToken = MINUS;
                    return token;
                }
                else if (c=="*") {
                    token->numToken = KRAT;
                    return token;
                }
                else if (c=="(") {
                    token->numToken = LZATVORKA;
                    return token;
                }
                else if (c==")") {
                    token->numToken = PZATVORKA;
                    return token;
                }
                else if (c=="{") {
                    token->numToken = PICNA_ZATVORKA_L;
                    return token;
                }
                else if (c=="}") {
                    token->numToken = PICNA_ZATVORKA_R;
                    return token;
                }
                else if (c==",") {
                    token->numToken = CIARKA;
                    return token;
                }
                else if (c==";") {
                    token->numToken = BODKO_CIARKA;
                    return token;
                }
                break;
        }
}   }