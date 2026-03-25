#include<stdio.h>

// TEKANAN
float TEKANAN(float F, float A);

int main(){
    float F, A;

    printf("Input gaya (F) = ");
    scanf("%f", &F);

    do{
        printf("Input luas (A) = ");
        scanf("%f", &A);
    } while(A == 0);

    printf("Tekanan = %.2f", TEKANAN(F, A));
    
    return 0;
}

float TEKANAN(float F, float A){
    return F/A;
}