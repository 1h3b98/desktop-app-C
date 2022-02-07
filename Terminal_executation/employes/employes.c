#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employes.h"

char employ_file_location[] = "employes.txt";
char connection_file_location[] = "connexions.txt";
char employ_file_location_tmp[] = "tmp_employes.txt";
char connection_file_location_tmp[] = "tmp_connexions.txt";

int ges_employes_screen()
{
    int choix;
    char chr_tmp[20];
    while(1)
    {
        do
        {
            printf("\n ===================================\n");
            printf("||          Gestion Employes          ||\n");
            printf(" ===================================\n");
            printf(" 1) Afficher tous employes.\n");
            printf(" 2) Ajouter Employes.\n");
            printf(" 3) Chercher Employes.\n");
            printf(" 4) Modifier/Supprimer Employer\n");
            printf(" 0) Quitter\n");
            printf("Choix : ");
            scanf("%d",&choix);
        }while ((choix > 2) && (choix < 0));
        switch (choix)
        {
        case 0:
            return 0;
            break;
        
        case 1:
            lister_employer();
            break;

        case 2:
            ajout_employer();
            break;
        case 3:
            printf("Donner l'identifiant a rechercher : ");
            fflush(stdin);
            scanf("%s",chr_tmp);
            chercher_employer(chr_tmp);
            break;
        case 4:
            modif_supp_employer();
        }
        
    }    
}

int user_type(char ur[], char ps[])
{
    FILE * f_lg;
    char usrid[20], usrpass[20];
    int role; 
    f_lg = fopen(connection_file_location, "r+");
    if (f_lg != NULL)
    {
        while (fscanf(f_lg, "%s %s %d", usrid, usrpass, &role) != EOF)
        {
            if (strcmp(ur,usrid) == 0)
            {
                if (strcmp(ps, usrpass) == 0)
                {
                    fclose(f_lg);
                    return role;
                }
                else
                {
                    fclose(f_lg);
                    return 3;
                }
            }
        }
        fclose(f_lg);
        return 4;
    }
    else
    {
        return 4;
        exit(0);
    }
}

void lister_employer()
{
    FILE * f_employes;
    FILE * f_conx ;
    char tmp_id[20];
    employes tmp_emp;
    f_employes = fopen(employ_file_location, "r+");
    if (f_employes != NULL)
    {
        while (fscanf(f_employes, "%s %s %s %s %s %s %s %s %s %s %s\n", tmp_emp.username, tmp_emp.cin, tmp_emp.prenom, tmp_emp.nom, tmp_emp.sexe, tmp_emp.naissance.jour,
        tmp_emp.naissance.mois, tmp_emp.naissance.annee, tmp_emp.telnumbr, tmp_emp.mail, tmp_emp.adresse) != EOF)
        {
            f_conx = fopen(connection_file_location, "r+");
            if (f_conx != NULL)
            {
                while ((fscanf(f_conx, "%s %s %d %s %s %s",tmp_id, tmp_emp.password, &tmp_emp.access, tmp_emp.last_access.jour, tmp_emp.last_access.mois, tmp_emp.last_access.annee ) != EOF) 
                && (strcmp(tmp_id, tmp_emp.username) != 0))
                {
                    tmp_emp.access = 3;
                    strcpy(tmp_emp.password, "NOT FOUND");
                    strcpy(tmp_emp.last_access.mois, "Never");
                }
                fclose(f_conx);
                afficher_employer(tmp_emp);
            }
            else
             {
                printf("ERREUR FILE CONNEXION.TXT");
                exit(0);
             }
            
        }  
    }
    else 
    {
        printf("ERREUR FILE EMPLOYES.TXT");
    }
}


void afficher_employer(employes vemp)
{
    printf("Identifiant : %s, MDP : %s, CIN : %s, Prenom : %s, Nom : %s, Sexe : %s, Naissance : %s/%s/%s, Tel : %s, Mail : %s, Adresse : %s, Accés autorisé : ",vemp.username,
    vemp.password, vemp.cin, vemp.prenom, vemp.nom, vemp.sexe, vemp.naissance.jour, vemp.naissance.mois, vemp.naissance.annee, vemp.telnumbr, vemp.mail, vemp.adresse);
    if (vemp.access == 1) printf("oui");
    else printf("non");
    printf(", Dernier access : ");
    if (strcmp(vemp.last_access.mois, "Never")== 0) printf("Jamais.\n");
    else printf("%s/%s/%s\n",vemp.last_access.jour, vemp.last_access.mois, vemp.last_access.annee);
}

