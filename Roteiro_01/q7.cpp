#include <stdio.h>
#include <stdlib.h>

float raizQuadrada(float num, float raiz, float margem);

int main()
{
    float n = 144;

    printf("√%.2f = %.2f.\n", n, raizQuadrada(n, 3.5, 0.001));

    return 0;
}

float raizQuadrada(float num, float raiz, float margem)
{
    int x = (raiz * raiz - num);

    if (x < 0)
    {
        x = -1;
    }
    else
    {
        x = 1;
    }

    if ((((raiz * raiz) - num) * (x)) <= margem)
    {
        return raiz;
    }

    return raizQuadrada(num, (raiz * raiz + num) / (2 * raiz), margem);
}