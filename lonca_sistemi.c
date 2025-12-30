#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char ad[30];
    char sinif[20];
    char rank [4];
    char irk[15];
    int yas;
    int durum;
}karakter;
void listele (karakter *liste , int kisi) {
    printf("AD--------SİNİF-------RANK----IRK-----YAS---DURUM \n");
    for (int i = 0 ;i < kisi ; i++) {
        printf("%-10s %-10s %-5s %-10s %-3d %-2d \n" ,(liste+i)->ad ,(liste+i)->sinif , (liste+i)->rank, (liste+i)->irk ,(liste+i)->yas ,(liste+i)->durum );
    }
}
int en_yasli (karakter *liste , int kisi) {
    int en_yasli = 0;
    for (int i = 1 ;i < kisi ; i++) {
        if ((liste+i)->yas > (liste+en_yasli)->yas) {
            en_yasli = i;
        }
    }
    printf("En yasli kisi \n %d" , (liste+en_yasli)->yas);
    return en_yasli;
}
void veri_al (karakter *liste , int kisi) {
    for (int i = 0 ;i < kisi ; i++) {
        printf("%d. kisinin adini giriniz",i+1);
        scanf("%s" , (liste+i)->ad);

        printf("%d. kisinin sinifini giriniz",i+1);
        scanf("%s", (liste+i)->sinif);

        printf("%d. kisinin rank giriniz",i+1);
        scanf("%s" ,  (liste+i)->rank);

        printf("%d. kisinin irk giriniz",i+1);
        scanf("%s",(liste+i)->irk);

        printf("%d. kisinin yasini giriniz",i+1);
        scanf("%d",&(liste+i)->yas);

        printf("%d. kisinin durum giriniz(eger loncaya kayiti ise 1 degil ise 0 olmali) ",i+1);
        scanf("%d",&(liste+i)->durum);
    }
}
float ortalama_hesapla (karakter *liste , int kisi) {
    int toplam = 0;
    for (int i = 0 ;i < kisi ; i++) {
        toplam += (liste+i)->yas;
    }
    return  (float) toplam / (float) kisi;
}
void durum_listele (karakter *liste , int kisi) {
    printf("HALİ HAZİRDA LONCADA OLANLAR \n"
        "AD--------SİNİF-------RANK----IRK-----YAS---DURUM \n");
    for (int i = 0 ;i < kisi ; i++) {
        if ((liste+i)->durum ==1) {
            printf("%-10s %-10s %-5s %-10s %-3d %-2d \n" ,(liste+i)->ad ,(liste+i)->sinif , (liste+i)->rank, (liste+i)->irk ,(liste+i)->yas ,(liste+i)->durum );
        }
    }
}
int main (void) {
    int kisi ;
    printf("kisi sayisini giriniz :");
    scanf("%d" ,&kisi);
    karakter *liste  = malloc(kisi*sizeof(karakter));
    if (liste == NULL) {
        printf("hata!!");
        exit(1);
    }
    veri_al(liste,kisi);
    listele (liste , kisi);
    durum_listele(liste,kisi);
    printf("---CIKTILAR--- \n");
    float sonuc = ortalama_hesapla (liste , kisi);
    printf("Ortalama = %.2f \n" , sonuc);
    int en_yasli_idx = en_yasli(liste, kisi);
    printf("\n");
    printf("En Degerli Uye: %s (%d yasinda)\n", (liste + en_yasli_idx)->ad, (liste + en_yasli_idx)->yas);
    free(liste);
    return 0;
}
