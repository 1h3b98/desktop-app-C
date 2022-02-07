#include "client.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void ajouter_client(client *cli);
void supprimer_client(client *cli);
void afficher_client(client cli);
void chercher_client();
void modifier_client(client *cli);




void ajouter_client(client *cli)
{
    printf("===============Ajouter Client===============\n");
    printf("Donner le username du client : ");
    fflush(stdin);
    gets(cli->username);
    printf("Donner le CIN du client : ");
    scanf("%ld", &cli->cinid);
    printf("Donner le prenom du client : ");
    fflush(stdin);
    gets(cli->prenom);
    printf("Donner le nom du client : ");
    fflush(stdin);
    gets(cli->nom);

    do
    {
        printf("Sexe (0 pour Homme | 1 pour Femme) : ");
        scanf("%d", &cli->sexe);

    }while (cli->sexe != 1 && cli->sexe != 0);
    do
    {
        printf("Donner le jour de la derniere visite : ");
        scanf("%d",&cli->last_visite.jour);
    }while(cli->last_visite.jour < 1 && cli->last_visite.jour > 32);
    do
    {
        printf("Donner le mois de la derniere visite : ");
        scanf("%d",&cli->last_visite.mois);
    }while(cli->last_visite.annee < 1 && cli->last_visite.annee > 12);
    do
    {
        printf("Donner l'annee de la derniere visite : ");
        scanf("%d", &cli->last_visite.annee);
    }while(cli->last_visite.annee < 2000 && cli->last_visite.annee > 2050);
    do
    {
        printf("Donner le tel du client : ");
        scanf("%ld",&cli->telnumbr);
    }while( !(((cli->telnumbr > 70000000)&&(&cli->telnumbr < 80000000))
              || ((cli->telnumbr > 90000000)&&(cli->telnumbr < 10000000))
              || ((cli->telnumbr > 50000000)&&(cli->telnumbr < 60000000))
              || ((cli->telnumbr > 20000000)&&(cli->telnumbr < 30000000))
              || ((cli->telnumbr > 40000000)&&(cli->telnumbr < 50000000))));

    printf("Donner d'adress mail : ");
    fflush(stdin);
    gets(cli->mail);
    printf("Donner d'adress Adress : ");
    fflush(stdin);
    gets(cli->adresse);
}
void supprimer_client(client *cli)
{
    printf("supprimer client");
}
void afficher_client(client cli)
{
    printf("\n===============Afficher Client===============\n");
    printf("Identifiant : %s\n",cli.username);
    printf("CIN : %.8ld\n",cli.cinid);
    printf("Prenom : %s\n",cli.prenom);
    printf("Nom : %s",cli.nom);
    printf("Sexe : ");

    if (cli.sexe == 1) printf("Femme\n");
    else printf("Homme\n");

    printf("Date de la derniere visite : %.2d/%.2d/%.4d\n",cli.last_visite.jour, cli.last_visite.mois,cli.last_visite.annee);
    printf("Tel : %ld\n",cli.telnumbr);
    printf("Mail : %s\n",cli.mail);
    printf("Adresse : %s",cli.adresse);
}
void chercher_client()
{
    printf("chercher_client");
    return 0;
}
void modifier_client(client *cli)
{
    printf("mofifier client");
}
