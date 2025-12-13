#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char isim[20];
    char icerik[100];
    int dolu_mu;
}dosya;

dosya disk [5];
typedef struct {
    char *komut_adi;
    char **argumanlar;
    int arguman_sayisi;
} komut;

void komut_temizle (komut *islem) {
    if (islem->komut_adi != NULL) {
        free(islem->komut_adi);
    }
    if (islem->argumanlar != NULL) {
        for (int i = 0; i < islem->arguman_sayisi; i++) {
            if (islem->argumanlar[i] != NULL) {
                free(islem->argumanlar[i]);
            }
        }
        free(islem->argumanlar);
    }
    free(islem);
}
int main(void) {
    for (int i = 0; i < 5; i++) {
        disk[i].dolu_mu = 0;
    }
    char satir[1000];
  while (1) {
      printf("BerkayOS > ");
      fgets(satir, sizeof(satir), stdin);
      satir[strcspn(satir, "\n")] = '\0';
      komut *yeni_islem = malloc(sizeof(komut));
      yeni_islem->argumanlar = malloc(10*sizeof(char*));
      yeni_islem->arguman_sayisi = 0;

      char *ilk_parca = strtok(satir, " ");
      if (ilk_parca== NULL) {
          free(yeni_islem->argumanlar);
          free(yeni_islem);
          continue;
      }

      if (ilk_parca != NULL) {
          yeni_islem->komut_adi = strdup(ilk_parca);
      }

      char *diger_parca = strtok(NULL, " ");

      while (diger_parca != NULL) {
          yeni_islem->argumanlar [yeni_islem -> arguman_sayisi] = strdup(diger_parca) ;
          yeni_islem->arguman_sayisi++;
          diger_parca = strtok(NULL, " ");
      }

      if (strcmp(yeni_islem-> komut_adi, "cikis") == 0 ) {
          komut_temizle(yeni_islem);
          break;
      }
        else if (strcmp(yeni_islem-> komut_adi, "yazdir") == 0 ) {
          for (int i = 0; i < yeni_islem-> arguman_sayisi; i++) {
              printf("%s "  , yeni_islem -> argumanlar[i]);
          }
            printf("\n");
      }
         else if (strcmp(yeni_islem-> komut_adi, "temizle") == 0 ) {
              system("cls");
          }
      else if (strcmp(yeni_islem-> komut_adi, "dosya_olustur") == 0 ) {
          if (yeni_islem-> arguman_sayisi < 1) {
              printf("dosya adi giriniz !\n");
          }
          else {
              int  basasrili = 0;
              for (int i = 0; i < 5; i++) {
                  if (disk[i].dolu_mu == 0) {
                      strcpy(disk[i].isim, yeni_islem -> argumanlar[0]);
                      strcpy(disk[i].icerik, "");
                      disk[i].dolu_mu =1;
                      basasrili=1;
                      printf("basarili dosya olusturldu %s (Index : %d)\n" ,disk[i].isim, i);
                      break;
                  }
              }
              if (basasrili == 0) {
                  printf("Hata : disk dolu!\n");
              }
          }
      }
      else if (strcmp(yeni_islem-> komut_adi, "dir") == 0 ) {
          printf("-----Disk Icerigi----- \n");
          for (int i = 0; i < 5; i++) {
              if (disk[i].dolu_mu == 1) {
                  printf("Index : %d ismi : %s \n" ,i , disk[i].isim);
              }
          }
      }
      else if (strcmp(yeni_islem->komut_adi ,"dosya_yaz") == 0) {
          if (yeni_islem-> arguman_sayisi < 2) {
              printf("hata :dosya adi ve icerik giriniz \n");
          }
            else {
                int bulundu = 0;
                for (int i = 0; i < 5; i++) {
                    if (disk[i].dolu_mu == 1 ) {
                        if (strcmp (yeni_islem-> argumanlar[0] ,disk[i].isim ) == 0) {
                            disk[i].icerik[0] = '\0';
                            for (int j = 0; j < yeni_islem-> arguman_sayisi; j++) {
                                strcat(disk[i].icerik , yeni_islem-> argumanlar[j]);
                                if (j <yeni_islem -> arguman_sayisi - 1)
                                    strcat(disk[i].icerik , " ");
                            }
                            bulundu = 1;
                            break;
                        }
                    }
                }
                if (bulundu == 0) {
                    printf("boyle bir dosya yok \n");
                }
            }
      }
      else if (strcmp(yeni_islem->komut_adi, "dosya_oku") == 0) {
          if (yeni_islem-> arguman_sayisi < 1) {
              printf("hata :dosya adi giriniz \n");
          }
          else {
              int bulundu = 0;
              for (int i = 0; i < 5; i++) {
                  if (disk[i].dolu_mu == 1) {
                      if (strcmp(yeni_islem-> argumanlar[0] ,disk[i].isim ) == 0) {
                        printf("%s " , disk[i].icerik);
                          bulundu =1;
                          break;
                      }
                  }
              }
              if (bulundu == 0) {
                  printf("boyle bir dosya yok \n");
              }
          }
          printf("\n");
      }
      else if (strcmp(yeni_islem-> komut_adi ,"dosya_sil") == 0 ) {
          if (yeni_islem-> arguman_sayisi < 1) {
              printf("hata :dosya adi giriniz \n");
          }
          else {
              int bulundu = 0;
              for (int i = 0; i < 5; i++) {
                  if (disk[i].dolu_mu == 1) {
                      if (strcmp (yeni_islem-> argumanlar[0], disk[i].isim)==0) {
                          disk[i].dolu_mu =0;
                          strcpy(disk[i].isim , "");
                          strcpy(disk[i].icerik ,  "");
                          bulundu =1;
                          printf("Basarili dosya [%s] silinidi \n" , yeni_islem-> argumanlar[0]);
                          break;
                      }
                  }
              }
              if (bulundu == 0) {
                  printf("silinecek boyle bir dosya yok \n");
              }
          }
      }
      else if (strcmp(yeni_islem-> komut_adi ,"yardim") == 0 ) {
          printf("dir ---> komutlari yazdirir\n"
                        "dosya_olustur ---> dosya olusturmayi sağlar\n"
                        "dosya_sil---> dosya silmeyi saglar\n"
                        "dosya_yaz ---> dosya'nın icine yazmayi saglar\n"
                        "dosya_oku ---> dosyaya yazilanlari okumayi saglar\n"
                        "yazdir ---> ekrana yazdiginiz islemleri tekrar ekrana yazmaya baslar \n"
                        "temizle---> ekrani siler \n"
                        "cikis ---> sistemi kapatmayi saglar \n"
                        "yardim---> sistem komutlarini gösterir\n"
                        );
      }
      else {
          printf("bilinmeyen komut [%s]\n" , yeni_islem-> komut_adi);
      }
      komut_temizle(yeni_islem);
  }
    return 0;
}
