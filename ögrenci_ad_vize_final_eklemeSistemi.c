#include <stdio.h>
#include <stdlib.h>
   typedef struct  {
        char name[20];
        int vize ;
        int final;
    }ogrenci;

int main(void) {
    FILE *belge;
    int i;
    int kisi;
    belge = fopen("notlar.txt" , "a");
    if ( belge == NULL ) {
        printf("Error opening file");
        exit(1);
    }
    printf("kisi sayisini giriniz");
    scanf("%d",&kisi);
    ogrenci *dizi = (ogrenci*) malloc(kisi*sizeof(ogrenci));
    for (i = 0 ; i<kisi; i++) {
        printf("ogrenci adini giriniz ");
        scanf("%s" , dizi[i].name);

        printf("ogrenci vize giriniz ");
        scanf("%d" , &dizi[i].vize);

        printf("ogrenci final giriniz ");
        scanf("%d" , &dizi[i].final);
    }
    for (i = 0 ; i<kisi; i++) {
        fprintf(belge , "%-10s // %-10d // %-10d \n" , dizi[i].name , dizi[i].vize ,  dizi[i].final );
    }
    fclose(belge);
    free(dizi);
    printf("belge basarıyla olusturuldu");
    return 0;
}
