#include <stdio.h>

// MERGE ARRAY

void MERGE(int *a, int *b, int size_a, int size_b, int *merge_arr, int size_total);
int main(){
    int size_a = 2;
    int size_b = 3;

    int array_a [size_a]= {1, 2};
    int array_b [size_b] = {3, 4, 5};

    int size_total = size_a + size_b;
    int merge_arr[size_total];

    MERGE(array_a, array_b, size_a, size_b, merge_arr, size_total);
    
    printf("Array A = ");
    for(int i = 0; i < size_a; i++){
        printf("%d ", array_a[i]);
    }
    printf("\n");

    printf("Array B = ");
    for(int i = 0; i < size_b; i++){
        printf("%d ", array_b[i]);
    }
    printf("\n");

    printf("Merge = ");
    for(int i = 0; i < size_total; i++){
        printf("%d ", merge_arr[i]);
    }
    return 0;
}

void MERGE(int *a, int *b, int size_a, int size_b, int *merge_arr, int size_total){
    for(int i = 0; i < size_total; i++){
        if(i >= size_a) *(merge_arr + i) = *(b +(i - size_a));
        else *(merge_arr + i) = *(a + i);
    }
}