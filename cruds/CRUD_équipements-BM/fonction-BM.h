#ifndef FONCTION-BM_H_INCLUDED
#define FONCTION-BM_H_INCLUDED

typedef struct equipement
{
    int identifiant;
    char nom[20];
    char date_ajout[10];
    char etat[10];
    char date_dernier_maintenaince[10];

}equipement;

void ajouter_equipement(equipement *e);
void supprimer_equipement(equipement *e);
void afficher_equipement(equipement *e);
int chercher_equipement();
void modifier_equipement(equipement *e);

#endif // FONCTION-BM_H_INCLUDED
