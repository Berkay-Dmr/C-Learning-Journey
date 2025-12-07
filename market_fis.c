#include <stdio.h>
    struct urun {
        char ad[20] ;
        int fiyat;
        int adet;
    };
    int hesapla (struct urun *p, int boyut ) {
        int toplam = 0;
        for (int i = 0 ; i < boyut ; i++) {
        toplam += p ->fiyat * p -> adet;
            p++; //p bir artar
        }
        return toplam;
    }

int main(void) {
        struct urun sepet[3] = {
            {"ekmek ", 15 , 4},
            {"kola" , 30 , 2 },
            {"balık" , 30 , 5}
        };
    printf("toplam sonucu = %d" , hesapla(sepet,3)); // 3 sebebi 3 tane struct degeri olması
        return 0;
    }
