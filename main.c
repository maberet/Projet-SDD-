#include "motif.h"

int main(int argc, char ** argv)
{
    Listesem_t listesem;
    Date_t     date[TAILLEMAX];
    int        i;
    int        x;
    char     * sauv;
    char     * motif;

    listesem = InitialisationSemaine();

    listesem = InsertionDonnees(argv[1],listesem);

    printf("Choisissez une action : \n");
    printf("1 - Afficher la liste des semaines\n2 - Sauvegarder dans un fichier\n3 - Afficher la liste des semaines contenant un motif\n4 - Supprimer une action\n");
    scanf("%d", &x);

    switch(x)
    {
        case 1: AfficherListeSemaine(listesem); break;

        case 2: printf("Nom du fichier de sauvegarde?\n");
                scanf("%s",sauv);
                Sauvegarde(sauv,listesem); break;

        case 3: printf("Motif?\n");
                scanf("%s",motif);
                i = Motif(motif,listesem,date,&date[TAILLEMAX]);
                AfficherListeContigue(motif,date,&date[i]); break;
        
        case 4: break;
    }

    return 0;
}
