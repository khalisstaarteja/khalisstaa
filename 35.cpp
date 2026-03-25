#include <stdio.h>

// COUNT EACH NUMBER FREQ
void CHECK(int *array, int n);

int main(){
    int n;
    printf("Input n = ");
    scanf("%d", &n);

    int array[n];
    for(int i = 0; i < n; i++){
        printf("Num (%d) = ", i + 1);
        scanf("%d", &array[i]);
    }

    CHECK(array, n);

    return 0;
}

void CHECK(int *array, int n){
    int count;
    for(int i = 0; i < n; i++){
        count = 1;
        for(int j = 0; j < n; j++){
            if(i != j){
                if(*(array + i) == *(array + j)&& *(array + j) != NULL){
                    count++;
                    *(array + j) = -1;
                } 
            }
        }
        if(*(array + i) != -1) printf("%d muncul sebanyak %d kali\n", *(array + i), count);
    }
}
