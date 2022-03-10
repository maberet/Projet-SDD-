#include "motif.h"


/* ----------------------------------------------------------------------------------------------------------------- */
/*                           Motif : Remplie la liste contigue "date" des semaines/actions contenant le motif "motif"*/
/*          									dans la liste des semaine listesem.                                  */
/*                                                                                                                   */
/*                            En entrée : Le motif demandé  (motif), la liste contigue (date), le pointeur de fin    */
/*                                      (findate) et la liste des semaines (listesem).                               */
/*                                                                                                                   */
/*                            En sortie : Le nombre (i) d'actions contenant le motif.                                */
/* ----------------------------------------------------------------------------------------------------------------- */

int Motif(char * motif, Listesem_t listesem, Date_t date[], Date_t * findate)
{
	int 	      i = 0;														// compteur du nombre d'action contenant le motif.
	Listeaction_t temp;															// pointeur temporaire sur la liste des actions.  

	while (!ListeSemaineVide(listesem) && (&date[i] != findate))
	{
		temp = (listesem->semaine).act;															

		while(!ListeActionVide(temp) && (&date[i] != findate))
		{
			if(strstr((temp->action).action,motif) != NULL) 					// test d'appartenance du motif à l'action. 
			{
				strcpy(date[i].anneesemaine,(listesem->semaine).anneesemaine);	// ajout des valeurs de l'action contenant le motif à la liste contigue.       
				strcpy(date[i].jourheure,((temp->action).jourheure));
				strcpy(date[i].action,((temp->action).action));	

				i++;															// incrémentation du nombre d'action contenant le motif. 
			}

			temp = temp->suiv;													// passage à l'action suivante. 
		}

		listesem = listesem->suiv;												// passage à la semaine suivante de la liste listesem.
	}

	return i;
}

/* ----------------------------------------------------------------------------------------------------------------- */
/*                              AfficherListeContigue : Affiche la liste contigue des semaines/action contenant      */
/*          									le motif entré.                                                      */
/*                                                                                                                   */
/*                              En entrée : Le motif demandé  (motif), la liste contigue (date), le pointeur de fin  */
/*                                      (findate).                                                                   */
/*                                                                                                                   */
/*                              En sortie : Rien. 						                                             */
/* ----------------------------------------------------------------------------------------------------------------- */


void AfficherListeContigue(char * motif, Date_t date[], Date_t * findate)
{
	int i = 0;																		// position dans la liste contigue. 

	printf("Liste des semaines contenant le motif : %s\n", motif);

	while(&date[i] != findate)														// parcours de la liste contigue. 
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


/* ----------------------------------------------------------------------------------------------------------------- */
/*                              ViderBuffer : Vide le buffer. 					                                     */
/*                                                                                                                   */
/*                              En entrée : Rien.			                                                         */
/*                                                                                                                   */
/*                              En sortie : Rien.						                                             */
/* ----------------------------------------------------------------------------------------------------------------- */

void ViderBuffer(void)
{
	int c=0; 
	while (c!=EOF&&c!='\n')		 													// tant que l 'on n'a pas atteint le bout.
	{
		c=getchar();
	}
}