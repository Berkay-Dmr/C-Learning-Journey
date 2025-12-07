#include <stdio.h>
    struct ogrenci {
        char ad[20];
        int devamsizlik;
    };
    void durumyazdir(struct ogrenci *ptr , int boyut , int sinir) {
        for (int i = 0; i<boyut; i++ ) {
            if (ptr->devamsizlik >= sinir) {
               printf("AD = %-10s // KALDI \n" , ptr->ad);
            }
            else {
                printf("AD = %-10s // GECDI \n" , ptr ->ad );
            }
            ptr++;
        }
    }

int main (void) {
    struct ogrenci sinif[4]= {
        {"ali " , 10},
        {"ahmet" , 5},
        {"ayşe" , 12},
        {"kemal" , 2}
    };
        durumyazdir(sinif,4,5);
        return 0;
}
