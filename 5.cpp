#include <stdio.h>

// PROGRAM +=*/
void hitung(double t1, double t2, double *t3, double *t4, double *t5, double *t6);

int main(){
    double a, b, c, d, e, f;

    printf("Masukkan 2 bilangan: ");
    scanf("%lf %lf", &a, &b);

    hitung(a, b, &c, &d, &e, &f);

    printf("Hasil Penjumlahan: %.2lf\n", c);
    printf("Hasil Pengurangan: %.2lf\n", d);
    printf("Hasil Perkalian: %.2lf\n", e);
    printf("Hasil Pembagian: %.2lf\n", f);

    return 0;
}

void hitung(double t1, double t2, double *t3, double *t4, double *t5, double *t6){
    *t3 = t1 + t2;
    *t4 = t1 - t2;
    *t5 = t1 * t2;

    if(t2 == 0){
        t2 = 1;
    }

    *t6 = t1 / t2;
}