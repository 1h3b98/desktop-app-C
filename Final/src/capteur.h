#ifndef CAPTEUR_H_INCLUDED
#define CAPTEUR_H_INCLUDED
#include <gtk/gtk.h>

typedef struct dat
{
int day;
char month[12];
int year;
}date;


typedef struct cap
{
    unsigned int ID;
    char marque[20];
    char precision[20];
    char type[30];
    date date;


}capteur;


unsigned int last_id_cap();
void ajou_capt(capteur cap);
void afficher_capteur(GtkWidget * employer_capteurs_treeview, char search_cap[]);
int supprimer_capteur(capteur cap);
void trouver_capteur(capteur * tmp_cap);
void modifier_capteur(capteur cap);
int empty_invalid_entry_capteur(capteur tmp_cap);

#endif // CAPTEUR_H_INCLUDED
