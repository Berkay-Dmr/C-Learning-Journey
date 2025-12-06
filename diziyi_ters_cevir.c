#include <stdio.h>

void ters(int *ptr, int boyut) {
    int *son;
    son = ptr + boyut - 1; // Son kutunun adresini bul

    // Sol el (ptr) Sağ elden (son) küçük olduğu sürece devam et
    while (ptr < son) {
        // 1. Değerleri Takas Et (Swap)
        int temp = *ptr;
        *ptr = *son;
        *son = temp;

        // 2. Adresleri Kaydır (Navigasyon)
        ptr++; // Sol parmağı bir sağa kaydır
        son--; // Sağ parmağı bir sola kaydır
    }
}

int main(void) {
    int dizi[5] = {1, 2, 3, 4, 5};
    int i;

    printf("Eski Hali: ");
    for(i = 0; i < 5; i++) printf("%d ", dizi[i]);
    printf("\n");

    // Fonksiyonu çağır
    ters(dizi, 5);

    printf("Yeni Hali: ");
    for(i = 0; i < 5; i++) printf("%d ", dizi[i]);
    printf("\n");

    return 0;
}
