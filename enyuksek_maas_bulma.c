#include <stdio.h>
    struct calısan {
        char name[20];
        int maas;
    };

    int main(void) {
        FILE *belge;
        int okunan;
        int max;
        char isimi[10];
        belge = fopen("rapor.txt" , "a");
        if ( belge == NULL ) {
            printf("Error opening file");
        }
        struct calısan ortam [3]=  {};
        for (int i = 0 ; i<3 ; i++) {
            printf("calisan adini giriniz ");
            scanf("%s" , ortam[i].name);

            printf("calisan maas giriniz ");
            scanf("%d" , &ortam[i].maas);
        }
        max = ortam[0].maas;
        int basarili = 0;
        for (int i = 0 ; i<3 ; i++) {
            if (ortam[i].maas > max) {
                max = ortam[i].maas;
                basarili = i;
            }
        }
        fprintf(belge, "%s ----------- %d\n" , ortam[basarili].name , ortam[basarili].maas);
        fclose(belge);
        return 0;
    }
