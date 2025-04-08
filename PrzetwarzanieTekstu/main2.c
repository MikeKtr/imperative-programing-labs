#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){
    char *tablica = malloc((26 + 26 + 10) * sizeof(char));
    for(int i = 0; i< 26; i++){
        tablica[i] = 97+i;
    }
    for(int i = 0;i< 26;i++){
        tablica[i+26] = 65+i;
    }
    for(int i = 0;i<10;i++){
        tablica[26+26+i] = 48 + i ;
    }
    printf("\n");
    for(int i = 0;i<(26+26+10);i++){
        int j = rand()%(26+26+10);
        char temp = tablica[i];
        tablica[i] = tablica[j];
        tablica[j] = temp;
    }
    for(int i = 0;i<(26+26+10);i++){
        printf("%c" , tablica[i]);
    }
    char slowo1[] = "";
    char slowo2[] = "";
    printf("\npodaj ciąg liter który chcesz zamienić");
    fgets(slowo1,216,stdin);
    printf("\npodaj ciąg na który chcesz zamienić");
    fgets(slowo2,216,stdin);


}