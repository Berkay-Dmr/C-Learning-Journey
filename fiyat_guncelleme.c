#include <stdio.h>
    struct urun {
        char ad[20];
        int fiyat;
    };

void zamyap(struct urun *ptr , int boyut , int zammiktari) {
    for (int i = 0; i < boyut; i++) {
        ptr->fiyat += zammiktari;
        ptr++;
    }
}


int main(void) {
    struct urun tanesi [3]={
        {"telefon" , 10000},
        {"oyuncak araba " , 100},
        {"kalemlik" , 190}
    };for (int i = 0 ; i < 3 ; i++) {
    printf("ad = %-14s  || eski fiyat = %-12d \n " , tanesi[i].ad , tanesi[i].fiyat );
    }
    printf("\n");
    zamyap(tanesi , 3 , 1000);
    for (int i = 0; i < 3; i++) {
        printf("ad = %-14s  || yeni fiyat = %-12d \n" , tanesi[i].ad , tanesi[i].fiyat);
    }
    return 0;
}
