#include "client.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char clients_file_location[] = "clients.txt";
char clients_file_location_tmp[] = "tmp_client.txt";


void ajouter_client(client *cli);
void supprimer_client(client *cli);
void afficher_client(client cli);
void chercher_client();
void modifier_client(client *cli);



int ges_clients_screen()
{
    int choix;
    char chr_cin[9];
    while(1)
    {
        do
        {
            printf("\n ===================================\n");
            printf("||          Gestion Clients          ||\n");
            printf(" ===================================\n");
            printf(" 1) Afficher tous les clients.\n");
            printf(" 2) Ajouter client.\n");
            printf(" 3) Chercher client.\n");
            printf(" 4) Modifier/Supprimer client\n");
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
            lister_clients();
            break;

        case 2:
            ajout_client();
            break;
        case 3:
            printf("Donner le cin a rechercher : ");
            fflush(stdin);
            scanf("%s",chr_cin);
            chercher_client(chr_cin);
            break;
        case 4:
            modif_supp_client();
        }
        
    }    
}


void saisie_client(client *pcli)
{
    printf("===============Ajouter Client===============\n");
    printf("Donner le CIN du client : ");
    scanf("%s", pcli->cinid);
    printf("Donner le prenom du client : ");
    fflush(stdin);
    scanf("%s",pcli->prenom);
    printf("Donner le nom du client : ");
    fflush(stdin);
    scanf("%s", pcli->nom);
    printf("Donner le sexe : ");
    fflush(stdin);
    scanf("%s", pcli->sexe);
    printf("Donner la date de la derniére visite : \n");
    fflush(stdin);
    scanf("%s", pcli->last_visite.jour);
    fflush(stdin);
    scanf("%s", pcli->last_visite.mois);
    fflush(stdin);
    scanf("%s", pcli->last_visite.annee);
    printf("Donner le number de tel du client : ");
    fflush(stdin);
    scanf("%s", pcli->telnumbr);
    printf("Donner d'adress mail : ");
    fflush(stdin);
    scanf("%s", pcli->mail);
    printf("Donner d'adress Adress : ");
    fflush(stdin);
    scanf("%s", pcli->adresse);
    }


void afficher_client(client vcli)
{
    printf("CIN : %s, Prenom : %s, Nom : %s, Sexe : %s, Date de la derniere visite : %s/%s/%s, Tel : %s, Mail : %s, Adresse : %s\n",vcli.cinid,vcli.prenom,vcli.nom,
    vcli.sexe, vcli.last_visite.jour, vcli.last_visite.mois, vcli.last_visite.annee, vcli.telnumbr, vcli.mail, vcli.adresse);
}

void chercher_client(char tmp_cin[])
{
    client tmp_cli;
    FILE * f_clients;

    f_clients = fopen(clients_file_location, "r+");
    if (f_clients != NULL)
    {
        while (fscanf(f_clients, "%s %s %s %s %s %s %s %s %s %s\n", tmp_cli.cinid, tmp_cli.prenom, tmp_cli.nom, tmp_cli.sexe, tmp_cli.last_visite.jour, tmp_cli.last_visite.mois, tmp_cli.last_visite.annee, 
        tmp_cli.telnumbr, tmp_cli.mail, tmp_cli.adresse) != EOF)
        {
            if (strstr(tmp_cli.cinid, tmp_cin) != NULL)
            {
                afficher_client(tmp_cli);
            }
        }
        fclose(f_clients);
    }
    else
    {
        printf("Erreur lecture fichier %s", clients_file_location);
    }
}
void modifier_client(client *pcli)
{
    char tmp[20] = "";
    printf("===============Modifier Client===============\n");
    printf("Le CIN du client est %s\n",pcli->cinid);
    printf("Ancien Prenom (%s) ('s' pour passer) : ",pcli->prenom);
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1)))
    {
        strcpy(pcli->prenom, tmp);
    }
    printf("Acien Nom (%s) ('s' pour passer) : ", pcli->nom);
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1)))
    {
        strcpy(pcli->nom, tmp);
    }

    printf("Acien sexe (%s) ('s' pour passer) : ", pcli->sexe);
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1)))
    {
        strcpy(pcli->sexe, tmp);
    }
    printf("Ancien date de la derniere visite (%s/%s/%s) ('s' pour passer): ", pcli->last_visite.jour, pcli->last_visite.mois, pcli->last_visite.annee);
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1)))
    {
        strcpy(pcli->last_visite.jour, tmp);
        fflush(stdin);
        scanf("%s",pcli->last_visite.mois);
        fflush(stdin);
        scanf("%s",pcli->last_visite.annee);
    }
    printf("Acien numero tel (%s) ('s' pour passer) : ",pcli->telnumbr);
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1)))
    {
        strcpy(pcli->telnumbr, tmp);
    }
    printf("Acien mail (%s) ('s' pour passer) : ", pcli->mail);
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1)))
    {
        strcpy(pcli->mail, tmp);
    }
    printf("Acienne adresse (%s) ('s' pour passer) : ", pcli->adresse);
    fflush(stdin);
    scanf("%s",tmp);
    if (!((tmp[0] =='s') && (strlen(tmp) == 1)))
    {
        strcpy(pcli->adresse, tmp);
    }
    }

