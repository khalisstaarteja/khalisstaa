#include<stdio.h>

// PROGRAM TEMPARTUR
double CONVERT(double N, char CHAR);

int main(){
    double N, HASIL;
    char CHAR;

    printf("Input angka: ");
    scanf("%lf", &N);
    printf("Input temperatur(C/F): ");
    scanf(" %c", &CHAR);

    HASIL = CONVERT(N, CHAR);

    if(CHAR =='C') printf("%.2lf %c = %.2lf F", N, CHAR, HASIL);
    else if(CHAR =='F') printf("%.2lf %c = %.2lf C", N, CHAR, HASIL);
}

double CONVERT(double N, char CHAR){
    double R;

    if(CHAR =='C') R = (N * 1.8) + 32;
    else if(CHAR =='F') R = (N - 32) / 1.8;

    return R;
}