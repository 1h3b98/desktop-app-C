#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ouvrier.h"

#include <gtk/gtk.h>

enum
{
EID_OUV,
ENOM_OUV,
EPRENOM_OUV,
EFONCTION_OUV,
COLUMNS
};
struct Cell_best_ouv
 {
     unsigned int id;
     char prenom[20];
     char nom[20];
     int jours_presents;
     int annee;
     struct Cell_best_ouv * suiv;
     
 };
typedef struct Cell_best_ouv * liste;
    
unsigned int last_id_ouv()
{
    FILE  *f_ouv;
    ouvrier ouv;
    unsigned int last_id_ouv = -1;
    f_ouv = fopen("ouvriers.txt", "r");
    if (f_ouv!= NULL)
    {
        while (fscanf(f_ouv,"%u\n%20[^\n]\n%20[^\n]\n%s\n%s\n%d %s %d\n%30[^\n]\n%30[^\n]\n",&ouv.id,ouv.nom,ouv.prenom,ouv.sexe,ouv.tel,&ouv.date.jour,ouv.date.mois,&ouv.date.annee,ouv.fonction,ouv.adresse) != EOF)
        {    
	        last_id_ouv = ouv.id;
        }
        fclose(f_ouv);
    }
    if (last_id_ouv == -1)
    {
        f_ouv= fopen("ouvriers.txt", "w");
        fprintf(f_ouv, "%u\n", 0);
        fclose(f_ouv);
        return 0;
    }
    return last_id_ouv; 
}
void ajouter_ouvrier(ouvrier ouv)
{
FILE *f_ouv;
unsigned int ouv_last_id;
ouv_last_id = last_id_ouv();
f_ouv=fopen("ouvriers.txt","a");
if(f_ouv!=NULL)
{

fprintf(f_ouv,"%s\n%s\n%s\n%s\n%d %s %d\n%s\n%s\n",ouv.nom,ouv.prenom,ouv.sexe,ouv.tel,ouv.date.jour,ouv.date.mois,ouv.date.annee,ouv.fonction,ouv.adresse);
fprintf(f_ouv, "%u\n", ouv_last_id+1);
        fclose(f_ouv);
        }
}
//**************afficher*********
void afficher_ouvrier(GtkWidget * ouvrier_treeview, char search[])
{
    GtkCellRenderer * renderer;
    GtkTreeViewColumn * column;
    GtkTreeIter iter;
    GtkListStore *store;
    GList * columns;

    ouvrier ouv;
    char ouv_id_str[20];
    FILE * f_ouv;
    

    store = gtk_tree_view_get_model(ouvrier_treeview);
    
    if(store == NULL) // Check if colums are already made if not make them
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Id", renderer, "text", EID_OUV, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(ouvrier_treeview), column);
        
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOM_OUV, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(ouvrier_treeview), column);
	
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text",EPRENOM_OUV, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(ouvrier_treeview), column);        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Fonction", renderer, "text", EFONCTION_OUV, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(ouvrier_treeview), column);       

        
        
        renderer = gtk_cell_renderer_text_new();
        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING); // number of G_TYPE_STRING same as the number of colums you need
        gtk_tree_view_set_model(GTK_TREE_VIEW(ouvrier_treeview), GTK_TREE_MODEL(store));
        columns = gtk_tree_view_get_columns (GTK_TREE_VIEW (ouvrier_treeview));
        
 
    }

    gtk_list_store_clear(store); // nettoyer la liste pour ne pas depliquer les resultat
    
    f_ouv = fopen("ouvriers.txt", "r");
    if (f_ouv != NULL)
    {
        while (fscanf(f_ouv,"%u\n%20[^\n]\n%20[^\n]\n%s\n%s\n%d %s %d\n%30[^\n]\n%30[^\n]\n",&ouv.id,ouv.nom,ouv.prenom,ouv.sexe,ouv.tel,&ouv.date.jour,ouv.date.mois,&ouv.date.annee,ouv.fonction,ouv.adresse) != EOF)
        {
                sprintf(ouv_id_str, "%u", ouv.id);
                if (strstr(ouv_id_str, search) != NULL && !(feof(f_ouv)))
                {
                    gtk_list_store_append(store, &iter);
                    gtk_list_store_set(store, &iter, EID_OUV, ouv_id_str,  ENOM_OUV, ouv.nom,EPRENOM_OUV, ouv.prenom, EFONCTION_OUV, ouv.fonction, -1);
                }
            }
    
        fclose(f_ouv);
    }
        gtk_tree_view_set_model(GTK_TREE_VIEW(ouvrier_treeview), GTK_TREE_MODEL(store));
    }
