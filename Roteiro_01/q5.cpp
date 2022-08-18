#include <stdio.h>

int contFib(int n, int k);
int contador = 0;

int main() {

  int n, k, resultado;
  
  do {
    printf("\n\n--> Escolha uma posicao do Fibonacci: ");
    scanf("%d", &n);

    printf("--> Escolha um numero para ver suas repeticoes: ");
    scanf("%d", &k);

    if(k > n) {
      printf("\nERROR: O numero da posicao tem que ser maior que o valor da repeticao!\n");
      printf("                        Tente novamente!\n");
    }

  } while(k > n);

  resultado = contFib(n, k);

  printf("\n*** O numero %i se repete %d vezes dentro do fib(%i) ***\n\n", k, resultado, n);

}

int contFib(int n, int k) {
  int i, fibonacci = 0;

  if(n == k) {
    contador = contador + 1;
  }

  if(n == 1 || n == 2) {
    return 1;
  }

  fibonacci =  contFib(n-1, k) + contFib(n-2, k); 

  return contador;
}

// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181...
