#include "troups.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum
{
    EID,
    ENOM,
    ETYPE,
    ESANTE,
    ENOURRITURE,
    ESEXE,
    COLUMNS
};


char troups_file_location[] = "troups.txt";
char tmp_troups_file_location[] = "tmp_troups.txt";

unsigned int last_id_troup()
{
    FILE * f_troups;
    troup tmp_trou;
    unsigned int last_id_troup = -1;
    f_troups = fopen(troups_file_location, "r");
    if (f_troups != NULL)
    {
        while (fscanf(f_troups, "%u\n%s\n%s\n%s\n%50[^\n]\n%s\n%d %s %d\n", &tmp_trou.id, tmp_trou.nom, tmp_trou.type, tmp_trou.sante, tmp_trou.nourriture, tmp_trou.sexe, &tmp_trou.naissance.jour, tmp_trou.naissance.mois, &tmp_trou.naissance.annee) != EOF)
        {
            last_id_troup = tmp_trou.id;
        } 
        fclose(f_troups);
    }
    
    if (last_id_troup == -1)
    {
        f_troups = fopen(troups_file_location, "w");
        fprintf(f_troups, "%u\n", 0);
        fclose(f_troups);
        return 0;
    }
    return last_id_troup; 
    
}
   
   void ajouter_troup(troup t_trou)
{
    FILE * f_troups;
    f_troups = fopen(troups_file_location, "a+");
    t_trou.id = last_id_troup();
    if (f_troups != NULL)
    {
        fprintf(f_troups, "%s\n%s\n%s\n%s\n%s\n%d %s %d\n", t_trou.nom, t_trou.type, t_trou.sante, t_trou.nourriture, t_trou.sexe, t_trou.naissance.jour, t_trou.naissance.mois, t_trou.naissance.annee);
        fprintf(f_troups, "%u\n", t_trou.id+1);
        fclose(f_troups);
    }  
}


void modifier_troup(troup t_trou)
{
    troup tmp_trou;
    FILE * f_troups;
    FILE * tmp_f_troups;
    f_troups = fopen(troups_file_location, "r");
    tmp_f_troups = fopen(tmp_troups_file_location, "w");

    if (f_troups != NULL && tmp_f_troups != NULL)
    {
        while (fscanf(f_troups, "%u\n%s\n%s\n%s\n%50[^\n]\n%s\n%d %s %d\n", &tmp_trou.id, tmp_trou.nom, tmp_trou.type, tmp_trou.sante, tmp_trou.nourriture, tmp_trou.sexe, &tmp_trou.naissance.jour, tmp_trou.naissance.mois, &tmp_trou.naissance.annee) != EOF)
        {
        
            if ((tmp_trou.id == t_trou.id) && !(feof(f_troups))) fprintf(tmp_f_troups,  "%u\n%s\n%s\n%s\n%s\n%s\n%d %s %d\n", t_trou.id, t_trou.nom, t_trou.type, t_trou.sante, t_trou.nourriture, t_trou.sexe, t_trou.naissance.jour, t_trou.naissance.mois, t_trou.naissance.annee);
            else if (!(feof(f_troups))) fprintf(tmp_f_troups, "%u\n%s\n%s\n%s\n%s\n%s\n%d %s %d\n", tmp_trou.id, tmp_trou.nom, tmp_trou.type, tmp_trou.sante, tmp_trou.nourriture, tmp_trou.sexe, tmp_trou.naissance.jour, tmp_trou.naissance.mois, tmp_trou.naissance.annee);
        }
      
        fprintf(tmp_f_troups, "%u\n", tmp_trou.id);
       
        fclose(f_troups);
       
        fclose(tmp_f_troups);
        remove(troups_file_location);
        rename(tmp_troups_file_location, troups_file_location);
    }
}


