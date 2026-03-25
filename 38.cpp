#include <stdio.h>

// ENERGI KINETIK
void INPUT(float *m, float *v, int n);
void CALCULATE(float *m, float *v, int n, float *EK);
void OUTPUT(float *EK, int n);

int main(){
    int n;

    printf("Input n = ");
    scanf("%d", &n);

    float EK[n];
    float m[n];
    float v[n];
    
    INPUT(m, v, n);
    CALCULATE(m, v, n, EK);
    OUTPUT(EK, n);

    return 0;
}

void INPUT(float *m, float *v, int n){
    for(int i = 0; i < n; i++){
        printf("\nBenda ke-%d: \n", i + 1);
        printf("Input massa (%d) = ", i + 1);
        scanf("%f", (m + i));
        printf("Input kecepatan (%d) = ", i + 1);
        scanf("%f", (v + i));
    }
}

void CALCULATE(float *m, float *v, int n, float *EK){
    for(int i = 0; i < n; i++){
        *(EK + i) = 0.5 * *(m + i) * *(v + i) * *(v + i);
    }
}

void OUTPUT(float *EK, int n){
    printf("\nEnergi kinektik: \n");
    for(int i = 0; i < n; i++){
        printf("Benda (%d) = %.2f\n", i + 1, *(EK + i));
    }
}