void touver_ouvrier(ouvrier * ouv)
{
    unsigned int id_o = ouv->id;
    FILE * f_ouv;
    f_ouv= fopen("ouvriers.txt", "r");
    if (f_ouv != NULL)
    {
        while (fscanf(f_ouv, "%u\n%20[^\n]\n%20[^\n]\n%s\n%s\n%d %s %d\n%30[^\n]\n%30[^\n]\n", &ouv->id,ouv->nom,ouv->prenom,ouv->sexe,ouv->tel,&ouv->date.jour,ouv->date.mois,&ouv->date.annee,ouv->fonction,ouv->adresse) != EOF && id_o != ouv->id);
        fclose(f_ouv);


    }
}
int supprimer_ouvrier(ouvrier ouv)
{
    ouvrier tmp_ouv;
    FILE * f_ouv;
    FILE * f_tmp_ouv;
    int delete_check_ouv = 0;
    f_ouv = fopen("ouvriers.txt", "r");
    f_tmp_ouv = fopen("ouvriers_tmp.txt", "w");

    if (f_ouv != NULL && f_tmp_ouv != NULL)
    {
        while (fscanf(f_ouv,"%u\n%20[^\n]\n%20[^\n]\n%s\n%s\n%d %s %d\n%30[^\n]\n%30[^\n]\n",&tmp_ouv.id,tmp_ouv.nom,tmp_ouv.prenom,tmp_ouv.sexe,tmp_ouv.tel,&tmp_ouv.date.jour,tmp_ouv.date.mois,&tmp_ouv.date.annee,tmp_ouv.fonction,tmp_ouv.adresse) != EOF)
        {
            if (( tmp_ouv.id!= ouv.id) && !(feof(f_ouv)))
	 fprintf(f_tmp_ouv, "%u\n%s\n%s\n%s\n%s\n%d %s %d\n%s\n%s\n ",tmp_ouv.id,tmp_ouv.nom,tmp_ouv.prenom,tmp_ouv.sexe,tmp_ouv.tel,tmp_ouv.date.jour,tmp_ouv.date.mois,tmp_ouv.date.annee,tmp_ouv.fonction,tmp_ouv.adresse) ;
            else if (!(feof(f_ouv)) && tmp_ouv.id == ouv.id)
		 delete_check_ouv = 1;
        }
        fprintf(f_tmp_ouv, "%u\n", tmp_ouv.id);
        fclose(f_ouv);
        fclose(f_tmp_ouv);
        remove("ouvriers.txt");
        rename("ouvriers_tmp.txt", "ouvriers.txt");
    }
    return delete_check_ouv;    
}
void modifier_ouvrier(ouvrier ouv)
{
    ouvrier tmp_ouv;
    FILE * f_ouv;
    FILE * f_tmp_ouv;
    f_ouv = fopen("ouvriers.txt", "r");
    f_tmp_ouv = fopen("ouvriers_tmp.txt", "w");

    if (f_ouv != NULL && f_tmp_ouv != NULL)
    {
        while (fscanf (f_ouv, "%u\n%20[^\n]\n%20[^\n]\n%s\n%s\n%d %s %d\n%30[^\n]\n%30[^\n]\n",&tmp_ouv.id,tmp_ouv.nom,tmp_ouv.prenom,tmp_ouv.sexe,tmp_ouv.tel,&tmp_ouv.date.jour,tmp_ouv.date.mois,&tmp_ouv.date.annee,tmp_ouv.fonction,tmp_ouv.adresse)!= EOF)
        {
            if ((tmp_ouv.id == ouv.id) && !(feof(f_ouv)))
                 fprintf(f_tmp_ouv,  "%u\n%s\n%s\n%s\n%s\n%d %s %d\n%s\n%s\n",ouv.id,ouv.nom,ouv.prenom,ouv.sexe,ouv.tel,ouv.date.jour,ouv.date.mois,ouv.date.annee,ouv.fonction,ouv.adresse);
            else if (!(feof(f_ouv)))
             fprintf(f_tmp_ouv, "%u\n%s\n%s\n%s\n%s\n%d %s %d\n%s\n%s\n",tmp_ouv.id,tmp_ouv.nom,tmp_ouv.prenom,tmp_ouv.sexe,tmp_ouv.tel,tmp_ouv.date.jour,tmp_ouv.date.mois,tmp_ouv.date.annee,tmp_ouv.fonction,tmp_ouv.adresse);
        }
        fprintf(f_tmp_ouv, "%u\n", tmp_ouv.id);
        fclose(f_ouv);
        fclose(f_tmp_ouv);
        remove("ouvriers.txt");
        rename("ouvriers_tmp.txt", "ouvriers.txt");
    }
}
    
