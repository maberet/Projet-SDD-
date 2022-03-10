#include "motif.h"

int main(int argc, char ** argv)
{
    Listesem_t listesem;
    Date_t     date[TAILLEMAX];
    Booleen_t  b;                                                                       // Vaut vrai si la semaine est vide apres la suppresion de l'action. 
    Booleen_t sortie = faux;
    int        i;                                                                       // Nombre de motif trouvé.
    int        x;                                                                       // Variable de sélection du menu. 
    char       sauv[20];                                                                
    char       motif[11];
    char       annee[5];
    int        jour;
    char       semaine[3];
    char       heure[3];

    listesem = InitialisationSemaine();

    listesem = InsertionDonnees(argv[1],listesem);                                      // Insertion des données du fichier entré conformes au format demandé.

    printf("Choisissez une action : \n");
    printf("1 - Afficher la liste des semaines\n2 - Sauvegarder dans un fichier\n3 - Afficher la liste des semaines contenant un motif\n4 - Supprimer une action\n5 - Sortie\n");

    while(!sortie)
    {
        while(scanf("%d", &x) == 0)                                                     // TEST validité du caractère. 
        {
            printf("Mauvais charactère\n");
            

            printf("Choisissez une action : \n");                                       // Affichage du menu. 
            printf("1 - Afficher la liste des semaines\n2 - Sauvegarder dans un fichier\n3 - Afficher la liste des semaines contenant un motif\n4 - Supprimer une action\n5 - Sortie\n");
            
            scanf("%d", &x);
            ViderBuffer();                                                              // vide le buffer. 
        }

        if(x>0 && x<6)
        {
            switch(x)
            {
                case 1: AfficherListeSemaine(listesem); break;                         

                case 2: printf("Nom du fichier de sauvegarde?\n");
                        scanf("%s",sauv);
                        Sauvegarde(sauv,listesem); break;

                case 3: printf("Motif?\n");                                             // Demande le motif à rechercher. 
                        scanf("%s",motif);                              
                        i = Motif(motif,listesem,date,&date[TAILLEMAX]);
                        AfficherListeContigue(motif,date,&date[i]); break;
            
                case 4: printf("Annee?\n");                                             // Demande l'action a supprimer. 
                        scanf("%s",annee);
                        printf("Semaine?\n");
                        scanf("%s",semaine);
                        printf("Jour?\n");
                        scanf("%d",&jour);
                        printf("Heure?\n");
                        scanf("%s",heure);
                        b = SuppressionAction(listesem, annee, semaine, jour, heure);
                        if (b)                                                          // Supprime la semaine si elle ne contient plus d'action. 
                        {
                            listesem=SuppressionMaillonSemaine(listesem, annee, semaine);
                        } 
                        break;

                case 5: sortie = vrai; break;                                           // Sortie du programme. 
            }
        }
        else
        {
            printf("Mauvais charactère\n");                                     // cas chiffre négatif ou supérieur à 5
        }

        printf("Choisissez une action : \n");
        printf("1 - Afficher la liste des semaines\n2 - Sauvegarder dans un fichier\n3 - Afficher la liste des semaines contenant un motif\n4 - Supprimer une action\n5 - Sortie\n");
    
    }

    LiberationSemaines(listesem);                                               // Libération de la liste semaine. 

    return 0;
}
