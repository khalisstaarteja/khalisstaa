#include<stdio.h>

// REMOVE DUPLICATE
void RMV(int *array, int n);
void OUTPUT(int *array, int n);

int main(){
    int n;
    printf("Input n = ");
    scanf("%d", &n);

    int array[n];

    for(int i = 0; i < n; i++){
        printf("Array(%d) = ", i + 1);
        scanf("%d", &array[i]);
    }

    RMV(array, n);
    OUTPUT(array, n);
}

void RMV(int *array, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                if(*(array + i) == *(array + j) && *(array + j) != NULL) *(array + j ) = NULL;
            }
        }
    }
}

void OUTPUT(int *array, int n){
    printf("Remove duplicate done = ");
    for(int i = 0; i < n; i++){
        if(*(array + i) != NULL) printf("%d ", *(array + i));
    }
}