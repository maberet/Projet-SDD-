#include "action.h"

/* ----------------------------------------------------------------------------------------------------------------- */
/*                              InitialisationAction : Initialise la liste des actions.                              */
/*                                                                                                                   */
/*                              En entrée : Aucune.                                                                  */
/*                                                                                                                   */
/*                              En sortie : Liste d'actions vide.                                                    */
/* ----------------------------------------------------------------------------------------------------------------- */

Listeaction_t InitialisationAction (void)
{
    return NULL;
}



/* ----------------------------------------------------------------------------------------------------------------- */
/*                              ListeActionVide : Teste si la liste est vide ou non.                                 */
/*                                                                                                                   */
/*                              En entrée : Liste d'actions.                                                         */
/*                                                                                                                   */
/*                              En sortie : 1 si elle est vide, 0 sinon.                                             */
/* ----------------------------------------------------------------------------------------------------------------- */

Booleen_t ListeActionVide(Listeaction_t listeact)
{
    Booleen_t result = faux;

    if (listeact==NULL)
    {
        result=vrai;
    }
    return (result);
}



/* ----------------------------------------------------------------------------------------------------------------- */
/*                              InsertionEnTeteAction : Insère en tête de liste la structure                         */
/*                                            d'actions en paramètre                                                 */
/*                                                                                                                   */
/*                              En entrée : Structure d'actions act, Liste d'actions listeact.                       */
/*                                                                                                                   */
/*                              En sortie : Liste d'actions mise à jour.                                             */
/* ----------------------------------------------------------------------------------------------------------------- */

Listeaction_t InsertionEnTeteAction(Action_t act, Listeaction_t listeact)
{

    MaillonAct_t *m;
    m = (MaillonAct_t *)malloc(sizeof(MaillonAct_t));

    if (m == NULL)
    {
        printf("Erreur d'allocation");
    }
    else
    {
        m->action = act;
        m->suiv = listeact;
    }

    return m;
}



/* ----------------------------------------------------------------------------------------------------------------- */
/*                              InsertionAction : Insère la structure d'actions à la bonne                           */
/*                                            place dans la liste.                                                   */
/*                                                                                                                   */
/*                              Entrée : Structure d'actions act, Liste d'actions listeact.                          */
/*                                                                                                                   */
/*                              Sortie : Liste d'actions listeact.                                                   */
/* ----------------------------------------------------------------------------------------------------------------- */

Listeaction_t InsertionAction(Action_t act,Listeaction_t listeact)
{
    if (ListeActionVide(listeact))
    {
        return InsertionEnTeteAction(act,listeact);
    }
    if (strcmp((listeact->action).jourheure,act.jourheure) > 0)
    {
        return InsertionEnTeteAction(act,listeact);
    }
    else
    {
        listeact->suiv = InsertionAction(act,listeact->suiv);
    }

    return listeact;
}



/* ----------------------------------------------------------------------------------------------------------------- */
/*                              AfficherListeAction : Affiche la liste des actions                                   */
/*                                                                                                                   */
/*                              En enntrée : Liste d'actions listeact.                                               */
/*                                                                                                                   */
/*                              En sortie : aucune.                                                                  */
/* ----------------------------------------------------------------------------------------------------------------- */

void AfficherListeAction(Listeaction_t listeact)
{

    while (!ListeActionVide(listeact))
    {
        printf("Jour : %c \t Heure : %c%ch\n", (listeact->action).jourheure[0],(listeact->action).jourheure[1],
            (listeact->action).jourheure[2]);
        printf("Action : %s\n", (listeact->action).action);
        printf("---------------------------------------------\n");
        listeact = listeact->suiv;
    }
}

// Listeaction_t SuppressionAction (Listeaction_t listeactprec)
// {
//     Listeaction_t           temp; 

//     temp=(listeactprec->suiv)->suiv;
//     free(listeactprec->suiv);
//     listeactprec->suiv=temp;
//     return (listeactprec);
// }

// void LiberationListeAction (Listeaction_t listeact) //listeact est le maillon source de la liste action. 
// {
//     while (!ListeActionVide(listeact)&&(!ListeActionVide(listeact->suiv)))
//     {
//         listeact=SuppressionAction(listeact); //supprime le suivant
//     }
//     free (listeact);
// }

void SauvegardeAction(FILE * file, char * anneesemaine, Listeaction_t listeact)
{
    while(!ListeActionVide(listeact))
    {
        fprintf(file, "%s%s%s\n", anneesemaine, (listeact->action).jourheure, (listeact->action).action);
        listeact = listeact->suiv;
    }
}

Booleen_t RechercheAction(Listeaction_t listeact, int jour, char heure[])
{   
    Booleen_t resultat = faux;
    char            jr[2];
    char            jourhr[4];

    sprintf(jr, "%d", jour);
    strcpy(jourhr,jr);
    strcat(jourhr,heure);


    while(listeact!=NULL)
    {
        if(strcmp((listeact->action).jourheure,jourhr) == 0) 
        {
            resultat = vrai;
        }
        listeact=listeact->suiv;
    }
    return resultat;
}

Listeaction_t SuppressionActionEnTete(Listeaction_t listeact)
{
    MaillonAct_t *ActionTemp; // Maillon temporaire qui va permettre de supprimer la tête de liste 
    if(ListeActionVide(listeact)) // si la liste est vide on ne peut rien supprimer, c'est un cas d'erreur
    {
        printf("Suppression d'une action sur une liste vide, operation interdite");
        exit(1);
    }
    ActionTemp = listeact; // recuperation de l'action en tête de liste
    listeact = listeact->suiv; // on avance la liste sur le maillon suivant
    free(ActionTemp); // on libere le maillon en tete
    return listeact;
}

Listeaction_t SuppressionMaillonAction(Listeaction_t listeact, int jour, char* heure)
{   
    Action_t        actionTemp = listeact->action;
    char            jr[2];
    char            jourhr[4];

    sprintf(jr, "%d", jour);
    strcpy(jourhr,jr);
    strcat(jourhr,heure);

    if(ListeActionVide(listeact)) // si la liste est vide, on retourne la liste
        return listeact;
    if(actionTemp.jourheure > jourhr) // jour et heure en tete > au jour voulu -> action pas dans la liste
        return listeact;
    if(strcmp(actionTemp.jourheure, jourhr) == 0) // si la tete vaut l'action voulue
        return SuppressionActionEnTete(listeact); // on la supprime

    listeact->suiv=SuppressionMaillonAction(listeact->suiv, jour, heure); // appel recursif
    return listeact;
}



void LiberationListeActions(Listeaction_t listeact)
{

    while(!ListeActionVide(listeact))
    {
        listeact = SuppressionActionEnTete(listeact);
    }
}