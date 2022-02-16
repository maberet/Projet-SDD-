#include"semaine.h"

/* -------------------------------------------------------------------- */
/* InitialisationSsemaine: initialisation de la liste des années et     */
/* des semaines.                                                        */
/* En entrée: Rien.                                                     */
/*                                                                      */
/* En sortie: Renvoie la liste vide.                                    */
/* -------------------------------------------------------------------- */

Listesem_t InitialisationSemaine (void){
    return NULL;
}

/* -------------------------------------------------------------------- */
/* ListeSemaineVide: vérifie si une liste est vide.                     */
/*                                                                      */
/* En entrée: Liste.                                                    */
/*                                                                      */
/* En sortie: Renvoie 1 si la liste est vide sinon 0.                   */
/* -------------------------------------------------------------------- */

Booleen_t ListeSemaineVide(Listesem_t listesem)
{
    Booleen_t result = faux;

    if (listesem==NULL)
    {
        result=vrai;
    }
    return (result);
}

/* -------------------------------------------------------------------- */
/* InsertionenteteSemaine: Insère en tête de la liste semaine.          */
/*                                                                      */
/* En entrée: Adresse d'une liste.                                      */
/*                                                                      */
/* En sortie: Renvoie 1 si la liste est vide sinon 0.                   */
/* -------------------------------------------------------------------- */

Listesem_t InsertionenteteSem(Semaine_t Sem,Listesem_t Listesem)
{
    Maillonsem_t *m;
    m=(Maillonsem_t*)malloc(sizeof(Maillonsem_t*));
                                                                 /// question ? " Pas d'écritures de messages d'erreur dans les fonctions de base : la fonction retourne un indicateur ou
                                                                 //  code d'erreur, que le programme appelant interprète et traite."
    if (m==NULL)
    {
        printf("problème d'allocation \n");
        exit(1);
    }
    m->semaine=Sem;
    m->suiv= Listesem;

    return m;
}

/* -------------------------------------------------------------------- */
/* InsertionSemaine: Recherche recursive de l'adresse d'insertion et    */
/* insertion.                                                           */
/*                                                                      */
/* En entrée: Adresse d'une liste.                                      */
/*                                                                      */
/* En sortie: Renvoie 1 si la liste est vide sinon 0.                   */
/* -------------------------------------------------------------------- */

Listesem_t InsertionSemaine (Semaine_t sem,Listesem_t liste)
{
    if (ListeSemaineVide(liste))
    {
        return InsertionenteteSem(sem,liste);
    }
    else
    {
        if (strcmp((liste->semaine).anneesemaine,sem.anneesemaine)>0)
        {
            return InsertionenteteSem(sem,liste);
        }
        else if (strcmp((liste->semaine).anneesemaine,sem.anneesemaine)==0)
        {
            (liste->semaine).act = InsertionAction((sem.act)->action,(liste->semaine).act);
            return liste;
        }
        else
        {
            liste->suiv = InsertionSemaine(sem,liste->suiv);
        }
    }
    return liste;
}

/* Le fichier existe exemple de chaine dans le fichier:202215108TPs de SDD */

/* -------------------------------------------------------------------- */
/* InsertionSemaine: Extraction des informations presente dans un       */
/* fichier et insertion dans une la structure.                          */
/*                                                                      */
/* En entrée: Adresse d'une liste et fichier.                           */
/*                                                                      */
/* En sortie: Renvoie l'adresse de la liste remplie.                    */
/* -------------------------------------------------------------------- */


void AfficherListeSemaine(Listesem_t listesem)
{
    /*printf(" -------------------\n");
    printf("|      LISTE       |\n");
    printf(" -------------------\n");*/
    while (!ListeSemaineVide(listesem))
    {
        printf("------- Année : %c%c%c%c \t Semaine : %c%c -------\n",(listesem->semaine).anneesemaine[0],(listesem->semaine).anneesemaine[1],(listesem->semaine).anneesemaine[2],(listesem->semaine).anneesemaine[3],(listesem->semaine).anneesemaine[4],(listesem->semaine).anneesemaine[5]);
        //AfficherListeAction((listesem->semaine).act);
        listesem=listesem->suiv;
    }
}
