#ifndef CAPTEUR_H_INCLUDED
#define CAPTEUR_H_INCLUDED


typedef struct dat
{
int day;
char month[20];
int year;
}date;


typedef struct capteur
{
    char ID[20];
    char marque[20];
    float precision;
    char type[20];
    date date;


}capteur;

void ajouter_capteur(capteur *c);
void Modif_supp_capt();
void afficher_capteur(capteur c);
int  Chercher_capt();
void modifier_capteur(capteur *c);
int ges_capteur_screen();
void lister_capt();
void ajou_capt();


#endif // CAPTEUR_H_INCLUDED
