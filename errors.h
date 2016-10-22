//
// Created by chronos on 10/13/16.
//

#ifndef IFJ_88_ERRORS_H
#define IFJ_88_ERRORS_H

#define LEX_ERROR 1
#define SYN_ERROR 2
#define SEM_DEFINITION_ERROR 3
#define SEM_TYPE_COMPATIBILITY_ERROR 4
#define SEM_OTHER_ERROR 6
#define RUN_LOADING_ERROR 7
#define RUN_NOT_INITIALIZED_ERROR 8
#define RUN_DIVIDE_BY_ZERO_ERROR 9
#define RUN_OTHER_ERROR 10
#define INTERNAL_ERROR 99

int printErrors(int error);

#endif //IFJ_88_ERRORS_H

/*koniec hlavickoveho suboru*/