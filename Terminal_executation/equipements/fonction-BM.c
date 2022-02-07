#include"fonction-BM.h"
#include <stdio.h>
#include <string.h>

int ges_equp_agri_screen()
{
	int x;
	while (1)
	{
		printf("---------------GESTION DES EQUIPEMENTS AGRICOLES----------------\n");
		printf("1-Afficher les équipements \n");
		printf("2-Ajouter un équipement \n");
		printf("3-Modifier/Supprimer un équipement \n");
		printf("4-Chercher un équipement \n");
		printf("0-Quitter");
		printf("----------------------------------------------------------------\n");
		do
		{
			printf("Donner votre choix :\n");
			scanf("%d",&x);
		}while(x<0 && x>4);
		printf("================================================================\n");
		
		switch(x)
		{
			case 1:
				printf("---------- AFFICHAGE DES EQUIPEMENTS AGRICOLES --------\n");
				lister_equipement();
				break;
			case 2:
				printf("------------- AJOUTER UN EQUIPEMENT AGRICOLE -----------\n");
				ajouter_equipement();
				break;
			case 3:
				printf("--------- Modifier/Supprimer UN EQUIPEMENT AGRICOLE -------\n");
				modifier_supprimer_equipement();
				break;			
			case 4:
				printf("-------------- CHERCHER UN EQUIPEMENT AGRICOLE ------------\n");
				chercher_equipement();
				break;
			case 0:
				return 0;
				break;
		}	
	}

}




void ajouter_equipement()
{
	FILE* f_equipements;
	equipement e;
	f_equipements=fopen("equipements.txt","a+");
	printf("Donner l'identifiant de l'équipement : ");
	fflush(stdin);
	scanf("%s",e.identifiant);
	printf("Donner le nom d'équipement : ");
	fflush(stdin);
	scanf("%s",e.nom);
	printf("Donner date d'ajout de l'équipement : ");
	fflush(stdin);	
	scanf("%s",e.date_ajout);
	printf("Donner l'état de l'équipement : ");
	fflush(stdin);	
	scanf("%s",e.etat);
	printf("Donner date de dernier maintenaince : ");
	fflush(stdin);
	scanf("%s",e.date_dernier_maintenaince);
	printf("Donner le type de l'équipement : ");
	fflush(stdin);	
	scanf("%s",e.type);
	fprintf(f_equipements,"%s |" ,e.identifiant);
	fprintf(f_equipements,"%s |" ,e.nom);
	fprintf(f_equipements,"%s |" ,e.date_ajout);
	fprintf(f_equipements,"%s |" ,e.etat);
	fprintf(f_equipements,"%s |" ,e.date_dernier_maintenaince);
	fprintf(f_equipements,"%s |" ,e.type);
	fclose(f_equipements);
}



void afficher_equipement(equipement e)
{
printf("IDENTIFIANT: %s \n", e.identifiant);
printf("NOM: %s \n", e.nom);
printf("DATE D'AJOUT: %s \n", e.date_ajout);
printf("ETAT: %s \n", e.etat);
printf("DATE DE DERNIER MAINTENAINCE: %s \n", e.date_dernier_maintenaince);
printf("TYPE : %s \n",e.type);
}


void chercher_equipement()
{
FILE* f_equipements;
equipement e;
char id_rech[20];
f_equipements=fopen("equipements.txt","r");
if(f_equipements!=NULL)
{
printf("Donner l'identifiant :");
scanf("%s",id_rech);
while(fscanf(f_equipements,"%s %s %s %s %s %s \n",e.identifiant,e.nom,e.date_ajout,e.etat,e.date_dernier_maintenaince,e.type)!=EOF)
{
if (strcmp(e.identifiant,id_rech) == 0)
{
afficher_equipement(e);
}
else
fprintf(f_equipements,"%s %s %s %s %s %s \n",e.identifiant,e.nom,e.date_ajout,e.etat,e.date_dernier_maintenaince,e.type);
}
fclose(f_equipements);;
}	
}


void modifier_supprimer_equipement()
{
	FILE *f_equipements, *tmp;
	char choix;
	equipement e;
	char id_rech[15];
	
	f_equipements=fopen("equipements.txt","r");
	tmp=fopen("tmp_equipement.txt","w");
	if(f_equipements!=NULL && tmp!=NULL)
	{
		printf("Donnerb l'identifiant de l'équipement :");
		fflush(stdin);
		scanf("%s",id_rech);
		while(fscanf(f_equipements,"%s %s %s %s %s %s \n",e.identifiant,e.nom,e.date_ajout,e.etat,e.date_dernier_maintenaince,e.type)!=EOF)
		{
			if(strcmp(e.identifiant,id_rech)==0)
				{
					afficher_equipement(e);
					printf("Modifier ou Supprimer l'équipement ?\n");
					printf("Taper (s) pour supprimer \n");
					printf("Taper (m) pour modifier \n");
					printf("Taper (i) pur ignorer \n");
					fflush(stdin);
					scanf("%c",&choix);
					switch(choix)
					{
						case 's':
						break;
						case 'm':
						modifier_equipement(&e);
						fprintf(tmp,"%s %s %s %s %s %s \n",e.identifiant,e.nom,e.date_ajout,e.etat,e.date_dernier_maintenaince,e.type);
						break;
						case 'i':
						fprintf(tmp,"%s %s %s %s %s %s \n",e.identifiant,e.nom,e.date_ajout,e.etat,e.date_dernier_maintenaince,e.type);
						break;
					}
				}
			else fprintf(tmp,"%s %s %s %s %s %s \n",e.identifiant,e.nom,e.date_ajout,e.etat,e.date_dernier_maintenaince,e.type);
		}
		}
	fclose(f_equipements);
	fclose(tmp);
	remove("equipements.txt");
	rename("tmp_equipement.txt","equipements.txt");
}

void lister_equipement()
{
FILE *f_equipements;
equipement tmp_equipement;
f_equipements=fopen("equipements.txt","r");
	if(f_equipements!=NULL)
	{
		while(fscanf(f_equipements,"%s %s %s %s %s %s \n",tmp_equipement.identifiant,tmp_equipement.nom,tmp_equipement.date_ajout,tmp_equipement.etat,tmp_equipement.date_dernier_maintenaince,tmp_equipement.type)!=EOF)
		{	
			afficher_equipement(tmp_equipement);
		}
		fclose(f_equipements);
	}
	else
		printf("Impossible d'ovrir le fichier");
}
			


void modifier_equipement(equipement *e)
{
FILE *f_equipements, *tmp;
equipement tmp_equi;
f_equipements=fopen("equipements.txt","r");
tmp=fopen("tmp_equipement.txt","w+");
while(fscanf(f_equipements,"%s %s %s %s %s %s \n",tmp_equi.identifiant,tmp_equi.nom,tmp_equi.date_ajout,tmp_equi.etat,tmp_equi.date_dernier_maintenaince,tmp_equi.type)!=EOF)
	{

	fprintf(tmp,"%s %s %s %s %s %s \n",tmp_equi.identifiant,tmp_equi.nom,tmp_equi.date_ajout,tmp_equi.etat,tmp_equi.date_dernier_maintenaince,tmp_equi.type);
	}
fclose(f_equipements);
fclose(tmp);
remove("equipements.txt");
rename("tmp_equipement.txt","equipements.txt");
}			











			
	

