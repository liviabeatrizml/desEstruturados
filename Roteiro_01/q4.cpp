#include <stdio.h>

float funcaoBinomial(int k,int n);

int main(){
    int n = 5, k = 2;
    
    printf("(%d/%d): %.1f\n", n, k, funcaoBinomial(n, k));

    return 1;
}

float funcaoBinomial(int n, int k){
    if (k > n){
        return 0;
    } else if(k == 0 || k == n){
        return 1;
    }

    return funcaoBinomial(n-1, k-1) + funcaoBinomial(n-1, k);
}

