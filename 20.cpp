#include <stdio.h>
#include <math.h>

double D(double P, double L, double T);

int main(){
    double P, L, T, diameter;
    int d10, d15, d20, d25;
    FILE *file;

    d10 = 0;
    d15 = 0;
    d20 = 0;
    d25 = 0;

    file = fopen("data.txt", "r");
    if(file == NULL){
        printf("File data.txt tidak ditemukan!");
    }
    else{
       while(fscanf(file, "%lf %lf %lf", &P, &L, &T) != EOF){
            diameter = D(P, L, T);
            
            if(diameter < 10) d10++;
            else if(diameter >= 10 && diameter < 15) d15++;
            else if(diameter >= 15 && diameter < 20) d20++;
            else if(diameter >= 20 && diameter < 25) d25++;
       }
    }
    fclose(file);

    printf("Jumlah bola diameter 10 = %d\n", d10);
    printf("Jumlah bola diameter 15 = %d\n", d15);
    printf("Jumlah bola diameter 20 = %d\n", d20);
    printf("Jumlah bola diameter 25 = %d\n", d25);

    return 0;
}

double D(double P, double L, double T){
    double R;

    R = sqrt(pow(P, 2) + pow(L, 2) + pow(T, 2));

    return R;
}