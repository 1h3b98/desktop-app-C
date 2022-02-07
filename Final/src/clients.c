#include "clients.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum
{
    EID,
    EPRENOM,
    ENOM,
    ECIN,
    ESEXE,
    EPHONE,
    EMAIL,
    EADDR,
    ELASTVISIT,
    COLUMNS
};


char clients_file_location[] = "clients.txt";
char tmp_clients_file_location[] = "tmp_clients.txt";

unsigned int last_id_client()
{
    FILE * f_clients;
    client tmp_cli;
    unsigned int last_id = -1;
    f_clients = fopen(clients_file_location, "r");
    if (f_clients != NULL)
    {
        while (fscanf(f_clients, "%u\n%s\n%20[^\n]\n%20[^\n]\n%s\n%d %s %d\n%s\n%s\n%20[^\n]\n%20[^\n]\n", &tmp_cli.id, tmp_cli.cin, tmp_cli.prenom, tmp_cli.nom, tmp_cli.sexe, &tmp_cli.derniere_visite.jour, tmp_cli.derniere_visite.mois, &tmp_cli.derniere_visite.annee, tmp_cli.telnumbr, tmp_cli.mail, tmp_cli.adresse, tmp_cli.paiment) != EOF)
        {
            last_id = tmp_cli.id;
        } 
        fclose(f_clients);
    }
    
    if (last_id == -1)
    {
        f_clients = fopen(clients_file_location, "w");
        fprintf(f_clients, "%u\n", 0);
        fclose(f_clients);
        return 0;
    }
    return last_id; 
}
void ajouter_client(client t_cli)
{
    FILE * f_clients;
    f_clients = fopen(clients_file_location, "a+");
    t_cli.id = last_id_client();
    if (f_clients != NULL)
    {
        fprintf(f_clients, "%s\n%s\n%s\n%s\n%d %s %d\n%s\n%s\n%s\n%s\n", t_cli.cin, t_cli.prenom, t_cli.nom, t_cli.sexe, t_cli.derniere_visite.jour, t_cli.derniere_visite.mois, t_cli.derniere_visite.annee, t_cli.telnumbr, t_cli.mail, t_cli.adresse, t_cli.paiment);
        fprintf(f_clients, "%u\n", t_cli.id+1);
        fclose(f_clients);
    }  
}
int check_errors_client(client t_cli)
{
    client tmp_cli;
    int error = 0;
    FILE * f_clients;
    f_clients = fopen(clients_file_location, "r");
    if (f_clients != NULL)
    {
        while (fscanf(f_clients, "%u\n%s\n%20[^\n]\n%20[^\n]\n%s\n%d %s %d\n%s\n%s\n%20[^\n]\n%20[^\n]\n", &tmp_cli.id, tmp_cli.cin, tmp_cli.prenom, tmp_cli.nom, tmp_cli.sexe, &tmp_cli.derniere_visite.jour, tmp_cli.derniere_visite.mois, &tmp_cli.derniere_visite.annee, tmp_cli.telnumbr, tmp_cli.mail, tmp_cli.adresse, tmp_cli.paiment) != EOF && (error != 7) && !(feof(f_clients)))
        {
            if ((strcmp(tmp_cli.cin, t_cli.cin) == 0) && (tmp_cli.id != t_cli.id)) error += 1;
            if ((strcmp(tmp_cli.telnumbr, t_cli.telnumbr) == 0) && (tmp_cli.id != t_cli.id)) error += 2;
            if ((strcmp(tmp_cli.mail, t_cli.mail) == 0) && (tmp_cli.id != t_cli.id)) error += 4;
        }
        fclose(f_clients);
    }
    return error;
}
void modifier_client(client t_cli)
{
    client tmp_cli;
    FILE * f_clients;
    FILE * tmp_f_clients;
    f_clients = fopen(clients_file_location, "r");
    tmp_f_clients = fopen(tmp_clients_file_location, "w");

    if (f_clients != NULL && tmp_f_clients != NULL)
    {
        while (fscanf(f_clients, "%u\n%s\n%20[^\n]\n%20[^\n]\n%s\n%d %s %d\n%s\n%s\n%20[^\n]\n%20[^\n]\n", &tmp_cli.id, tmp_cli.cin, tmp_cli.prenom, tmp_cli.nom, tmp_cli.sexe, &tmp_cli.derniere_visite.jour, tmp_cli.derniere_visite.mois, &tmp_cli.derniere_visite.annee, tmp_cli.telnumbr, tmp_cli.mail, tmp_cli.adresse, tmp_cli.paiment) != EOF)
        {
            if ((tmp_cli.id == t_cli.id) && !(feof(f_clients))) fprintf(tmp_f_clients,  "%u\n%s\n%s\n%s\n%s\n%d %s %d\n%s\n%s\n%s\n%s\n", t_cli.id, t_cli.cin, t_cli.prenom, t_cli.nom, t_cli.sexe, t_cli.derniere_visite.jour, t_cli.derniere_visite.mois, t_cli.derniere_visite.annee, t_cli.telnumbr, t_cli.mail, t_cli.adresse, t_cli.paiment);
            else if (!(feof(f_clients))) fprintf(tmp_f_clients, "%u\n%s\n%s\n%s\n%s\n%d %s %d\n%s\n%s\n%s\n%s\n", tmp_cli.id, tmp_cli.cin, tmp_cli.prenom, tmp_cli.nom, tmp_cli.sexe, tmp_cli.derniere_visite.jour, tmp_cli.derniere_visite.mois, tmp_cli.derniere_visite.annee, tmp_cli.telnumbr, tmp_cli.mail, tmp_cli.adresse, tmp_cli.paiment);
        }
        fprintf(tmp_f_clients, "%u\n", tmp_cli.id);
        fclose(f_clients);
        fclose(tmp_f_clients);
        remove(clients_file_location);
        rename(tmp_clients_file_location, clients_file_location);
    }
}

