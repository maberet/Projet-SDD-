typedef struct maillon {
    Semaine semaine; 

    struct maillon *suiv;
}Maillonsem,*Listesem;

typedef struct sem {
    char annee [4];
    char semaine [2];
    char ptaction; 
}Semaine;


typedef struct action {
    char jourheure[3];
    char action[10];

    struct action *suiv;
}Action,*Listeaction; 

Listesem ListesemInit(void);

Listesem Insertion(Listesem)
