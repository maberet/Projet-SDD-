#ifndef projet

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "action.h"

#endif

typedef struct sem {
    char anneesemaine[7];
    
    MaillonAct_t *act; 
}Semaine_t;

typedef struct maillon {
    Semaine_t semaine; 

    struct maillon *suiv;
}Maillonsem_t,*Listesem_t;


Listesem_t InitialisationSemaine(void);
Booleen_t ListeSemaineVide(Listesem_t);
Listesem_t InsertionSemaine(Semaine_t, Listesem_t);
void AfficherListeSemaine(Listesem_t);
// Listesem_t LiberationSemaine (Listesem_t);
// void LiberationListeSemaine (Listesem_t);
Listesem_t InsertionDonnees(char *, Listesem_t);
Semaine_t LectureDonnees(FILE *);
void Sauvegarde(char *, Listesem_t);
Booleen_t RechercheSemaineAction(Listesem_t, char [], char[], int, char[]);
Booleen_t SuppressionAction(Listesem_t, char *, char *, int, char *);
Listesem_t SuppressionSemaineEnTete(Listesem_t);
Listesem_t SuppressionMaillonSemaine(Listesem_t, char* , char* );
void LiberationSemaines(Listesem_t);