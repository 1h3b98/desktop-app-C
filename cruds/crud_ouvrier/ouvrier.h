#ifndef OUVRIER_H_INCLUDED
#define OUVRIER_H_INCLUDED
typedef struct Date {
int jour;
int mois;
int annee;
} date;
typedef struct gestion_ouvrier
{   char Nom[20];
	char Prenom[20];
	int Sexe;
	unsigned long Cin;
	int ID;
	unsigned long Tel;
    date  date_debut;
	int  fonction;
	char adresse [30];
}ouvrier;
void afficher_ouvrier(ouvrier *o);
void chercher_ouvrier( );
void ajouter_ouvrier (ouvrier *o);
void modifier_ouvrier(ouvrier *o);
void supprimer_ouvrier(ouvrier *o);
#endif // OUVRIER_H_INCLUDED