int supprimer_client(client t_cli)
{
    client tmp_cli;
    FILE * f_clients;
    FILE * tmp_f_clients;
    int delete_check = 0;
    f_clients = fopen(clients_file_location, "r");
    tmp_f_clients = fopen(tmp_clients_file_location, "w");

    if (f_clients != NULL && tmp_f_clients != NULL)
    {
        while (fscanf(f_clients, "%u\n%s\n%20[^\n]\n%20[^\n]\n%s\n%d %s %d\n%s\n%s\n%20[^\n]\n%20[^\n]\n", &tmp_cli.id, tmp_cli.cin, tmp_cli.prenom, tmp_cli.nom, tmp_cli.sexe, &tmp_cli.derniere_visite.jour, tmp_cli.derniere_visite.mois, &tmp_cli.derniere_visite.annee, tmp_cli.telnumbr, tmp_cli.mail, tmp_cli.adresse, tmp_cli.paiment) != EOF)
        {
            if ((tmp_cli.id != t_cli.id) && !(feof(f_clients))) fprintf(tmp_f_clients, "%u\n%s\n%s\n%s\n%s\n%d %s %d\n%s\n%s\n%s\n%s\n", tmp_cli.id, tmp_cli.cin, tmp_cli.prenom, tmp_cli.nom, tmp_cli.sexe, tmp_cli.derniere_visite.jour, tmp_cli.derniere_visite.mois, tmp_cli.derniere_visite.annee, tmp_cli.telnumbr, tmp_cli.mail, tmp_cli.adresse, tmp_cli.paiment);
            else if (!(feof(f_clients)) && tmp_cli.id == t_cli.id) delete_check = 1;
        }
        fprintf(tmp_f_clients, "%u\n", tmp_cli.id);
        fclose(f_clients);
        fclose(tmp_f_clients);
        remove(clients_file_location);
        rename(tmp_clients_file_location, clients_file_location);
    }
    return delete_check;    
}
void afficher_client(GtkWidget * client_treeview, char search[])
{
    GtkCellRenderer * renderer;
    GtkTreeViewColumn * column;
    GtkTreeIter iter;
    GtkListStore *store;
    GList * columns;

    client tmp_cli;
    char cli_id_str[20];
    char derniere_date[35];
    FILE * f_clients;


    store = gtk_tree_view_get_model(client_treeview);


    
    if(store == NULL) // Check if colums are already made if not make them
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", EID, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(client_treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Prénom", renderer, "text", EPRENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(client_treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(client_treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Cin", renderer, "text", ECIN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(client_treeview), column);    
    
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Sexe", renderer, "text", ESEXE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(client_treeview), column);       

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Tel", renderer, "text", EPHONE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(client_treeview), column);       
   
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Mail", renderer, "text", EMAIL, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(client_treeview), column);       
   
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Adresse", renderer, "text", EADDR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(client_treeview), column);       

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Dernière visite", renderer, "text", ELASTVISIT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(client_treeview), column);       

        renderer = gtk_cell_renderer_text_new();
        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING); // number of G_TYPE_STRING same as the number of colums you need
        gtk_tree_view_set_model(GTK_TREE_VIEW(client_treeview), GTK_TREE_MODEL(store));
        columns = gtk_tree_view_get_columns (GTK_TREE_VIEW (client_treeview));
 
    }
    
    gtk_list_store_clear(store); // nettoyer la liste pour ne pas depliquer les resultat

    f_clients = fopen(clients_file_location, "r");
    if (f_clients != NULL)
    {
        while (fscanf(f_clients, "%u\n%s\n%20[^\n]\n%20[^\n]\n%s\n%d %s %d\n%s\n%s\n%20[^\n]\n%20[^\n]\n", &tmp_cli.id, tmp_cli.cin, tmp_cli.prenom, tmp_cli.nom, tmp_cli.sexe, &tmp_cli.derniere_visite.jour, tmp_cli.derniere_visite.mois, &tmp_cli.derniere_visite.annee, tmp_cli.telnumbr, tmp_cli.mail, tmp_cli.adresse, tmp_cli.paiment) != EOF)
        {
            sprintf(cli_id_str, "%u", tmp_cli.id);
            if ( !(feof(f_clients)) && (strstr(tmp_cli.cin, search) != NULL || strstr(tmp_cli.prenom, search) != NULL || strstr(tmp_cli.nom, search) != NULL || strstr(cli_id_str, search) != NULL ))
            {
                strcpy(derniere_date, "");
                sprintf(derniere_date, "%d/%s/%d", tmp_cli.derniere_visite.jour, tmp_cli.derniere_visite.mois, tmp_cli.derniere_visite.annee);
                
                gtk_list_store_append(store, &iter);
                gtk_list_store_set(store, &iter, EID, cli_id_str, EPRENOM, tmp_cli.prenom, ENOM, tmp_cli.nom, ECIN, tmp_cli.cin, ESEXE, tmp_cli.sexe, EPHONE, tmp_cli.telnumbr, EMAIL, tmp_cli.mail, EADDR, tmp_cli.adresse, ELASTVISIT, derniere_date, -1);
            }
        }
        fclose(f_clients);
        gtk_tree_view_set_model(GTK_TREE_VIEW(client_treeview), GTK_TREE_MODEL(store));
    }

    
}
int phone_number_correct(char str_nbr[])
{
    if ((strlen(str_nbr) == 8) && ((str_nbr[0] == '2') || (str_nbr[0] == '9') || (str_nbr[0] == '7') || (str_nbr[0] == '5') || (str_nbr[0] == '4'))) return 1;
    return 0;
}
int empty_invalid_entry_client(client tmp_client)
{
    int i, pass = 0;
    if (strlen(tmp_client.cin) == 8)
    {
        for (i = 0 ; i < 8; i++)
        {
            if (tmp_client.cin[i] > '9' || tmp_client.cin[i] < '0') return 0 ;
        }
    }
    else return 0;
    if (strlen(tmp_client.prenom) < 3) return 0;
    if (strlen(tmp_client.nom) < 3) return 0;
    if (strlen(tmp_client.mail)< 3) return 0;
    else
    {
        for (i = 0 ; i < strlen(tmp_client.mail) ; i++)
        {
            if (tmp_client.mail[i] == '@' && i != 0) pass += 1;
            if (pass == 2) pass += 1;
            if (tmp_client.mail[i] == '.' && pass == 1) pass += 1;
        }
        if (pass != 3) return 0;
    }
    if (strlen(tmp_client.adresse) < 3) return 0;
    if (strlen(tmp_client.paiment) < 1) return 0;
    if (strcmp(tmp_client.derniere_visite.mois, "Janvier") != 0 && strcmp(tmp_client.derniere_visite.mois, "Février") != 0 && strcmp(tmp_client.derniere_visite.mois, "Mars") != 0 && 
    strcmp(tmp_client.derniere_visite.mois, "Avril") != 0 && strcmp(tmp_client.derniere_visite.mois, "Mai") != 0 && strcmp(tmp_client.derniere_visite.mois, "Juin") != 0 &&
    strcmp(tmp_client.derniere_visite.mois, "Juillet") != 0 && strcmp(tmp_client.derniere_visite.mois, "Août") != 0 && strcmp(tmp_client.derniere_visite.mois, "Septembre") != 0 &&
    strcmp(tmp_client.derniere_visite.mois, "Octobre") != 0 && strcmp(tmp_client.derniere_visite.mois, "Novembre") != 0 && strcmp(tmp_client.derniere_visite.mois, "Décembre") != 0) return 0;
    
    return 1;
    
}

void touver_client(client * tmp_cli)
{
    unsigned int id = tmp_cli->id;
    FILE * f_clients;
    f_clients = fopen(clients_file_location, "r");
    if (f_clients != NULL)
    {
        while (fscanf(f_clients, "%u\n%s\n%20[^\n]\n%20[^\n]\n%s\n%d %s %d\n%s\n%s\n%20[^\n]\n%20[^\n]\n", &tmp_cli->id, tmp_cli->cin, tmp_cli->prenom, tmp_cli->nom, tmp_cli->sexe, &tmp_cli->derniere_visite.jour, tmp_cli->derniere_visite.mois, &tmp_cli->derniere_visite.annee, tmp_cli->telnumbr, tmp_cli->mail, tmp_cli->adresse, tmp_cli->paiment) != EOF && id != tmp_cli->id);
        fclose(f_clients);
    }
}
