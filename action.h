#ifndef projet

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#endif 

typedef enum 
{ 
    faux,vrai
}Booleen_t;

typedef struct action 
{
    char jourheure[4];
    char action[11];
} Action_t;

typedef struct maillonact_t
{
    Action_t              action;
    struct maillonact_t * suiv;
} MaillonAct_t,*Listeaction_t; 

Listeaction_t InitialisationAction(void);
Booleen_t ListeActionVide(Listeaction_t);
Listeaction_t InsertionEnTeteAction(Action_t, Listeaction_t);
Listeaction_t InsertionAction(Action_t, Listeaction_t);
void AfficherListeAction(Listeaction_t);
void SauvegardeAction(FILE *, char *, Listeaction_t);
Booleen_t RechercheAction(Listeaction_t, int, char[]);
Listeaction_t SuppressionActionEnTete(Listeaction_t );
Listeaction_t SuppressionMaillonAction(Listeaction_t, int, char*);
void LiberationListeActions(Listeaction_t);