//**********TAUX*********

    
void afficher_taux(GtkWidget * taux_treeview)
{

    GtkCellRenderer * renderer;
    GtkTreeViewColumn * column;
    GtkTreeIter iter;
    GtkListStore *store;
    GList * columns;
    Taux t;
    
    FILE * f_taux;
    FILE *f_abs;
    int j_abs=0 ;
    int j_pre=0;
    int currentMonth=0;
    float taux;
    char  str_mois[3], str_anne[5], str_taux[7];
    f_taux=fopen("taux.txt","w");
    f_abs=fopen("absenteisme.txt","r");
    store = gtk_tree_view_get_model(taux_treeview);
    
    if(store == NULL) 
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text", 0, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(taux_treeview), column);
        
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Année", renderer, "text", 1, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(taux_treeview), column);
	
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Taux", renderer, "text",2, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(taux_treeview), column);        

        renderer = gtk_cell_renderer_text_new();
        
        store = gtk_list_store_new(3, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING); 
        gtk_tree_view_set_model(GTK_TREE_VIEW(taux_treeview), GTK_TREE_MODEL(store));
        columns = gtk_tree_view_get_columns (GTK_TREE_VIEW (taux_treeview));
        
 
    }

    gtk_list_store_clear(store); 
    
   



        if (f_abs != NULL && f_taux!= NULL)
        {
            while (fscanf(f_abs,"%d %d %d %d %d\n",&t.id,&t.j,&t.m,&t.a,&t.prs) != EOF)
            {
                if (currentMonth == 0) 
			currentMonth = t.m;

               if (currentMonth != t.m)
                {
		   
                   taux = (j_abs /(float) (j_abs+j_pre))*100;
                   if (currentMonth != 12)
                   {

                   fprintf(f_taux,"%d %d %.2f%%\n",currentMonth,t.a, taux);
                   }
                   else
                   {

                   fprintf(f_taux,"%d %d %.2f%%\n",currentMonth,t.a-1, taux); 
                   }

		    currentMonth =t.m;
		    j_abs = 0;
		    j_pre = 0;

                }

 		if (t.prs == 1) j_pre++;
                else j_abs++;

            }

 	    taux = (j_abs /(float) (j_abs+j_pre))*100;

                              fprintf(f_taux,"%d %d %.2f%%\n",currentMonth,t.a, taux);
		
    fclose(f_taux);
        }



//************************
    f_taux=fopen("taux.txt","r");
    if (f_taux!= NULL)
    {
        while (fscanf(f_taux,"%s %s %s", str_mois, str_anne, str_taux) != EOF)
        {
                
                if (!(feof(f_taux)))
                {
                    gtk_list_store_append(store, &iter);
                    gtk_list_store_set(store, &iter, 0, str_mois,1, str_anne, 2, str_taux, -1);
                }
            }
    
        fclose(f_taux);
    }
        gtk_tree_view_set_model(GTK_TREE_VIEW(taux_treeview), GTK_TREE_MODEL(store));
    }
    
    
 unsigned int meilleur_ouvrier(char m_prenom[], char m_nom[], int annee_search)
 {
     liste tete = NULL;
     liste last = NULL;
     liste pos = NULL;
     struct Cell_best_ouv * new;
     FILE * f_ouv;
     FILE * f_absence;
     ouvrier ouv;
     int id_ab, jr_ab, m_ab, an_ab, etat_ab;
     int max_pr = 0;
     unsigned int mei_id = 4294967295;
     f_ouv = fopen("ouvriers.txt", "r");
     f_absence = fopen("absenteisme.txt", "r");
     if (f_absence != NULL && f_ouv != NULL)
     {
         while (fscanf(f_ouv, "%u\n%20[^\n]\n%20[^\n]\n%s\n%s\n%d %s %d\n%30[^\n]\n%30[^\n]\n", &ouv.id,ouv.nom,ouv.prenom,ouv.sexe,ouv.tel,&ouv.date.jour,ouv.date.mois,&ouv.date.annee,ouv.fonction,ouv.adresse) != EOF)
         {
             if (!(feof(f_ouv)))
             {
                 new = (struct Cell_best_ouv*)malloc(sizeof(struct Cell_best_ouv));
                 new->id = ouv.id;
                 strcpy(new->prenom, ouv.prenom);
                 strcpy(new->nom, ouv.nom);
                 new->jours_presents = 0;
                 new->annee = annee_search;
                 new->suiv = NULL;
                 if (tete == NULL)
                 {
                     tete = new;
                     last = new;
                 }
                 else
                 {
                     last->suiv = new;
                     last = new;
                 }
             }
         }
         if (tete != NULL)
         {
            while (fscanf(f_absence, "%u %d %d %d %d\n", &id_ab, &jr_ab, &m_ab, &an_ab, &etat_ab) != EOF)
            {
                pos = tete;//1er ouvrier
                while (pos != NULL)
                {
                    if((pos->id == id_ab) && (an_ab == annee_search))
                    {
                        if (etat_ab == 1) pos->jours_presents +=1;
                        pos->annee = an_ab;
                    }
                    pos = pos->suiv;
                }

                
            }
                    pos = tete;
                    while (pos != NULL)
                    {
                        if ((pos->jours_presents > max_pr))
                        {
                            max_pr = pos->jours_presents;
                            mei_id = pos->id;
                        }
                        pos = pos->suiv;
                    } 

         }
         if (tete != NULL)
         {
             pos = tete;
             while (pos != NULL)
             {
                 if (mei_id == pos->id) 
                 {
                     strcpy(m_nom, pos->nom);
                     strcpy(m_prenom, pos->prenom);
                    // g_print("%u\n",mei_id);
                     //printf("Le Meilleur ouvrier est : %s %s\n", pos->prenom, pos->nom);
                 }
                 pos = pos->suiv;
             }
         }
      fclose(f_absence);
      fclose(f_ouv);  
      return mei_id;
     }
     return mei_id;

 }
