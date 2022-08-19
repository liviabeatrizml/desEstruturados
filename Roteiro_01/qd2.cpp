#include <stdio.h>
#include <stdlib.h>

#define numLin 6
#define numCol 6

int **alocaMatriz(int numLinha, int numColuna);
void limpaMatriz(int ** Matriz, int numLinha);
void mostrarMatriz(int ** mat, int linha, int coluna);
void movimentar(int ** mat,  int linAtual, int colAtual, int linDestino, int colDestino);

int main () {
    int ** mat;
    int L, C, linInicio, colInicio, linChegada, colChegada, area;
    size_t i , j;

    mat = alocaMatriz(numLin, numCol);    

    for (i = 0; i < numLin; i ++){
        for (j = 0; j < numCol; j ++){
            if((j == 1 && (i < 2 || i > 2)) || (j == 2 && ((i < 2 || (i > 2 && i < 5)))) || (j == 4 && (i < 3 || i > 3))){
                mat[i][j] = 1;
            } else {
                mat[i][j] = 0;
            }
        }
    }

    printf("\n - Defina o ponto de inicio.\n\tLinha: ");
    scanf("%d", &linInicio);
    printf("\tColuna: ");
    scanf("%d", &colInicio);

    printf("\n - Defina o ponto de chegada.\n\tLinha: ");
    scanf("%d", &linChegada);
    printf("\tColuna: ");
    scanf("%d", &colChegada);

    movimentar(mat, linInicio-1, colInicio-1, linChegada-1, colChegada-1);

    limpaMatriz(mat, numLin);
}

int **alocaMatriz(int numLinha, int numColuna){
    int ** mat;

    mat = (int **) malloc(numLinha * sizeof(int *));
    mat[0] = (int *) malloc(6 * 6 * sizeof (int ));

    for (size_t i = 1; i < numColuna; i ++){
        mat[i] = mat[0] + i * 6;
    }

    return mat;
}

void limpaMatriz(int ** Matriz, int numLinha){
    for(size_t i = 0; i < numLinha; i++)
        free(Matriz[i]);
    free(Matriz);
}

void movimentar(int ** mat, int linAtual, int colAtual, int linDestino, int colDestino){
    if(linAtual == linDestino && colAtual == colDestino){
        mostrarMatriz(mat, linAtual, colAtual);
        printf("\n!!! VOCE CHEGOU AO SEU DESTINO !!!\n");

        return;
    }

    if((mat[linAtual][colAtual] == 1) || (linAtual < 0 || linAtual > 5) || (colAtual < 0 || colAtual > 5))
        return movimentar(mat, linAtual+1, colAtual-1, linDestino, colDestino);
        
    mostrarMatriz(mat, linAtual, colAtual);
    return movimentar(mat, linAtual, colAtual+1, linDestino, colDestino);
}

void mostrarMatriz(int ** mat, int lin, int col){
    size_t i , j;

    printf("\n");

    for (i = 0; i < 6; i ++){
        printf("\t");
        for (j = 0; j < 6; j ++){
            if(i == lin && j == col){
                printf("X ");
            } else if(i == 5 && j == 5){
                printf("Y ");
            } else {
                printf("%d ", mat[i][j]);
            }
            

        }
        printf("\n");
    }

    printf("\n");
}