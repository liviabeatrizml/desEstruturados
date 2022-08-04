#include <stdio.h>
#include<time.h>


	int alg(int n){
	int soma=0;
	int i,j,k,l;
	
	for( i=0; i<n; i++){
         for(j=0; j<n;j++){
			for(k=0; k<n; k++){
		       for( l=0; l<n;l++){
		       	soma= i+j+k+l;
			
		}
	}
}
	}
	return soma;
	}
	
	int main(){
        clock_t t1,soma=0;
        int x=10,i;
       
        for( i=0; i<x; i++){
t1 = clock();
		alg(100);
        t1 = clock()-t1;
        soma +=t1; 
          }
		printf("time: %f\n",(float)t1/CLOCKS_PER_SEC);
	}