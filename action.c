#include <stdlib.h>
#include <stdio.h>
#include"action.h"
#include"semaine.h"

/*-----------------------------------------------------
InitialisationAction : Initialise la liste des actions.

Entrée : Rien.

Sortie : Liste d'actions vide.
-----------------------------------------------------*/

Listeaction_t InitialisationAction(void){
    return NULL;
} 



/*--------------------------------------------------
ListeActionVide : Teste si la liste est vide ou non.

Entrée : Liste d'actions.

Sortie : 1 si elle est vide, 0 sinon.
--------------------------------------------------*/

int ListeActionVide(Listeaction_t listeact){
    
    int result = 0;

    if (listeact == NULL){
        result = 1;
    }

    return result;
}



/*---------------------------------------------------------------------------------
InsertionEnTeteAction : Insère en tête de liste la structure d'actions en paramètre

Entrée : Structure d'actions act, Liste d'actions listeact.

Sortie : Liste d'actions mise à jour.
---------------------------------------------------------------------------------*/

Listeaction_t InsertionEnTeteAction(Action_t act, Listeaction_t listeact){
   
    MaillonAct_t *m;
    m = (MaillonAct_t *)malloc(sizeof(MaillonAct_t));

    if (m == NULL){
        printf("Erreur d'allocation");
    }
    else{
        m->action = act;
        m->suiv = listeact;
    }

    return m;
}



/*-----------------------------------------------------------------------------
InsertionAction : Insère la structure d'actions à la bonne place dans la liste.

Entrée : Structure d'actions act, Liste d'actions listeact.

Sortie : Liste d'actions listeact.
-----------------------------------------------------------------------------*/

Listeaction_t InsertionAction(Action_t act,Listeaction_t listeact){
    
    if (ListeActionVide(listeact)){
        InsertionEnTeteAction(act,listeact);
    }
    if ((listeact->action).jourheure > act.jourheure){
        InsertionEnTeteAction(act,listeact);
    }
    else{
        InsertionAction(act,listeact->suiv);
    }

    return listeact;
}

