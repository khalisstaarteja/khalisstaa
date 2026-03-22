#include <stdio.h>

// PRIMA
int PRIMA(int X);

int main(){
    int N, X, prima;

    printf("Input angka: ");
    scanf("%d", &N);

    for(X = 1; X <= N; X++){
        prima = PRIMA(X);
        if(prima == 1) printf("%d adalah bilangan prima\n", X);
        else printf("%d bukan bilangan prima\n", X);
    }
}

int PRIMA(int X){
    int prima;
    if(X < 2){
        prima = 0;
    }
    else{
        prima = 1;
        for(int i = 2; i < X; i++){ 
            if(X % i == 0){
                prima = 0;
                break;
            }
        }
    }
    return prima;
}