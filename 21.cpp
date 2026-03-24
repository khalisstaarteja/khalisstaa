#include <stdio.h>

// SERI PARAREL
double SERI(int N, double X[]);
double PARAREL(int N, double X[]);

int main(){
    int N;
    double hasil_seri, hasil_pararel;

    printf("Input banyak data: ");
    scanf("%d", &N);

    double X[N];

    for(int i = 0; i < N; i++){
        printf("Input angka ke-%d: ", i+1);
        scanf("%lf", &X[i]);
    }

    hasil_seri = SERI(N, X);
    hasil_pararel = PARAREL(N, X);

    printf("Seri = %.2lf\n", hasil_seri);
    printf("Pararel = %.2lf\n", hasil_pararel);

    return 0;
}

double SERI(int N, double X[]){
    double total;

    total = 0;

    for(int i = 0; i < N; i++){
        total += X[i];
    }

    return total;
}

double PARAREL(int N, double X[]){
    double total;

    total = 0;

    for(int i = 0; i < N; i++){
        total += 1/X[i];
    }

    return 1/total;
}
