#include"semaine.h"

/* -------------------------------------------------------------------- */
/* InitialisationSemaine: initialisation de la liste des années et      */
/* des semaines.                                                        */
/*                                                                      */
/* En entrée: Aucune.                                                   */
/*                                                                      */
/* En sortie: Renvoie la liste vide.                                    */
/* -------------------------------------------------------------------- */

Listesem_t InitialisationSemaine (void){
    return NULL;
}



/* -------------------------------------------------------------------- */
/* ListeSemaineVide: vérifie si une liste est vide.                     */
/*                                                                      */
/* En entrée: Liste des semaines.                                       */
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



/* --------------------------------------------------------------------------------- */
/* InsertionenteteSemaine: Insère la structure semaine en tête de la liste semaine.  */
/*                                                                                   */
/* En entrée: Structure semaine, Liste des semaines.                                 */
/*                                                                                   */
/* En sortie: Tête de la liste des semaines.                                         */
/* --------------------------------------------------------------------------------- */

Listesem_t InsertionenteteSem(Semaine_t Sem,Listesem_t Listesem)
{
    Maillonsem_t *m;
    m=(Maillonsem_t*)malloc(sizeof(Maillonsem_t));
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
    while (!ListeSemaineVide(listesem))
    {
        printf("---------------------------------------------\n");
        printf("--------- Année %c%c%c%c \t Semaine %c%c ---------\n",(listesem->semaine).anneesemaine[0],(listesem->semaine).anneesemaine[1],(listesem->semaine).anneesemaine[2],(listesem->semaine).anneesemaine[3],(listesem->semaine).anneesemaine[4],(listesem->semaine).anneesemaine[5]);
        AfficherListeAction((listesem->semaine).act);
        listesem=listesem->suiv;
    }
}



/* -------------------------------------------------------------------------- */
/* LectureDonnees: Ajoute les données du fichier dans la structure semaine.   */
/*                                                                            */
/* En entrée: File.                                                           */
/*                                                                            */
/* En sortie: Structure semaine                                               */
/* -------------------------------------------------------------------------- */

Semaine_t LectureDonnees(FILE * file)
{
    Action_t            act;
    Semaine_t           sem;

    fscanf(file,"%6s %3s %[^\n]%*c",sem.anneesemaine, act.jourheure, act.action);
    sem.act = InsertionAction(act,InitialisationAction());

    return sem;
}



/* ----------------------------------------------------------------------------- */
/* InsertionDonnees: Ajoute les données du fichier dans la liste des semaines.   */
/*                                                                               */
/* En entrée: Nom du fichier, liste des semaines.                                */
/*                                                                               */
/* En sortie: Liste des semaines                                                 */
/* ----------------------------------------------------------------------------- */

Listesem_t InsertionDonnees(char * fichier, Listesem_t listesem)
{
    FILE       * file;
    Semaine_t    sem;

    file = fopen(fichier,"r");

    if (file == NULL)
    {
        printf("Erreur d'ouverture de fichier");
    }
    else
    {
        sem = LectureDonnees(file);
        while(!feof(file))
        {
            listesem = InsertionSemaine(sem,listesem);
            sem = LectureDonnees(file);
        }
    }

    fclose(file);

    return listesem;
}



void Sauvegarde(char * fichier, Listesem_t listesem)
{   
    FILE * file;

    file = fopen(fichier,"w");

    if (file == NULL)
    {
        printf("Erreur d'ouverture de fichier");
    }
    else
    {
        while(!ListeSemaineVide(listesem))
        {
            SauvegardeAction(file, (listesem->semaine).anneesemaine, (listesem->semaine).act);
            listesem = listesem->suiv;
        }
    }

    fclose(file);
}