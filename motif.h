#ifndef question2

#include "semaine.h"

#endif

#define TAILLEMAX 300

typedef struct date
{
	char anneesemaine[7];
	char jourheure[4];
	char action[11];
} Date_t;

int Motif(char * motif, Listesem_t listesem, Date_t date[], Date_t * findate);
void AfficherListeContigue(char * motif, Date_t date[], Date_t * findate);