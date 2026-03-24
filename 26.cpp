#include<stdio.h>
#include<math.h>

//PROGRAM KAPASITOR
void v(double t);

int main(){
    double start, finish, step, time;

    printf("Masukkan awal, akhir, dan pertambahan waktu: ");
    scanf("%lf %lf %lf", &start, &finish, &step);

    time = start;

    while(time <= finish){
        v(time);
        time += step;
    }

    return 0;
}

void v(double t){
    double vt;

    vt = (t + 0.1) * exp(sqrt(t));

    printf("Tegangan kapasitor pada %.2lf detik: %.2lf volt\n", t, vt);
}