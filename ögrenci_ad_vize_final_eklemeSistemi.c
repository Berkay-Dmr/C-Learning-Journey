#include <stdio.h>
#include <stdlib.h>
    struct ogrenci {
        char name[20];
        int vize ;
        int final;
    };

    int main(void) {
        FILE *belge;
        int i;
        belge = fopen("notlar.txt" , "a");
        if ( belge == NULL ) {
            printf("Error opening file");
        }
        struct ogrenci sinif [3]=  {};
            for (i = 0 ; i<3 ; i++) {
                printf("ogrenci adini giriniz ");
                scanf("%s" , sinif[i].name);

                printf("ogrenci vize giriniz ");
                scanf("%d" , &sinif[i].vize);

                printf("ogrenci final giriniz ");
                scanf("%d" , &sinif[i].final);
            }
        for (i = 0 ; i<3 ; i++) {
            fprintf(belge , "%-10s // %-10d // %-10d\n" , sinif[i].name , sinif[i].vize , sinif [i].final );
        }
        fclose(belge);
        return 0;
    }
