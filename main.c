#include "motif.h"

int main(int argc, char ** argv)
{
    Listesem_t listesem;
    Date_t date[TAILLEMAX];

    listesem = InitialisationSemaine();

    listesem = InsertionDonnees(argv[1],listesem);

    //AfficherListeSemaine(listesem);

    Sauvegarde(argv[2],listesem);

    int i = Motif(argv[3],listesem,date,&date[TAILLEMAX]);

    AfficherListeContigue(argv[3],date,&date[i]);

    return 0;
}
