#include <stdio.h>
#include <stdlib.h>

int fat(int num);
int fatorialComCauda(int num);
int fatorialSemCauda(int num);

int main(){
    int fatorial;
    fatorial = 5;

    printf("Fatorial com Cauda de %d e igual a %d.\n", fatorial, fatorialComCauda(fatorial));
    printf("Fatorial Sem Cauda de %d e igual a %d.\n", fatorial, fatorialSemCauda(fatorial));

    return 0;
}

int fat(int num){
    if(num == 0){
        return 0;
    } else if(num == 1){
        return 1;
    }

    return num * fat(num-1);
}

int fatorialComCauda(int num){
    return fat(num);
}

int fatorialSemCauda(int num){
    int i = 1;

    for(i = 1; num > 1; num--){
        i = i * num;
    }

    return i;
}