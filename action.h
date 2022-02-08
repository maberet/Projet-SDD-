typedef struct action {
    char jourheure[3];
    char action[10];

    struct action *suiv;
}Action,*Listeaction; 


