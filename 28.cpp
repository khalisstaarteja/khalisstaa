#include <stdio.h>

//PROGRAM DISKRIMINAN
double DISKRIMINAN(double A, double B, double C);

int main(){
    double X, Y, Z, HASIL;

    printf("Input A: ");
    scanf("%lf", &X);

    printf("Input B: ");
    scanf("%lf", &Y);

    printf("Input C: ");
    scanf("%lf", &Z);

    HASIL = DISKRIMINAN(X, Y, Z);

    printf("Hasil diskriminan = %.2lf", HASIL);
}

double DISKRIMINAN(double A, double B, double C){
    double D;
    D = B*B - (4*A*C);
    return D;
}