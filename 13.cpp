#include <stdio.h>

// REVERSE W SAME ARRAY
void REVERSE(int *a, int *b);

int main(){
    int n = 5;
    int num[n] = {1, 2, 3, 4, 5};

    printf("Before = ");
    for(int i = 0; i < n; i++){
        printf("%d ", num[i]);
    }
    printf("\n");


    for(int i = 0; i < n/2; i++){
        REVERSE(&num[i], &num[n-i-1]);
    }

    printf("After = ");
    for(int i = 0; i < n; i++){
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}

void REVERSE(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}