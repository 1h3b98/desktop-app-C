#ifndef EQUIPMENTS_H_INCLUDED
#define EQUIPMENTS_H_INCLUDED
#include <gtk/gtk.h>

typedef struct date_equipement_s
{
    int jour;
    char mois[10];
    int annee;
} date_equipement;

typedef struct equipement_s
{
    unsigned int id;
    char nom[20];
    char type[20];
    char etat[10];
    date_equipement date_ajout;
    date_equipement date_dernier_maintenance;

}equipement;


unsigned int last_id_equi();

void ajouter_equipement(equipement t_equi);

int check_errors_equipement(equipement t_equi);

void modifier_equipement(equipement t_equi);

int supprimer_equipement(equipement t_equi);

void afficher_equipement(GtkWidget * equip_agri_treeview, char search_equi[]);

int empty_invalid_entry_equipement(equipement tmp_equip);

void touver_equipement(equipement * tmp_equi);


#endif // EQUIPMENTS_H_INCLUDED
