#include <stdlib.h>
#include <stdio.h>
#include <time.h>

float media(float *res, int tam);

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

float media(float *res, int tam)
{
    if (tam == 1)
    {
        return res[0];
    }
    else
    {
        return (res[tam - 1] + (tam - 1) * media(res, tam - 1)) / tam;
    }
}

int main()
{
    printf(" Sequencia ␣ aleatoria \n");
    size_t n = 10; // 10³, 10⁶, 10⁹
    float *res = gerador(n);

    for (size_t i = 0; i < n; i++)
    {
        printf("res [% lu ]=% f\n", i, res[i]);
    }

    printf("Média = %.2f\n", (media(res, n)));
}
