#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERSUCHE 5 /* Anzahl der Versuche. */

int nutzer_eingabe();
void tipp_geben(int eingabe, int zufallszahl);

/* Zahlenraten zwischen 1 und 100.*/
int main() {

    srand(time(0));
    const int zufallszahl = rand()%100;
    
    //Test
    //printf("Gesucht: %d\n", zufallszahl);
    
	printf("Gesucht ist eine zufällige Zahl zwischen 1 und 100. \n");
	printf("Kannst Du sie erraten? Du hast %d Versuche.\n", MAX_VERSUCHE);
    
    int versuche_uebrig = MAX_VERSUCHE;
    
    while(versuche_uebrig) {
        int eingabe = nutzer_eingabe();
        
        if(eingabe == zufallszahl) {
            printf("Richtig. Du hast gewonnen!\n");
            break;
        } else if(--versuche_uebrig > 0) {
            printf("Leider falsch. ");
            tipp_geben(eingabe, zufallszahl);
            
            printf("Noch %d ", versuche_uebrig);
            if(versuche_uebrig > 1) {
                printf("Versuche.\n");
            } else {
                printf("Versuch.\n");             
            }
            
        } else {
            printf("Du hast leider keine Versuche mehr übrig. Gesucht war %d.\n", zufallszahl);
        }
    }
    
    return 0;
}

int nutzer_eingabe() {
    int num;
    int status; /* Eingabe valid: status != 0. */

    while((status = scanf("%d", &num)) != EOF) {
        if(status == 0) {
            printf("Das ist keine Zahl.\n");
            while(getchar() != '\n');
        } else {
            if(num > 0 && num < 100) {
                break;         
            } else {
                printf("Zahl muss > 0 und < 100 sein.\n");               
            }            
        }
    }
    
    return num;
}

void tipp_geben(int eingabe, int zufallszahl) {
    printf("Die gesuchte Zahl ist ");
    if(eingabe < zufallszahl) {
       printf("groesser als %d. ", eingabe);
    } else {
       printf("kleiner als %d. ", eingabe);
    }
}
