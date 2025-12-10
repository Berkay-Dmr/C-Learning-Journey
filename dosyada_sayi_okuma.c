#include <stdio.h>
    int main(void) {
        FILE *belge;
        int okunan;
        belge = fopen("sayilar.txt", "w");
        if (belge == NULL) {
            printf("Sayilar.txt not found");
            return 1;
        }
        for (int i = 1; i <= 10; i++) {
            fprintf(belge, "%d \n", i);
        }
        fclose(belge);
        printf("dosya basarıyla olsuturuldu \n ");
        belge = fopen("sayilar.txt", "r");
        int toplam  = 0;
        while (fscanf(belge, "%d", &okunan) != EOF) {
            toplam+= okunan;
        }
        fclose(belge);
        printf("toplam = %d" , toplam);
        return 0;
    }
