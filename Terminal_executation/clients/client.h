#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
typedef struct date_r_c_tab
{
    char jour[3];
    char mois[10];
    char annee[5];
} date_r_c;

typedef struct client
{
    char cinid[9];
    char prenom[20];
    char nom[20];
    char sexe[6];
    date_r_c last_visite;
    char telnumbr[9];
    char mail[30];
    char adresse[30];
}client;

int ges_clients_screen(); 

void afficher_client(client vcli); 
void lister_clients(); 

void saisie_client(client *pcli); 
void ajout_client(); 

void chercher_client(char iden[]);

void modif_supp_client(); 

void modifier_client(client *pcli); 


#endif // CLIENT_H_INCLUDED
