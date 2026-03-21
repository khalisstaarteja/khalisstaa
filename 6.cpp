#include <stdio.h>

//PROGRAM FACTORIAL
int fact(int n);

int main(){
    int n; 

    printf("Input n: ");
    scanf("%d", &n);

    printf("Hasil faktorial = %d", fact(n));
}

int fact(int n){
    int fact;
    int count = n - 1;

    for(int i = count; i >= 1; i--){
        fact = n * i;
        n = fact;
    }
    return(fact);
}