void ajout_employer()
{
    FILE * f_emp;
    FILE * f_conx;
    employes tmp_emp;
    saisie_employer(&tmp_emp);
    f_emp = fopen(employ_file_location, "a+");
    if (f_emp != NULL)
    {
        fprintf(f_emp, "%s %s %s %s %s %s %s %s %s %s %s\n", tmp_emp.username, tmp_emp.cin, tmp_emp.prenom, tmp_emp.nom, tmp_emp.sexe, tmp_emp.naissance.jour,
        tmp_emp.naissance.mois, tmp_emp.naissance.annee, tmp_emp.telnumbr, tmp_emp.mail, tmp_emp.adresse);
        fclose(f_emp);
    }
    else
    {
        printf("Erreur ajout au fichier employes.txt\n");
    }
    
    f_conx = fopen(connection_file_location, "a+");
    if (f_conx != NULL)
    {
        fprintf(f_conx, "%s %s %d %s %s %s\n",tmp_emp.username, tmp_emp.password, tmp_emp.access, tmp_emp.last_access.jour, tmp_emp.last_access.mois, tmp_emp.last_access.annee );
        fclose(f_emp);
    }
    else
    {
        printf("Erreur ajout au fichier connexion.txt\n");
    } 

}



void modifier_employer(employes *pemp)
{
    char tmp[20] = "";
    printf("Modification de l'Identifiant : %s\n",pemp->username);
    printf("Ancien Prenom (%s) ('s' pour passer): ",pemp->prenom);
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1)))
    {
        strcpy(pemp->prenom, tmp);
    }
    strcpy(tmp, "");

    printf("Ancien Nom (%s) ('s' pour passer): ", pemp->nom);
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1)))
    {
        strcpy(pemp->nom, tmp);
    }
    strcpy(tmp, "");

    printf("Ancien MDP (%s) ('s' pour passer): ", pemp->password);
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1)))
    {
        strcpy(pemp->password, tmp);
    }
    strcpy(tmp, "");

    printf("Ancien Sexe (%s) ('s' pour passer): ", pemp->sexe);
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1)))
    {
        strcpy(pemp->sexe, tmp);
    }
    strcpy(tmp, "");
    
    printf("Ancien date de naissance (%s/%s/%s) ('s' pour passer): ", pemp->naissance.jour, pemp->naissance.mois, pemp->naissance.annee);
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1)))
    {
        strcpy(pemp->naissance.jour, tmp);
        fflush(stdin);
        scanf("%s",pemp->naissance.mois);
        fflush(stdin);
        scanf("%s",pemp->naissance.annee);
    }
    strcpy(tmp, "");

    printf("Ancien Tel (%s) ('s' pour passer): ", pemp->telnumbr);
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1)))
    {
        strcpy(pemp->telnumbr, tmp);
    }
    strcpy(tmp, "");

    printf("Ancien mail (%s) ('s' pour passer): ", pemp->mail);
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1)))
    {
        strcpy(pemp->mail, tmp);
    }
    strcpy(tmp, "");

    printf("Ancienne Adresse (%s) ('s' pour passer): ", pemp->adresse);
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1)))
    {
        strcpy(pemp->adresse, tmp);
    }
    strcpy(tmp, "");

    printf("Ancien droit d'accée (Autorisé : ");
    if (pemp->access == 1)
    {
        printf("Oui) ('s' pour passer | 1 pour oui | 0 pour non):");
    }
    else
    {
        printf("Non) ('s' pour passer | 1 pour oui | 0 pour non):");
    }
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1))&&((tmp[0] == '0') || (tmp[0] == '1')))
    {
        if (tmp[0] == '1')
        {
            pemp->access = 1;
        }
        else pemp->access = 0; 
    }
    strcpy(tmp, "");
}


