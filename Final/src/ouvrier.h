#ifndef OUVRIER_H_INCLUDED
#define OUVRIER_H_INCLUDED
#include <gtk/gtk.h>
typedef struct dt
{
	int jour;
	char mois[20];
	int annee;
}Date;

typedef struct ouv
{   	char nom[20];
	char prenom[20];
	char sexe[20];
	 unsigned int id;
	char tel[20];
   	 Date date;
	char  fonction[20];
	char adresse [20];
}ouvrier;
typedef struct t
{
int id;
int j;
int m;
int a;
int prs;
} 
Taux;

void ajouter_ouvrier(ouvrier ouv);
unsigned int last_id_ouv();
void afficher_ouvrier(GtkWidget *liste,char search[]);
void touver_ouvrier(ouvrier * ouv);
int supprimer_ouvrier(ouvrier ouv);
void modifier_ouvrier(ouvrier ouv);
void afficher_taux(GtkWidget * taux_treeview);

#endif // CLIENTS_H_INCLUDED
