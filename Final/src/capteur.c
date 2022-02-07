#include <stdio.h>
#include <stdlib.h>
#include "capteur.h"
#include <string.h>
#include <gtk/gtk.h>




enum
{
    EID_CAP,
    EPRECISION,
    EMARQUE,
    COLUMNS
};



char capteur_file_location[] = "capteur.txt";
char tmp_capteur_file_location[] = "tmp_capteur.txt";

unsigned int last_id_cap()
{
    FILE  *f_capteur;
    capteur cap;
    unsigned int last_id_cap = -1;
    f_capteur= fopen(capteur_file_location, "r");
    if (f_capteur!= NULL)
    {
        while (fscanf(f_capteur,"%u\n%s\n%s\n%d %s %d\n%20[^\n]\n",&cap.ID,cap.precision,cap.marque,&cap.date.day,cap.date.month,&cap.date.year,cap.type)!= EOF)
        {    
	        last_id_cap= cap.ID;
        }
        fclose(f_capteur);
    }
    if (last_id_cap== -1)
    {
        f_capteur= fopen(capteur_file_location, "w");
        fprintf(f_capteur, "%u\n", 0);
        fclose(f_capteur);
        return 0;
    }
    return last_id_cap; 
}

void  ajou_capt(capteur cap)
{
FILE  *f_capteur;
unsigned int id;
id = last_id_cap();
f_capteur=fopen(capteur_file_location,"a+");

			if(f_capteur!=NULL)
			{
	 		
	 		fprintf(f_capteur,"%s\n%s\n%d %s %d\n%s\n",cap.precision,cap.marque,cap.date.day,cap.date.month,cap.date.year,cap.type);
	 		
 fprintf(f_capteur, "%u\n", id+1);	 		
fclose(f_capteur);
	 	}	

}      


//******************chek error*************


int check_errors_capteur(capteur t_cap)
{
    capteur tmp_cap;
    int error = 0;
    FILE * f_capteur;
    f_capteur = fopen(capteur_file_location, "r");
    if (f_capteur != NULL)
    {
        while (fscanf(f_capteur, "%u\n%s\n%s\n%d %s %d\n%20[^\n]\n",&tmp_cap.ID,tmp_cap.precision,tmp_cap.marque,&tmp_cap.date.day,tmp_cap.date.month,&tmp_cap.date.year,tmp_cap.type) != EOF && (error != 7) && !(feof(f_capteur)))
        {
            if ((strcmp(tmp_cap.precision, t_cap.precision) == 0) && (tmp_cap.ID != t_cap.ID)) error += 1;
         
        }
        fclose(f_capteur);
    }
    return error;
}















//*****************modifier******************




void modifier_capteur(capteur cap)
{
    capteur tmp_cap;
    FILE * f_capteur;
    FILE * tmp_f_capteur;
    f_capteur = fopen(capteur_file_location, "r");
    tmp_f_capteur = fopen(tmp_capteur_file_location, "w");

    if (f_capteur != NULL && tmp_f_capteur != NULL)
    {
        while (fscanf(f_capteur, "%u\n%s\n%s\n%d %s %d\n%20[^\n]\n", &tmp_cap.ID,tmp_cap.precision,tmp_cap.marque,&tmp_cap.date.day,tmp_cap.date.month,&tmp_cap.date.year,tmp_cap.type) != EOF)
        {
            if ((tmp_cap.ID == tmp_cap.ID) && !(feof(f_capteur))) fprintf(tmp_f_capteur,  "%u\n%s\n%s\n%d %s %d\n%s\n", cap.ID,cap.precision,cap.marque,cap.date.day,cap.date.month,cap.date.year,cap.type);
            else if (!(feof(f_capteur))) fprintf(tmp_f_capteur, "%u\n%s\n%s\n%d %s %d\n%s\n", cap.ID,cap.precision,cap.marque,cap.date.day,cap.date.month,cap.date.year,cap.type);
        }
        fprintf(tmp_f_capteur, "%u\n", tmp_cap.ID);
        fclose(f_capteur);
        fclose(tmp_f_capteur);
        remove(capteur_file_location);
        rename(tmp_capteur_file_location, capteur_file_location);
    }
}

//*********************supprimer*************

int supprimer_capteur(capteur t_cap)
{
    capteur tmp_cap;
    FILE * f_capteur;
    FILE * tmp_f_capteur;
    int delete_check = 0;
    f_capteur = fopen(capteur_file_location, "r");
    tmp_f_capteur = fopen(tmp_capteur_file_location, "w");

    if (f_capteur != NULL && tmp_f_capteur != NULL)
    {
        while (fscanf(f_capteur, "%u\n%s\n%s\n%d %s %d\n%20[^\n]\n", &tmp_cap.ID,tmp_cap.precision,tmp_cap.marque,&tmp_cap.date.day,tmp_cap.date.month,&tmp_cap.date.year,tmp_cap.type) != EOF)
        {
            if ((tmp_cap.ID != t_cap.ID) && !(feof(f_capteur))) fprintf(tmp_f_capteur, "%u\n%s\n%s\n%d %s %d\n%s\n", tmp_cap.ID,tmp_cap.precision,tmp_cap.marque,tmp_cap.date.day,tmp_cap.date.month,tmp_cap.date.year,tmp_cap.type);
            else if (!(feof(f_capteur)) && tmp_cap.ID == tmp_cap.ID) delete_check = 1;
        }
        fprintf(tmp_f_capteur, "%u\n", tmp_cap.ID);
        fclose(f_capteur);
        fclose(tmp_f_capteur);
        remove(capteur_file_location);
        rename(tmp_capteur_file_location, capteur_file_location);
    }
    return delete_check;    
}












