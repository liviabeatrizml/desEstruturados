#include <stdio.h>
#include <stdlib.h>

int **alocaMatriz(int numLinha, int numColuna);
void mostrarMatriz(int ** mat, int linha, int coluna);
void limpaMatriz(int ** Matriz, int numLinha);
int calcularArea(int ** mat, int linInicial, int colInicial, int linha, int coluna);

int main () {
    int ** mat;
    int L, C, area;

    printf("Determine o tamanho do quadrado.\n\tLinha - ");
    scanf("%d", &L);
    printf("\tColuna - ");
    scanf("%d", &C);
    printf("\n");

    mat = alocaMatriz(L, C);

    for (size_t i = 0; i < L; i ++){
        for (size_t j = 0; j < C; j ++){
            if((i == 0 && j == 1) || (i <= 4 && j == 2) || (j == 3 && i > 3) || (i == 5 && j == 4)){
                mat[i][j] = 1;
            } else {
                mat[i][j] = 0;
            }
        }
    }

    printf("\nEm que ponto vai comecar a contagem?\n\tLinha: ");
    scanf("%d", &L);
    printf("\tColuna: ");
    scanf("%d", &C);

    mostrarMatriz(mat, L-1, C-1);
    area = calcularArea(mat, L-1, C-1, L-1, C-1);

    printf("A tamanho da area em branco a partir do ponto (%d , %d) eh de %d quadrados!\n", L-1, C-1, area);

    limpaMatriz(mat, 6);
}

int calcularArea(int ** mat, int linInicial, int colInicial, int linhaAtual, int colunaAtual){
    if((linhaAtual < 0 || linhaAtual > 5) || (colunaAtual < 0 || colunaAtual > 5))
        return 0;

    if(colInicial == 0){
        if(linInicial == 0){
            if (mat[linhaAtual][colunaAtual] == 1){
                return calcularArea(mat, linInicial, colInicial, linhaAtual+1, colInicial);
            } else {
                mostrarMatriz(mat, linhaAtual, colunaAtual);
                return 1 + calcularArea(mat, linInicial, colInicial, linhaAtual, colunaAtual+1);
            }
        } else if(linInicial == 5){
            if (mat[linhaAtual][colunaAtual] == 1){
                return calcularArea(mat, linInicial, colInicial, linhaAtual-1, colInicial);
            } else {
                mostrarMatriz(mat, linhaAtual, colunaAtual);
                return 1 + calcularArea(mat, linInicial, colInicial, linhaAtual, colunaAtual+1);
            }
        }
    } else if(colInicial == 5){
        if(linInicial == 0){
            if (mat[linhaAtual][colunaAtual] == 1){
                return calcularArea(mat, linInicial, colInicial, linhaAtual+1, colInicial);
            } else {
                mostrarMatriz(mat, linhaAtual, colunaAtual);
                return 1 + calcularArea(mat, linInicial, colInicial, linhaAtual, colunaAtual-1);
            }
        } else if(linInicial == 5){
            if (mat[linhaAtual][colunaAtual] == 1){
                return calcularArea(mat, linInicial, colInicial, linhaAtual-1, colInicial);
            } else {
                mostrarMatriz(mat, linhaAtual, colunaAtual);
                return 1 + calcularArea(mat, linInicial, colInicial, linhaAtual, colunaAtual-1);
            }
        }
    }
}

int **alocaMatriz(int numLinha, int numColuna){
    int ** mat;

    mat = (int **) malloc(numLinha * sizeof(int *));
    mat[0] = (int *) malloc(numLinha * numColuna * sizeof (int ));

    for (size_t i = 1; i < numColuna; i ++){
        mat[i] = mat[0] + i * numLinha;
    }

    return mat;
}

void limpaMatriz(int ** Matriz, int numLinha){
    for(size_t i = 0; i < numLinha; i++)
        free(Matriz[i]);

    free(Matriz);
}
    
void mostrarMatriz(int ** mat, int lin, int col){
    printf("\n");

    for (size_t i = 0; i < 6; i ++){
        printf("\t");
        for (size_t j = 0; j < 6; j ++){
            if(i == lin && j == col){
                printf("X ");
            } else {
                printf("%d ", mat[i][j]);
            }
            
        }
        printf("\n");
    }

    printf("\n");
}
 


