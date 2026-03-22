#include <stdio.h>

// REVERSE WITH NEW ARRAY
void REVERSE(int *num, int n, int *revArr);

int main(){
    int n = 4;
    int num[n];
    int revArr[n];

    for(int i = 0; i < n; i++){
        printf("Num (%d) = ", i+1);
        scanf("%d", &num[i]);
    }

    REVERSE(num, n, revArr);

    printf("Swap = ");
    for(int i = 0; i < n; i++){
        printf("%d ", revArr[i]);
    }
}

void REVERSE(int *num, int n, int *revArr){
    int x = n - 1;
    for(int i = x; i >= 0; i--){
        *(revArr + (n - i - 1)) = *(num + i);
    }
}

