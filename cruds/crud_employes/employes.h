#ifndef EMPLOYES_H_INCLUDED
#define EMPLOYES_H_INCLUDED

typedef struct employes
{
    char username[20];
    int  cinid;
    char password[20];
    char prenom[20];
    char nom[20];
    char sexe;
    date naissance;
    tele telnumbr;
    char mail[20];
    adre adresse[20];
    char access;
    date last_access;
};
void ajouter_employer(employes *);
void supprimer_employer(employes *);
void afficher_employer(employes*);
int chercher_employer();
void modifier_employer(employes *);



#endif // EMPLOYES_H_INCLUDED
