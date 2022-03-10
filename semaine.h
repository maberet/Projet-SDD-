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
Listesem_t InsertionDonnees(char *, Listesem_t);
Semaine_t LectureDonnees(FILE *);
void Sauvegarde(char *, Listesem_t);
Booleen_t RechercheSemaineAction(Listesem_t listesem, char annee[], char sem[], int jour, char heure[]);
Booleen_t SuppressionAction(Listesem_t listesem, char* annee, char* sem, int jour, char* heure);
Listesem_t SuppressionSemaineEnTete(Listesem_t listesem);
Listesem_t SuppressionMaillonSemaine(Listesem_t listesem, char* annee, char* sem);
Listesem_t LiberationSemaines(Listesem_t listesem);
