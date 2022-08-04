#include <stdio.h>
#include <time.h>
 
int algoritmoDemorado(int);
 
int main()
{
    // clock do processador
    clock_t t1, soma = 0;
    //serve para calcular a média
    int x = 10;
    //numeros de 0 a 200
    int y = 200;
    for (int i = 0; i < x; i++)
    {
        // clock inicial
        t1 = clock();
        algoritmoDemorado(y);
        // marcação do tempo após o algoritmoDemorado
        t1 = clock() - t1;
        // soma todos os tempos
        soma += t1;
    }
    printf("O tempo foi %f\n", (((float)soma) / x) / CLOCKS_PER_SEC);
}
 
int algoritmoDemorado(int n)
{
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    soma = i + j + k + l;
                }
            }
        }
    }
    return soma;
}
