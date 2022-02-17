#include "motif.h"

void Ajout(char * anneesem, char * jourheure, char * action, Date_t date)
{
	strcpy(date.anneesemaine,anneesem);
	strcpy(date.jourheure,jourheure);
	strcpy(date.action,action);
}



Date_t * Motif(char * motif, Listesem_t listesem)
{
	
}