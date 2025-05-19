#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define ARR_LEN 256

/*
Die erste Struktur enthält zwei int's:
Den Wert der Zahl sowie einen Zähler, wie oft diese Zahl bisher vorkam.
*/
typedef struct firststruct {
    int value;
    int counter;
}firststruct;

/*
Die zweite Struktur enthält ein Array von solchen Wert/Zähler-Paaren
(das Array darf wieder eine fixe, mittels Konstante festgelegte Größe haben)
sowie einen int für die Anzahl der in diesem Array aktuell gespeicherten Werte
(belegten Elemente).
*/
typedef struct secondstruct {
    firststruct *arr[ARR_LEN]; 
    int curr_saved;
}secondstruct;

/*
Die Funktion suche wird mit einer solchen Array-Struktur (als Referenz)
und einem int-Wert aufgerufen. Sie sucht den Wert im Werte-Array der Struktur.
Findet sie ihn, gibt sie eine Referenz auf das dazugehörige Wert/Zähler-Paar zurück.
Findet sie den Wert nicht, hängt sie ihn hinten an (prüfen, ob noch Platz ist, und
Anzahl der belegten Elemente erhöhen!), setzt den dazugehörigen Zähler auf 0,
und liefert eine Referenz auf dieses frisch initialisierte Wert/Zähler-Paar.
*/
firststruct suche(secondstruct *sstruct, int tosearch){
    //suche Wert tosearch in der Array in secondstruct 
    for(int i = 0; i < ARR_LEN; i++){
        if(tosearch == sstruct->arr[i]->value){
            firststruct rstruct = {sstruct->arr[i]->value};
            return rstruct;
        }
    }
    //ab hier nicht gefunden
    if(sstruct->curr_saved < ARR_LEN){ //256 für '\0' BSP.(12,34,45,23,'\0')
        (sstruct->curr_saved)++;
        sstruct->arr[sstruct->curr_saved]->counter = 0;
        sstruct->arr[sstruct->curr_saved]->value = tosearch;
    }else{
        //kein Platz mehr im Array
    }  
}

void drucke(secondstruct *sstruct){
    for(int i = 0; i != sstruct->curr_saved++; i++){
    std::cout << "Value" << sstruct->arr[i]->value;
    std::cout << "Amount" << sstruct->arr[i]->counter;
    std::cout << "\n";
    } 
}

int main(int argc, char *argv[]){
    secondstruct mystruct[ARR_LEN];
    for(int i = 1; i < argc; i++){
        suche(mystruct, atoi(argv[i])).counter++;
    }
    drucke(mystruct);
}
