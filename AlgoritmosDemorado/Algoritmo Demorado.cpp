#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int algoritmoDemorado(int);

int main(){
    setlocale(LC_ALL, "Portuguese");
    clock_t t1, soma = 0;
    int x = 10;

    for(int i  = 0; i < x; i++) {
        t1 = clock();
        algoritmoDemorado(100);
        t1 = clock() - t1;

        soma += t1;
    }

    printf("\n\nPrimeira soma -> %i\n", algoritmoDemorado(200));
    printf("Tempo -> %f\n\n", (((float)soma)/x)/CLOCKS_PER_SEC);

    //printf("Segunda soma -> %i\n\n", algoritmoDemorado(100));
    //printf("Terceira Soma -> %i\n", algoritmoDemorado(1000));
}

int algoritmoDemorado(int n)
{
    int soma = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                for (int l = 0; l < n; l++){
                    soma = i + j + k + l;
                }
            }
        }
    }

    return soma;
}