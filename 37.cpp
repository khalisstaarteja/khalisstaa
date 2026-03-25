#include <stdio.h>

float BERAT(float m);

int main(){
    float m;

    printf("Input massa (m) = ");
    scanf("%f", &m);

    printf("Berat = %.2f", BERAT(m));

    return 0;
}

float BERAT(float m){
    return 9.8 * m;
}