#include <stdio.h>
    struct ogrenci {
        char name[20];
        int vize ;
        int final;
        int ort ;
    };
void yazdir(struct ogrenci *p) {
    p -> ort =  (p -> vize + p -> final)/2 ;
    printf("%-10s // %-12d // %-12d //  %-12d \n " ,  p-> name , p -> vize , p ->final , p -> ort );

}

    int main(void) {
        struct ogrenci *ptr;
        struct ogrenci sinif [3] ={
            {"ali",90,80 },
            {"Berkay ", 100 ,98 },
            {"ahmet " , 70 , 89}
        };
        ptr =sinif;
   for (int i = 0 ; i<3 ;i++) {
       yazdir(ptr);
       ptr++;

   }
        return 0;
    }
