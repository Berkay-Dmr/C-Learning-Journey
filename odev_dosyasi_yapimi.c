#include <stdio.h>
int main(void) {
    FILE *belge;
    char okunan[100];
    belge = fopen("isim.txt","w");
    fprintf(belge,"Hello World\n");
    fclose(belge);
    belge =fopen ("isim.txt","r");
    if (belge == NULL) {
        printf("Error");
        return 1;
    }
    while (fgets (okunan, 100, belge) != NULL){
        printf("= %s" ,okunan);
    }
    fclose(belge);
    return 0;
}#include <stdio.h>
int main(void) {
    FILE *belge;
    char okunan[100];
    belge = fopen("isim.txt","w");
    fprintf(belge,"Hello World\n");
    fclose(belge);
    belge =fopen ("isim.txt","r");
    if (belge == NULL) {
        printf("Error");
        return 1;
    }
    while (fgets (okunan, 100, belge) != NULL){
        printf("= %s" ,okunan);
    }
    fclose(belge);
    return 0;
}#include <stdio.h>
int main(void) {
    FILE *belge;
    char okunan[100];
    belge = fopen("isim.txt","w");
    fprintf(belge,"Hello World\n");
    fclose(belge);
    belge =fopen ("isim.txt","r");
    if (belge == NULL) {
        printf("Error");
        return 1;
    }
    while (fgets (okunan, 100, belge) != NULL){
        printf("= %s" ,okunan);
    }
    fclose(belge);
    return 0;
}#include <stdio.h>
int main(void) {
    FILE *belge;
    char okunan[100];
    belge = fopen("isim.txt","w");
    fprintf(belge,"Hello World\n");
    fclose(belge);
    belge =fopen ("isim.txt","r");
    if (belge == NULL) {
        printf("Error");
        return 1;
    }
    while (fgets (okunan, 100, belge) != NULL){
        printf("= %s" ,okunan);
    }
    fclose(belge);
    return 0;
}