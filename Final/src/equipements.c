#include "equipements.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum
{
    EIDENTIFIANT_EQUIP,
    ENOM_EQUIP,
    ETYPE_EQUIP,
	EETAT_EQUIP,
    COLUMNS
};

char equipements_file_location[] = "equipements.txt";
char tmp_equipements_file_location[] = "tmp_equipements.txt";

//id checked
unsigned int last_id_equi()
{
    FILE * f_equipements;
    equipement tmp_equi;
    unsigned int last_id_equi = -1;
    f_equipements = fopen(equipements_file_location, "r");
    if (f_equipements != NULL)
    {
        while (fscanf(f_equipements, "%u\n%20[^\n]\n%20[^\n]\n%s\n%d %s %d\n%d %s %d\n", &tmp_equi.id, tmp_equi.nom, tmp_equi.type, tmp_equi.etat, &tmp_equi.date_ajout.jour, tmp_equi.date_ajout.mois, &tmp_equi.date_ajout.annee, &tmp_equi.date_dernier_maintenance.jour, tmp_equi.date_dernier_maintenance.mois, &tmp_equi.date_dernier_maintenance.annee) != EOF)
        {
            last_id_equi = tmp_equi.id;
        } 
        fclose(f_equipements);
    }
    
    if (last_id_equi == -1)
    {
        f_equipements = fopen(equipements_file_location, "w");
        fprintf(f_equipements, "%u\n", 0);
        fclose(f_equipements);
        return 0;
    }
    return last_id_equi; 
}

//ajouter equipement checked
void ajouter_equipement(equipement t_equi)
{
    FILE * f_equipements;
    f_equipements = fopen(equipements_file_location, "a+");
    t_equi.id = last_id_equi();
    if (f_equipements != NULL)
    {
        fprintf(f_equipements, "%s\n%s\n%s\n%d %s %d\n%d %s %d\n", t_equi.nom,  t_equi.type, t_equi.etat, t_equi.date_ajout.jour, t_equi.date_ajout.mois, t_equi.date_ajout.annee, t_equi.date_dernier_maintenance.jour, t_equi.date_dernier_maintenance.mois, t_equi.date_dernier_maintenance.annee);
        fprintf(f_equipements, "%u\n", t_equi.id+1);
        fclose(f_equipements);
    }  
}


//modifier equipement
void modifier_equipement(equipement t_equi)
{
    equipement tmp_equi;
    FILE * f_equipements;
    FILE * tmp_f_equipements;
    f_equipements = fopen(equipements_file_location, "r");
    tmp_f_equipements = fopen(tmp_equipements_file_location, "w");

    if (f_equipements != NULL && tmp_f_equipements != NULL)
    {
        while (fscanf(f_equipements, "%u\n%20[^\n]\n%20[^\n]\n%s\n%d %s %d\n%d %s %d\n", &tmp_equi.id, tmp_equi.nom, tmp_equi.type, tmp_equi.etat, &tmp_equi.date_ajout.jour, tmp_equi.date_ajout.mois, &tmp_equi.date_ajout.annee, &tmp_equi.date_dernier_maintenance.jour, tmp_equi.date_dernier_maintenance.mois, &tmp_equi.date_dernier_maintenance.annee) != EOF)
        {
            if ((tmp_equi.id == t_equi.id) && !(feof(f_equipements))) fprintf(tmp_f_equipements,  "%u\n%s\n%s\n%s\n%d %s %d\n%d %s %d\n", t_equi.id, t_equi.nom,  t_equi.type, t_equi.etat, t_equi.date_ajout.jour, t_equi.date_ajout.mois, t_equi.date_ajout.annee, t_equi.date_dernier_maintenance.jour, t_equi.date_dernier_maintenance.mois, t_equi.date_dernier_maintenance.annee);
            else if (!(feof(f_equipements))) fprintf(tmp_f_equipements, "%u\n%s\n%s\n%s\n%d %s %d\n%d %s %d\n", tmp_equi.id, tmp_equi.nom,  tmp_equi.type, tmp_equi.etat, tmp_equi.date_ajout.jour, tmp_equi.date_ajout.mois, tmp_equi.date_ajout.annee, tmp_equi.date_dernier_maintenance.jour, tmp_equi.date_dernier_maintenance.mois, tmp_equi.date_dernier_maintenance.annee);
        }
        fprintf(tmp_f_equipements, "%u\n", tmp_equi.id);
        fclose(f_equipements);
        fclose(tmp_f_equipements);
        remove(equipements_file_location);
        rename(tmp_equipements_file_location, equipements_file_location);
    }
}



