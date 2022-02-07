
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ouvrier.h"


void ges_ouvrier_screen()
{
        int choix;
        do{
        affichMenu ();
        choix = getChoix ();
        switch (choix){
        case 2 : ajouter_ouvrier ();break;
        case 4: modifier_ouvrier ();break;
        case 5: supprimer_ouvrier ();break;
        case 1: lister_ouvrier();break;
        case 3: rechercher_ouvrier ();break;
        }
        }while (choix != 0);
}


void affichMenu (){

            printf("\n ===================================\n");
            printf("||          Gestion Ouvrier          ||\n");
            printf(" ===================================\n");
            printf(" 1) Afficher tous les ouvrier.\n");
            printf(" 2) Ajouter un ouvrier.\n");
            printf(" 3) Chercher un ouvrier.\n");
            printf(" 4) Modifier ouvrier\n");
            printf(" 5) Supprimer ouvrier\n");
            printf(" 0) Quitter\n");
            printf("Choix : ");
}

int getChoix (){
int x;
do{
printf ("Donner votre choix : ");
scanf ("%d",&x);
}while ((x>5) || (x<0));

return x;
}


//recherche par id
int rech(char id_rech[])
{
        FILE *f_ouv;
        ouvrier o;
        f_ouv=fopen("ouvriers.txt","r");
        while (fscanf(f_ouv,"%s %s %d %s %ld %d %d %d %s %s\n",o.nom,o.prenom,&o.sexe,o.id,&o.tel,&o.date.jour,&o.date.mois,&o.date.annee,o.fonction,o.adresse)!=EOF)
        {
                if (strcmp(id_rech,o.id)==0)
                {
                        fclose(f_ouv);
                        return 1;
                }
        }
        fclose(f_ouv);
        return 0;
}

//************ saisie_ouvrier************
void saisie_ouvrier(ouvrier *o)
{	
	char nv_id[10];
        do
        {
                printf("\n Entrez un nouveau id:");
                fflush(stdin);
	        scanf("%s",nv_id);
                if(rech(nv_id)==1)
        	{
   	                printf("Cet id existe deja\n");
	        }
        } while (rech(nv_id)==1);
        strcpy(o->id,nv_id);
	printf("Donnez le nom d'ouvrier\n");
        fflush(stdin);
        scanf("%s",o->nom);
        printf("Donnez le prenom de l'ouvrier \n");
        fflush(stdin);
        scanf("%s",o->prenom);
	do{
        printf("Donnez le sexe (1:femme,0:homme)\n ");
        scanf("%d",&o->sexe);
	}while((o->sexe!=1) && (o->sexe!=0));
        printf("Donnez le numéro de telephone \n");
        scanf("%ld",&o->tel);
	do{
        printf("Donnez la date (jour) ");
        scanf("%d",&o->date.jour);
        }while((o->date.jour<=0) && (o->date.jour>=31));
	do {
	printf("Donnez la date (mois) ");
        scanf("%d",&o->date.mois);
        }while((o->date.mois<=0) && (o->date.mois)>12);
	do { printf("Donnez la date (annee) ");
        scanf("%d",&o->date.annee);}
        while ((o->date.annee<=2010) && (o->date.annee>2020));
        printf("Donnez la fonction  \n");
        fflush(stdin);
        scanf("%s",o->fonction);
        printf("Donnez l'adresse \n");
        fflush(stdin);
        scanf("%s",o->adresse); 
}
 //**************** fonction ajouter ********************************************   
void ajouter_ouvrier()
{FILE *f_ouv;
 ouvrier ouv;
f_ouv=fopen("ouvriers.txt","a");
if(f_ouv!=NULL)
{
saisie_ouvrier(&ouv);
fprintf(f_ouv,"%s %s %d %s %ld %d %d %d %s %s\n",ouv.nom,ouv.prenom,ouv.sexe,ouv.id,ouv.tel,ouv.date.jour,ouv.date.mois,ouv.date.annee,ouv.fonction,ouv.adresse);
        fclose(f_ouv);
        }else{
	 		printf("Impossible d'ouvrir le fichier ");}
}
// ***************fonction rechercher**************
void rechercher_ouvrier()
{
char id_rech[10];
FILE *f_ouv;
ouvrier o;
printf("donnez l'id de l'ouvrier à affichier\n");
scanf("%s",id_rech);
f_ouv=fopen("ouvriers.txt","r");
while (fscanf(f_ouv,"%s %s %d %s %ld %d %d %d %s %s\n",o.nom,o.prenom,&o.sexe,o.id,&o.tel,&o.date.jour,&o.date.mois,&o.date.annee,o.fonction,o.adresse)!=EOF)
{
if(strcmp(id_rech,o.id)==0)
{
 afficher_ouvrier(o);
}
}
fclose(f_ouv);
}
//************* supprimer************
void supprimer_ouvrier()
{ouvrier o;
  char rep;
  char id_sup[20];
  FILE *Fich,*f_ouv;
  printf("entrer le num de l'ouvrier que vous voulez supprimer:");
  fflush(stdin);
  scanf("%s",id_sup);
  
          f_ouv=fopen("ouvriers.txt","r");
          Fich=fopen("Tempouvriers.txt","a");
        
          while(fscanf(f_ouv,"%s %s %d %s %ld %d %d %d %s %s\n",o.nom,o.prenom,&o.sexe,o.id,&o.tel,&o.date.jour,&o.date.mois,&o.date.annee,o.fonction,o.adresse)!=EOF)
	{
    	  if (strcmp(id_sup,o.id)!=0)
			{
               fprintf(Fich,"%s %s %d %s %ld %d %d %d %s %s\n",o.nom,o.prenom,o.sexe,o.id,o.tel,o.date.jour,o.date.mois,o.date.annee,o.fonction,o.adresse);
}}
          fclose(Fich);
          fclose (f_ouv);
          remove("ouvriers.txt");
          rename("Tempouvriers.txt","ouvriers.txt");
          printf("supression reussite");

      }

