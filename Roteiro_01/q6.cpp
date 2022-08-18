#include <stdio.h>
#include <stdlib.h>

 //função que utiliza um vetor de inteiros e retorna recursivamente esse mesmo vetor com os valores invertidos

void imprimir(int v[], int tam){ // função pra imprimir
    if(tam == 1)
        printf("%d\t", v[tam - 1]);
    else{
        imprimir(v, tam - 1);
        printf("%d\t", v[tam - 1]);
    }
}

void inverter(int v[], int i, int f){ // função para inverter os valores
    int aux; //variável auxiliar para troca
    if(i < f){
        aux = v[i];
        v[i] = v[f];
        v[f] = aux;
        inverter(v, i + 1, f - 1);
    }
}

int main () {

    int vet[10] = {1,2,3,4,5,6,7,8,9,10}; //vetor com 10 elemento

    imprimir(vet, 10);  // vetor e tamanho, imprimido normalmente.
    inverter(vet, 0, 9); // vetor, inicio e fim, função de inversão
    printf("\n");
    imprimir(vet, 10); // vetor e tamanho, imprimido após a inversão

    return 0;
}