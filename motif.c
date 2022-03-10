#include "motif.h"

int Motif(char * motif, Listesem_t listesem, Date_t date[], Date_t * findate)
{
	int 	      i = 0;
	Listeaction_t temp;

	while (!ListeSemaineVide(listesem) && (&date[i] != findate))
	{
		temp = (listesem->semaine).act;

		while(!ListeActionVide(temp) && (&date[i] != findate))
		{
			if(strstr((temp->action).action,motif) != NULL)
			{
				strcpy(date[i].anneesemaine,(listesem->semaine).anneesemaine);
				strcpy(date[i].jourheure,((temp->action).jourheure));
				strcpy(date[i].action,((temp->action).action));	

				i++;
			}

			temp = temp->suiv;
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