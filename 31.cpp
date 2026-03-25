#include <stdio.h>
#include <math.h>

// PERHITUNGAN JARAK
void INPUT(float *x1, float *x2, float *y1, float *y2);
float CALCULATE(float x1, float x2, float y1, float y2);

int main(){
    float x1, x2, y1, y2;
    float d;

    INPUT(&x1, &x2, &y1, &y2);
    d = CALCULATE(x1, x2, y1, y2);

    printf("Jarak = %.2f", d);

    return 0;
}

void INPUT(float *x1, float *x2, float *y1, float *y2){
    printf("Input x1 = ");
    scanf("%f", x1);
    printf("Input x2 = ");
    scanf("%f", x2);
    printf("Input y1 = ");
    scanf("%f", y1);
    printf("Input y2 = ");
    scanf("%f", y2);
}

float CALCULATE(float x1, float x2, float y1, float y2){
    float r = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    return r;
}