#include <stdio.h>
#include <stdlib.h>
#include "capteur.h"
#include <string.h>

int ges_capteur_screen()
{
int numf; 
 while (1)
 {
 	do
 	{
        printf("       *** Gestion Capteur ***      \n");
        printf(" 1) Afficher la liste des capteurs.\n");
    	printf(" 2) Ajouter un nouveau capteurs.\n");
    	printf(" 3) Modifier/Supprimer un capteur.\n");
        printf(" 4) Rechercher un capteur\n");
        printf(" 0) Quitter\n");
        printf("Choix : ");
		scanf("%d",&numf);
		}
		while (numf<=1 && numf>=5);
		
		switch (numf)
		{
			case 1:
			    lister_capt();
				break;
			case 2:
				ajou_capt();
				break;
			case 3:
				 Modif_supp_capt();
				break;
			case 4:
				 Chercher_capt();
				break;
			case 0:
				return 0;
				break;
	 	
}
 }
}














void afficher_capteur(capteur A)
{
 printf("ID: %s | marque: %s | precision: %f | type: %s  | date d'ajoute: %d %s %d \n" ,A.ID,A.marque,A.precision,A.type,A.date.day,A.date.month,A.date.year);
}


void Ajouter_capteur(capteur *Aj)
{
  printf("donner l'ID de capteur\n");
  scanf("%s",Aj->ID);
  fflush(stdin);
  printf("donner la marque de capteur \n");
  scanf("%s",Aj->marque);
  fflush(stdin);
  printf("donner la précision \n ");
  scanf("%f",&Aj->precision);
  fflush(stdin);
  printf("donner type de capteur\n");
  scanf("%s",Aj->type);
  fflush(stdin);
  printf("donner le date d'ajoute de capteur ");
  scanf("%d %s %d",&Aj->date.day,Aj->date.month,&Aj->date.year);




}



void Modif_supp_capt()
	{
	FILE *f, *t;
	char choix;
	capteur M;
	char id_rech[15];
	
	f=fopen("capteur.txt","r");
	t=fopen("tmp_capt.txt","w"); 
	if(f !=NULL && t !=NULL)
	{
	printf("donner l' ID de capteur");
	fflush(stdin);
	scanf("%s",id_rech);
	while(fscanf(f,"%s %s %f %s %d %s %d \n",M.ID,M.marque,&M.precision,M.type,&M.date.day,M.date.month,&M.date.year)!=EOF)
	{
	if (strcmp(M.ID,id_rech) == 0 )
		{
		afficher_capteur(M);
		printf("voulez vous modifier ou supprimer le capteur \n");
		printf("ecrire s : pour supprimer \n"); 
		printf("ecrire m : pour modifier \n");
		printf("ecrire i : pour ignorer \n"); 
		getchar();
		scanf("%c",&choix);
		switch (choix)
		{
			case 's':
			break;

			case 'm' :
			printf("Chosen m");
			modifier_capteur(&M);
			fprintf(t,"%s %s %f %s %d %s %d\n",M.ID,M.marque,M.precision,M.type,M.date.day,M.date.month,M.date.year);	
			break;

			case 'i' :
			fprintf(t,"%s %s %f %s %d %s %d\n",M.ID,M.marque,M.precision,M.type,M.date.day,M.date.month,M.date.year);
			break;
		}
		}
		else
		fprintf(t,"%s %s %f %s %d %s %d\n",M.ID,M.marque,M.precision,M.type,M.date.day,M.date.month,M.date.year);		
		}
		fclose(t);
		fclose(f);
		
	remove("capteur.txt");
	rename("tmp_capt.txt","capteur.txt");
	
	
		}
		}


void modifier_capteur(capteur *M)
{
  printf("l'ID du capteur est %s\n", M->ID);
  printf("donner la marque de capteur \n");
  fflush(stdin);
  scanf("%s",M->marque);
  printf("donner la précision de capteur\n ");
  fflush(stdin);
  scanf("%f",&M->precision);
  printf("donner la type de capteur\n");
  fflush(stdin);
  scanf("%s",M->type);
  printf("donner le date d'ajoute de capteur ");
  fflush(stdin);
  scanf("%d %s %d",&M->date.day,M->date.month,&M->date.year);
}

int Chercher_capt()
	{
	FILE * f;
	char choix;
	capteur M;
	char id_rech[15];
	
	f=fopen("capteur.txt","r");
	if(f !=NULL)
	{
	printf("donner l' ID de capteur");
	fflush(stdin);
	scanf("%s",id_rech);
	while(fscanf(f,"%s %s %f %s %d %s %d\n",M.ID,M.marque,&M.precision,M.type,&M.date.day,M.date.month,&M.date.year)!=EOF)
	{
	if (strcmp(M.ID,id_rech) == 0 )
		{
		afficher_capteur(M);
		}
	else
		fprintf(f,"%s %s %f %s %d %s %d\n",M.ID,M.marque,M.precision,M.type,M.date.day,M.date.month,M.date.year);		
		}
		
		fclose(f);
		}
		}

void lister_capt()
{
FILE * f;
capteur A;
f=fopen("capteur.txt","r");
printf("***affichage de capteur***\n");

			if(f!=NULL)
			{
			while(fscanf(f,"%s %s %f  %s %d %s %d\n",A.ID,A.marque,&A.precision,A.type,&A.date.day,A.date.month,&A.date.year)!=EOF)
	 		{
	 		afficher_capteur(A) ;
	 		}
	 		fclose(f);
	 		}
	 		else 
	 		printf("Impossible d'ouvrir le fichier ");
	 		
}
void ajou_capt()
{
FILE * f;
capteur A;
f=fopen("capteur.txt","a+");

			if(f!=NULL)
			{
	 		Ajouter_capteur(&A);
	 		fprintf(f,"%s %s %f %s %d %s %d\n",A.ID,A.marque,A.precision,A.type,A.date.day,A.date.month,A.date.year);
	 		
	 		fclose(f);
	 		}
	 		else 
	 		printf("Impossible d'ouvrir le fichier ");
}        