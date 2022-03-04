#include "motif.h"

int Motif(char * motif, Listesem_t listesem, Date_t date[], Date_t * findate)
{
	int i = 0;

	while (!ListeSemaineVide(listesem) && (&date[i] != findate))
	{
		while((!ListeActionVide((listesem->semaine).act))  && (&date[i] != findate))
		{
			if(strstr((((listesem->semaine).act)->action).action,motif) != NULL)
			{
				strcpy(date[i].anneesemaine,(listesem->semaine).anneesemaine);
				strcpy(date[i].jourheure,(((listesem->semaine).act)->action).jourheure);
				strcpy(date[i].action,(((listesem->semaine).act)->action).action);	

				i++;
			}

			(listesem->semaine).act = ((listesem->semaine).act)->suiv;
		}

		listesem = listesem->suiv;
	}

	return i;
}



void AfficherListeContigue(char * motif, Date_t date[], Date_t * findate)
{
	int i = 0;

	printf("Liste des semaines contenant le motif : %s\n", motif);

	while(&date[i] != findate)
	{
		printf("---------------------------------------------\n");
        printf("--------- Année %c%c%c%c \t Semaine %c%c ---------\n",date[i].anneesemaine[0],date[i].anneesemaine[1],date[i].anneesemaine[2],date[i].anneesemaine[3],date[i].anneesemaine[4],date[i].anneesemaine[5]);
        printf("Jour : %c \t Heure : %c%ch\n", date[i].jourheure[0],date[i].jourheure[1],
            date[i].jourheure[2]);
        printf("Action : %s\n", date[i].action);
        printf("---------------------------------------------\n");

        i++;
	}
}