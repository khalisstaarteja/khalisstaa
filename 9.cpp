#include <stdio.h>
#include <string.h>

// PROGRAM SHOPPING LIST
typedef struct{
    char nama[50];
    int jumlah;
} List;

List item[50];

void tampilData();
void tambahData();
int menuUtama();

int choice;

int main(){
    menuUtama();
}

int menuUtama(){
    do{
        printf("\n--- Shopping List ---\n");
        printf("1. Menampilkan Data\n");
        printf("2. Menambah Data\n");
        printf("3. Keluar\n");
        printf("Pilih (1-3): ");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1 : tampilData(); break;
            case 2 : tambahData(); break;
            case 3 : return 0;
            default : printf("Pilihan tidak valid\n");
        } 
    } while (choice != 3);
}

void tambahData(){
    int i = 0;
    char verify;

    printf("\n--- Tambah Data ---\n");
    do{
        printf("Nama: ");
        fgets(item[i].nama, sizeof(item[i].nama), stdin);
        item[i].nama[strcspn(item[i].nama, "\n")] = 0;
        
        printf("Jumlah: ");
        scanf("%d", &item[i].jumlah);
        getchar();

        FILE *file;
        file = fopen("ShoppingList.txt", "a");
        if(file == NULL){
            printf("\nFile belum ada!\n");
            return;
        }
        fprintf(file, "---------------------------------\n");
        fprintf(file, "Nama     : %s\n", item[i].nama);
        fprintf(file, "Jumlah   : %d\n", item[i].jumlah);
        fprintf(file, "---------------------------------\n\n");
        fclose(file);

        printf("\nData berhasil ditambahkan!\n");
        printf("Lanjut tambah data? (y/n): ");
        scanf(" %c", &verify);
        getchar();
        
    } while(verify == 'y' || verify == 'Y');
}

void tampilData(){
    FILE *file;
    file = fopen("ShoppingList.txt", "r");

    if(file == NULL){
        printf("\nFile belum ada!\n");
        return;
    }

    char buffer[100];
    if(fgets(buffer, sizeof(buffer), file) == NULL){
        printf("\nData belum ada!\n");
        fclose(file);
        return;
    }

    else{
        printf("\n      --- Shopping List ---\n");
        printf("%s", buffer);
    }
       
    while(fgets(buffer, sizeof(buffer), file)){
        printf("%s", buffer);
    }

    fclose(file);
}