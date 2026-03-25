#include <stdio.h>

//KECEPATAN
float CALCULATE(float s, float v);

int main(){
    float s, v, t;

    printf("Input jarak (s) = ");
    scanf("%f", &s);

    printf("Input kecepatan (v) = ");
    scanf("%f", &v);

    t = CALCULATE(s, v);

    printf("Waktu tempuh = %.2f", t);

    return 0;
}

float CALCULATE(float s, float v){
    return s/v;
}