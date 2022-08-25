#include <stdlib.h>
#include <stdio.h>
#include <time.h>

float mediaR(float *res, int tam);
float mediaI(float *vet, int tam);

float *gerador(size_t n)
{
    srand(time(NULL));
    float *res = (float *)malloc(n * sizeof(int));

    for (size_t i = 0; i < n; i++)
    {
        res[i] = rand() % 1000;
    }

    return res;
}

float mediaR(float *res, int tam)
{
    if (tam == 1)
    {
        return res[0];
    }
    else
    {
        return (res[tam - 1] + (tam - 1) * mediaR(res, tam - 1)) / tam;
    }
}

float mediaI(float *vet, int tam)
{
    int soma = 0;
    for (int i = 0; i < tam; i++)
    {
        soma += vet[i];
    }
    return soma / tam;
}

int main()
{
    printf(" Sequencia aleatoria \n");
    size_t n = 1000; // 10³, 10⁶, 10⁹
    float *res = gerador(n);
    float *vet = gerador(n);

    for (size_t i = 0; i < n; i++)
    {
        printf("res [% lu ]=% f\n", i, res[i]);
        // printf("vet [% lu ]=% f\n", i, vet[i]);
    }

    printf("Media interativa = %.2f\n", (mediaI(vet, n)));
    printf("Media recursiva = %.2f\n", (mediaR(res, n)));
}
