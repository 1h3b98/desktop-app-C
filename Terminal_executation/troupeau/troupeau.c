#include <stdio.h>
#include <stdlib.h>
#include "troupeau.h"
#include <string.h>


int ges_troupeaux_screen()
{
int numf; 
 while (1)
 {
 	do
 	{
		printf("\n ===================================\n");
        printf("||        Gestion Troupeaux        ||\n");
        printf(" ===================================\n");
        printf(" 1) Afficher la liste des troupeaux.\n");
    	printf(" 2) Ajouter un nouveau troupeau.\n");
    	printf(" 3) Modifier/Supprimer un troupeau.\n");
        printf(" 4) Rechercher un troupeau\n");
        printf(" 0) Quitter\n");
        printf("Choix : ");
		scanf("%d",&numf);
		}
		while (numf<=1 && numf>=5);
		
		switch (numf)
		{
			case 1:
				lister_troup();
				break;
			case 2:
				ajou_troup();
				break;
			case 3:
				Modif_supp_troup();
				break;
			case 4:
				Chercher_troup();
				break;
			case 0:
				return 0;
				break;
	 	
}
 }
}



void Afficher_troup(Troupeau A)
{
 printf("ID: %s | type: %s | nourriture: %s | sante: %s | sexe:%s | date d'ajoute: %d %s %d \n" ,A.ID,A.type,A.nourriture,A.sante,A.sexe,A.date.day,A.date.month,A.date.year);
}
void Ajouter_troup(Troupeau *Aj)
{
  printf("donner l'ID de troupeau\n");
  scanf("%s",Aj->ID);
  fflush(stdin);
  printf("donner la type de troupeau \n");
  scanf("%s",Aj->type);
  fflush(stdin);
  printf("donner la nourriture de troupeau\n ");
  scanf("%s",Aj->nourriture);
  fflush(stdin);
  printf("donner la santé de troupeau\n");
  scanf("%s",Aj->sante);
  printf("donner le sexe de troupeau \n");
  scanf("%s",Aj->sexe);
  fflush(stdin);
  printf("donner le date d'ajoute de troupeau ");
  scanf("%d %s %d",&Aj->date.day,Aj->date.month,&Aj->date.year);
}
void Modif_supp_troup()
	{
	FILE *f, *t;
	char choix;
	Troupeau M;
	char id_rech[15];
	
	f=fopen("troupeau.txt","r");
	t=fopen("tmp_troup.txt","w"); 
	if(f !=NULL && t !=NULL)
	{
	printf("donner le ID de troupeau");
	fflush(stdin);
	scanf("%s",id_rech);
	while(fscanf(f,"%s %s %s %s %s %d %s %d \n",M.ID,M.type,M.nourriture,M.sante,M.sexe,&M.date.day,M.date.month,&M.date.year)!=EOF)
	{
	if (strcmp(M.ID,id_rech) == 0 )
		{
		Afficher_troup(M);
		printf("voulez vous modifier ou supprimer le troupeau \n");
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
			modif_troup(&M);
			fprintf(t,"%s %s %s %s %s %d %s %d \n",M.ID,M.type,M.nourriture,M.sante,M.sexe,M.date.day,M.date.month,M.date.year);	
			break;

			case 'i' :
			fprintf(t,"%s %s %s %s %s %d %s %d \n",M.ID,M.type,M.nourriture,M.sante,M.sexe,M.date.day,M.date.month,M.date.year);
			break;
		}
		}
		else
		fprintf(t,"%s %s %s %s %s %d %s %d \n",M.ID,M.type,M.nourriture,M.sante,M.sexe,M.date.day,M.date.month,M.date.year);		
		}
		fclose(t);
		fclose(f);
		
	remove("troupeau.txt");
	rename("tmp_troup.txt","troupeau.txt");
	
	
		}
		}


void modif_troup(Troupeau *M)
{
  printf("l'ID du troupeau est %s\n", M->ID);
  printf("donner la type de troupeau \n");
  fflush(stdin);
  scanf("%s",M->type);
  printf("donner la nourriture de troupeau\n ");
  fflush(stdin);
  scanf("%s",M->nourriture);
  printf("donner la santé de troupeau\n");
  fflush(stdin);
  scanf("%s",M->sante);
  printf("donner le sexe de troupeau \n");
  fflush(stdin);
  scanf("%s",M->sexe);
  printf("donner le date d'ajoute de troupeau ");
  fflush(stdin);
  scanf("%d %s %d",&M->date.day,M->date.month,&M->date.year);
}
	
	
	
	

int Chercher_troup()
	{
	FILE * f;
	char choix;
	Troupeau M;
	char id_rech[15];
	
	f=fopen("troupeau.txt","r");
	if(f !=NULL)
	{
	printf("donner le ID de troupeau");
	fflush(stdin);
	scanf("%s",id_rech);
	while(fscanf(f,"%s %s %s %s %s %d %s %d \n",M.ID,M.type,M.nourriture,M.sante,M.sexe,&M.date.day,M.date.month,&M.date.year)!=EOF)
	{
	if (strcmp(M.ID,id_rech) == 0 )
		{
		Afficher_troup(M);
		}
	else
		fprintf(f,"%s %s %s %s %s %d %s %d \n",M.ID,M.type,M.nourriture,M.sante,M.sexe,M.date.day,M.date.month,M.date.year);		
		}
		
		fclose(f);
		}
		}
		
void lister_troup()
{
FILE * f;
Troupeau tmp_troup;
f=fopen("troupeau.txt","r");
printf("<=====affichage de troupeau=======>\n");

			if(f!=NULL)
			{
			while(fscanf(f,"%s %s %s %s %s %d %s %d \n",tmp_troup.ID,tmp_troup.type,tmp_troup.nourriture,tmp_troup.sante,tmp_troup.sexe,&tmp_troup.date.day,tmp_troup.date.month,&tmp_troup.date.year)!=EOF)
	 		{
	 		Afficher_troup(tmp_troup) ;
	 		}
	 		fclose(f);
	 		}
	 		else 
	 		printf("Impossible d'ouvrir le fichier ");
	 		
}
void ajou_troup()
{
FILE * f;
Troupeau tmp_troup;
f=fopen("troupeau.txt","a+");

			if(f!=NULL)
			{
	 		Ajouter_troup(&tmp_troup);
	 		fprintf(f,"%s %s %s %s %s %d %s %d \n",tmp_troup.ID,tmp_troup.type,tmp_troup.nourriture,tmp_troup.sante,tmp_troup.sexe,tmp_troup.date.day,tmp_troup.date.month,tmp_troup.date.year);
	 		
	 		fclose(f);
	 		}
	 		else 
	 		printf("Impossible d'ouvrir le fichier ");
}
	

