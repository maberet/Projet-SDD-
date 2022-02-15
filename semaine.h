#ifndef SEMAINE_H
#define SEMAINE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "action.h"

#endif
typedef enum 
{ 
    faux,vrai
}Booleen_t;

typedef struct sem {
    char anneesemaine [6];
    
    MaillonAct_t *act; 
}Semaine_t;

typedef struct maillon {
    Semaine_t semaine; 

    struct maillon *suiv;
}Maillonsem_t,*Listesem_t;



Listesem_t ListesemInit(void);
Booleen_t ListeSemaineVide(Listesem_t);
Listesem_t Insertion(Listesem_t);
Listesem_t ExtractionFichier(FILE *,Listesem_t);