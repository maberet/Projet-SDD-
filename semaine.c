#include"semaine.h"

/* ----------------------------------------------------------------------------------------------------------------- */
/*                              InitialisationSemaine : Initialise la liste des semaines.                            */
/*                                                                                                                   */
/*                              En entrée : Aucune.                                                                  */
/*                                                                                                                   */
/*                              En sortie : Liste de semaines vide.                                                  */
/* ----------------------------------------------------------------------------------------------------------------- */

Listesem_t InitialisationSemaine (void)
{
    return NULL;
}



/* ----------------------------------------------------------------------------------------------------------------- */
/*                              ListeActionVide : Teste si la liste est vide ou non.                                 */
/*                                                                                                                   */
/*                              En entrée : Liste des semaines listesem.                                             */
/*                                                                                                                   */
/*                              En sortie : 1 si elle est vide, 0 sinon.                                             */
/* ----------------------------------------------------------------------------------------------------------------- */

Booleen_t ListeSemaineVide(Listesem_t listesem)
{
    Booleen_t result = faux;

    if (listesem==NULL)
    {
        result=vrai;
    }
    return (result);
}



/* ----------------------------------------------------------------------------------------------------------------- */
/*                              InsertionEnTeteSemaine : Insère en tête de liste la structure                        */
/*                                            semaine en paramètre                                                   */
/*                                                                                                                   */
/*                              En entrée : Structure semaine Sem, Liste des semaines listesem.                      */
/*                                                                                                                   */
/*                              En sortie : Liste des semaines mise à jour.                                          */
/* ----------------------------------------------------------------------------------------------------------------- */

Listesem_t InsertionenteteSem(Semaine_t Sem,Listesem_t Listesem)
{
    Maillonsem_t *m;
    m=(Maillonsem_t*)malloc(sizeof(Maillonsem_t)); // on alloue un maillon.
                                                            
    if (m==NULL)
    {
        printf("problème d'allocation \n");
        exit(1);
    }
    m->semaine=Sem; // on ajoute la semaine dans le maillon.
    m->suiv= Listesem; // on fait pointer le suivant du maillon sur la liste.

    return m;
}



/* ----------------------------------------------------------------------------------------------------------------- */
/*                              InsertionSemaine : Insère la structure semaine à la bonne                            */
/*                                            place dans la liste.                                                   */
/*                                                                                                                   */
/*                              Entrée : Structure semaine sem, Liste des semaines listesem.                         */
/*                                                                                                                   */
/*                              Sortie : Liste des semaines listesem.                                                */
/* ----------------------------------------------------------------------------------------------------------------- */

Listesem_t InsertionSemaine (Semaine_t sem,Listesem_t liste)
{
    if (ListeSemaineVide(liste)) // si la liste est vide:
    {
        return InsertionenteteSem(sem,liste); // on insère en tête.
    }
    else
    {
        if (strcmp((liste->semaine).anneesemaine,sem.anneesemaine)>0) // si la chaine anneesemaine du maillon à ajouter est plus petite que celle de la liste:
        {
            return InsertionenteteSem(sem,liste); // on insère en tête.
        }
        else if (strcmp((liste->semaine).anneesemaine,sem.anneesemaine)==0) // si la chaine jourheure du maillon à ajouter est égale que celle de la liste:
        {
            (liste->semaine).act = InsertionAction((sem.act)->action,(liste->semaine).act); // on insère la structure action à la bonne place dans la semaine.
            return liste;
        }
        else
        {
            liste->suiv = InsertionSemaine(sem,liste->suiv); // sinon on passe au suivant.
        }
    }
    return liste;
}




/* ----------------------------------------------------------------------------------------------------------------- */
/*                              AfficherListeSemaine : Affiche la liste des semaines                                 */
/*                                                                                                                   */
/*                              En enntrée : Liste des semaines listesem.                                            */
/*                                                                                                                   */
/*                              En sortie : aucune.                                                                  */
/* ----------------------------------------------------------------------------------------------------------------- */


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



/* ----------------------------------------------------------------------------------------------------------------- */
/*                              LectureDonnees: Ajoute les données du fichier dans la structure semaine.             */
/*                                                                                                                   */
/*                              En entrée: File.                                                                     */
/*                                                                                                                   */
/*                              En sortie: Structure semaine.                                                        */
/* ----------------------------------------------------------------------------------------------------------------- */

Semaine_t LectureDonnees(FILE * file)
{
    Action_t            act;
    Semaine_t           sem;

    fscanf(file,"%6s %3s %[^\n]%*c",sem.anneesemaine, act.jourheure, act.action); // on lit les données dans le fichier.
    sem.act = InsertionAction(act,InitialisationAction()); // on insère dans la liste des actions.

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

    //printf("annesem: %s\n",anneesem);

    if(RechercheSemaineAction(listesem, annee, sem, jour, heure)) // si l'action existe dans la liste
    {   //printf("avion\n");
        while(listesem!=NULL)
        {
            if(strcmp((listesem->semaine).anneesemaine, anneesem) == 0) // si on trouve la semaine voulue
            {
                (listesem->semaine).act = SuppressionMaillonAction((listesem->semaine).act, jour, heure); // suppression de l'action dans la liste d'actions
                Validation = ListeActionVide((listesem->semaine).act); // si la liste des actions est vide après suppression on notifie que l'on doit supprimer la semaine de la liste
                /*if (Validation==1)
                {
                 listesem= SuppressionMaillonSemaine(listesem,annee,sem);
                }*/
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
    Maillonsem_t        * SemTemp; // Maillon temporaire qui va permettre de supprimer la tête de liste 
    
    if(ListeSemaineVide(listesem)) // si la liste est vide on ne peut rien supprimer, c'est un cas d'erreur
    {
        printf("Liste vide");
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

Listesem_t LiberationSemaines(Listesem_t listesem)
{
    while(!ListeSemaineVide(listesem))
    {
        LiberationListeActions((listesem->semaine).act);
        listesem = SuppressionSemaineEnTete(listesem);
    }
    return listesem;
}