//supprimer equipement
int supprimer_equipement(equipement t_equi)
{
    equipement tmp_equi;
    FILE * f_equipements;
    FILE * tmp_f_equipements;
    int delete_check_equi = 0;
    f_equipements = fopen(equipements_file_location, "r");
    tmp_f_equipements = fopen(tmp_equipements_file_location, "w");

    if (f_equipements != NULL && tmp_f_equipements != NULL)
    {
        while (fscanf(f_equipements, "%u\n%20[^\n]\n%20[^\n]\n%s\n%d %s %d\n%d %s %d\n", &tmp_equi.id, tmp_equi.nom, tmp_equi.type, tmp_equi.etat, &tmp_equi.date_ajout.jour, tmp_equi.date_ajout.mois, &tmp_equi.date_ajout.annee, &tmp_equi.date_dernier_maintenance.jour, tmp_equi.date_dernier_maintenance.mois, &tmp_equi.date_dernier_maintenance.annee) != EOF)
        {
            if ((tmp_equi.id != t_equi.id) && !(feof(f_equipements))) fprintf(tmp_f_equipements, "%u\n%s\n%s\n%s\n%d %s %d\n%d %s %d\n",tmp_equi.id, tmp_equi.nom,  tmp_equi.type, tmp_equi.etat, tmp_equi.date_ajout.jour, tmp_equi.date_ajout.mois, tmp_equi.date_ajout.annee, tmp_equi.date_dernier_maintenance.jour, tmp_equi.date_dernier_maintenance.mois, tmp_equi.date_dernier_maintenance.annee);
            else if (!(feof(f_equipements)) && tmp_equi.id == t_equi.id) delete_check_equi = 1;
        }
        fprintf(tmp_f_equipements, "%u\n", tmp_equi.id);
        fclose(f_equipements);
        fclose(tmp_f_equipements);
        remove(equipements_file_location);
        rename(tmp_equipements_file_location, equipements_file_location);
    }
    return delete_check_equi;    
}


//afficher equipement checked
void afficher_equipement(GtkWidget * equip_agri_treeview, char search_equi[])
{
    GtkCellRenderer * renderer;
    GtkTreeViewColumn * column;
    GtkTreeIter iter;
    GtkListStore *store;
    GList * columns;

    equipement tmp_equi;
    char equi_id_str[20];
    FILE * f_equipements;


    store = gtk_tree_view_get_model(equip_agri_treeview);

    if(store == NULL) // Check if colums are already made if not make them
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", EIDENTIFIANT_EQUIP, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(equip_agri_treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOM_EQUIP, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(equip_agri_treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text", ETYPE_EQUIP, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(equip_agri_treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Etat", renderer, "text", EETAT_EQUIP, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(equip_agri_treeview), column);       

        renderer = gtk_cell_renderer_text_new();
        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING); // number of G_TYPE_STRING same as the number of colums you need
        gtk_tree_view_set_model(GTK_TREE_VIEW(equip_agri_treeview), GTK_TREE_MODEL(store));
        columns = gtk_tree_view_get_columns (GTK_TREE_VIEW (equip_agri_treeview));
 
    }

    gtk_list_store_clear(store); // nettoyer la liste pour ne pas depliquer les resultat

    f_equipements = fopen(equipements_file_location, "r");
    if (f_equipements != NULL)
    {
        while (fscanf(f_equipements, "%u\n%20[^\n]\n%20[^\n]\n%s\n%d %s %d\n%d %s %d\n", &tmp_equi.id, tmp_equi.nom, tmp_equi.type, tmp_equi.etat, &tmp_equi.date_ajout.jour, tmp_equi.date_ajout.mois, &tmp_equi.date_ajout.annee, &tmp_equi.date_dernier_maintenance.jour, tmp_equi.date_dernier_maintenance.mois, &tmp_equi.date_dernier_maintenance.annee) != EOF)
        {
            sprintf(equi_id_str, "%u", tmp_equi.id);
            if ( !(feof(f_equipements)) && (strstr(tmp_equi.nom, search_equi) != NULL || strstr(tmp_equi.type, search_equi) != NULL || strstr(tmp_equi.etat, search_equi) != NULL || strstr(equi_id_str, search_equi) != NULL ))
            {
                
                gtk_list_store_append(store, &iter);
                gtk_list_store_set(store, &iter, EIDENTIFIANT_EQUIP, equi_id_str, ENOM_EQUIP, tmp_equi.nom, ETYPE_EQUIP, tmp_equi.type, EETAT_EQUIP, tmp_equi.etat, -1);
            }
        }
        fclose(f_equipements);
        gtk_tree_view_set_model(GTK_TREE_VIEW(equip_agri_treeview), GTK_TREE_MODEL(store));
    }
  
}


