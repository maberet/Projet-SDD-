#ifndef question2

#include "semaine.h"
#endif

#define TAILLEMAX 300

/* -------------------------------Déclaration des structures.---------------------------------------*/

typedef struct date {
	
	char anneesemaine[7];								// Concaténation de l'année et de la semaine.
	char jourheure[4];                                  // Concaténation du jour et de l'heure. 
	char action[11];

}Date_t;

/* ------------------------------- Déclaration des fonctions.---------------------------------------*/

int Motif(char *, Listesem_t, Date_t[], Date_t * );
void AfficherListeContigue(char * , Date_t[], Date_t *);
void ViderBuffer (void);

/*---------------------------------------------------------------------------------------------------*/