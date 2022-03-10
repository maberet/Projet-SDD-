#include "action.h"

/* ----------------------------------------------------------------------------------------------------------------- */
/*                              InitialisationAction : Initialise la liste des actions.                              */
/*                                                                                                                   */
/*                              En entrée : Aucune.                                                                  */
/*                                                                                                                   */
/*                              En sortie : Liste d'actions vide.                                                    */
/* ----------------------------------------------------------------------------------------------------------------- */

Listeaction_t InitialisationAction(void)
{
    return NULL;
}



/* ----------------------------------------------------------------------------------------------------------------- */
/*                              ListeActionVide : Teste si la liste est vide ou non.                                 */
/*                                                                                                                   */
/*                              En entrée : Liste d'actions listeact.                                                */
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
    m = (MaillonAct_t *)malloc(sizeof(MaillonAct_t)); // on alloue un maillon.

    if (m == NULL)
    {
        printf("Erreur d'allocation");
    }
    else
    {
        m->action = act; // on ajoute l'action dans le maillon.
        m->suiv = listeact; // on fait pointer le suivant du maillon sur la liste.
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
        return InsertionEnTeteAction(act,listeact); // si la liste est vide, on insère en tête.
    }
    if (strcmp((listeact->action).jourheure,act.jourheure) > 0) // si la chaine jourheure du maillon à ajouter est plus petite que celle de la liste:
    {
        return InsertionEnTeteAction(act,listeact); // on insère devant.
    }
    else
    {
        listeact->suiv = InsertionAction(act,listeact->suiv); // sinon on passe au suivant.
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



/* ----------------------------------------------------------------------------------------------------------------- */
/*                              SauvegardeAction : Sauvegarde la liste des actions dans                              */
/*                                                un fichier donné                                                   */
/*                                                                                                                   */
/*                              En enntrée : Liste d'actions listeact, chaine anneesemaine, fichier file.            */
/*                                                                                                                   */
/*                              En sortie : aucune.                                                                  */
/* ----------------------------------------------------------------------------------------------------------------- */

void SauvegardeAction(FILE * file, char * anneesemaine, Listeaction_t listeact)
{
    while(!ListeActionVide(listeact))
    {
        fprintf(file, "%s%s%s\n", anneesemaine, (listeact->action).jourheure, (listeact->action).action); // on insère les données dans le fichier voulu.
        listeact = listeact->suiv; // on passe au suivant.
    }
}



/* ----------------------------------------------------------------------------------------------------------------- */
/*                              RechercheAction : Recherche si une action est présente                               */
/*                                                dans la liste ou non.                                              */
/*                                                                                                                   */
/*                              En enntrée : Liste d'actions listeact, entier jour, chaine heure.                    */
/*                                                                                                                   */
/*                              En sortie : Booléen.                                                                 */
/* ----------------------------------------------------------------------------------------------------------------- */

Booleen_t RechercheAction(Listeaction_t listeact, int jour, char heure[])
{   
    Booleen_t resultat = faux;
    char            jr[2];
    char            jourhr[4];

    sprintf(jr, "%d", jour);
    strcpy(jourhr,jr);
    strcat(jourhr,heure); // on concatène le jour et l'heure pour être accordé avec la structure.

    while(listeact!=NULL)
    {
        if(strcmp((listeact->action).jourheure,jourhr) == 0) 
        {
            resultat = vrai; // si l'action est présente, on renvoie vrai.
        }
        listeact=listeact->suiv;
    }

    return resultat;
}



/* ----------------------------------------------------------------------------------------------------------------- */
/*                              SuppressionActionEnTete : Supprime l'action en tête de liste.                        */
/*                                                                                                                   */
/*                              En enntrée : Liste d'actions listeact.                                               */
/*                                                                                                                   */
/*                              En sortie : Liste d'actions listeact.                                                */
/* ----------------------------------------------------------------------------------------------------------------- */

Listeaction_t SuppressionActionEnTete(Listeaction_t listeact)
{
    MaillonAct_t *ActionTemp; // maillon temporaire.
    if(ListeActionVide(listeact)) // cas d'erreur.
    {
        printf("Liste vide");
        exit(1);
    }
    ActionTemp = listeact; // on récupère la tête de liste.
    listeact = listeact->suiv; // on passe au suivant.
    free(ActionTemp); // on libere le maillon en tete.
    return listeact;
}



/* ----------------------------------------------------------------------------------------------------------------- */
/*                              SuppressionMaillonAction: Supprime l'action voulue dans la liste,                    */
/*                                               à l'aide des paramètres.                                            */
/*                                                                                                                   */
/*                              En enntrée : Liste d'actions listeact, entier jour, chaine heure.                    */
/*                                                                                                                   */
/*                              En sortie : Liste d'actions listeact.                                                */
/* ----------------------------------------------------------------------------------------------------------------- */

Listeaction_t SuppressionMaillonAction(Listeaction_t listeact, int jour, char* heure)
{   
    char            jr[2];
    char            jourhr[4];

    sprintf(jr, "%d", jour);
    strcpy(jourhr,jr);
    strcat(jourhr,heure);
    printf ("jourhr: %s\n", jourhr);

    if(ListeActionVide(listeact)) // si la liste est vide:
        return listeact; // on retourne la liste.
    if(strcmp((listeact->action).jourheure, jourhr)>0) // si le jourheure supérieur au jour voulu, l'action n'est pas dans la liste:
        return listeact; // on retourne la liste.
    if(strcmp((listeact->action).jourheure, jourhr) == 0) // si la tete vaut l'action voulue:
        return SuppressionActionEnTete(listeact); // on la supprime.

    listeact->suiv=SuppressionMaillonAction(listeact->suiv, jour, heure); // appel recursif

    return listeact;
}



/* ----------------------------------------------------------------------------------------------------------------- */
/*                              LiberationListeActions: Supprime toutes les actions de la liste.                     */
/*                                                                                                                   */
/*                              En enntrée : Liste d'actions listeact.                                               */
/*                                                                                                                   */
/*                              En sortie : aucune.                                                                  */
/* ----------------------------------------------------------------------------------------------------------------- */

void LiberationListeActions(Listeaction_t listeact)
{
    while(!ListeActionVide(listeact)) // Tant que la liste n'est pas vide:
    {
        listeact = SuppressionActionEnTete(listeact); // on supprime l'action en tête.
    }
}
