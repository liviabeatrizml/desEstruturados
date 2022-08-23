#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *palindromoVerify(const char* string, int begin, int end);

int main(){
    const char* string = "ria so tive sorte ma a metros evito sair.";
    int begin, end;

    begin = 0;
    end = strlen(string);

    palindromoVerify(string, begin, end);

    return 0;
}

void *palindromoVerify(const char* string, int begin, int end){
    if(string[begin] == 32 || string[begin] == 44 || string[begin] == 46){
        return palindromoVerify(string, begin+1, end);
    }
    
    if(string[end-1] == 32 || string[end-1] == 44 || string[end-1] == 46){
        return palindromoVerify(string, begin, end-1);
    }

    if (string[begin] != string[end-1]){
        printf("Nao eh palindromo!!!\n");
        return 0;
    } else if(end == 0){
        printf("Eh palindromo!!!\n");
        return 0;
    }

    return palindromoVerify(string, begin+1, end-1);
}