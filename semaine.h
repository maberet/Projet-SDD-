typedef struct maillon {
    Semaine semaine; 

    struct maillon *suiv;
}Maillonsem,*Listesem;

typedef struct sem {
    char annee [4];
    char semaine [2];
    char ptaction; 
}Semaine;


Listesem ListesemInit(void);

Listesem Insertion(Listesem)
