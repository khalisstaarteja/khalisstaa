#include <stdio.h>

// SHIFT 
void SHIFT(int *array, int n);
void OUTPUT(int *array, int n);

int main(){
    int n;

    printf("Input n = ");
    scanf("%d", &n);

    int array[n];

    for(int i = 0; i < n; i++){
        printf("Num(%d) = ", i + 1);
        scanf("%d", &array[i]);
    }

    SHIFT(array, n);
    OUTPUT(array, n);

    return 0;
}

void SHIFT(int *array, int n){
    int temp = *(array + n - 1);
    for(int i = n - 1; i >= 0; i--){
        *(array + i) = *(array + i - 1);
        if(i == 0) *(array + i) = temp;
    }
}

void OUTPUT(int *array, int n){
    int *ptr = array;
    for(int i = 0; i < n; i++){
        printf("%d ", *ptr);
        ptr++;
    }
}