#include <stdio.h>
#include <math.h>

double X, N;
double F();

int main(){
    double HASIL;
    HASIL = F();
    printf("Hasil perhitungan adalah = %.4lf", HASIL);
}

double F(){
    double R;
    printf("Input X: ");
    scanf("%lf", &X);
    printf("Input N: ");
    scanf("%lf", &N);

    R = 1 / (pow(X, N) * (exp(1.432)/X) - 1);
    return R;
}