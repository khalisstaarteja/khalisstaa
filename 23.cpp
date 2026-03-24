#include <stdio.h>

//RATA RATA
double RATA();

int main(){
    double hasil;

    hasil = RATA();

    printf("Rata-rata = %.2lf\n", hasil);

    return 0;
}

double RATA(){
    int n, total;

    total = 0;

    printf("Banyak angka: ");
    scanf("%d", &n);

    int num[n];

    for(int i = 0; i < n; i++){
        printf("Angka ke-%d: ", i + 1);
        scanf("%d", &num[i]);
        total += num[i];
    }

    return (double) total / n;
}