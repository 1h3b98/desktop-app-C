#ifndef EMPLOYES_H_INCLUDED
#define EMPLOYES_H_INCLUDED

typedef struct date_r_e_tab
{
    char jour[3];
    char mois[10];
    char annee[5];
} date_r_e;

typedef struct employ
{
    char username[20];
    char password[20];
    char cin[9];
    char prenom[20];
    char nom[20];
    char sexe[6];
    date_r_e naissance;
    char telnumbr[9];
    char mail[20];
    char adresse[20];
    int access;
    date_r_e last_access;
}employes;
int user_type(char ur[], char ps[]); //Done

int ges_employes_screen(); //Done

void afficher_employer(employes vemp); //Done
void lister_employer(); //Done

void saisie_employer(employes *pemp);
void ajout_employer();

void chercher_employer(char iden[]);

void modif_supp_employer();

void supprimer_employer(employes *pemp);
void modifier_employer(employes *pemp);




#endif // EMPLOYES_H_INCLUDED
