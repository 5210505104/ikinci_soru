#include <stdio.h>

// Linear Search algoritması ile elemanın dizide olup olmadığını kontrol eden fonksiyon
int linearSearch(int dizi[], int n, int aranan) {
    int i;
    for(i = 0; i < n; i++) {
        if(dizi[i] == aranan) {
            return 1;
        }
    }
    return 0;
}

// Binary Search algoritması ile elemanın dizide olup olmadığını kontrol eden fonksiyon
int binarySearch(int dizi[], int sol, int sag, int aranan) {
    while (sol <= sag) {
        int orta = sol + (sag - sol) / 2;
        if (dizi[orta] == aranan) {
            return 1;
        }
        if (dizi[orta] < aranan) {
            sol = orta + 1;
        }
        else {
            sag = orta - 1;
        }
    }
    return 0;
}

int main() {
    int n, i, aranan, secim;
    printf("Dizinin boyutunu giriniz: ");
    scanf("%d", &n);
    int dizi[n];
    for(i = 0; i < n; i++) {
        printf("%d. elemanı giriniz: ", i+1);
        scanf("%d", &dizi[i]);
    }
    printf("Arama algoritmasını seçin: \n");
    printf("1) Linear Search\n");
    printf("2) Binary Search\n");
    scanf("%d", &secim);
    printf("Aranacak elemanı giriniz: ");
    scanf("%d", &aranan);
    if(secim == 1) {
        if(linearSearch(dizi, n, aranan)) {
            printf("Aranılan eleman dizide mevcut.\n");
        }
        else {
            printf("Aranılan eleman dizide bulunamadı.\n");
        }
    }
    else if(secim == 2) {
        if(binarySearch(dizi, 0, n-1, aranan)) {
            printf("Aranılan eleman dizide mevcut.\n");
        }
        else {
            printf("Aranılan eleman dizide bulunamadı.\n");
        }
    }
    else {
        printf("Geçersiz seçim.\n");
    }
    return 0;
}
