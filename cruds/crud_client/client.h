#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
typedef struct dt
{
    int jour;
    int mois;
    int annee;
} date;
typedef struct client
{
    char username[20];
    unsigned long cinid;
    char prenom[20];
    char nom[20];
    int sexe;
    date last_visite;
    unsigned long telnumbr;
    char mail[30];
    char adresse[30];
}client;

void ajouter_client(client * c);
void supprimer_client(client * c);
void afficher_client(client c);
void chercher_client();
void modifier_client(client * c);

#endif // CLIENT_H_INCLUDED
