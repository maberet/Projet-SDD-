#include "semaine.h"


int main()
{
    Listeaction_t listeact;
    FILE        * file;
    char          anneesemaine[7];
    Action_t      siuu;

    listeact = InitialisationAction();
    file = fopen("action.txt","r");
    if (file == NULL)
    {
        printf("Erreur d'ouverture");
    }
    else
    {
        while(!feof(file))
        {
            fscanf(file,"%6s %3s %[^\n]%*c",anneesemaine,siuu.jourheure,siuu.action);
            listeact = InsertionAction(siuu,listeact);
        }
    }

    AfficherListeAction(listeact);

    return 0;
}

