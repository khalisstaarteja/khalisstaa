#include <stdio.h>

// FIBONACCI 
void FIBONACCI(int *a, int *b, int n, int *arr);

int main(){
    int a, b, n, temp;
    a = 0;
    b = 1;
    
    printf("How many numbers? = ");
    scanf("%d", &n);

    int arr[n];

    FIBONACCI(&a, &b, n, arr);

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

void FIBONACCI(int *a, int *b, int n, int *arr){
    int temp;

    arr[0] = *a;
    arr[1] = *b;
    
    for(int i = 2; i < n; i++){
        temp = *a;
        *a = *b;
        *b = *b + temp;
        *(arr + i) = *b;
    }
}