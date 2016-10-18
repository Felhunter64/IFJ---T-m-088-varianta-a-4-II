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
#include "vyrazy.h"
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



    processExp();


//printf("%s\n",getNextToken()->stringToken);
//printf("%d\n",getNextToken()->numToken);
  //getNextToken();
  // getNextToken();


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
                    token->stringToken[++countChar] = '\0';
                    token->numToken = PLUS;

                    return token;

                } else if (c == EOF) {

                    token->numToken = END;

                    return token;

                } else if (c == '-') {
                    token->stringToken[countChar] = c;
                    token->stringToken[++countChar] = '\0';
                    token->numToken = MINUS;
                    return token;
                } else if (c == '*') {
                    token->stringToken[countChar] = c;
                    token->stringToken[++countChar] = '\0';
                    token->numToken = MULTIPLY;
                    return token;
                } else if (c == '(') {
                    token->stringToken[countChar] = c;
                    token->stringToken[++countChar] = '\0';
                    token->numToken = L_BRACKET;
                    return token;
                } else if (c == ')') {
                    token->stringToken[countChar] = c;
                    token->stringToken[++countChar] = '\0';
                    token->numToken = R_BRACKET;
                    return token;
                } else if (c == '{') {
                    token->stringToken[countChar] = c;
                    token->stringToken[++countChar] = '\0';
                    token->numToken = L_PI_BRACKET;
                    return token;
                } else if (c == '}') {
                    token->stringToken[countChar] = c;
                    token->stringToken[++countChar] = '\0';
                    token->numToken = R_PI_BRACKET;
                    return token;
                } else if (c == ',') {
                    token->stringToken[countChar] = c;
                    token->stringToken[++countChar] = '\0';
                    token->numToken = COMMA;
                    return token;
                } else if (c == ';') {
                    token->stringToken[countChar] = c;
                    token->stringToken[++countChar] = '\0';
                    token->numToken = DOT_COMMA;
                    return token;
                } else if (c == '=') {
                    token->stringToken[countChar] = c;
                    state = CMP;
                } else if (c == '<') {
                    token->stringToken[countChar] = c;
                    state = LESS_STATE;
                } else if (c == '>') {
                    token->stringToken[countChar] = c;
                    state = GREATER_STATE;
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
                    token->stringToken[++countChar] = '\0';
                    token->numToken = EQUAL;
                    return token;
                } else {
                    ungetc(c, sourceFile);
                    token->numToken = ASSIGN;
                    return token;
                }
                break;
            case LESS_STATE :
                if (c == '=') {
                    countChar++;
                    token->stringToken[countChar] = c;
                    token->stringToken[++countChar] = '\0';
                    token->numToken = LESS_EQUAL;
                    return token;
                } else {
                    ungetc(c, sourceFile);
                    token->numToken = LESS;
                    return token;
                }
                break;
            case GREATER_STATE :
                if (c == '=') {
                    countChar++;
                    token->stringToken[countChar] = c;
                    token->stringToken[++countChar] = '\0';
                    token->numToken = GREATER_EQUAL;
                    return token;
                } else {
                    ungetc(c, sourceFile);
                    token->numToken = GREATER;
                    return token;
                }
                break;
            case NOT :
                if (c == '=') {
                    countChar++;
                    token->stringToken[countChar] = c;
                    token->stringToken[++countChar] = '\0';
                    token->numToken = NOT_EQUAL;
                    return token;
                } else {
                    printErrors(LEX_CHYBA);
                    xFree(token,htable);
                    xFree(token->stringToken,htable);
                    exit(LEX_CHYBA);
                }
                break;
            case DIV_OR_COM :
               if (c!='*' && c!= '/'){
                   ungetc(c,sourceFile);
                   token->numToken=DIVINE;
                   return token;
               } else if (c== '*') state=MULTI_LINE_COMMENT;
                 else if (c== '/') state=LINE_COMMENT;
                break;
            case LINE_COMMENT :
                while(c != '\n' && c!= EOF ){
                    c=getc(sourceFile);
                } if (c==EOF) state=END;
                  else state = START;
                break;
            case MULTI_LINE_COMMENT :
                while(c != '*' && c!= EOF ) {
                    c = getc(sourceFile);
                } if (c==EOF) state=END;
                  else state =END_COMMENT;
                break;
            case END_COMMENT :
                if (c == '/') state = START;
                else state=MULTI_LINE_COMMENT;
            break;



        }
    }


}
