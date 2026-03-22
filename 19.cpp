#include<stdio.h>

void UPAH(int jam_kerja, double upah_perjam, double *upah_total);
void PTKP(int menikah, int tanggungan, double *total_ptkp); 
void PPH(double upah_total, double total_ptkp, double *total_pkp, double *pajak_penghasilan);

int main(){
    char nama[30];
    int jam_kerja, menikah, tanggungan;
    double upah_perjam, upah_total, total_ptkp, total_pkp, pajak_penghasilan, gaji_bersih;
    FILE *file;

    file = fopen("pegawai.txt", "r");
    if(file == NULL){
        printf("File pegawai.txt tidak ditemukan!");
    }
    else{
        while(fscanf(file, "%s %d %lf %d %lf", nama, &jam_kerja, &upah_perjam, &menikah, &tanggungan) != EOF){
            UPAH(jam_kerja, upah_perjam, &upah_total);
            PTKP(menikah, tanggungan, &total_ptkp);
            PPH(upah_total, total_ptkp, &total_pkp, &pajak_penghasilan);

            gaji_bersih = upah_total - pajak_penghasilan;

            printf("Nama: %s\n", nama);
            printf("Total upah: %.2lf\n", upah_total);
            printf("PTKP: %.2lf\n", total_ptkp);
            printf("PKP: %.2lf\n", total_pkp);
            printf("PPH: %.2lf\n", pajak_penghasilan);
            printf("Gaji bersih: %.2lf\n", gaji_bersih);
            
            printf("\n");
        }
        fclose(file);
    }
    
    return 0;
}

void UPAH(int jam_kerja, double upah_perjam, double *upah_total){
    if(jam_kerja <= 40) *upah_total = jam_kerja * upah_perjam;
    else *upah_total = (40 * upah_perjam) + ((jam_kerja - 40) * 1.5 *upah_perjam);
}

void PTKP(int menikah, int tanggungan, double *total_ptkp){
    if(menikah == 0) *total_ptkp = 400000;
    else *total_ptkp = 400000 + 350000;

    if(tanggungan > 0) *total_ptkp += 300000 * tanggungan;
}

void PPH(double upah_total, double total_ptkp, double *total_pkp, double *pajak_penghasilan){
    *total_pkp = upah_total - total_ptkp;

    if(*total_pkp < 0) *total_pkp = 0;
    else if(*total_pkp <= 1000000) *pajak_penghasilan = *total_pkp * 0;
    else if(*total_pkp <= 2500000) *pajak_penghasilan = *total_pkp * 0.05;
    else if (*total_pkp <= 5000000) *pajak_penghasilan = *total_pkp * 0.10;
    else if(*total_pkp <= 10000000)  *pajak_penghasilan = *total_pkp * 0.15;
    else *pajak_penghasilan = *total_pkp * 0.20;
}