#include <stdio.h>

// PROGRAM RANGE, RATA-RATA
int RANGE(int N, int X[]);
double RATA(int N, int X[]);

int main(){
    int N, range_akhir;
    double rata_akhir;

    printf("Input banyak data: ");
    scanf("%d", &N);

    int X[N];

    for(int i = 0; i < N; i++){
        printf("Input angka ke-%d: ", i+1);
        scanf("%d", &X[i]);
    }

    range_akhir = RANGE(N, X);
    rata_akhir = RATA(N, X);

    printf("Range = %d\n", range_akhir);
    printf("Rata-rata = %.2f\n", rata_akhir);
}

int RANGE(int N, int X[]){
    int min, max;

    min = X[0];
    max = X[0];

    for(int i = 0; i < N; i++){
        if(X[i] < min) min = X[i];
        if(X[i] > max) max = X[i];
    }

    return max - min;
}

double RATA(int N, int X[]){
    int total = 0;

    for(int i = 0; i < N; i++){
        total += X[i];
    }

    return total / N;
}
