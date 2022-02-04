#include <stdlib.h>
#include <stdio.h>
#include"projet.h"

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
