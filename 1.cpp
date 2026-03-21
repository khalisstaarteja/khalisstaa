#include <stdio.h>
#include <string.h>

// PROGRAM PARKIR
typedef struct{
   char nama[30];
   int jumlah_kendaraan; 
   char jenis_kendaraan[3][30];
   int lama_parkir[3];
   double biaya_parkir[3];
   double diskon[3];
   int total_biaya;
} detail_parkir;

void header();
void clean();
void error();
void inputData(detail_parkir *item, int pilih_kendaraan[]);
int jenisKendaraan(int pilih_kendaraan, char jenis_kendaraan[]);
double cekFreeParkir(int lama_parkir, double biaya_parkir);
double biayaParkir(char jenis_kendaraan[], int lama_parkir, double biaya_parkir, int jumlah_kendaraan);
double cekDiskon(int lama_parkir, double biaya_parkir, double *diskon);
int totalBiaya(double biaya_parkir, int total_biaya);
void strukPembayaran(detail_parkir *item);
void cetakStrukPembayaran(detail_parkir *item);
void footer();

int main(){
    detail_parkir item;
    int pilih_kendaraan[3];
    item.total_biaya = 0;
    item.jumlah_kendaraan = 0;

    header();

    inputData(&item, pilih_kendaraan);

    for(int i = 0; i < item.jumlah_kendaraan; i++){
        item.biaya_parkir[i] = cekFreeParkir(item.lama_parkir[i], item.biaya_parkir[i]);
        item.biaya_parkir[i] = biayaParkir(item.jenis_kendaraan[i], item.lama_parkir[i], item.biaya_parkir[i], item.jumlah_kendaraan);
        item.biaya_parkir[i] = cekDiskon(item.lama_parkir[i], item.biaya_parkir[i], &item.diskon[i]);
        item.total_biaya = totalBiaya(item.biaya_parkir[i], item.total_biaya);
    }

    strukPembayaran(&item);
    cetakStrukPembayaran(&item);

    footer();
}

void header(){
    printf("======================================\n");
    printf("    SISTEM BIAYA PARKIR KENDARAAN      \n");
    printf("=======================================\n");
}

void clean(){
    while(getchar() != '\n');
}

void error(){
    printf("\n[ERROR: Input Tidak Valid!]\n");
}

void footer(){
    printf("======================================\n");
    printf("            PROGRAM SELESAI           \n");
    printf("=======================================\n");
}

void inputData(detail_parkir *item, int pilih_kendaraan[]){
    printf("Nama: ");
    fgets(item->nama, sizeof(item->nama), stdin);
    item->nama[strcspn(item->nama, "\n")] = 0;

    while(item->jumlah_kendaraan > 3 || item->jumlah_kendaraan < 1){
        printf("Jumlah Kendaraan (Min: 1, Maks: 3): ");
        scanf("%d", &item->jumlah_kendaraan);
        clean();

        if(item->jumlah_kendaraan > 3 || item->jumlah_kendaraan < 1){
            error();
            continue;
        }
        else{
            for(int i = 0; i < item->jumlah_kendaraan; i++){
                int valid;
                do{
                    printf("\n=======================================\n");
                    printf("           KENDARAAN KE - %d           \n", i + 1);
                    printf("=======================================\n");
                    printf("1. Mobil\n");
                    printf("2. Motor\n");
                    printf("3. Truk\n");
                    printf("Pilih Jenis Kendaraan (1-3): ");
                    scanf("%d", &pilih_kendaraan[i]);

                    valid = jenisKendaraan(pilih_kendaraan[i], item->jenis_kendaraan[i]);
                    
                    if(!valid){
                        error();
                    }
                } while(!valid);

                printf("Lama Parkir (Jam): ");
                scanf("%d", &item->lama_parkir[i]);
            }
        }
    }
}

int jenisKendaraan(int pilih_kendaraan, char jenis_kendaraan[]){
    if(pilih_kendaraan == 1){
        strcpy(jenis_kendaraan, "Mobil");
    }
    else if(pilih_kendaraan == 2){
        strcpy(jenis_kendaraan, "Motor");
    }
    else if(pilih_kendaraan == 3){
        strcpy(jenis_kendaraan, "Truk");
    }
    else{
        return 0;
    }
    return 1;
}

