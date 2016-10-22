//
// Created by chronos on 10/13/16.
//

#ifndef IFJ_88_ERRORS_H
#define IFJ_88_ERRORS_H

#define LEX_ERROR 1
#define SYN_ERROR 2
#define SEM_DEFINICIA_ERROR 3
#define SEM_TYPOVA_KOMPATIBILITA_ERROR 4
#define SEM_INA_ERROR 6
#define RUN_NACITANIE_ERROR 7
#define RUN_NEINICIALIZOVANIE_ERROR 8
#define RUN_DELENIE_NULOU_ERROR 9
#define RUN_INA_ERROR 10
#define INTERNA_ERROR 99

int printErrors(int error);

#endif //IFJ_88_ERRORS_H

/*koniec hlavickoveho suboru*/