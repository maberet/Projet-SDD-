#ifndef projet

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "action.h"

#endif
/* -------------------------------Déclaration des structures.---------------------------------------*/
typedef struct sem {
    char anneesemaine[7];                               // Concaténation de l'année et de la semaine. 
    
    MaillonAct_t *act;                                  // Pointeur sur la liste des action. 
}Semaine_t;

typedef struct maillon {
    Semaine_t semaine;                                  // Struture semaine.

    struct maillon *suiv;                               // Pointeur sur la semaine suivante. 
}Maillonsem_t,*Listesem_t;

/* ------------------------------- Déclaration des fonctions.---------------------------------------*/

Listesem_t InitialisationSemaine(void);
Booleen_t ListeSemaineVide(Listesem_t);
Listesem_t InsertionSemaine(Semaine_t, Listesem_t);
void AfficherListeSemaine(Listesem_t);
Listesem_t InsertionDonnees(char *, Listesem_t);
Semaine_t LectureDonnees(FILE *);
void Sauvegarde(char *, Listesem_t);
Booleen_t RechercheSemaineAction(Listesem_t, char [], char[], int, char[]);
Booleen_t SuppressionAction(Listesem_t, char *, char *, int, char *);
Listesem_t SuppressionSemaineEnTete(Listesem_t);
Listesem_t SuppressionMaillonSemaine(Listesem_t, char* , char* );
Listesem_t LiberationSemaines(Listesem_t);

/*---------------------------------------------------------------------------------------------------*/