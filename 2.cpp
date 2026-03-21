#include <stdio.h>

// PROGRAM DIVIDE ARRAY
void SIZE(int *size1, int *size2, int n);
void DIVIDE(int *arr, int n, int *arr1, int *arr2, int size1, int size2);
void OUTPUT(int *arr1, int *arr2, int size1, int size2);

int main(){
    int n, size1, size2;

    n = 5;

    int arr[n] = {1, 2, 3, 4, 5};

    SIZE(&size1, &size2, n);

    int arr1[size1];
    int arr2[size2];
        
    DIVIDE(arr, n, arr1, arr2, size1, size2);
    OUTPUT(arr1, arr2, size1, size2);
}

void SIZE(int *size1, int *size2, int n){
    *size1 = n / 2; 
    *size2 = n - *size1;
}

void DIVIDE(int *arr, int n, int *arr1, int *arr2, int size1, int size2){
    for(int i = 0; i < size1; i++){
        *(arr1 + i) = *(arr + i);
    }

    for(int i = size1; i < n; i++){
        *(arr2 + i - size1) = *(arr + i);
    }
}

void OUTPUT(int *arr1, int *arr2, int size1, int size2){
    printf("Array 1 = ");
    for(int i = 0; i < size1; i++){
        printf("%d ", *(arr1 + i));
    }
    printf("\n");
        
    printf("Array 2 = ");
    for(int i = 0; i < size2; i++){
        printf("%d ", *(arr2 + i));
    }
    printf("\n");
}