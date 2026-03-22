#include <stdio.h>

// CONVERT
char HURUF(double N);
double NUM(char C);

int main(){
    double N, X;
    char C;

    printf("Input angka: ");
    scanf("%lf", &N);

    C = HURUF(N);
    X = NUM(C);

    printf("Angka = %.2lf\n", N);
    printf("Nilai Huruf = %c\n", C);
    printf("Nilai Numerik = %.2lf", X);
}

char HURUF(double N){
    char H;

    if(N >= 90.0 && N <= 100) H = 'A';
    else if(N >= 80.0 && N <= 89.9) H = 'B';
    else if(N >= 70.0 && N <= 79.9) H = 'C';
    else if(N >= 60.0 && N <= 69.9) H = 'D';
    else if(N >= 50.0 && N <= 59.9) H = 'E';
    else if(N >= 0.0 && N <= 49.9) H = 'F';

    return H;
}

double NUM(char CHAR){
    double R;

    if(CHAR == 'A') R = 4.0;
    else if(CHAR == 'B') R = 3.0;
    else if(CHAR == 'C') R = 2.0;
    else if(CHAR == 'D') R = 1.0;
    else if(CHAR == 'E') R = 0.0;
    else if(CHAR == 'F') R = 0.0;

    return R;
}