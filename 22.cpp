#include<stdio.h>

//PROGRAM PPN
void hargaPpn(int harga_barang);

int main(){
    int harga;

    printf("Masukkan harga barang: ");
    scanf("%d", &harga);

    hargaPpn(harga);

    return 0;
}

void hargaPpn(int harga_barang){
    int ppn;
    int bayar;

    ppn = 10 * harga_barang / 100;
    bayar = harga_barang + ppn;

    printf("Harga barang: Rp. %d\n", harga_barang);
    printf("PPN: Rp. %d\n", ppn);
    printf("Total bayar: Rp. %d\n", bayar);
}