//**********************afficher*************

void afficher_capteur(GtkWidget * employer_capteurs_treeview, char search_cap[])
{
    GtkCellRenderer * renderer;
    GtkTreeViewColumn * column;
    GtkTreeIter iter;
    GtkListStore *store;
    GList * columns;
	
    capteur tmp_cap;
    char cap_id_str[20];
    FILE * f_capteur;
 
    store = gtk_tree_view_get_model(employer_capteurs_treeview);

if(store == NULL) // Check if colums are already made if not make them
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("EID_CAP", renderer, "text", EID_CAP, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(employer_capteurs_treeview), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Precision", renderer, "text", EPRECISION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(employer_capteurs_treeview), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Marque", renderer, "text", EMARQUE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(employer_capteurs_treeview), column);


renderer = gtk_cell_renderer_text_new();
        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING); // number of G_TYPE_STRING same as the number of colums you need
        gtk_tree_view_set_model(GTK_TREE_VIEW(employer_capteurs_treeview), GTK_TREE_MODEL(store));
        columns = gtk_tree_view_get_columns (GTK_TREE_VIEW (employer_capteurs_treeview));
 
    }

gtk_list_store_clear(store); // nettoyer la liste pour ne pas depliquer les resultat
f_capteur = fopen(capteur_file_location, "r");


    if (f_capteur != NULL)
    {
        while (fscanf(f_capteur, "%u\n%s\n%s\n%d %s %d\n%20[^\n]\n", &tmp_cap.ID,tmp_cap.precision,tmp_cap.marque,&tmp_cap.date.day,tmp_cap.date.month,&tmp_cap.date.year,tmp_cap.type) != EOF)
        {
            sprintf(cap_id_str, "%u", tmp_cap.ID);
            if ( !(feof(f_capteur)) && (strstr(tmp_cap.precision, search_cap) != NULL || strstr(tmp_cap.marque, search_cap) != NULL || strstr(cap_id_str, search_cap) != NULL ))
            {
                
                gtk_list_store_append(store, &iter);
                gtk_list_store_set(store, &iter, EID_CAP, cap_id_str, EPRECISION, tmp_cap.precision, EMARQUE, tmp_cap.marque, -1);
            }
        }
        fclose(f_capteur);
        gtk_tree_view_set_model(GTK_TREE_VIEW(employer_capteurs_treeview), GTK_TREE_MODEL(store));
    }

    
}



int empty_invalid_entry_capteur(capteur tmp_capteur)
{
   /*/ int i, pass = 0;
    if (strlen(tmp_capteur.precision) == 2)//?????????????? 2
    {
        for (i = 0 ; i < 2; i++)
        {
            if (tmp_capteur.precision[i] > '1' || tmp_capteur.precison[i] < '0') return 0 ;
        }
    }
    else return 0;
    
    else
    {
        if (pass != 3) return 0;
    }
   */
    if (strlen(tmp_capteur.precision) < 1) return 0;
    if (strcmp(tmp_capteur.date.month, "Janvier") != 0 && strcmp(tmp_capteur.date.month, "Février") != 0 && strcmp(tmp_capteur.date.month, "Mars") != 0 && 
    strcmp(tmp_capteur.date.month, "Avril") != 0 && strcmp(tmp_capteur.date.month, "Mai") != 0 && strcmp(tmp_capteur.date.month, "Juin") != 0 &&
    strcmp(tmp_capteur.date.month, "Juillet") != 0 && strcmp(tmp_capteur.date.month, "Août") != 0 && strcmp(tmp_capteur.date.month, "Septembre") != 0 &&
    strcmp(tmp_capteur.date.month, "Octobre") != 0 && strcmp(tmp_capteur.date.month, "Novembre") != 0 && strcmp(tmp_capteur.date.month, "Décembre") != 0) return 0;
    
    return 1;
    
}



void trouver_capteur(capteur * tmp_cap)
{
    unsigned int id = tmp_cap->ID;
    FILE * f_capteur;
    f_capteur = fopen(capteur_file_location, "r");
    if (f_capteur != NULL)
    {
        while (fscanf(f_capteur, "%u\n%s\n%s\n%d %s %d\n%20[^\n]\n", &tmp_cap->ID,tmp_cap->precision,tmp_cap->marque,&tmp_cap->date.day,tmp_cap->date.month,&tmp_cap->date.year,tmp_cap->type) != EOF && id != tmp_cap->ID);
        fclose(f_capteur);
        g_print("%s", tmp_cap->marque);
        
    }
}


