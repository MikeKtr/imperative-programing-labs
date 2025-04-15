#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define max_input 512
#define max_strings 100


void czy_palindrom(char *slowo){
    int i = 0;
    int j = 0;
    while(slowo[j] != '\0'){j++;}
    j--;
    while(slowo[j] == slowo[i]){
        if(j == i || i == j-1){
            printf("WOW, palindrom %s \n" , slowo);
            return;
        }
        i++;
        j--;
    }
}

void usun_znaki(char *slowo){
    int i = 0;
    int j = 0;
    while(slowo[i] != '\0'){
        if(isalpha((char)slowo[i])){
            slowo[j] = slowo[i];
            j++;
        }
        i++;

    }
    slowo[j] = '\0';
}

int main(void){
    bool czy_dalej = true;
   

    


    printf("Podaj nazwe pliku tekstowego: ");
    char nazwa_pliku[50];
    scanf("%s",nazwa_pliku);


    while(czy_dalej){
        char *slowa[max_strings];
        int ile = 0;

        char slowo[max_input];
        bool flag = true;

        while(1){
            printf("podaj słowo: ");
            if(fgets(slowo,max_input,stdin) == NULL){
                break;
            } 
            
            slowo[strcspn(slowo,"\n")] = '\0';

            if(strcmp(slowo,"<STOP>\0") == 0){
                break;
            };

            slowa[ile] = malloc(strlen(slowo) + 1);
            strcpy(slowa[ile],slowo);
            ile+=1;

        }

        int *tablica = malloc(ile * (sizeof(int)));
        for(int i = 0;i<ile;i++){
            tablica[i] = i;
        }


        for(int i = 0;i<ile;i++){
            usun_znaki(slowa[i]);
            czy_palindrom(slowa[i]);

            int j = rand()%(ile);
            int temp = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = temp;
        }

        char znak[] = {'.','!','?'};


        
    FILE *file = fopen(nazwa_pliku,"w");
    if(file == NULL){
        printf("Błąd w odczytywaniu pliku\n");
    }
    else{

        for(int i = 0 ; i < ile; i++){
            
            fputs(" ",file);
            fputs(slowa[tablica[i]],file);
        }
        

    }
    printf("Czy chcesz tworzyć zdania dalej? (tak/nie) ");
    fgets(slowo,4,stdin);
    if(strcmp(slowo,"nie\0") == 0){
        return 0;
    }
    }
}