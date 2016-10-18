//
// Created by oldo on 5.10.16.
//
//todo funkcia na prevod stringu na cislo pre EDKA
//todo ked dostanem EOF tak freeujem string ....
//todo namallocovanie stringu
//todo prepisat enumVyrazy z knihovne vyrazy.h do anglictiny


#define dlzka_tokenu= 50


#include "scanner.h"
#include <ctype.h>
#include <stdio.h>
#include "memory.h"
#include "errors.h"
#include <string.h>
#include <stdlib.h>

FILE *sourceFile;
tTableOfAddress * htable;
int temp=0;
int main(int argc,char *argv[]){
    if((sourceFile = fopen("testovaci_subor2.txt", "r")) == NULL)
    //if((sourceFile = fopen(argv[1], "r")) == NULL)
        return printErrors(13);





    if((htable = createHtable(100)) == NULL)
        return printErrors(INTERNA_CHYBA);






//printf("%s\n",getNextToken()->stringToken);
//printf("%d\n",getNextToken()->numToken);
    getNextToken();
    getNextToken();


    deleteHtable(htable);
    return 0;
}

tToken getNextToken(){
    int c;
    int countChar=0;
    int  state = START;
    tToken token = (tToken) xMalloc(sizeof(struct sToken), htable);
    token->stringToken=xMalloc(sizeof(char)*50,htable);
    /*if (getc(sourceFile)==EOF){
        xFree(token,htable);
    }*/
    while(1) {
        c=getc(sourceFile);
        switch (state) {
            case START:
                if (isspace(c)) {
                    state = START;
                } else if (c == '+') {
                    token->stringToken[countChar] = c;
                    token->numToken = PLUS;

                    return token;

                } else if (c == '-') {
                    token->stringToken[countChar] = c;
                    token->numToken = MINUS;
                    return token;
                } else if (c == '*') {
                    token->stringToken[countChar] = c;
                    token->numToken = KRAT;
                    return token;
                } else if (c == '(') {
                    token->stringToken[countChar] = c;
                    token->numToken = LZATVORKA;
                    return token;
                } else if (c == ')') {
                    token->stringToken[countChar] = c;
                    token->numToken = PZATVORKA;
                    return token;
                } else if (c == '{') {
                    token->stringToken[countChar] = c;
                    token->numToken = PICNA_ZATVORKA_L;
                    return token;
                } else if (c == '}') {
                    token->stringToken[countChar] = c;
                    token->numToken = PICNA_ZATVORKA_R;
                    return token;
                } else if (c == ',') {
                    token->stringToken[countChar] = c;
                    token->numToken = CIARKA;
                    return token;
                } else if (c == ';') {
                    token->stringToken[countChar] = c;
                    token->numToken = BODKO_CIARKA;
                    return token;
                } else if (c == '=') {
                    token->stringToken[countChar] = c;
                    state = CMP;
                } else if (c == '<') {
                    token->stringToken[countChar] = c;
                    state = LESS;
                } else if (c == '>') {
                    token->stringToken[countChar] = c;
                    state = GREATHER;
                } else if (c == '!') {
                    token->stringToken[countChar] = c;
                    state = NOT;
                } else if (c == '/') {
                    token->stringToken[countChar] = c;
                    state = DIV_OR_COM;
                } else if ((isalpha(c)) || (c == '_') || (c == '$')) {
                    token->stringToken[countChar] = c;
                    state = IDENTIFY;
                } else if ((isdigit(c))) {
                    token->stringToken[countChar] = c;
                    state = NUMBER;
                } else if (c == '\"') {
                    token->stringToken[countChar] = c;
                    state = MAYBE_STRING;
                }
                break;
            case CMP :
                if (c == '=') {
                    countChar++;
                    token->stringToken[countChar] = c;
                    token->numToken = ROVNASA2;
                    return token;
                } else {
                    ungetc(c, sourceFile);
                    token->numToken = ROVNA_SA;
                    return token;
                }
            case LESS :
                if (c == '=') {
                    countChar++;
                    token->stringToken[countChar] = c;
                    token->numToken = MENSITKO_ROVNASA;
                    return token;
                } else {
                    ungetc(c, sourceFile);
                    token->numToken = MENSITKO;
                    return token;
                }
            case GREATHER :
                if (c == '=') {
                    countChar++;
                    token->stringToken[countChar] = c;
                    token->numToken = VACSITKO_ROVNASA;
                    return token;
                } else {
                    ungetc(c, sourceFile);
                    token->numToken = VACSITKO;
                    return token;
                }
            case NOT :
                if (c == '=') {
                    countChar++;
                    token->stringToken[countChar] = c;
                    token->numToken = NEROVNASA;
                    return token;
                } else {
                    printErrors(LEX_CHYBA);
                    // TODO garbage collector + exit value? -> deleteHtable(htable);
                    // a zatial daj aj do exit parametru LEX_CHYBA
                    exit(LEX_CHYBA);
                }
            case DIV_OR_COM : if (c!= '/' && c!= '*'){
                    ungetc(c,sourceFile);
                    token->numToken=DELENO;
                    return token;
                }
                else if (c == '/') {
                    c=getc(sourceFile);
                    while(c != '\n' && c!= EOF ){
                        c=getc(sourceFile);
                    }
                    if (c==EOF) state=END;
                    else state = START;

                }

        }
    }


}
