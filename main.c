#include "head.h"

int main(int C, char **V){
    if (C==1){
        printf("lab 2 by Ghost\nuse -h to help!\n");
        return 0;
    }
    if (C==2){
        if (!strcmp(V[1],"-h")){
            helpMenu();
            return 0;
        }
        if (!strcmp(V[1],"-s")){
            work();
            return 0;
        }
    }
    printf("unknown parameters!\nuse -h to help!\n");
    return 1;
}