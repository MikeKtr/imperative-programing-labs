#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define ILOSC_HASEL 100
#define DLUGOSC_HASLA 100
#define MAX_ILOSC_HASEL 100

    

int main(void){
    
    FILE *file = fopen("plikiTekstowe/Hasla_KF.txt", "r");
    if(file == NULL){
        printf("Błąd odczytu\n");
        return 1;
    }

    // char buffor[BUFSIZ];

    // setvbuf(hasla,buffor,_IOLBF,1024);

    char *hasla[ILOSC_HASEL];
    int ile = 0;
    char linia[DLUGOSC_HASLA];
    while(fgets(linia,DLUGOSC_HASLA,file)!=NULL){
        
        hasla[ile] = malloc(strlen(linia));
        strcpy(hasla[ile],linia);
    
        ile+=1;
        // printf("%s ",linia);
    }
    


    char *haslo = hasla[rand()%ILOSC_HASEL-4];

    int liczbaGraczy = 0;
    char gracze[5][DLUGOSC_HASLA];
    int punkty[5] = {0,0,0,0,0};
    int tura = 1;
    int punkt = 0;

    printf("Witaj w KOLE FORTUNY. Podaj liczbę graczy(1-4): ");
    scanf(" %d",&liczbaGraczy);
    printf("\n");

    int j = 0;
    
    for(j = 0; j <= liczbaGraczy; j++){
        if(j == 0) {
        fgets(gracze[j],DLUGOSC_HASLA,stdin);
        continue;
        }
        printf("Podaj imie gracza nr %d: ",j);
        fgets(gracze[j],DLUGOSC_HASLA,stdin);
    }

    j = 0;

    int len = 0;
    while(haslo[j] != '\0'){
        len++;
        j++;
    }
    
    char *wynik = malloc(len * sizeof(char));
    
    j = 0;

    fflush(stdin);

    for(int i = 0; i<strlen(haslo)-1;i++){
        if(haslo[j] == ' ') wynik[j] = ' ';
        else                wynik[j] = '_';
        j++;
    }
    
    wynik[j] = '\0';
    
    j = 0;

    
    
    char guess = '#';
    do{
        j = 0;
        
        printf("Tura gracza: %d ", tura);
        j = 0;
        while(gracze[tura][j] != '\0'){printf("%c",gracze[tura][j]);j++;}
        
        
        printf("Podaj literę ('/' zakańcza ): ");
        scanf(" %c",&guess);
        
        
        for(char *p = strchr(haslo,guess);p != NULL; p = strchr(p + 1,guess)){
            wynik[p - haslo] = guess;
            punkt += 1;
        }
        
        punkty[tura] += punkt;

    printf("Zdobywasz %d pkt!\n",punkt);
    if(punkt == 0){
        tura = ((tura)%liczbaGraczy) + 1;
    }
    punkt = 0;

    j = 0;
    while(wynik[j] != '\0'){
        printf("%c", wynik[j]);
        j++;
    }
    printf("\n");


    while(wynik[j] != '\0'){
        printf("%c", wynik[j]);
        j++;
    }


    
    }while(guess != '/');


    printf("Oto tabela wyników: \n");
    for(j = 1;j<=liczbaGraczy;j++){
        printf("%s%d\n",gracze[j],punkty[j]);
    }

    return 0;
}