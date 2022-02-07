#include <stdio.h>
#include <stdlib.h>

#include "employes/employes.h"
#include "Capteurs/capteur.h"
#include "ouvrier/ouvrier.h"
#include "equipements/fonction-BM.h"
#include "clients/client.h"
#include "troupeau/troupeau.h"

void auth_screen();
int admin_screen();
int employes_screen();


void auth_screen()
{
    char lg_user[20], lg_pass[20];
    while(1)
    {
        printf("\n ===================================\n");
        printf("||               Login              ||\n");
        printf(" ===================================\n");
        printf("Identifiant : ");
        fflush(stdin);
        scanf("%s",lg_user);
        printf("MDP : ");
        fflush(stdin);
        scanf("%s",lg_pass);
        switch (user_type(lg_user, lg_pass))
        {
        case 0:
            printf("ACCESS REFUSE !!!\n");
            break;
        case 1:
            employes_screen();
            break;
        case 2:
            admin_screen();
            break;
        case 3:
            printf("Mot de passe incorrect !! \n");
            break;
        case 4:
            printf("Identifiant non trouve !!\n");
            break;
        }
    }

}

int admin_screen()
{
    int choix;
    while(1)
    {
        do
        {
            printf("\n ===================================\n");
            printf("||          Espace Admin           ||\n");
            printf(" ===================================\n");
            printf(" 1) Tableau de bord.\n");
            printf(" 2) Gestion Employes.\n");
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
            /*TDB_screen();*/
            break;
        case 2:
            ges_employes_screen();
            break;
        }
        
    }
}

int employes_screen()
{
    int choix;
    while(1)
    {
        do
        {
            printf("\n ===================================\n");
            printf("||           Espace Employes        ||\n");
            printf(" ===================================\n");
            printf(" 1) Gestion des capteurs.\n");
            printf(" 2) Gestion des Ouvrier.\n");
            printf(" 3) Gestion des Equipement Agricole.\n");
            printf(" 4) Gestion des clients\n");
            printf(" 5) Gestion des Troupeaux\n");
            printf(" 0) Deconnection\n");
            printf("Choix : ");
            scanf("%d",&choix);
        }while ((choix > 6) && (choix < 0));
        switch (choix)
        {
        case 0:
            return 0;
            break;
        
        case 1:
            ges_capteur_screen();
            break;
        case 2:
            ges_ouvrier_screen();
            break;
        case 3:
            ges_equp_agri_screen();
            break;
        case 4:
            ges_clients_screen();
            break;
        case 5:
            ges_troupeaux_screen();
            break;
        }
        
    }


}




int main()
{
    int choix;
    while(1)
    {
        do
        {
            printf("\n ===================================\n");
            printf("||             Menu                ||\n");
            printf(" ===================================\n");
            printf(" 1) Identification.\n");
            printf(" 2) Espace Administrateur.\n");
            printf(" 3) Espace Employes.\n");
            printf(" 0) Quitter\n");
            printf("Choix : ");
            scanf("%d",&choix);
        }while ((choix > 3) && (choix < 0));
        switch (choix)
        {
        case 0:
            exit(0);
            break;
        
        case 1:
            auth_screen();
            break;
        case 2:
            admin_screen();
            break;
        case 3:
            employes_screen();
            break;
        }
        
    }

}

