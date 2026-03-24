#include <stdio.h>
#include <math.h>

double C(double X, double N);


int main(){
    double N, X, HASIL;

    printf("Input N: ");
    scanf("%lf", &N);

    for(double X = -1; X <= 1; X+=0.1){
        HASIL = C(X, N);
        printf("X = %.2lf   Hasil = %.2lf\n", X, HASIL);
    }
}

double C(double X, double N){
    double R;
    if(X >= 0){
        R = X + (pow(X, N)/N) - (pow(X, N+2)) / (N+2);
    }
    else{
        R = -((pow(X, N-1)) / (N-1)) - (pow(X, N+1)) / (N+1);
    }

    return R;
} 