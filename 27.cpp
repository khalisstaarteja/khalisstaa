#include <stdio.h>
#include <math.h>

// PROGRAM CICILAN
double CICILAN(double R, double A, int N, int Y);

int main(){
    double R, A, HASIL;
    int N, Y;

    N = 0;

    while(N < 1 || N > 12){
        printf("Input bunga: ");
        scanf("%lf", &R);
        printf("Input rupiah: ");
        scanf("%lf", &A);
        printf("Berapa kali pembayaran per tahun: ");
        scanf("%d", &N);
        printf("Berapa tahun: ");
        scanf("%d", &Y);
    }
    HASIL = CICILAN(R, A, N, Y);

    printf("Besar cicilan = Rp. %.0lf", HASIL);
}

double CICILAN(double R, double A, int N, int Y){
    double C;

    C = (R * (A/N)) / (1-(pow(1+(R/N), -N*Y)));

    return C;
}