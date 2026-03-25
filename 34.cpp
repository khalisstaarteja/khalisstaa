#include <stdio.h>

// CEK NILAI
int CHECK(int num, int *array, int n);

int main(){
    int num, d;
    int n = 5;
    int array[n] = {1, 2, 3, 4, 5};

    printf("Input angka = ");
    scanf("%d", &num);

    d = CHECK(num, array, n);

    printf("%d", num);
    if(d == 0) printf(" tidak ada dalam daftar array.\n");
    else printf(" ada dalam daftar array.\n");

    return 0;
}

int CHECK(int num, int *array, int n){
    int r = 0;
    for(int i = 0; i < n; i++){
        if(num == *(array + i)){
            r = 1;
            break;
        } 
    }
    return r;
}
