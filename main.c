#include "semaine.h"

int main(int argc, char ** argv)
{
    Listesem_t listesem;
    listesem = InitialisationSemaine();

    listesem = InsertionDonnees(argv[1],listesem);

    AfficherListeSemaine(listesem);

    Sauvegarde(argv[2],listesem);

    return 0;
}
