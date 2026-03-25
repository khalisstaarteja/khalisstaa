#include <stdio.h>

//GANJIL GENAP
void CHECK(int *array, int n);

int main(){
    int n;

    printf("Input n = ");
    scanf("%d", &n);

    int array[n];

    for(int i = 0; i < n; i++){
        printf("Num[%d] = ", i+1);
        scanf("%d", &array[i]);
    }
    
    CHECK(array, n);
}

void CHECK(int *array, int n){
    int *ptr = array;   
    for(int i = 0; i < n; i++){
        if(*ptr % 2 == 0) printf("%d adalah angka genap\n", *ptr);
        else printf("%d adalah angka ganjil\n", *ptr);
        ptr++;
    }
}