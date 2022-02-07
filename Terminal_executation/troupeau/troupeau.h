#ifndef TROUPEAU_H_INCLUDED
#define TROUPEAU_H_INCLUDED
struct date_troup_tab{
int day;
char month[20];
int year;
};
typedef struct date_troup_tab Date_troup;
struct troupeau{
char ID[15];
char type[20];
char nourriture[20];
char sante[20];
char sexe[20];
Date_troup date;
};
typedef struct troupeau Troupeau;

int ges_troupeaux_screen();
void Afficher_troup(Troupeau );
void Ajouter_troup(Troupeau *);
void ajou_troup();
void Modif_supp_troup();
void modif_troup(Troupeau *);
int Chercher_troup();
void lister_troup();



#endif
