#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int vize;
    int final;
    int odev;
    float ortalama;
    char harf;
}ogrenci;
int main() {
    int n;
    printf("ogrenci sayisini giriniz : ");
    scanf("%d",&n);
    int ogrenci_sayisi = n;
    ogrenci *p ;
    p =malloc(ogrenci_sayisi*sizeof(ogrenci));
    if (p == NULL) {
        printf("hata");
        exit(1);
    }
    for (int i=0;i<ogrenci_sayisi;i++) {
        printf("%d . ogrencinin id giriniz" , i+1);
        scanf("%d", &(p+i)-> id);

        printf("%d . ogrencinin vize  giriniz" , i+1);
        scanf("%d",&(p+i)->vize);

        printf("%d . ogrencinin final giriniz" , i+1);
        scanf("%d",&(p+i)->final);

        printf("%d . ogrencinin odev giriniz" , i+1);
        scanf("%d",&(p+i)->odev);

        printf("\n\n");
    }
    printf("veriler alındı\n");

    for (int i=0;i<ogrenci_sayisi;i++) {
        (p+i)->ortalama = (p+i)->vize *0.4 + (p+i)->final*0.5 + (p+i)->odev*0.1;
    }
    for (int i=0;i<ogrenci_sayisi;i++) {
        if ((p+i)->ortalama <=100 && (p+i)->ortalama >=90) {
            (p+i)->harf = 'A';
        }
        else if ((p+i)->ortalama <= 89 &&(p+i)->ortalama >=80) {
            (p+i)->harf = 'B';
        }
        else if ((p+i)->ortalama <=79 && (p+i)->ortalama >=70) {
            (p+i)->harf = 'C';
        }
        else if ((p+i)->ortalama <=69 && (p+i)->ortalama >=60) {
            (p+i)->harf = 'D';
        }
        else if ((p+i)->ortalama <= 59 && (p+i) ->ortalama >=50) {
            (p+i)->harf = 'E';
        }
        else {
            (p+i)->harf = 'F';
        }
    }
    float max , min;
    int indis1,indis2;
    max = (p+0)->ortalama;
    min = (p+0)->ortalama;
    for (int i=0;i<ogrenci_sayisi;i++) {
        if ((p+i)->ortalama >max) {
            max = (p+i)->ortalama;
            indis1 = i;
        }
        if ((p+i)->ortalama <min) {
            min= (p+i)->ortalama;
            indis2 = i;
        }
    }
    printf("EN YUKSEK OLAN \n"
           "%-5d  %-6f %-5c \n ",(p+indis1)->id , (p+indis1)->ortalama ,(p+indis1)->harf);

    printf( "En DUSUK OLAN \n "
            "%-5d  %-6f  %-5c \n",(p+indis2)->id , (p+indis2)->ortalama ,(p+indis2)->harf);
    free(p);
    return 0;
}
