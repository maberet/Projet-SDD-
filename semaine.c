#include <stdlib.h>
#include <stdio.h>
<<<<<<< HEAD
#include"semaine.h"
=======
#include"projet.h"
>>>>>>> 673b522847e940c2607e04e762c4b16952154259

Listesem ListesemInit (void){
    return NULL;
}

Listesem Insertionentete(Listesem liste) 
{
    Maillonsem *m;
    m=(Maillonsem*)malloc(sizof(Maillonsem));

    if (m==NULL)
    {
        printf("problème malloc \n");
        exit(1);
    }
    m->suiv= liste; 

    return m; 
}

Listesem Insertion (Listesem liste)
{ 

    if (liste.annee<)
}
