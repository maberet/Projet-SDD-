#include "motif.h"

int main(int argc, char ** argv)
{
    Listesem_t listesem;
    // Date_t date[TAILLEMAX];
    int i; 

    listesem = InitialisationSemaine();

    listesem = InsertionDonnees(argv[1],listesem);

    AfficherListeSemaine(listesem);

    i=SuppressionAction(listesem," 022","15",4,"08");
    printf("i=%d\n",i);
    AfficherListeSemaine(listesem);
    Sauvegarde(argv[2],listesem);

    LiberationSemaines(listesem);
    
    // int i = Motif(argv[3],listesem,date,&date[TAILLEMAX]);

    // AfficherListeContigue(argv[3],date,&date[i]);

    return 0;
}
