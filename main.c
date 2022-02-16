#include "semaine.h"

Semaine_t LectureDonnees(FILE * file)
{
    Action_t            act;
    Semaine_t           sem;

    fscanf(file,"%6s %3s %[^\n]%*c",sem.anneesemaine, act.jourheure, act.action);
    sem.act = InsertionAction(act,InitialisationAction());

    return sem;
}



int main()
{
    Listesem_t          listesem;
    Semaine_t           sem;
    FILE              * file;

    listesem = InitialisationSemaine();
    file = fopen("action.txt","r");
    if (file == NULL)
    {
        printf("Erreur d'ouverture");
    }
    else
    {   
        while(!feof(file))
        {
            sem = LectureDonnees(file);
            listesem = InsertionSemaine(sem,listesem);
        }
    }

    AfficherListeSemaine(listesem);

    return 0;
}
