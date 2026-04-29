/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
*   Modul                       : 03 – Structure and Dynamic Arrays
*   Hari dan Tanggal            : Rabu, 29 April 2026
*   Nama (NIM)                  : Aziiz Adityatama (13224070)
*   Nama File                   : Soal1Modul3.c
*   Deskripsi                   : Mengurutkan data artefak dengan aturan multi-kriteria
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Artefak{
    char Nama[50];
    char Kategori[50];
    int Tahun;
    int Nilai;
} Artefak;


int Compare(const void *a, const void *b) {
    Artefak *Artefak1 = (Artefak *)a;
    Artefak *Artefak2 = (Artefak *)b;

    if (strcmp(Artefak1->Kategori, Artefak2->Kategori) != 0){
        return strcmp(Artefak1->Kategori, Artefak2->Kategori);
    }

    if (Artefak1->Tahun != Artefak2->Tahun) {
        return Artefak1->Tahun - Artefak2->Tahun;
    }
    
    if (Artefak1->Nilai != Artefak2->Nilai) {
        return Artefak2->Nilai - Artefak1->Nilai;
    }
    
    return strcmp(Artefak1->Nama, Artefak2->Nama);
}

int main(){
    int Banyak;
    scanf("%d", &Banyak);

    Artefak Array[Banyak];
    for (int i = 0; i < Banyak; i++) {
        scanf("%s %s %d %d", Array[i].Nama, Array[i].Kategori, &Array[i].Tahun, &Array[i].Nilai);
    }

    qsort(Array, Banyak, sizeof(Artefak), Compare);

    for (int i = 0; i < Banyak; i++) {
        printf("%s %s %d %d\n", Array[i].Nama, Array[i].Kategori, Array[i].Tahun, Array[i].Nilai);
    }

    return 0;
}
