#include <stdio.h>
#include <stdlib.h>
#include "client.h"

void main()
{
    client a;

    ajouter_client(&a);
    afficher_client(a);
}
//    FILE * fclients;
//    char newclient[200] = "";
//    char str2[2] = {'\0'};
//    char str8[8] = {'\0'};
//    char str4[4] = {'\0'};
//
//    fclients = fopen(furlcli,"a");
//    strcat(newclient, "\nIdentifiant : ");
//    strcat(newclient, cli->username);
//    strcat(newclient, ", CIN : ");
//    sprintf(str8, "%.8ld", cli->cinid);
//    strcat(newclient, str8);
//    strcat(newclient, ", Prenom : ");
//    strcat(newclient, cli ->prenom);
//    strcat(newclient, ", Nom : ");
//    strcat(newclient, cli ->nom);
//    strcat(newclient, ", Sexe : ");
//    strcat(newclient, cli ->sexe);
//    strcat(newclient, ", Date de la derniere visite : ");
//    sprintf(str2, "%.2d", cli->last_visite.jour);
//    strcat(newclient, str2);
//    strcat(newclient, "/");
//    sprintf(str2, "%.2d", cli->last_visite.mois);
//    strcat(newclient, str2);
//    strcat(newclient, "/");
//    sprintf(str4, "%.4d", cli->last_visite.annee);
//    strcat(newclient, str4);
//    strcat(newclient, ",Tel : ");
//    sprintf(str8, "%.8ld", cli->telnumbr);
//    strcat(newclient, str8);
//    strcat(newclient, ", Mail :");
//    strcat(newclient, cli ->mail);
//    strcat(newclient, ", Adresse : ");
//    strcat(newclient, cli->adresse);
//    printf("\n\n%s\n\nend\n",newclient);
//    fputs(newclient,fclients);
//    fclose(fclients);
