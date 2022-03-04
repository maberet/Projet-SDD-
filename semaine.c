#include"semaine.h"

/* -------------------------------------------------------------------- */
/* InitialisationSemaine: initialisation de la liste des années et      */
/* des semaines.                                                        */
/*                                                                      */
/* En entrée: Aucune.                                                   */
/*                                                                      */
/* En sortie: Renvoie la liste vide.                                    */
/* -------------------------------------------------------------------- */

Listesem_t InitialisationSemaine (void)
{
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



/* -------------------------------------------------------------------- */
/* AfficherListeSemaine: Affiche la liste des années/semaine et appelle */
/* la fonction d'affichage des actions.                                 */
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
// A faire !! 
/* -------------------------------------------------------------------- */
/* LibérationSemaine: Affiche la liste des années/semaine et appelle    */
/* la fonction d'affichage des actions.                                 */
/*                                                                      */
/* En entrée: Adresse d'une liste et fichier.                           */
/*                                                                      */
/* En sortie: Renvoie l'adresse de la liste remplie.                    */
/* -------------------------------------------------------------------- */

// Listesem_t LiberationSemaine (Listesem_t listeprec)
// {
//     Listesem_t              temp;


//     LiberationListeAction(((listeprec->suiv)->semaine).act);
//     temp=(listeprec->suiv)->suiv;
//     free ((listeprec->suiv)->suiv);
//     listeprec->suiv=temp; 
//     return listeprec; 
// }

// A faire !! 
/* -------------------------------------------------------------------- */
/* LibérationSemaine: Affiche la liste des années/semaine et appelle    */
/* la fonction d'affichage des actions.                                 */
/*                                                                      */
/* En entrée: Adresse d'une liste et fichier.                           */
/*                                                                      */
/* En sortie: Renvoie l'adresse de la liste remplie.                    */
/* -------------------------------------------------------------------- */

// void LiberationListeSemaine (Listesem_t listesem)
// {
//      while (!ListeSemaineVide(listesem)&&(!ListeSemaineVide(listesem->suiv)))
//     {
//         listesem=LiberationSemaine(listesem); // supprime le suivant
//     }
//     LiberationListeAction((listesem->semaine).act);
//     free (listesem);
// }


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

Booleen_t RechercheSemaineAction(Listesem_t listesem, char annee[], char sem[], int jour, char heure[])
{
    Booleen_t       resultat = faux;
    char            anneesem[7];

    strcpy(anneesem,annee);
    strcat(anneesem,sem);
    while(listesem!=NULL)
    {
        if(strcmp((listesem->semaine).anneesemaine, anneesem) == 0) // si on trouve la semaine voulue
        {
            resultat = RechercheAction((listesem->semaine).act, jour, heure);
        }
        listesem=listesem->suiv;
    }
    return resultat;
}

Booleen_t SuppressionAction(Listesem_t listesem, char* annee, char* sem, int jour, char* heure)
{   
    Booleen_t       Validation = faux; // permet de savoir si l'action a été supprimée quand on parcours la liste
    char            anneesem[7];

    strcpy(anneesem,annee);
    strcat(anneesem,sem);

    if(RechercheSemaineAction(listesem, annee, sem, jour, heure)) // si l'action existe dans la liste
    {
        while(listesem!=NULL)
        {
            if(strcmp((listesem->semaine).anneesemaine, anneesem) == 0) // si on trouve la semaine voulue
            {
                (listesem->semaine).act = SuppressionMaillonAction((listesem->semaine).act, jour, heure); // suppression de l'action dans la liste d'actions
                Validation = ListeActionVide((listesem->semaine).act); // si la liste des actions est vide après suppression on notifie que l'on doit supprimer la semaine de la liste
            }
            listesem = listesem->suiv;
        }
        printf("La suppression a ete effectuee\n");
    }
    else{
        printf("L'action a supprimer n'existe pas\n");
    }

    return Validation;
}

Listesem_t SuppressionSemaineEnTete(Listesem_t listesem)
{
    Maillonsem_t        *SemTemp; // Maillon temporaire qui va permettre de supprimer la tête de liste 
    
    if(ListeSemaineVide(listesem)) // si la liste est vide on ne peut rien supprimer, c'est un cas d'erreur
    {
        printf("Suppression d'une semaine sur une liste vide, operation interdite");
        exit(1);
    }
    SemTemp = listesem; // recuperation de la semaine en tête de liste
    listesem = listesem->suiv; // on avance la liste sur le maillon suivant
    free(SemTemp); // on libere le maillon en tete
    return listesem;
}

Listesem_t SuppressionMaillonSemaine(Listesem_t listesem, char* annee, char* sem)
{   
    Semaine_t       Temp;
    char            anneesem[7];

    strcpy(anneesem,annee);
    strcat(anneesem,sem);

    if(ListeSemaineVide(listesem)) // si la liste est vide, on retourne la liste
        return listesem;
    Temp = listesem->semaine;

    if(strcmp(Temp.anneesemaine, anneesem)>0) // si l'annee en tete est > a l'annee voulue -> semaine pas dans la liste
        return listesem;
    if(strcmp(Temp.anneesemaine, anneesem) == 0) // si la tete vaut la semaine voulue
        return SuppressionSemaineEnTete(listesem); // on la supprime

    listesem->suiv=SuppressionMaillonSemaine(listesem->suiv, annee, sem); // appel recursif
    return listesem;
}

void LiberationSemaines(Listesem_t listesem)
{

    while(!ListeSemaineVide(listesem))
    {
        LiberationListeActions((listesem->semaine).act);
        listesem = SuppressionSemaineEnTete(listesem);
    }
}