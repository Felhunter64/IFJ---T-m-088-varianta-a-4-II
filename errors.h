//
// Created by chronos on 10/13/16.
//

#ifndef IFJ_88_ERRORS_H
#define IFJ_88_ERRORS_H

#define LEX_CHYBA 1
#define SYN_CHYBA 2
#define SEM_DEFINICIA_CHYBA 3
#define SEM_TYPOVA_KOMPATIBILITA_CHYBA 4
#define SEM_INA_CHYBA 6
#define RUN_NACITANIE_CHYBA 7
#define RUN_NEINICIALIZOVANIE_CHYBA 8
#define RUN_DELENIE_NULOU_CHYBA 9
#define RUN_INA_CHYBA 10
#define INTERNA_CHYBA 99

int printErrors(int error);

#endif //IFJ_88_ERRORS_H

/*koniec hlavickoveho suboru*/