void lister_clients()
{
    client tmp_cli;
    FILE * f_clients;

    f_clients = fopen(clients_file_location, "r+");
    if (f_clients != NULL)
    {
        while (fscanf(f_clients, "%s %s %s %s %s %s %s %s %s %s\n", tmp_cli.cinid, tmp_cli.prenom, tmp_cli.nom, tmp_cli.sexe, tmp_cli.last_visite.jour, tmp_cli.last_visite.mois, tmp_cli.last_visite.annee, 
        tmp_cli.telnumbr, tmp_cli.mail, tmp_cli.adresse) != EOF)
        {
            afficher_client(tmp_cli);
        }
    }
    else
    {
        printf("Erreur lecture fichier %s", clients_file_location);
    }
}

void ajout_client()
{
    client tmp_cli;
    FILE * f_clients;

    f_clients = fopen(clients_file_location, "a+");
    if (f_clients != NULL)
    {
        saisie_client(&tmp_cli);
        fprintf(f_clients, "%s %s %s %s %s %s %s %s %s %s\n", tmp_cli.cinid, tmp_cli.prenom, tmp_cli.nom, tmp_cli.sexe, tmp_cli.last_visite.jour, tmp_cli.last_visite.mois, tmp_cli.last_visite.annee, 
        tmp_cli.telnumbr, tmp_cli.mail, tmp_cli.adresse);
        fclose(f_clients);
        printf("Client Ajouté !! \n");
    }
    else
    {
        printf("Erreur d'ecriture sur le fichier %s", clients_file_location);
    }
}

void modif_supp_client()
{
    FILE *f_clients, *f_clients_tmp;
    client tmp_cli;
    char choix;
    char cin_rech[20];

    f_clients = fopen(clients_file_location, "r+");
    f_clients_tmp = fopen(clients_file_location_tmp, "w");
    if (f_clients_tmp != NULL && f_clients != NULL)
    {
        printf("Donner le cin du client a modifier ou supprimer : ");
        fflush(stdin);
        scanf("%s", cin_rech);
        while (fscanf(f_clients, "%s %s %s %s %s %s %s %s %s %s\n", tmp_cli.cinid, tmp_cli.prenom, tmp_cli.nom, tmp_cli.sexe, tmp_cli.last_visite.jour, tmp_cli.last_visite.mois, tmp_cli.last_visite.annee, 
        tmp_cli.telnumbr, tmp_cli.mail, tmp_cli.adresse) != EOF)
        {
            if (strstr(tmp_cli.cinid, cin_rech) != NULL)
            {
                afficher_client(tmp_cli);
                do
                {
                    printf("Choisie (s : supprimer  m : modifier, i : ignorer) : ");
                    fflush(stdin);
                    getchar();
                    scanf("%c",&choix);
                } while ( choix != 's' && choix != 'm' && choix != 'i');
                switch (choix)
                {
                case 's':
                    break;
                
                case 'm':
                    modifier_client(&tmp_cli);
                    fprintf(f_clients_tmp, "%s %s %s %s %s %s %s %s %s %s\n", tmp_cli.cinid, tmp_cli.prenom, tmp_cli.nom, tmp_cli.sexe, tmp_cli.last_visite.jour, tmp_cli.last_visite.mois, tmp_cli.last_visite.annee, 
                    tmp_cli.telnumbr, tmp_cli.mail, tmp_cli.adresse);
                    break;
                case 'i':
                    fprintf(f_clients_tmp, "%s %s %s %s %s %s %s %s %s %s\n", tmp_cli.cinid, tmp_cli.prenom, tmp_cli.nom, tmp_cli.sexe, tmp_cli.last_visite.jour, tmp_cli.last_visite.mois, tmp_cli.last_visite.annee, 
                    tmp_cli.telnumbr, tmp_cli.mail, tmp_cli.adresse);
                    break;
                }
            }
            else
            {
                fprintf(f_clients_tmp, "%s %s %s %s %s %s %s %s %s %s\n", tmp_cli.cinid, tmp_cli.prenom, tmp_cli.nom, tmp_cli.sexe, tmp_cli.last_visite.jour, tmp_cli.last_visite.mois, tmp_cli.last_visite.annee, 
                tmp_cli.telnumbr, tmp_cli.mail, tmp_cli.adresse);
            }
        }
        fclose(f_clients_tmp);
        fclose(f_clients);
        remove(clients_file_location);
        rename(clients_file_location_tmp, clients_file_location);

    }
    else
    {
        printf("Erreur lecture fichier : %s ou %s\n", clients_file_location_tmp, clients_file_location);
    }
    

}