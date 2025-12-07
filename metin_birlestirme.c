#include <stdio.h>
    void birlestir(char *hedef , char *kaynak) {
        while (*hedef != '\0') {
            hedef++;
        }
        while (*kaynak != '\0') {
            *hedef = *kaynak;
            kaynak++;
            hedef++;
        }
        *hedef = '\0';
    }
int main() {
        char h[50] = "Kodlama";
        char k[] = "Harika";

        birlestir(h, k);
        printf("Sonuc: %s ", h);
        return 0;
    }
