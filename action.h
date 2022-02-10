typedef struct maillonact{
    Action_t action;
    struct maillonact_t *suiv
} MaillonAct_t,*Listeaction_t; 

typedef struct action {
    char jourheure[3];
    char action[10];
}Action_t,

Listeaction_t InitialisationAction(void);
int ListeActionVide(Listeaction_t);
Listeaction_t InsertionEnTeteAction(Action_t, Listeaction_t);
Listeaction_t InsertionAction(Action_t, Listeaction_t);