#ifndef FONCTION_BM_H_INCLUDED
#define FONCTION_BM_H_INCLUDED


typedef struct equipement
{
    char identifiant[10];
    char nom[20];
    char date_ajout[10];
    char etat[10];
    char date_dernier_maintenaince[10];
    char type[20];

}equipement;

void ajouter_equipement();
void afficher_equipement(equipement e);
void chercher_equipement();
void modifier_supprimer_equipement();
void lister_equipement();
int ges_equp_agri_screen();


void modifier_equipement(equipement *e);

#endif // FONCTION-BM_H_INCLUDED
