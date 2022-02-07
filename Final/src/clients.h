#ifndef CLIENTS_H_INCLUDED
#define CLIENTS_H_INCLUDED
#include <gtk/gtk.h>
typedef struct date_client_s
{
    int jour;
    char mois[10];
    int annee;
} date_client;

typedef struct client_s
{
    unsigned int id;
    char cin[9];
    char prenom[20];
    char nom[20];
    char sexe[6];
    date_client derniere_visite;
    char telnumbr[9];
    char mail[35];
    char adresse[40];
    char paiment[35];
}client;

unsigned int last_id_client();
void ajouter_client(client t_cli);
int check_errors_client(client t_cli);
void modifier_client(client t_cli);
int supprimer_client(client t_cli);
void afficher_client(GtkWidget * client_treeview, char search[]);
int empty_invalid_entry_client(client tmp_client);
void touver_client(client * tmp_cli);

#endif // CLIENTS_H_INCLUDED