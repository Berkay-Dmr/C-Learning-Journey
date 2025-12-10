#include <stdio.h>
    int main(void) {
        FILE *belge;
        FILE *yaz_tek;
        FILE *yaz_cift;
        int okunan;
        belge = fopen("sayilar.txt", "r");
        yaz_tek = fopen("yaz_tek","w");
        yaz_cift = fopen("yaz_cift", "w");
        if (belge == NULL) {
            printf("Sayilar.txt not found");
        }
        while (fscanf(belge, "%d", &okunan) != EOF) {
            if (okunan%2 == 0) {
                fprintf(yaz_cift, "%d\n", okunan);
            }
            else {
                fprintf(yaz_tek, "%d\n", okunan);
            }
        }
        fclose(belge);
        fclose(yaz_tek);
        fclose(yaz_cift);
        yaz_tek = fopen("yaz_tek","r");
        yaz_cift = fopen("yaz_cift", "r");
        while (fscanf(yaz_cift, "%d", &okunan) != EOF) {
            printf("okunanlar = %d\n" , okunan);
        }
        printf("\n");
        while (fscanf(yaz_tek,"%d", &okunan) != EOF) {
            printf("okunanar = %d\n", okunan);
        }
        fclose(yaz_tek);
        fclose(yaz_cift);
        return 0;
    }
