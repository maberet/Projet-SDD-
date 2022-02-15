#include "action.h"
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

Booleen_t ListeSemaineVide(Listesem_t liste) 
{
    Booleen_t result = faux; 

    if (liste==NULL)
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
    m=(Maillonsem_t*)malloc(sizof(Maillonsem_t*));
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
        InsertionenteteSem(sem,liste);
    }
    else 
    {
        if (strcmp((liste->semaine).anneesemaine,sem.anneesemaine)>0)
        {
            InsertionSemaine (sem,liste->suiv);
        }
        else if (strcmp((liste->semaine).anneesemaine,sem.anneesemaine)==0)
        {
            InsertionAction(sem.act,(liste->semaine).act);
        }
        else
        {
            InsertionenteteSem(sem,liste);
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

Listesem_t ExtractionFichier (FILE * file,Listesem_t liste)
{ 
    Action_t           * act; 
    Semaine_t            sem; 
    FILE               * fichier =NULL;
    
    fichier=fopen(file,'r'); 

    if (fichier!= NULL)
    {
        while (! feof(fichier))
        {
            fscanf(file,"%6s %3s %[^\n]%*c",sem.anneesemaine,act->jourheure,act->action);
            sem.act=act; 
            liste=InsertionSemaine(sem,liste); 
        } 
    }
    fclose(fichier); 
    return liste;
}
