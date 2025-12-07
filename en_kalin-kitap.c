#include <stdio.h>
    struct kitap {
        char ad [20];
        int sayfa ;
    };
void kalinkitaplaribul(struct kitap *ptr , int boyut) {
    struct kitap *sampion;
    sampion = ptr;
    for (int i = 0; i<4 ;i++ ) {
        if (ptr->sayfa > sampion->sayfa) {
            sampion = ptr;
        }
        ptr++;
    }
    printf("%-10s // %-12d" , sampion->ad , sampion->sayfa);
}

int main(void) {
    struct kitap raf[4]={
        {"sefiiler" , 1000},
        {"pia matter " , 900},
        {"dua matter" , 100},
        {"archnoid matter" , 480}
    };
    kalinkitaplaribul(raf,0);
    return 0;
}