void modif_supp_employer()
{
    printf("Hello World in modif supp employes\n");
    FILE *f_employes, *f_employes_tmp;
    FILE *f_conx, *f_conx_tmp;
    char tmp_id[20], smt[20];
    char choix;
    employes tmp_emp;
    printf("Donner l'identifiant de l'employes : ");
    fflush(stdin);
    scanf("%s", smt);
    f_employes = fopen(employ_file_location, "r+");
    f_employes_tmp = fopen(employ_file_location_tmp, "w+");
    if (f_employes != NULL && f_employes_tmp != NULL)
    {
        while (fscanf(f_employes, "%s %s %s %s %s %s %s %s %s %s %s\n", tmp_emp.username, tmp_emp.cin, tmp_emp.prenom, tmp_emp.nom, tmp_emp.sexe, tmp_emp.naissance.jour,
        tmp_emp.naissance.mois, tmp_emp.naissance.annee, tmp_emp.telnumbr, tmp_emp.mail, tmp_emp.adresse) != EOF)
        {
            f_conx = fopen(connection_file_location, "r+");
            f_conx_tmp = fopen(connection_file_location_tmp, "a+");
            if (f_conx != NULL && f_conx_tmp != NULL)
            {
                while ((fscanf(f_conx, "%s %s %d %s %s %s",tmp_id, tmp_emp.password, &tmp_emp.access, tmp_emp.last_access.jour, tmp_emp.last_access.mois, tmp_emp.last_access.annee ) != EOF) 
                && (strcmp(tmp_id, tmp_emp.username) != 0))
                {
                    tmp_emp.access = 3;
                    strcpy(tmp_emp.password, "NOT FOUND");
                    strcpy(tmp_emp.last_access.mois, "Never");
                }
                fclose(f_conx);
                if (strstr(tmp_emp.username, smt) != NULL)
                {
                    afficher_employer(tmp_emp);
                    do
                    {
                        printf("Choisir ('m' modifier, 's' supprimer, 'i', ignorer) :");
                        fflush(stdin);
                        getchar();
                        scanf("%c", &choix);
                    } while ((choix != 'm') && (choix  != 's') && (choix != 'i'));
                    switch (choix)
                    {
                    case 'm':
                        modifier_employer(&tmp_emp);
                        fprintf(f_employes_tmp, "%s %s %s %s %s %s %s %s %s %s %s\n", tmp_emp.username, tmp_emp.cin, tmp_emp.prenom, tmp_emp.nom, tmp_emp.sexe, tmp_emp.naissance.jour,
                        tmp_emp.naissance.mois, tmp_emp.naissance.annee, tmp_emp.telnumbr, tmp_emp.mail, tmp_emp.adresse);
                        fprintf(f_conx_tmp, "%s %s %d %s %s %s\n",tmp_emp.username, tmp_emp.password, tmp_emp.access, tmp_emp.last_access.jour, tmp_emp.last_access.mois, tmp_emp.last_access.annee );
                        break;
                    
                    case 's':
                        printf("Deleted \n");
                        break;
                    case 'i':
                        fprintf(f_employes_tmp, "%s %s %s %s %s %s %s %s %s %s %s\n", tmp_emp.username, tmp_emp.cin, tmp_emp.prenom, tmp_emp.nom, tmp_emp.sexe, tmp_emp.naissance.jour,
                        tmp_emp.naissance.mois, tmp_emp.naissance.annee, tmp_emp.telnumbr, tmp_emp.mail, tmp_emp.adresse);
                        fprintf(f_conx_tmp, "%s %s %d %s %s %s\n",tmp_emp.username, tmp_emp.password, tmp_emp.access, tmp_emp.last_access.jour, tmp_emp.last_access.mois, tmp_emp.last_access.annee );
                        break;
                    }
                }
                else
                {
                    fprintf(f_employes_tmp, "%s %s %s %s %s %s %s %s %s %s %s\n", tmp_emp.username, tmp_emp.cin, tmp_emp.prenom, tmp_emp.nom, tmp_emp.sexe, tmp_emp.naissance.jour,
                    tmp_emp.naissance.mois, tmp_emp.naissance.annee, tmp_emp.telnumbr, tmp_emp.mail, tmp_emp.adresse);
                    fprintf(f_conx_tmp, "%s %s %d %s %s %s\n",tmp_emp.username, tmp_emp.password, tmp_emp.access, tmp_emp.last_access.jour, tmp_emp.last_access.mois, tmp_emp.last_access.annee ); 
                }
               
            fclose(f_conx_tmp);
            }
            else
             {
                printf("ERREUR FILE CONNEXION.TXT");
                exit(0);
             }
            
        }
        fclose(f_employes);
        fclose(f_employes_tmp);
        f_conx = fopen(connection_file_location, "r+");
        f_conx_tmp = fopen(connection_file_location_tmp, "a+");
        if ((f_conx_tmp != NULL) && (f_conx != NULL))
        {
            while (fscanf(f_conx, "%s %s %d %s %s %s",tmp_emp.username, tmp_emp.password, &tmp_emp.access, tmp_emp.last_access.jour, tmp_emp.last_access.mois, tmp_emp.last_access.annee ) != EOF)
            {
                if (tmp_emp.access == 2)
                {
                    fprintf(f_conx_tmp, "%s %s %d %s %s %s\n",tmp_emp.username, tmp_emp.password, tmp_emp.access, tmp_emp.last_access.jour, tmp_emp.last_access.mois, tmp_emp.last_access.annee );
                }
                tmp_emp.access = 4;
            }
            fclose(f_conx_tmp);
            fclose(f_conx);
        }
        remove(employ_file_location);
        remove(connection_file_location);
        rename(employ_file_location_tmp, employ_file_location);
        rename(connection_file_location_tmp, connection_file_location);
    }
    else 
    {
        printf("ERREUR FILE EMPLOYES.TXT");
    }

}