//*******modifier************************
void modifier_ouvrier()
{
FILE *Fich,*f_ouv;
char id_mod[10];
ouvrier o;

printf("entrer le num de l'ouvrier que vous voulez modifier:");
fflush(stdin);  
scanf("%s",id_mod);
  

          f_ouv=fopen("ouvriers.txt","r");
          Fich=fopen("Tempouvriers.txt","w");
          if ( f_ouv != NULL)
          {
        while(fscanf(f_ouv,"%s %s %d %s %ld %d %d %d %s %s\n",o.nom,o.prenom,&o.sexe,o.id,&o.tel,&o.date.jour,&o.date.mois,&o.date.annee,o.fonction,o.adresse)!=EOF)
                      { if (strcmp(id_mod,o.id)==0)
                       {
                   
        printf("Donnez le nv nom d'ouvrier\n");
        scanf("%s",o.nom);
        printf("Donnez le  nv prenom de l'ouvrier \n");
        scanf("%s",o.prenom);
        do { 
		printf("Donnez le sexe (1:femme,0:homme)\n ");
        scanf("%d",&o.sexe);}while ((o.sexe)!=1  && (o.sexe)!=0);

        printf("Donnez le  nv numéro de telephone \n");
        scanf("%ld",&o.tel);
	do{	
        printf("Donnez la nouvelle date (jour) ");
        scanf("%d",&o.date.jour);}while((o.date.jour)<0 && (o.date.jour)>=31);
	do{	
        printf("Donnez la nouvelle date (mois) ");
        scanf("%d",&o.date.mois);}while((o.date.mois)<0 && (o.date.mois)>=12);
	do{	
        printf("Donnez la nouvelle date (annee) ");
        scanf("%d",&o.date.annee);}while((o.date.annee)<2015 && (o.date.annee)>=2020);
        printf("Donnez la nouvelle fonction  \n");
        scanf("%s",o.fonction);
        printf("Donnez la nouvelle adresse \n");
        scanf("%s",o.adresse);
      fprintf(Fich,"%s %s %d %s %ld %d %d %d %s %s\n",o.nom,o.prenom,o.sexe,o.id,o.tel,o.date.jour,o.date.mois,o.date.annee,o.fonction,o.adresse);
          }
          else 
           {
                        fprintf(Fich,"%s %s %d %s %ld %d %d %d %s %s\n",o.nom,o.prenom,o.sexe,o.id,o.tel,o.date.jour,o.date.mois,o.date.annee,o.fonction,o.adresse);
           }
                      }
          
          fclose(f_ouv);
          fclose (Fich);
          remove("ouvriers.txt");
          rename("Tempouvriers.txt","ouvriers.txt");
          printf("la modification est reussi");
          }
          else
          {
                  printf("Erreur fichier");
          }
          

}


//**************afficher*********

void afficher_ouvrier(ouvrier o)
{
       
        printf ("\n ");
        printf("%s\t\t",o.id);
        printf(" %s\t\t",o.nom);
        printf(" %s\t\t",o.prenom);
        printf(" %s\t\t\n",o.fonction);
    } 
          
void lister_ouvrier()
{ FILE *f_ouv;
ouvrier o;
f_ouv=fopen("ouvriers.txt","r");
if(f_ouv!=NULL){
            printf("la list des ouvriers est:\n \n");
    printf("id\t\t nom \t\t prenom\t\t fonction  \t\t");
while(fscanf(f_ouv,"%s %s %d %s %ld %d %d %d %s %s\n",o.nom,o.prenom,&o.sexe,o.id,&o.tel,&o.date.jour,&o.date.mois,&o.date.annee,o.fonction,o.adresse)!=EOF){ 
afficher_ouvrier(o);
}
fclose(f_ouv);
}
else
{
printf ("ce fichier n'existe pas ");
}
}

