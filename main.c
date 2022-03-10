#include "motif.h"

int main(int argc, char ** argv)
{
    Listesem_t listesem;
    Date_t     date[TAILLEMAX];
    Booleen_t  b;
    Booleen_t sortie = faux;
    int        i;
    int        x;
    char       sauv[20];
    char       motif[11];
    char       annee[5];
    int        jour;
    char       semaine[3];
    char       heure[3];

    listesem = InitialisationSemaine();

    listesem = InsertionDonnees(argv[1],listesem);

    while(!sortie)
    {
        printf("Choisissez une action : \n");
        printf("1 - Afficher la liste des semaines\n2 - Sauvegarder dans un fichier\n3 - Afficher la liste des semaines contenant un motif\n4 - Supprimer une action\n5 - Sortie\n");
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
        
            case 4: printf("Annee?\n");
                    scanf("%s",annee);
                    printf("Semaine?\n");
                    scanf("%s",semaine);
                    printf("Jour?\n");
                    scanf("%d",&jour);
                    printf("Heure?\n");
                    scanf("%s",heure);
                    b = SuppressionAction(listesem, annee, semaine, jour, heure);
                    if (b)
                    {
                        listesem=SuppressionMaillonSemaine(listesem, annee, semaine);
                    } 
                    break;

            case 5: sortie = vrai; break;
        }
    }

    LiberationSemaines(listesem);

    return 0;
}
