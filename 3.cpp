#include <stdio.h>

// PROGRAM COPY ARRAY
void SIZE(int *size_lama, int *size_baru, int n);
void COPY(int *arrayA, int size_lama, int size_baru, int *gandaArr);
void OUTPUT(int *arrayA, int size_lama, int size_baru, int *gandaArr);

int main(){
    int n, size_lama, size_baru;

    n = 4;
    int arrayA[n] = {1, 2, 3, 4};
    
    SIZE(&size_lama, &size_baru, n);
    int gandaArr[size_baru];

    COPY(arrayA, size_lama, size_baru, gandaArr);
    OUTPUT(arrayA, size_lama, size_baru, gandaArr);
   
    return 0;
}

void SIZE(int *size_lama, int *size_baru, int n){
    *size_lama = n;
    *size_baru = n * 2;
}

void OUTPUT(int *arrayA, int size_lama, int size_baru, int *gandaArr){
     printf("Array lama = ");
    for(int i = 0; i < size_lama; i++){
        printf("%d ", *(arrayA + i));
    }

    printf("\n");

    printf("Array baru = ");
    for(int i = 0; i < size_baru; i++){
        printf("%d ", *(gandaArr + i));
    }
}

void COPY(int *arrayA, int size_lama, int size_baru, int *gandaArr){
    for(int i = 0; i < size_baru; i++){
        if(i >= size_lama) *(gandaArr + i) = 0;
        else *(gandaArr + i) = *(arrayA + i);
    }
}