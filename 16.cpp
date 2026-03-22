#include <stdio.h>

//MODUS
void MOD(int *num, int n, int *result);

int main(){
    int n, result;
    printf("Input n = ");
    scanf("%d", &n);

    int num[n];

    for(int i = 0; i < n; i++){
        printf("Num(%d) = ", i + 1);
        scanf("%d", &num[i]);
    }

    MOD(num, n, &result);

    printf("MOD = %d", result);
}

void MOD(int *num, int n, int *result){
    int countMax = 0;
    int count;

    for(int i = 0; i < n; i++){
        count = 0;
        for(int j = 0; j < n; j++){
            if(*(num + i) == *(num + j)) count++;
        }
        if(count > countMax){
            countMax = count; 
            *result = *(num + i);
        } 
    }
    if(countMax == 1){
        *result = -1;
    }
}