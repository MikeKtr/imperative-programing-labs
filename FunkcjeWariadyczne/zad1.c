#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void najwiekszy(char *lancuchFormatujacy,...){
    va_list args;
    va_start(args,lancuchFormatujacy);

    char *p = lancuchFormatujacy;
    double najwiekszy;
    
    bool czyNajwiekszy = false;

    
    while(*p){
        double liczba;
        if(*p == '%'){
            
            switch(*(++p)){
                case 'x':
                    liczba = (double)va_arg(args,int);
                    
                    break;
                case 'd':
                    liczba = (double)va_arg(args,int);
                    
                break;
                case 'c':
                    va_arg(args,int);
                break;
                case 'f':

                    liczba = va_arg(args,double);
                    
                break;
            }

            if(!czyNajwiekszy){
                najwiekszy = liczba;
                czyNajwiekszy = true;
            }
            if(najwiekszy < liczba){
                najwiekszy = liczba;
            }

        }
        p++;
    }
    printf("Najwiekszy element: %.2f",najwiekszy);}

void sumaISrednia(char *lancuchFormatujacy,...){
    va_list args;
    va_start(args,lancuchFormatujacy);
    
    char *p = lancuchFormatujacy;
    double suma = 0;
    int ile = 0;
    
    while(*p){
        long liczba;    
        if(*p == '%'){
            ile++;
            switch (*(++p)){
            
                case 'd':
                liczba = va_arg(args,int);
                suma += (double)liczba;
                break;

                case 'f':
                double liczbaz = va_arg(args,double);
                suma += liczbaz;
                break;

                case 'c': 
                char *c = va_arg(args,char*);
                printf("To nie jest liczba: %s\n",c);
                break;

                case 'x':
                liczba = va_arg(args,int);
                suma += (double)liczba;
                break;

            }


        
        }
        p++;
    }
    printf("Suma jest rowna: %.2f\n",suma);
    printf("Srednia jest rowna %.2f\n",suma/ile);
}

int main(void){
    // char *slowa[30];
    // // printf("Podaj nazwe pliku z którego należy pobrać dane\n");
    // // char nazwaPliku[100];
    // // scanf("%s",nazwaPliku);
    // int i = 0;
    // FILE *file = fopen("tekst.txt","r");
    // if(file == NULL){
    //     printf("Błąd odczyty pliku\n");
    // }
    // fseek(file,0,SEEK_END);
    // long fsize = ftell(file);
    // fseek(file,0,SEEK_SET);
    // char *string = malloc(fsize + 1);
    // fread(string,fsize,1,file);
    // fclose(file);
    // for(int i = 0; i < fsize; i ++){
    //     printf("%c",string[i]);
    // }

    sumaISrednia("%f %f %f",1.4,16.0,12.2);
    najwiekszy("%d %c %x %f",12,'s',0xFE,30.3);
    return 0;
}