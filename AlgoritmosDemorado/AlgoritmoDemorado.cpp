#include <stdio.h>
#include <time.h>

int algoritmoDemorado(int n);

int main(){
    clock_t t1, soma = 0;

    // t2 = clock();
    // algoritmoDemorado(200);
    // t2 = clock() - t2;
    // printf("Tempo: %f\n", (float)t2/CLOCKS_PER_SEC);

    // t3 = clock();
    // algoritmoDemorado(1000);
    // t3 = clock() - t3;
    // printf("Tempo: %f\n", (float)t1/CLOCKS_PER_SEC);

    for (int i = 0; i < 10; i++){
        t1 = clock();
        algoritmoDemorado(200);
        t1 = clock() - t1;

        soma += t1;
    }
    
    printf("Tempo: %f\n", ((float)soma/10)/CLOCKS_PER_SEC);

    return 0;
}

int algoritmoDemorado(int n){
    long int soma = 0;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                for(int l = 0; l < n; l++){
                    soma = i + j + k + l;                
                }
            }
        }
    }
    
    return soma;
}