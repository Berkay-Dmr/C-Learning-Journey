#include <stdio.h>
#include  <stdlib.h>
typedef struct {
    int ogrno;
    int vizenotu;
} ogrenci;
    int main (void) {
        int kisi;
        ogrenci ogr1;
        printf("ogrenci sayisini giriniz:");
        scanf("%d" , &kisi);
         ogrenci *dizi = (ogrenci*) malloc (kisi*sizeof (ogrenci));
        if (dizi == NULL) {
            printf("malloc error");
        }
        printf("%d tane ogrenci vize notu giriniz \n", kisi);
        for (int i = 0 ; i < kisi; i++) {
            printf("%d ogrencini no sunu giriniz :" , i+1);
            scanf("%d" , &dizi[i].ogrno);

            printf("%d . ogrencinin vize notunu giriniz:", i+1);
            scanf("%d" , &dizi[i].vizenotu);
        }
        printf("---------- SONUCLAR----------\n");
        for (int i = 0 ; i < kisi; i++) {
             printf("%d . ogrencinin no su = %-10d  " , i+1, dizi[i].ogrno);
            printf("%d . ogrencinin notu = %-10d \n"  , i+1, dizi[i].vizenotu);
        }
        free(dizi);
        return 0;
    }