//verfication checked
int empty_invalid_entry_equipement(equipement tmp_equipement)
{
   
    if (strlen(tmp_equipement.nom) < 3) return 0; //verfication nom

    if (strlen(tmp_equipement.type) < 1) return 0; //verfication type

    if (strlen(tmp_equipement.etat) < 1) return 0; // verfication etat

//verification date d'ajout
    if (strcmp(tmp_equipement.date_ajout.mois, "Janvier") != 0 && strcmp(tmp_equipement.date_ajout.mois, "Fevrier") != 0 && strcmp(tmp_equipement.date_ajout.mois, "Mars") != 0 && 
    strcmp(tmp_equipement.date_ajout.mois, "Avril") != 0 && strcmp(tmp_equipement.date_ajout.mois, "Mai") != 0 && strcmp(tmp_equipement.date_ajout.mois, "Juin") != 0 &&
    strcmp(tmp_equipement.date_ajout.mois, "Juillet") != 0 && strcmp(tmp_equipement.date_ajout.mois, "Aout") != 0 && strcmp(tmp_equipement.date_ajout.mois, "Septembre") != 0 &&
    strcmp(tmp_equipement.date_ajout.mois, "Octobre") != 0 && strcmp(tmp_equipement.date_ajout.mois, "Novembre") != 0 && strcmp(tmp_equipement.date_ajout.mois, "Decembre") != 0) return 0;
    

//verfication date de dernier maintenance
if (strcmp(tmp_equipement.date_dernier_maintenance.mois, "Janvier") != 0 && strcmp(tmp_equipement.date_dernier_maintenance.mois, "Fevrier") != 0 && strcmp(tmp_equipement.date_dernier_maintenance.mois, "Mars") != 0 && 
    strcmp(tmp_equipement.date_dernier_maintenance.mois, "Avril") != 0 && strcmp(tmp_equipement.date_dernier_maintenance.mois, "Mai") != 0 && strcmp(tmp_equipement.date_dernier_maintenance.mois, "Juin") != 0 &&
    strcmp(tmp_equipement.date_dernier_maintenance.mois, "Juillet") != 0 && strcmp(tmp_equipement.date_dernier_maintenance.mois, "Aout") != 0 && strcmp(tmp_equipement.date_dernier_maintenance.mois, "Septembre") != 0 &&
    strcmp(tmp_equipement.date_dernier_maintenance.mois, "Octobre") != 0 && strcmp(tmp_equipement.date_dernier_maintenance.mois, "Novembre") != 0 && strcmp(tmp_equipement.date_dernier_maintenance.mois, "Decembre") != 0) return 0;
    
    return 1;
    
}

//trouver equipement checked
void touver_equipement(equipement * tmp_equi)
{
    unsigned int id_e = tmp_equi->id;
    FILE * f_equipements;
    f_equipements = fopen(equipements_file_location, "r");
    if (f_equipements != NULL)
    {
        while (fscanf(f_equipements, "%u\n%20[^\n]\n%20[^\n]\n%s\n%d %s %d\n%d %s %d\n", &tmp_equi->id, tmp_equi->nom, tmp_equi->type, tmp_equi->etat, &tmp_equi->date_ajout.jour, tmp_equi->date_ajout.mois, &tmp_equi->date_ajout.annee, &tmp_equi->date_dernier_maintenance.jour, tmp_equi->date_dernier_maintenance.mois, &tmp_equi->date_dernier_maintenance.annee ) != EOF && id_e != tmp_equi->id);
        fclose(f_equipements);
    }
}

