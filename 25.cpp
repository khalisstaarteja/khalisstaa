#include <stdio.h>

// PROGRAM SELINDER
void selinder(double tinggi, double radius, double *luas, double *isi);

int main(){
    double t, r, l, v;

    printf("Masukkan tinggi dan jari-jari selinder: ");
    scanf("%lf %lf", &t, &r);

    selinder(t, r, &l, &v);

    printf("Luas selinder adalah: %.2lf\n", l);
    printf("Isi selinder adalah: %.2lf\n", v);

    return 0;
}

void selinder(double tinggi, double radius, double *luas, double *isi){
    int phi;

    phi = 22/7;

    *luas = 2 * phi * radius * radius + 2 * phi * radius * tinggi;
    *isi = phi * radius * radius * tinggi;
}