double cekFreeParkir(int lama_parkir, double biaya_parkir){
    if(lama_parkir == 0){
        biaya_parkir = 0;
    }
    return biaya_parkir;
}

double biayaParkir(char jenis_kendaraan[], int lama_parkir, double biaya_parkir, int jumlah_kendaraan){
    int tarif_dasar = 5000;

    if(strcmp(jenis_kendaraan, "Mobil") == 0){
        biaya_parkir = tarif_dasar * lama_parkir;
    }
    else if(strcmp(jenis_kendaraan, "Motor") == 0){
        biaya_parkir = (tarif_dasar * 0.5 * lama_parkir) + tarif_dasar;
    }
    else if(strcmp(jenis_kendaraan, "Truk") == 0){
        biaya_parkir = (tarif_dasar * 2 * lama_parkir) + tarif_dasar;
    }
    return biaya_parkir;
}

double cekDiskon(int lama_parkir, double biaya_parkir, double *diskon){
    if(lama_parkir > 5){
        *diskon = biaya_parkir * 0.1;
        biaya_parkir *= 0.9;
        
        return biaya_parkir;
    }
    else{
        return biaya_parkir;
    }
}

int totalBiaya(double biaya_parkir, int total_biaya){
    total_biaya += biaya_parkir;
    return total_biaya;
}

void strukPembayaran(detail_parkir *item){
    printf("\n=======================================\n");
    printf("            STRUK PEMBAYARAN           \n");
    printf("=======================================\n");
    printf("Nama: %s\n", item->nama);
    printf("Jumlah Kendaraan: %d\n", item->jumlah_kendaraan);
    printf("---------------------------------------\n");
    printf("            Jenis Kendaraan:           \n");
    printf("---------------------------------------\n");
    for(int i = 0; i < item->jumlah_kendaraan; i++){
        printf("%d. %s (%d jam) (Rp. %.0lf)\n", i+1, item->jenis_kendaraan[i], item->lama_parkir[i], item->biaya_parkir[i]);

        if(item->lama_parkir[i] > 5){
            printf("   -> SUDAH MENDAPAT DISKON 10%% (Rp. %.0lf)\n", item->diskon[i]);
        }
    }
    printf("---------------------------------------\n");
    printf("          Total Biaya: Rp. %d          \n", item->total_biaya);
    printf("=======================================\n");
    printf("             TERIMA KASIH!             \n");
    printf("=======================================\n");
}

void cetakStrukPembayaran(detail_parkir *item){
    FILE *file_struk_pembayaran;
    file_struk_pembayaran = fopen("struk_pembayaran.txt", "w");

    if(file_struk_pembayaran == NULL){
        printf("\nFile belum ada!\n");
        return;
    }
    else{
        fprintf(file_struk_pembayaran, "\n=======================================\n");
        fprintf(file_struk_pembayaran, "            STRUK PEMBAYARAN           \n");
        fprintf(file_struk_pembayaran, "=======================================\n");
        fprintf(file_struk_pembayaran, "Nama: %s\n", item->nama);
        fprintf(file_struk_pembayaran, "Jumlah Kendaraan: %d\n", item->jumlah_kendaraan);
        fprintf(file_struk_pembayaran, "---------------------------------------\n");
        fprintf(file_struk_pembayaran, "            Jenis Kendaraan:           \n");
        fprintf(file_struk_pembayaran, "---------------------------------------\n");
        for(int i = 0; i < item->jumlah_kendaraan; i++){
            fprintf(file_struk_pembayaran, "%d. %s (%d jam) (Rp. %.0lf)\n", i+1, item->jenis_kendaraan[i], item->lama_parkir[i], item->biaya_parkir[i]);
            if(item->lama_parkir[i] > 5){
                fprintf(file_struk_pembayaran, "   -> SUDAH MENDAPAT DISKON 10%% (Rp. %.0lf)\n", item->diskon[i]);
            }
        }
        fprintf(file_struk_pembayaran, "---------------------------------------\n");
        fprintf(file_struk_pembayaran, "          Total Biaya: Rp. %d          \n", item->total_biaya);
        fprintf(file_struk_pembayaran, "=======================================\n");
        fprintf(file_struk_pembayaran, "             TERIMA KASIH!             \n");
        fprintf(file_struk_pembayaran, "=======================================\n");
        fclose(file_struk_pembayaran);

        printf("\n[Struk Pembayaran Berhasil Dicetak!]\n\n");
    }
}



