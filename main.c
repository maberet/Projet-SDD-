#include "motif.h"

int main(int argc, char ** argv)
{
    Listesem_t listesem;
    // Date_t date[TAILLEMAX];
    int i; 

    listesem = InitialisationSemaine();

    listesem = InsertionDonnees(argv[1],listesem);

    printf("Avant suppression\n");
    AfficherListeSemaine(listesem);

    i=SuppressionAction(listesem,"2022","15",4,"16");
    if (i){
        listesem=SuppressionMaillonSemaine(listesem,"2022","15");
    }
    printf("Après suppression\n");
    AfficherListeSemaine(listesem);
    Sauvegarde(argv[2],listesem);
    printf("Suppression de tout\n");
    listesem=LiberationSemaines(listesem);
    AfficherListeSemaine(listesem);
    
    // int i = Motif(argv[3],listesem,date,&date[TAILLEMAX]);

    // AfficherListeContigue(argv[3],date,&date[i]);

    return 0;
}