int supprimer_troup(troup t_trou)
{
    troup tmp_trou;
    FILE * f_troups;
    FILE * tmp_f_troups;
    int delete_check = 0;
    f_troups = fopen(troups_file_location, "r");
    tmp_f_troups = fopen(tmp_troups_file_location, "w");
 
    if (f_troups != NULL && tmp_f_troups != NULL)
    {
        while (fscanf(f_troups, "%u\n%s\n%s\n%s\n%50[^\n]\n%s\n%d %s %d\n", &tmp_trou.id, tmp_trou.nom, tmp_trou.type, tmp_trou.sante, tmp_trou.nourriture, tmp_trou.sexe, &tmp_trou.naissance.jour, tmp_trou.naissance.mois, &tmp_trou.naissance.annee) != EOF)
        {
        
            if ((tmp_trou.id != t_trou.id) && !(feof(f_troups))) fprintf(tmp_f_troups, "%u\n%s\n%s\n%s\n%s\n%s\n%d %s %d\n", tmp_trou.id, tmp_trou.nom, tmp_trou.type, tmp_trou.sante, tmp_trou.nourriture, tmp_trou.sexe, tmp_trou.naissance.jour, tmp_trou.naissance.mois, tmp_trou.naissance.annee);
            else if (!(feof(f_troups)) && tmp_trou.id == t_trou.id) delete_check = 1;
        }
        
        fprintf(tmp_f_troups, "%u\n", tmp_trou.id);
        fclose(f_troups);
        fclose(tmp_f_troups);
        remove(troups_file_location);
        rename(tmp_troups_file_location, troups_file_location);
    }
    
    return delete_check;    
}
void afficher_troup(GtkWidget * troup_treeview, char search[])
{
    GtkCellRenderer * renderer;
    GtkTreeViewColumn * column;
    GtkTreeIter iter;
    GtkListStore *store;
    GList * columns;

    troup tmp_trou;
    char trou_id_str[20];
    FILE * f_troups;


    store = gtk_tree_view_get_model(troup_treeview);

    if(store == NULL) // Check if colums are already made if not make them
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", EID, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(troup_treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text", ETYPE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(troup_treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(troup_treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Sante", renderer, "text", ESANTE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(troup_treeview), column);   
        
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nourriture", renderer, "text", ENOURRITURE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(troup_treeview), column); 
        
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Sante", renderer, "text", ESANTE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(troup_treeview), column);   

  
        renderer = gtk_cell_renderer_text_new();
       
        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING); // number of G_TYPE_STRING same as the number of colums you need
        gtk_tree_view_set_model(GTK_TREE_VIEW(troup_treeview), GTK_TREE_MODEL(store));
        columns = gtk_tree_view_get_columns (GTK_TREE_VIEW (troup_treeview));
 
    }

    gtk_list_store_clear(store); // nettoyer la liste pour ne pas depliquer les resultat

    f_troups = fopen(troups_file_location, "r");
  
    if (f_troups != NULL)
    {
        while (fscanf(f_troups, "%u\n%s\n%s\n%s\n%50[^\n]\n%s\n%d %s %d\n", &tmp_trou.id, tmp_trou.nom, tmp_trou.type, tmp_trou.sante, tmp_trou.nourriture, tmp_trou.sexe, &tmp_trou.naissance.jour, tmp_trou.naissance.mois, &tmp_trou.naissance.annee) != EOF)
        {
            sprintf(trou_id_str, "%u", tmp_trou.id);
            if ( !(feof(f_troups)) && (strstr(tmp_trou.type, search) != NULL  || strstr(tmp_trou.nom, search) != NULL || strstr(trou_id_str, search) != NULL ))
            {
                
                gtk_list_store_append(store, &iter);
                gtk_list_store_set(store, &iter, EID, trou_id_str, ENOM, tmp_trou.nom, ETYPE, tmp_trou.type, ESANTE, tmp_trou.sante, ENOURRITURE, tmp_trou.nourriture, -1);
            }
        }
        fclose(f_troups);
        gtk_tree_view_set_model(GTK_TREE_VIEW(troup_treeview), GTK_TREE_MODEL(store));
    }

    
}

void touver_troup(troup * tmp_trou)
{
    unsigned int id = tmp_trou->id;
    FILE * f_troups;
    f_troups = fopen(troups_file_location, "r");
    if (f_troups != NULL)
    {
        while (fscanf(f_troups, "%u\n%s\n%s\n%s\n%50[^\n]\n%s\n%d %s %d\n", &tmp_trou->id, tmp_trou->nom, tmp_trou->type, tmp_trou->sante, tmp_trou->nourriture, tmp_trou->sexe, &tmp_trou->naissance.jour, tmp_trou->naissance.mois, &tmp_trou->naissance.annee) != EOF && id != tmp_trou->id);
        fclose(f_troups);
    }
}
