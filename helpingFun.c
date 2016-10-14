//
// Created by david on 14.10.16.
//

#include "helpingFun.h"

int lenght(char *string){
    int lenght=0;

    while(string[lenght]!=='\0'){
        lenght++;

    }
    return lenght;
}
void merge_sort(char *string){
    int A=strlen(string);
    int left=A/2;;
    int right=left;
    int x=0,y=0,z=0;
    int L=left,R=right;
    while(x<L && z<R){
        if(L[x]<=R[z]){
            A[y]=L[x];
            x++;
        }
        else{
            A[y]=R[z];
            z++;
        }
        while(x<L){
            A[y]=L[x];
            x++;
            y++;
        }
        while(z<R){
            A[y]=R[z];
            z++;
            y++;
        }
    }



}

int main(){
    char string="sajfkl";
    printf("%d\n",lenght(string);
}