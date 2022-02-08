<<<<<<< HEAD
typedef struct action {
    char jourheure[3];
    char action[10];

    struct action *suiv;
}Action,*Listeaction; 


=======
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
>>>>>>> 673b522847e940c2607e04e762c4b16952154259
