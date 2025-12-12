#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
    int main(void) {
        int n;
        int *dizi;
        printf("kac sayi gireceksiniz :");
        scanf("%d",&n);
        dizi = (int*) malloc(n*sizeof(int));

        if (dizi == NULL) {
            printf("Malloc failed !");
        }
        for (int i = 0; i < n; i++) {
            printf("%d. sayiyi giriniz :" , i+1);
            scanf("%d", &dizi[i]);
        }
        int temp ;
        for (int i = 0; i < n/2; i++) {
            temp = dizi[i];
            dizi[i] = dizi[n-1-i];
            dizi[n-1-i] = temp;
        }
        printf("sonuc = ");
        for (int i = 0; i < n; i++) {
            printf("%d ", dizi[i]);
        }
        free(dizi);
    }
