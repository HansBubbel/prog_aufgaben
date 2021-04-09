#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERSUCHE 20
#define BEREICHS_ANFANG 1
#define BEREICHS_ENDE 100

int zahl_raten();

/* Zahlenraten zwischen BEREICHS_ANFANG und BEREICHS_ENDE.*/
int main() {

    srand(time(0));
    const int gesuchte_zahl = (rand() % (BEREICHS_ENDE - BEREICHS_ANFANG + 1)) + BEREICHSANFANG;

	printf("Das Program soll eine Zahl zwischen ");
	printf("%d und %d raten. \n", BEREICHS_ANFANG, BEREICHS_ENDE);
	printf("Gesucht ist die Zahl %d.\n", gesuchte_zahl);
    
    int versuch, bereichs_breite, test_zahl, aprox, erfolg;
    int zahlenbereich[2] = {BEREICHS_ANFANG, BEREICHS_ENDE};
    versuch = 1;
    bereichs_breite = zahlenbereich[1] + 1 - zahlenbereich[0];
    test_zahl = bereichs_breite / 2;
    aprox = bereichs_breite / 2;
    erfolg = 0;

    while(versuch < MAX_VERSUCHE) {
    
        aprox = aprox > 1 ? aprox / 2 : 1;
             
        printf("%d ", test_zahl);
        if(test_zahl == gesuchte_zahl) {
            printf("gefunden!\n");
            erfolg = 1;
            break;
        } else if(test_zahl < gesuchte_zahl) {
            test_zahl += aprox;
            printf("ist kleiner als n.\n");
            zahlenbereich[1] = test_zahl;
        } else if(test_zahl > gesuchte_zahl) {
            test_zahl -= aprox;
            printf("ist größer als n.\n");
            zahlenbereich[0] = test_zahl;
        }
        
        //printf("AP: %d BA: %d BE: %d\n", aprox, zahlenbereich[0], zahlenbereich[1]);

        ++versuch;
    }
    
    if(erfolg) {
      printf("Zahl wurde mit %d Versuchen gefunden.\n", versuch);  
    } else {
      printf("Zahl wurde nicht innerhalb von %d gefunden.", MAX_VERSUCHE);        
    }

    return 0;
}

