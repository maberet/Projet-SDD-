#include "semaine.h"

//  Remarque : Le nom du fichier en entrée doit être en argument de la ligne de commande.


int main()
{
    Listesem_t          listesem;
    Action_t            siuu;
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
            sem.act=(MaillonAct_t *)malloc(sizeof(MaillonAct_t));
            fscanf(file,"%6s %3s %[^\n]%*c",sem.anneesemaine,siuu.jourheure,siuu.action);
            (sem.act)->action=siuu;
            listesem = InsertionSemaine(sem,listesem);
        }
    }

    AfficherListeSemaine(listesem);
    LiberationListeSemaine(listesem);
    return 0;
}

