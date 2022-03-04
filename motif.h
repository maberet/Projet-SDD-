#ifndef question2

#include "semaine.h"
#endif

#define TAILLEMAX 300

typedef struct date {
	
	char anneesemaine[7];
	char jourheure[4];
	char action[11];

}Date_t;

int Motif(char *, Listesem_t, Date_t[], Date_t * );
void AfficherListeContigue(char * , Date_t[], Date_t *);