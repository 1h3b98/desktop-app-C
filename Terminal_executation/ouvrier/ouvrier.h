
typedef struct dt
{
int jour;
int mois;
int annee;
}Date;

typedef struct ouv
{   char nom[20];
	char prenom[20];
	int sexe;
	char id[10];
	unsigned long tel;
    Date date;
	char  fonction[20];
	char adresse [30];
}ouvrier;
void afficher_ouvrier(ouvrier o);
void ajouter_ouvrier();
void modifier_ouvrier();
void rechercher_ouvrier();
void supprimer_ouvrier();
void saisie_ouvrier(ouvrier *o);
void lister_ouvrier();
void ges_ouvrier_screen();
void affichMenu ();
int getChoix ();