void saisie_employer(employes * pemp)
{
    char noth[] = "";
	printf("Remplisage d'un employe(e)\n");
    do
    {
        printf("Donner l'identifiant : \n");
        fflush(stdin);
        //fgets(pemp->username, size_of(pemp->username), stdin);
        //pemp->username[strlen(pemp->username) -1] = '\0';
        scanf("%s",pemp->username);
    } while (user_type(pemp->username, noth) != 4);
    printf("Donner le mdp : \n");
    fflush(stdin);
    //getchar();
    //fgets(pemp->password, sizeof(pemp->password), stdin);
    //pemp->password[strlen(pemp->password)-1] = '\0';
    scanf("%s",pemp->password);
    printf("Donner le CIN : \n");
    fflush(stdin);
    scanf("%s",pemp->cin);
    printf("Donner Prenom : \n");
    fflush(stdin);
    //getchar();
    //fgets(pemp->prenom, sizeof(pemp->prenom), stdin);
    //pemp->prenom[strlen(pemp->prenom)-1] = '\0';
    scanf("%s", pemp->prenom);
    printf("Donner le Nom : \n");
    fflush(stdin);
    //getchar();
    //fgets(pemp->nom, sizeof(pemp->nom), stdin);
    //pemp->nom[strlen(pemp->nom)-1] = '\0';
    scanf("%s", pemp->nom);
    printf("Donner le sexe : \n");
    fflush(stdin);
    scanf("%s",pemp->sexe);
    printf("Donner la date de naissance : \n");
    fflush(stdin);
    scanf("%s",pemp->naissance.jour);
    fflush(stdin);
    scanf("%s",pemp->naissance.mois);
    fflush(stdin);
    scanf("%s",pemp->naissance.annee);
    printf("Donner le tel : \n");
    fflush(stdin);
    scanf("%s",pemp->telnumbr);
    printf("Donner le mail : \n");
    fflush(stdin);
    scanf("%s",pemp->mail);
    printf("Donner l'adresse : \n");
    fflush(stdin);
    //getchar();
    //fgets(pemp->adresse, sizeof(pemp->adresse), stdin);
    //pemp->adresse[strlen(pemp->adresse)-1] = '\0';
    scanf("%s", pemp->adresse);
    strcpy(pemp->last_access.jour,"00");
    strcpy(pemp->last_access.mois,"Never");
    strcpy(pemp->last_access.annee,"0000");
    do
    {
        printf("Autorisé l'acces (1 pour oui | 0 pour non) : ");
        fflush(stdin);
        getchar();
        scanf("%d",&pemp->access);
    } while (pemp->access != 1 && pemp -> access != 0);
}

void supprimer_employer(employes * pemp)
{
	printf("Programme vide\n");
}

void chercher_employer(char smt[])
{
    FILE * f_employes;
    FILE * f_conx ;
    char tmp_id[20];
    employes tmp_emp;
    f_employes = fopen(employ_file_location, "r+");
    if (f_employes != NULL)
    {
        while (fscanf(f_employes, "%s %s %s %s %s %s %s %s %s %s %s\n", tmp_emp.username, tmp_emp.cin, tmp_emp.prenom, tmp_emp.nom, tmp_emp.sexe, tmp_emp.naissance.jour,
        tmp_emp.naissance.mois, tmp_emp.naissance.annee, tmp_emp.telnumbr, tmp_emp.mail, tmp_emp.adresse) != EOF)
        {
            f_conx = fopen(connection_file_location, "r+");
            if (f_conx != NULL)
            {
                while ((fscanf(f_conx, "%s %s %d %s %s %s",tmp_id, tmp_emp.password, &tmp_emp.access, tmp_emp.last_access.jour, tmp_emp.last_access.mois, tmp_emp.last_access.annee ) != EOF) 
                && (strcmp(tmp_id, tmp_emp.username) != 0))
                {
                    tmp_emp.access = 3;
                    strcpy(tmp_emp.password, "NOT FOUND");
                    strcpy(tmp_emp.last_access.mois, "Never");
                }
                fclose(f_conx);
                if (strstr(tmp_emp.username, smt) != NULL)
                {
                    afficher_employer(tmp_emp);
                }
            }
            else
             {
                printf("ERREUR FILE CONNEXION.TXT");
                exit(0);
             }
            
        }  
    }
    else 
    {
        printf("ERREUR FILE EMPLOYES.TXT");
    }
}

