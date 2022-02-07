#ifndef TROUPS_H_INCLUDED
#define TROUPS_H_INCLUDED
#include <gtk/gtk.h>
typedef struct date_troup_s
{
    int jour;
    char mois[10];
    int annee;
} date_troup;

typedef struct troup_s
{
    unsigned int id;
    char nom[20];
    char type[20];
    char sante[20];
    char nourriture[50];
    char sexe[9];
    date_troup naissance;
}troup;

unsigned int last_id_troup();
void ajouter_troup(troup t_trou);
int check_errors_troup(troup t_trou);
void afficher_troup(GtkWidget * troup_treeview, char search[]);
void touver_troup(troup * tmp_trou);
void modifier_troup(troup t_trou);
int supprimer_troup(troup t_trou);
#endif // TROUPS_H_INCLUDED
