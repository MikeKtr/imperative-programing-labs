#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME 50

enum rodzajOferty{sprzedaz,wyporzyczenie,wizyta};

void clear (void)
{
    while ( getchar() != '\n' );
}

struct dzielo{
    int ID;
    char nazwa[MAX_NAME];
    int rok;
    enum rodzajOferty oferta;
    double koszt;
    bool dostepnosc;
};

int liczbaRekordow(){
    struct dzielo k1;
    int i =0;
    FILE *file = fopen("plikiTekstowe/bazaDanych.txt","r");
    if(file == NULL){
        printf("Błąd otwarcia pliku");
        return 0;
    }
    while(fread(&k1,sizeof(struct dzielo),1,file) != NULL){
        i++;
    }
    return i;
}


bool dodajRekord(){
    printf("Wybrano dodawanie rekordu\n");


    FILE *file = fopen("plikiTekstowe/bazaDanych.txt","ab");
    if(file == NULL){
        printf("Błąd otwarcia pliku");
        return 1;
    }


    struct dzielo d1;
    d1.ID = liczbaRekordow() + 1;

    clear();

    printf("Podaj nazwe: ");
    fgets(d1.nazwa,MAX_NAME,stdin);
    d1.nazwa[strcspn(d1.nazwa,"\n")] = 0;
    printf("Podaj rok: ");
    scanf("%d",&d1.rok);
    printf("Podaj numer oferty (1.sprzedarz 2.kupno 3.wypozyczenie): ");
    scanf("%d",&d1.oferta);
    printf("Podaj koszt: ");
    scanf("%d",&d1.koszt);


    int temp = 0;
    printf("Podaj dostepnosc (1,0): ");
    scanf("%d",&temp);
    d1.dostepnosc = temp;


    fwrite(&d1,sizeof(d1),1,file);
    
    fclose(file);

    printf("pomyslnie dodano rekord!");
    return true;
}

bool edytujRekord(){
    printf("Liczba rekordów: %d\n", liczbaRekordow());
    printf("Podaj nr. rekordu który chcesz edytować: ");
    int choice = 0;
    scanf("%d",&choice);
    if(choice > liczbaRekordow())return 0;

}

bool wyswietlRekord(){
    printf("Liczba rekordów: %d\n", liczbaRekordow());
    printf("Podaj nr. rekordu który chcesz wyświetlić: ");
    int choice = 0;
    scanf("%d",&choice);

    struct dzielo d1;

    FILE *file = fopen("plikiTekstowe/bazaDanych.txt","r");
    if(file == NULL){
        printf("Bład otwarcia pliku");
        return 0;
    }

    for(int i = 0; i < choice && i < liczbaRekordow();i++){
        fread(&d1,sizeof(struct dzielo),1,file);
        printf("ID: %d \n",d1.ID);
        printf("Nazwa: %s \n",d1.nazwa);
        printf("Rok: %i \n",d1.rok);
        printf("Koszt: %d \n",d1.koszt);
        printf("Dostepność: %d \n",d1.dostepnosc);
    }

}

bool wyswietlWszystkie(){
    printf("Liczba rekordów: %d\n", liczbaRekordow());
    
    struct dzielo d1;
    
    FILE *file = fopen("plikiTekstowe/bazaDanych.txt","r");
    if(file == NULL){
        printf("Bład otwarcia pliku");
        return 0;
    }

    for(int i = 0;i < liczbaRekordow();i++){
        fread(&d1,sizeof(struct dzielo),1,file);
        printf("%d.",d1.ID);
        printf("%s \n",d1.nazwa);
    }
}

int wypiszMenu(){
    int opcja = 0;
    printf("========Baza Danych========\n");
    printf("Liczba rekordów: %d\n", liczbaRekordow());
    printf("1.Dodaj rekord\n");
    printf("2.Wyświetl rekord\n");
    printf("3.Edytuj Rekord\n");
    printf("4.Wyświetl wszystkie rekordy\n");
    printf("5.Zakończ\n");
    printf("Wybierz obcje: ");
    scanf("%d",&opcja);
    printf("\n");
    return opcja;
}

int main(void){
   while(1){ liczbaRekordow();
    switch(wypiszMenu()){
        case 1:
        dodajRekord();
        break;
        case 2:
        wyswietlRekord();
        break;
        case 3:
        // edytujRekord();
        break;
        case 4:
        wyswietlWszystkie();
        break;
        case 5:
        return 0;
        break;
    }
}
    return 0;
}