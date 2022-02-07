#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "troups.h"
#include "clients.h"
#include "equipements.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "equipements.h"
#include "ouvrier.h"
#include "employes.h"
#include "capteur.h"

enum
{
    EID_TROUP,
    ENOM_TROUP,
    ETYPE_TROUP,
    ESANTE_TROUP,
    ENOURRITURE_TROUP,
    ESEXE_TROUP,
    COLUMNS_TROUP
};
enum
{
    EIDENTIFIANT_EQUIP,
    ENOM_EQUIP,
    ETYPE_EQUIP,
    EETAT_EQUIP
};
enum
{
    EID_CLIENTS,
    EPRENOM_CLIENTS,
    ENOM_CLIENTS,
    ECIN_CLIENTS,
    COLUMNS_CLIENTS
};
enum
{
EID_OUV,
ENOM_OUV,
EPRENOM_OUV,
EFONCTION_OUV,
COLUMNS
};
enum
{
    EID_CAP,
    EPRECISION,
    EMARQUE, 
};

GtkWidget *window_employer = NULL;
GtkWidget *window_equipement_mod_sup = NULL;
GtkWidget *window_equipement_ajouter = NULL;
GtkWidget *window_client_ajouter = NULL;
GtkWidget *window_client_m_s = NULL;
GtkWidget *window_troup_ajouter = NULL;
GtkWidget *window_troup_modifier = NULL;
GtkWidget *window_ouvrier_ajouter=NULL;
GtkWidget *window_ouvrier_supprimer=NULL;
GtkWidget *window_capteur_modifier_supprimer = NULL;
GtkWidget *window_capteur_ajouter = NULL;
GtkWidget *admin_screen;


GtkWidget *splash_added_true = NULL;
GtkWidget *splash_added_false = NULL;
GtkWidget *splash_edited_true = NULL;
GtkWidget *splash_edited_false = NULL;
GtkWidget *splash_deleted_true = NULL;
GtkWidget *splash_deleted_false = NULL;
GtkWidget *splash_login_false = NULL;

gboolean delay_destroy_login_false() 
{
  gtk_widget_destroy(splash_login_false);
  splash_login_false = NULL;
  return FALSE;
}

gboolean delay_destroy_edited_true() 
{
  gtk_widget_destroy(splash_edited_true);
  splash_edited_true = NULL;
  return FALSE;
}

gboolean delay_destroy_edited_false() 
{
  gtk_widget_destroy(splash_edited_false);
  splash_edited_false = NULL;
  return FALSE;
}

gboolean delay_destroy_deleted_true() 
{
  gtk_widget_destroy(splash_deleted_true);
  splash_deleted_true = NULL;
  return FALSE;
}

gboolean delay_destroy_deleted_false() 
{
  gtk_widget_destroy(splash_deleted_false);
  splash_deleted_false = NULL;
  return FALSE;
}

gboolean delay_destroy_added_true() 
{
  gtk_widget_destroy(splash_added_true);
  splash_added_true = NULL;
  return FALSE;
}
gboolean delay_destroy_added_false() 
{
  gtk_widget_destroy(splash_added_false);
  splash_added_false = NULL;
  return FALSE;
}





void
on_notebook1_switch_page               (GtkNotebook     *notebook,
                                        GtkNotebookPage *page,
                                        guint            page_num,
                                        gpointer         user_data)
{
GtkWidget *taux_treeview;
if (admin_screen == NULL) admin_screen = lookup_widget(page, "admin_screen");
if (page_num == 0) 
  {
    taux_treeview = lookup_widget(admin_screen, "admin_treeview_taux");
    afficher_taux(taux_treeview);
  }
}


gboolean
on_notebook1_select_page               (GtkNotebook     *notebook,
                                        gboolean         move_focus,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_admin_scr_ges_employ_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_admin_scr_ges_employ_search_entry_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data)
{

}


void
on_admin_scr_ges_employ_button_add_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_employer_notebook_switch_page       (GtkNotebook     *notebook,
                                        GtkNotebookPage *page,
                                        guint            page_num,
                                        gpointer         user_data)
{
  GtkWidget *equip_agri_treeview;
  GtkWidget *equip_agri_search_entry;
  GtkWidget *client_treeview;
  GtkWidget *client_search_entry;
  GtkWidget *troup_treeview;
  GtkWidget *troup_search_entry;
  GtkWidget *ouvrier_treeview;
  GtkWidget *ouvrier_search_entry;
  GtkWidget *capteur_treeview;
  GtkWidget *cap_search_entry;
  char cap_search_string[20];
  char troup_search_string[20];
  char equip_agri_search_string[20];
  char client_search_string[20];
  char ouvrier_search_string[20];
  if (window_employer == NULL) window_employer = lookup_widget(page, "window_employer");
if (page_num == 0) 
  {
    cap_search_entry = lookup_widget(window_employer, "employer_capteurs_entry_recherche");
    strcpy(cap_search_string,gtk_entry_get_text(GTK_ENTRY(cap_search_entry)));

    capteur_treeview = lookup_widget(window_employer, "employer_capteurs_treeview");
    afficher_capteur(capteur_treeview,cap_search_string);
  }
  if (page_num == 1) 
  {
    ouvrier_search_entry = lookup_widget(window_employer, "employer_ouvriers_entry_recherche");
    strcpy(ouvrier_search_string,gtk_entry_get_text(GTK_ENTRY(ouvrier_search_entry)));
    
    ouvrier_treeview = lookup_widget(window_employer, "employer_ouvriers_treeview");
    afficher_ouvrier(ouvrier_treeview,ouvrier_search_string);
  }
  if (page_num == 2) 
  {
    equip_agri_search_entry = lookup_widget(window_employer, "employer_equip_agri_entry_recherche");
    strcpy(equip_agri_search_string,gtk_entry_get_text(GTK_ENTRY(equip_agri_search_entry)));

    equip_agri_treeview = lookup_widget(window_employer, "employer_equip_agri_treeview");
    afficher_equipement(equip_agri_treeview,equip_agri_search_string);
  }
  if (page_num == 3) 
  {
    client_search_entry = lookup_widget(window_employer, "employer_clients_entry_recherche");
    strcpy(client_search_string,gtk_entry_get_text(GTK_ENTRY(client_search_entry)));

    client_treeview = lookup_widget(window_employer, "employer_clients_treeview");
    afficher_client(client_treeview,client_search_string); 
  }
  if (page_num == 4) 
  {
        troup_search_entry = lookup_widget(window_employer, "employer_troup_entry_recherche");
    strcpy(troup_search_string,gtk_entry_get_text(GTK_ENTRY(troup_search_entry)));

    troup_treeview = lookup_widget(window_employer, "employer_troup_treeview");
    afficher_troup(troup_treeview,troup_search_string); 
  }
}


void
on_employer_capteurs_entry_recherche_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data)
{
GtkWidget *capteur_treeview;
    GtkWidget *capteur_search_entry;
    char capteur_search_string[20];
    capteur_search_entry = lookup_widget(window_employer, "employer_capteurs_entry_recherche");
    strcpy(capteur_search_string,gtk_entry_get_text(GTK_ENTRY(capteur_search_entry)));

    capteur_treeview = lookup_widget(window_employer, "employer_capteurs_treeview");
    afficher_capteur(capteur_treeview,capteur_search_string);
}


void
on_employer_capteurs_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


  GtkWidget *capteur_m_s_id;
  GtkWidget *capteur_m_s_entry_nom;
  GtkWidget *capteur_m_s_schneider;
  GtkWidget *capteur_m_s_simens;
  GtkWidget *capteur_m_s_temperature;
  GtkWidget *capteur_m_s_humidite;
  GtkWidget *capteur_m_s_jour;
  GtkWidget *capteur_m_s_mois;
  GtkWidget *capteur_m_s_annee;
  GtkWidget *capteur_m_s_id_out;
  GtkWidget *capteur_ajouter_entry_nom;
  


  GtkTreeIter iter;
  capteur tmp_cap;
  char *ptr;
  gchar *id; 
  gchar *precision;
  gchar *marque;
  char cap_id_str[20];
	
	if (window_capteur_modifier_supprimer == NULL) 
  {
    GtkTreeModel *model = gtk_tree_view_get_model(treeview); 
    if (gtk_tree_model_get_iter(model, &iter, path)) 
    {
gtk_tree_model_get(model, &iter, EID_CAP, &id, EPRECISION, &precision, EMARQUE,&marque ,-1); 
        strcpy(cap_id_str, id); 
      tmp_cap.ID = strtoul(cap_id_str, &ptr, 10); 
      trouver_capteur(&tmp_cap); 

      window_capteur_modifier_supprimer = create_window_capteur_modifier_supprimer(); 
      gtk_widget_show (window_capteur_modifier_supprimer); 

	capteur_m_s_id_out = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_label_id_out"); 
     capteur_m_s_entry_nom = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_entry_nom");//precision
     
      capteur_m_s_simens = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_radiobutton_simens");
      capteur_m_s_schneider = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_radiobutton_schneider");
      capteur_m_s_jour = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_spinbutton_jour");
 capteur_m_s_mois = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_comboboxentry_mois");
      capteur_m_s_annee = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_spinbutton_annee");
      capteur_m_s_temperature = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_checkbutton_temperature");
      capteur_m_s_humidite = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_checkbutton_humidite");
    


gtk_label_set_text(capteur_m_s_id_out, cap_id_str); // ecrire dans le label id l'id du client a modifier
      gtk_entry_set_text(capteur_m_s_entry_nom, tmp_cap.precision); // ecrire dans l'entry l'ancien cin du client

      if (strstr(tmp_cap.marque, "Simens") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(capteur_m_s_simens), TRUE); // si il est un Homme le button radio homme est selectionner
      else gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(capteur_m_s_schneider), TRUE); // sinon le button radio femme selectionner

         gtk_spin_button_set_value(GTK_SPIN_BUTTON(capteur_m_s_jour), tmp_cap.date.day); // changer la valeur du spin jour avec l'ancienne valeur du client a modifier 

      //????? derniere_visite

      

if (strstr(tmp_cap.date.month, "Janvier") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(capteur_m_s_mois), 0); // si le mois est Janvier alors il faut selectionner Janvier du combobox qui est dans la position 0
      else if (strstr(tmp_cap.date.month, "Fevrier") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(capteur_m_s_mois), 1); // ........ est Fevrier .............la position 1
      else if (strstr(tmp_cap.date.month, "Mars") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(capteur_m_s_mois), 2); // same
      else if (strstr(tmp_cap.date.month, "Avril") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(capteur_m_s_mois), 3); // same
      else if (strstr(tmp_cap.date.month, "Mai") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(capteur_m_s_mois), 4); // same
      else if (strstr(tmp_cap.date.month, "Juin") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(capteur_m_s_mois), 5); //same
      else if (strstr(tmp_cap.date.month, "Juillet") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(capteur_m_s_mois), 6); //same
      else if (strstr(tmp_cap.date.month, "Aout") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(capteur_m_s_mois), 7); //same
      else if (strstr(tmp_cap.date.month, "Septembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(capteur_m_s_mois), 8); //same
      else if (strstr(tmp_cap.date.month, "Octobre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(capteur_m_s_mois), 9);  //same
      else if (strstr(tmp_cap.date.month, "Novembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(capteur_m_s_mois), 10); //same
      else if (strstr(tmp_cap.date.month, "Decembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(capteur_m_s_mois), 11); //same

 

gtk_spin_button_set_value(GTK_SPIN_BUTTON(capteur_m_s_annee), tmp_cap.date.year); // changer la valeur du spin annee avec la valeur de l'annee du client

      /*gtk_entry_set_text(capteur_m_s_tel, tmp_cli.telnumbr); // ecrire dans l'entry l'ancien num tel du client
      gtk_entry_set_text(client_m_s_mail, tmp_cli.mail); // ...
      gtk_entry_set_text(client_m_s_addresse, tmp_cli.adresse); // ...
		???????ma3meltech menhom
*/


      if (strstr(tmp_cap.type, "Temperature") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(capteur_m_s_temperature), TRUE); // si le client utilise Espèces alors le checkbox Espèces sera activé
      if (strstr(tmp_cap.type, "Humidite") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(capteur_m_s_humidite), TRUE); // ... Chèque ....checkbox Chèque activé
  
    }
  }
}


void
on_employer_capteurs_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
//thamer///
GtkWidget *capteur_ajouter_id_out;
 gchar id_str_cap[20];
 unsigned int id_cap;

  
  if (window_capteur_ajouter == NULL) 
  {
    id_cap = last_id_cap(); 
    sprintf(id_str_cap, "%u", id_cap);
    window_capteur_ajouter=create_window_capteur_ajouter ();
    gtk_widget_show(window_capteur_ajouter); 
    capteur_ajouter_id_out = lookup_widget(window_capteur_ajouter, "capteur_ajouter_id_out");
   gtk_label_set_text(capteur_ajouter_id_out, id_str_cap);
    
  }//
}


void
on_employer_capteurs_radiobutton_humi_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_employer_capteurs_radiobutton_temp_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_employer_ouvriers_entry_recherche_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data)
{
    GtkWidget *ouvrier_treeview;
    GtkWidget *ouvrier_search_entry;
    char ouvrier_search_string[20];
    ouvrier_search_entry = lookup_widget(window_employer, "employer_ouvriers_entry_recherche");
    strcpy(ouvrier_search_string,gtk_entry_get_text(GTK_ENTRY(ouvrier_search_entry)));

    ouvrier_treeview = lookup_widget(window_employer, "employer_ouvriers_treeview");
    afficher_ouvrier(ouvrier_treeview,ouvrier_search_string);
}


void
on_employer_ouvriers_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
  char *ptre;
  ouvrier ouv;
  GtkWidget *ouvrier_supp_nom;
  GtkWidget *ouvrier_supp_prenom;
  GtkWidget *ouvrier_supp_id_out;
  GtkWidget *ouvrier_supp_sexef;
  GtkWidget *ouvrier_supp_sexeh;
  GtkWidget *ouvrier_supp_tel;
  GtkWidget *ouvrier_supp_adresse;
  GtkWidget *ouvrier_supp_jour;
  GtkWidget *ouvrier_supp_mois ;
  GtkWidget *ouvrier_supp_annee;
  GtkWidget *ouvrier_supp_ouvrier_agricole;
  GtkWidget *ouvrier_supp_securite;
 char id_str_ouv[20];
  gchar *id_ouv; 
  gchar *nom_ouv;
  gchar *prenom_ouv;
  gchar *fonction_ouv;
  

 if (window_ouvrier_supprimer == NULL) 
  {
    GtkTreeModel *model = gtk_tree_view_get_model(treeview); 
    if (gtk_tree_model_get_iter(model, &iter, path))  
    {
      gtk_tree_model_get(model, &iter, EID_OUV, &id_ouv, ENOM_OUV, &nom_ouv, EPRENOM_OUV, &prenom_ouv, EFONCTION_OUV, &fonction_ouv
   ,-1); 
      strcpy(id_str_ouv, id_ouv); 
      ouv.id = strtoul(id_str_ouv, &ptre, 10); 
      touver_ouvrier(&ouv); 
       window_ouvrier_supprimer = create_window_ouvrier_supprimer ();
      gtk_widget_show (window_ouvrier_supprimer); 

      ouvrier_supp_id_out = lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_label_id_out"); 
      ouvrier_supp_nom = lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_entry_nom");
      ouvrier_supp_prenom = lookup_widget(window_ouvrier_supprimer, "entry6");
      ouvrier_supp_sexef=lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_radiobutton_femme");
      ouvrier_supp_sexeh=lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_radiobutton_homme");
      ouvrier_supp_tel = lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_entry_tel");
	ouvrier_supp_jour = lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_spinbutton_jour");
  	ouvrier_supp_mois = lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_comboboxentry_mois");
  	ouvrier_supp_annee = lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_spinbutton_annee");
        ouvrier_supp_ouvrier_agricole= lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_checkbutton_ouvrier_agricole");
        ouvrier_supp_securite = lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_checkbutton_securite");
	ouvrier_supp_adresse= lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_entry_adresse");

      gtk_label_set_text(ouvrier_supp_id_out, id_str_ouv); 
      gtk_entry_set_text(ouvrier_supp_nom, ouv.nom); 
	gtk_entry_set_text(ouvrier_supp_prenom, ouv.prenom);
	
	 
	if (strstr(ouv.sexe, "Femme") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(ouvrier_supp_sexef), TRUE);
		else gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(ouvrier_supp_sexeh), TRUE); 
      
	gtk_entry_set_text(ouvrier_supp_tel,ouv.tel);
     
 if (strstr(ouv.fonction, "ouvrier agricole") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON( ouvrier_supp_ouvrier_agricole), TRUE); 
    		 else gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(ouvrier_supp_securite), TRUE);

  
      gtk_spin_button_set_value(GTK_SPIN_BUTTON(ouvrier_supp_jour), ouv.date.jour); 
	

      if (strstr(ouv.date.mois, "Janvier") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(ouvrier_supp_mois), 0); 
      else if (strstr(ouv.date.mois, "Fevrier") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(ouvrier_supp_mois), 1); 
      else if (strstr(ouv.date.mois, "Mars") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(ouvrier_supp_mois), 2); 
      else if (strstr(ouv.date.mois, "Avril") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(ouvrier_supp_mois), 3); 
      else if (strstr(ouv.date.mois, "Mai") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(ouvrier_supp_mois), 4); 
      else if (strstr(ouv.date.mois, "Juin") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(ouvrier_supp_mois), 5);
      else if (strstr(ouv.date.mois, "Juillet") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(ouvrier_supp_mois), 6); 
      else if (strstr(ouv.date.mois, "Aout") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(ouvrier_supp_mois), 7); 
      else if (strstr(ouv.date.mois, "Septembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(ouvrier_supp_mois), 8); 
     else if (strstr(ouv.date.mois, "Octobre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(ouvrier_supp_mois), 9); 
      else if (strstr(ouv.date.mois, "Novombre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(ouvrier_supp_mois), 10); 
      else if (strstr(ouv.date.mois, "Decombre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(ouvrier_supp_mois), 11); 

      gtk_spin_button_set_value(GTK_SPIN_BUTTON(ouvrier_supp_annee), ouv.date.annee); 
	
 	gtk_entry_set_text(ouvrier_supp_adresse, ouv.adresse);
}
}
}

void
on_employer_ouvriers_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *ouvrier_ajouter_id_out;
 gchar id_str_ouv[20];
 unsigned int id_ouv;

  
  if (window_ouvrier_ajouter == NULL) 
  {
    id_ouv = last_id_ouv(); 
    sprintf(id_str_ouv, "%u", id_ouv);
    window_ouvrier_ajouter=create_window_ouvrier_ajouter();
    gtk_widget_show(window_ouvrier_ajouter); 
    ouvrier_ajouter_id_out = lookup_widget(window_ouvrier_ajouter, "ouvrier_ajouter_label_id_out");
   gtk_label_set_text(ouvrier_ajouter_id_out, id_str_ouv);
    
  }
}


void
on_employer_equip_agri_entry_recherche_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data)
{
  GtkWidget *equip_agri_treeview;
  GtkWidget *equip_agri_search_entry;
  char equip_agri_search_string[20];


    equip_agri_search_entry = lookup_widget(window_employer, "employer_equip_agri_entry_recherche");
    strcpy(equip_agri_search_string,gtk_entry_get_text(GTK_ENTRY(equip_agri_search_entry)));

    equip_agri_treeview = lookup_widget(window_employer, "employer_equip_agri_treeview");
    afficher_equipement(equip_agri_treeview,equip_agri_search_string);
}


void
on_employer_equip_agri_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *equipement_ms_nom;
  GtkWidget *equipement_ms_machine;
  GtkWidget *equipement_ms_instrument;
  GtkWidget *equipement_ms_mauvais;
  GtkWidget *equipement_ms_bon;
  GtkWidget *equipement_ms_excellent;
  GtkWidget *equipement_ms_jour;
  GtkWidget *equipement_ms_mois;
  GtkWidget *equipement_ms_annee;
  GtkWidget *equipement_ms_jour2;
  GtkWidget *equipement_ms_mois2;
  GtkWidget *equipement_ms_annee2;
  GtkWidget *equipement_ms_id_out;

  GtkTreeIter iter;
  equipement tmp_equi;
  char *ptre;
  gchar *id_equi; 
  gchar *nom_equi;
  gchar *type_equi;
  gchar *etat_equi;
  char id_str_equi[20];

 if (window_equipement_mod_sup == NULL) // verifie si la fenetre modifier supprimer equipement est déja ouvert pour ne pas avoir deux fenetre and create une confusion 
  {
    GtkTreeModel *model = gtk_tree_view_get_model(treeview); 
    if (gtk_tree_model_get_iter(model, &iter, path))  
    {
      gtk_tree_model_get(model, &iter, EIDENTIFIANT_EQUIP, &id_equi, ENOM_EQUIP, &nom_equi, ETYPE_EQUIP, &type_equi, EETAT_EQUIP, &etat_equi ,-1); // lecture de la ligne selectionner et mettre ses valeur dans des variable gchar dans la fonction
      strcpy(id_str_equi, id_equi); // convertir du type gchar vers char (chaine de caractere)
      tmp_equi.id = strtoul(id_str_equi, &ptre, 10); // convertir du type chaine de caractere vers "unsigned int" et ptr c'est juste une variable dans la quelle si il y a une erreur de conversion et 10 c'est la base 10
      touver_equipement(&tmp_equi); // chercher le reste des donnée du equipement apartir du fichier equipement car on a juste l'id apartir du treeview donc il faut completer les donner  a partir du ficher pour les afficher dans la fenetre modifier supprimer
      window_equipement_mod_sup = create_window_equipement_mod_sup(); // crée la fenetre modifier supprimer equipement dans la RAM
      gtk_widget_show (window_equipement_mod_sup); // afficher la fenetre modifier supprimer equipement dans l'ecran

      equipement_ms_id_out = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_id_out"); 
      equipement_ms_nom = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_entry_nom");
    equipement_ms_machine = lookup_widget(window_equipement_mod_sup, "equipemeny_mod_sup_checkbutton_machine");
    equipement_ms_instrument = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_checkbutton_instrument");

    equipement_ms_excellent = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_radiobutton_excellent");
    equipement_ms_bon = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_radiobutton_bon");
    equipement_ms_mauvais = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_radiobutton_mauvais");

    equipement_ms_jour = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_ajout_spinbutton_jour");
    equipement_ms_mois = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_ajout_comboboxentry_mois");
    equipement_ms_annee = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_ajout_spinbutton_annee");

    equipement_ms_jour2 = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_main_spinbutton_jour");
    equipement_ms_mois2 = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_main_comboboxentry_mois");
    equipement_ms_annee2 = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_main_spinbutton_annee");

// id et nom
      gtk_label_set_text(equipement_ms_id_out, id_str_equi); // ecrire dans le label id l'id du equipement a modifier
      gtk_entry_set_text(equipement_ms_nom, tmp_equi.nom); // ecrire dans l'entry l'ancien cin du equipement

//type
      if (strstr(tmp_equi.type, "Machine") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(equipement_ms_machine), TRUE); // si le type est machine alors le checkbox machine sera activé
      if (strstr(tmp_equi.type, "Instrument") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(equipement_ms_instrument), TRUE);

//etat
      if (strstr(tmp_equi.etat, "Excellent") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(equipement_ms_excellent), TRUE); // si l'etat est excellent le button radio excellent est selectionner
      else if (strstr(tmp_equi.etat, "Bon") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(equipement_ms_bon), TRUE);
			else gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(equipement_ms_mauvais), TRUE); 

//date ajout
      gtk_spin_button_set_value(GTK_SPIN_BUTTON(equipement_ms_jour), tmp_equi.date_ajout.jour); // changer la valeur du spin jour avec l'ancienne valeur du equipement a modifier

      if (strstr(tmp_equi.date_ajout.mois, "Janvier") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois), 0); // si le mois est Janvier alors il faut selectionner Janvier du combobox qui est dans la position 0
      else if (strstr(tmp_equi.date_ajout.mois, "Fevrier") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois), 1); 
      else if (strstr(tmp_equi.date_ajout.mois, "Mars") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois), 2); // same
      else if (strstr(tmp_equi.date_ajout.mois, "Avril") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois), 3); 
      else if (strstr(tmp_equi.date_ajout.mois, "Mai") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois), 4); 
      else if (strstr(tmp_equi.date_ajout.mois, "Juin") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois), 5);
      else if (strstr(tmp_equi.date_ajout.mois, "Juillet") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois), 6); 
      else if (strstr(tmp_equi.date_ajout.mois, "Aout") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois), 7); 
      else if (strstr(tmp_equi.date_ajout.mois, "Septembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois), 8); 
      else if (strstr(tmp_equi.date_ajout.mois, "Octobre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois), 9);  
      else if (strstr(tmp_equi.date_ajout.mois, "Novembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois), 10); 
      else if (strstr(tmp_equi.date_ajout.mois, "Decembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois), 11); 

      gtk_spin_button_set_value(GTK_SPIN_BUTTON(equipement_ms_annee), tmp_equi.date_ajout.annee); // changer la valeur du spin annee avec la valeur de l'annee du equipement

//date dernier maintenance
      gtk_spin_button_set_value(GTK_SPIN_BUTTON(equipement_ms_jour2), tmp_equi.date_dernier_maintenance.jour); // changer la valeur du spin jour avec l'ancienne valeur du equipement a modifier

      if (strstr(tmp_equi.date_dernier_maintenance.mois, "Janvier") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois2), 0); // si le mois est Janvier alors il faut selectionner Janvier du combobox qui est dans la position 0
      else if (strstr(tmp_equi.date_dernier_maintenance.mois, "Fevrier") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois2), 1); 
      else if (strstr(tmp_equi.date_dernier_maintenance.mois, "Mars") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois2), 2); // same
      else if (strstr(tmp_equi.date_dernier_maintenance.mois, "Avril") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois2), 3); 
      else if (strstr(tmp_equi.date_dernier_maintenance.mois, "Mai") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois2), 4); 
      else if (strstr(tmp_equi.date_dernier_maintenance.mois, "Juin") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois2), 5);
      else if (strstr(tmp_equi.date_dernier_maintenance.mois, "Juillet") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois2), 6); 
      else if (strstr(tmp_equi.date_dernier_maintenance.mois, "Aout") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois2), 7); 
      else if (strstr(tmp_equi.date_dernier_maintenance.mois, "Septembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois2), 8); 
      else if (strstr(tmp_equi.date_dernier_maintenance.mois, "Octobre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois2), 9);  
      else if (strstr(tmp_equi.date_dernier_maintenance.mois, "Novembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois2), 10); 
      else if (strstr(tmp_equi.date_dernier_maintenance.mois, "Decembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(equipement_ms_mois2), 11); 

      gtk_spin_button_set_value(GTK_SPIN_BUTTON(equipement_ms_annee2), tmp_equi.date_dernier_maintenance.annee);

    }
  }
}


void
on_employer_equip_agri_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *equipement_ajouter_id_out;
  gchar id_str_equi[20];
  unsigned int id_equi;

  //itoa(id, id_str_equi, 15);
  if (window_equipement_ajouter == NULL) // Verifie si la fenetre ajout equipement est déja ouverte
  {
    id_equi = last_id_equi(); 
    sprintf(id_str_equi, "%u", id_equi); // convertir l'id du type unsigned int vers une chaine de caratere
    window_equipement_ajouter = create_window_equipement_ajouter (); // creation de la fenetre d'ajout equipement dans la Ram
    gtk_widget_show (window_equipement_ajouter); // affichage de la fenetre d'ajout equipement
    equipement_ajouter_id_out = lookup_widget(window_equipement_ajouter, "equipement_ajouter_id_out"); // recherche de la label de l'id dans la fenetre ajout equipement
    gtk_label_set_text(equipement_ajouter_id_out, id_str_equi); // modification de la l'id dans la feneter ajout equipement
    
  }
}


void
on_employer_clients_entry_recherche_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data)
{

GtkWidget *client_treeview;
GtkWidget *client_search_entry;
char client_search_string[20];
if (window_employer == NULL) window_employer = lookup_widget(editable, "window_employer");


client_search_entry = lookup_widget(window_employer, "employer_clients_entry_recherche");
strcpy(client_search_string,gtk_entry_get_text(GTK_ENTRY(client_search_entry)));


client_treeview = lookup_widget(window_employer, "employer_clients_treeview");
afficher_client(client_treeview,client_search_string); 

}


void
on_employer_clients_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *client_m_s_cin;
  GtkWidget *client_m_s_prenom;
  GtkWidget *client_m_s_nom;
  GtkWidget *client_m_s_homme;
  GtkWidget *client_m_s_femme;
  GtkWidget *client_m_s_jour;
  GtkWidget *client_m_s_mois;
  GtkWidget *client_m_s_annee;
  GtkWidget *client_m_s_tel;
  GtkWidget *client_m_s_mail;
  GtkWidget *client_m_s_addresse;
  GtkWidget *client_m_s_especes;
  GtkWidget *client_m_s_cheque;
  GtkWidget *client_m_s_carte_bancaire;
  GtkWidget *client_m_s_id_out;



  GtkTreeIter iter;
  client tmp_cli;
  char *ptr;
  gchar *id; 
  gchar *prenom;
  gchar *nom;
  gchar *cin;
  char id_str[20];
  if (window_client_m_s == NULL)
  {
    GtkTreeModel *model = gtk_tree_view_get_model(treeview); 
    if (gtk_tree_model_get_iter(model, &iter, path))
    {
      gtk_tree_model_get(model, &iter, EID_CLIENTS, &id, EPRENOM_CLIENTS, &prenom, ENOM_CLIENTS, &nom, ECIN_CLIENTS, &cin ,-1);
      strcpy(id_str, id);
      tmp_cli.id = strtoul(id_str, &ptr, 10);
      touver_client(&tmp_cli);
      window_client_m_s = create_window_client_m_s();
      gtk_widget_show (window_client_m_s);
      client_m_s_id_out = lookup_widget(window_client_m_s, "client_m_s_id_out"); 
      client_m_s_cin = lookup_widget(window_client_m_s, "client_m_s_entry_cin");
      client_m_s_prenom = lookup_widget(window_client_m_s, "client_m_s_entry_prenom");
      client_m_s_nom = lookup_widget(window_client_m_s, "client_m_s_entry_nom");
      client_m_s_homme = lookup_widget(window_client_m_s, "client_m_s_radiobutton_homme");
      client_m_s_femme = lookup_widget(window_client_m_s, "client_m_s_radiobutton_femme");
      client_m_s_jour = lookup_widget(window_client_m_s, "client_m_s_spinbutton_jour");
      client_m_s_mois = lookup_widget(window_client_m_s, "client_m_s_comboboxentry_mois");
      client_m_s_annee = lookup_widget(window_client_m_s, "client_m_s_spinbutton_annee");
      client_m_s_tel = lookup_widget(window_client_m_s, "client_m_s_entry_tel");
      client_m_s_mail = lookup_widget(window_client_m_s, "client_m_s_entry_mail");
      client_m_s_addresse = lookup_widget(window_client_m_s, "client_m_s_entry_addr");
      client_m_s_especes = lookup_widget(window_client_m_s, "client_m_s_checkbutton_especes");
      client_m_s_cheque = lookup_widget(window_client_m_s, "client_m_s_checkbutton_cheque");
      client_m_s_carte_bancaire = lookup_widget(window_client_m_s, "client_m_s_checkbutton_cartebancaire");

      gtk_label_set_text(client_m_s_id_out, id_str);
      gtk_entry_set_text(client_m_s_cin, tmp_cli.cin);
      gtk_entry_set_text(client_m_s_prenom, tmp_cli.prenom);
      gtk_entry_set_text(client_m_s_nom, tmp_cli.nom);

      if (strstr(tmp_cli.sexe, "Homme") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(client_m_s_homme), TRUE);
      else gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(client_m_s_femme), TRUE);
      
      gtk_spin_button_set_value(GTK_SPIN_BUTTON(client_m_s_jour), tmp_cli.derniere_visite.jour);

      if (strstr(tmp_cli.derniere_visite.mois, "Janvier") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(client_m_s_mois), 0);
      else if (strstr(tmp_cli.derniere_visite.mois, "Février") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(client_m_s_mois), 1);
      else if (strstr(tmp_cli.derniere_visite.mois, "Mars") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(client_m_s_mois), 2);
      else if (strstr(tmp_cli.derniere_visite.mois, "Avril") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(client_m_s_mois), 3);
      else if (strstr(tmp_cli.derniere_visite.mois, "Mai") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(client_m_s_mois), 4);
      else if (strstr(tmp_cli.derniere_visite.mois, "Juin") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(client_m_s_mois), 5);
      else if (strstr(tmp_cli.derniere_visite.mois, "Juillet") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(client_m_s_mois), 6);
      else if (strstr(tmp_cli.derniere_visite.mois, "Août") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(client_m_s_mois), 7);
      else if (strstr(tmp_cli.derniere_visite.mois, "Septembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(client_m_s_mois), 8);
      else if (strstr(tmp_cli.derniere_visite.mois, "Octobre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(client_m_s_mois), 9); 
      else if (strstr(tmp_cli.derniere_visite.mois, "Novembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(client_m_s_mois), 10);
      else if (strstr(tmp_cli.derniere_visite.mois, "Décembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(client_m_s_mois), 11);

      gtk_spin_button_set_value(GTK_SPIN_BUTTON(client_m_s_annee), tmp_cli.derniere_visite.annee);

      gtk_entry_set_text(client_m_s_tel, tmp_cli.telnumbr);
      gtk_entry_set_text(client_m_s_mail, tmp_cli.mail);
      gtk_entry_set_text(client_m_s_addresse, tmp_cli.adresse);


      if (strstr(tmp_cli.paiment, "Espèces") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(client_m_s_especes), TRUE);
      if (strstr(tmp_cli.paiment, "Chèque") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(client_m_s_cheque), TRUE);
      if (strstr(tmp_cli.paiment, "CB") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(client_m_s_carte_bancaire), TRUE);
    }
  }
}


void
on_employer_clients_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *client_ajouter_id_out;
  gchar id_str[20];
  unsigned int id;

  if (window_client_ajouter == NULL) 
  {
    id = last_id_client(); 
    sprintf(id_str, "%u", id); 
    window_client_ajouter = create_window_client_ajouter (); 
    gtk_widget_show (window_client_ajouter); 
    client_ajouter_id_out = lookup_widget(window_client_ajouter, "client_ajouter_id_out"); 
    gtk_label_set_text(client_ajouter_id_out, id_str);     
  }
}


void
on_employer_troup_entry_recherche_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data)
{
  GtkWidget *troup_treeview;
  GtkWidget *troup_search_entry;
  
  char troup_search_string[20];
  troup_search_entry = lookup_widget(window_employer, "employer_troup_entry_recherche");
  strcpy(troup_search_string,gtk_entry_get_text(GTK_ENTRY(troup_search_entry)));

   troup_treeview = lookup_widget(window_employer, "employer_troup_treeview");
   afficher_troup(troup_treeview,troup_search_string); 
}


void
on_employer_troup_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *troup_modifier_entry_nom;
  GtkWidget *troup_modifier_type;
  GtkWidget *troup_modifier_sante;
  GtkWidget *troup_modifier_ble;
  GtkWidget *troup_modifier_haricot;
  GtkWidget *troup_modifier_eau;
  GtkWidget *troup_modifier_herbe;
  GtkWidget *troup_modifier_masculin;
  GtkWidget *troup_modifier_feminin;
  GtkWidget *troup_modifier_jour;
  GtkWidget *troup_modifier_mois;
  GtkWidget *troup_modifier_annee;
  GtkWidget *troup_modifier_id_out;

  GtkTreeIter iter;
  troup tmp_trou;
  char *ptr;
  gchar *id; 
  gchar *nom;
  gchar *type;
  gchar *sante;
  char id_str[20];
  if (window_troup_modifier == NULL) // verifie si la fenetre modifier supprimer troup est déja ouvert pour ne pas avoir deux fenetre and create une confusion 
  {
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);
    if (gtk_tree_model_get_iter(model, &iter, path)) 
    {
      gtk_tree_model_get(model, &iter, EID_TROUP, &id, ENOM_TROUP, &nom, ETYPE_TROUP, &type, ESANTE_TROUP, &sante ,-1); // lecture de la ligne selectionner et mettre ses valeur dans des variable gchar dans la fonction
      strcpy(id_str, id); // convertir du type gchar vers char (chaine de caractere)
      tmp_trou.id = strtoul(id_str, &ptr, 10); // convertir du type chaine de caractere vers "unsigned int" et ptr c'est juste une variable dans la quelle si il y a une erreur de conversion et 10 c'est la base 10
      touver_troup(&tmp_trou); // chercher le reste des donnée du troup apartir du fichier troup car on a juste l'id apartir du treeview donc il faut completer les donner  a partir du ficher pour les afficher dans la fenetre modifier supprimer
      window_troup_modifier = create_window_troup_modifier(); // crée la fenetre modifier supprimer troup dans la RAM
      gtk_widget_show (window_troup_modifier); // afficher la fenetre modifier supprimer troup dans l'ecran
      troup_modifier_id_out = lookup_widget(window_troup_modifier, "troup_modifier_id_out"); 
      troup_modifier_entry_nom = lookup_widget(window_troup_modifier, "troup_modifier_entry_nom");
      troup_modifier_type = lookup_widget(window_troup_modifier, "troup_modifier_comboboxentry_type");
      troup_modifier_sante = lookup_widget(window_troup_modifier, "comboboxentry1");
      troup_modifier_ble = lookup_widget(window_troup_modifier, "troup_modifier_checkbutton_ble");
      troup_modifier_haricot = lookup_widget(window_troup_modifier, "troup_modifier_checkbutton_haricot");
      troup_modifier_eau = lookup_widget(window_troup_modifier, "troup_modifier_checkbutton_eau");
      troup_modifier_herbe = lookup_widget(window_troup_modifier, "troup_modifier_checkbutton_herbe");
      troup_modifier_masculin = lookup_widget(window_troup_modifier, "troup_modifier_radiobutton_masculin");
      troup_modifier_feminin = lookup_widget(window_troup_modifier, "troup_modifier_radiobutton_feminin");
      troup_modifier_jour = lookup_widget(window_troup_modifier, "troup_modifier_spinbutton_jour");
      troup_modifier_mois = lookup_widget(window_troup_modifier, "troup_modifier_comboboxentry_mois");
      troup_modifier_annee = lookup_widget(window_troup_modifier, "troup_modifier_spinbutton_annee");
      

      gtk_label_set_text(troup_modifier_id_out, id_str); // ecrire dans le label id l'id du troup a modifier
      gtk_entry_set_text(troup_modifier_entry_nom, tmp_trou.nom); // ecrire dans l'entry l'ancien nom du troup


  if (strstr(tmp_trou.type, "Poule") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_type), 0);
      else if (strstr(tmp_trou.type, "Mouton") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_type), 1);
      else if (strstr(tmp_trou.type, "Vache") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_type), 2);
      else if (strstr(tmp_trou.type, "Cheveaux") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_type), 3);
      else if (strstr(tmp_trou.type, "Chien") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_type), 4);
      else if (strstr(tmp_trou.type, "Ane") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_type), 5);

if (strstr(tmp_trou.sante, "Mauvaise") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_sante), 0);
      else if (strstr(tmp_trou.sante, "Moyenne") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_sante), 1);
      else if  (strstr(tmp_trou.sante, "Bonne") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_sante), 2);
      
       if (strstr(tmp_trou.nourriture, "son de blé") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(troup_modifier_ble), TRUE); // si le troup mange ble alors le checkbox ble sera activé
      if (strstr(tmp_trou.nourriture, "haricot") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(troup_modifier_haricot), TRUE); // ... 
      if (strstr(tmp_trou.nourriture, "eau") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(troup_modifier_eau), TRUE); // ...
      if (strstr(tmp_trou.nourriture, "herbe") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(troup_modifier_herbe), TRUE); // ...

      if (strstr(tmp_trou.sexe, "Masculin") != NULL) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(troup_modifier_masculin), TRUE); // si il est un masculin le button radio homme est selectionner
      else gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(troup_modifier_feminin), TRUE); // sinon le button radio feminin selectionner
      
      gtk_spin_button_set_value(GTK_SPIN_BUTTON(troup_modifier_jour), tmp_trou.naissance.jour); // changer la valeur du spin jour avec l'ancienne valeur du troup a modifier

      if (strstr(tmp_trou.naissance.mois, "Janvier") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_mois), 0); // si le mois est Janvier alors il faut selectionner Janvier du combobox qui est dans la position 0
      else if (strstr(tmp_trou.naissance.mois, "Février") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_mois), 1); // ........ est Fevrier .............la position 1
      else if (strstr(tmp_trou.naissance.mois, "Mars") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_mois), 2); // same
      else if (strstr(tmp_trou.naissance.mois, "Avril") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_mois), 3); // same
      else if (strstr(tmp_trou.naissance.mois, "Mai") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_mois), 4); // same
      else if (strstr(tmp_trou.naissance.mois, "Juin") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_mois), 5); //same
      else if (strstr(tmp_trou.naissance.mois, "Juillet") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_mois), 6); //same
      else if (strstr(tmp_trou.naissance.mois, "Août") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_mois), 7); //same
      else if (strstr(tmp_trou.naissance.mois, "Septembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_mois), 8); //same
      else if (strstr(tmp_trou.naissance.mois, "Octobre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_mois), 9);  //same
      else if (strstr(tmp_trou.naissance.mois, "Novembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_mois), 10); //same
      else if (strstr(tmp_trou.naissance.mois, "Décembre") != NULL) gtk_combo_box_set_active(GTK_COMBO_BOX(troup_modifier_mois), 11); //same

      gtk_spin_button_set_value(GTK_SPIN_BUTTON(troup_modifier_annee), tmp_trou.naissance.annee); // changer la valeur du spin annee avec la valeur de l'annee du troup  
    }
  }
}


void
on_employer_troup_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *troup_ajouter_id_out;

  gchar id_str[20];
  unsigned int id;

  if (window_troup_ajouter == NULL) 
  {
    id = last_id_troup();
    sprintf(id_str, "%u", id); 
    window_troup_ajouter = create_window_troup_ajouter();
    gtk_widget_show (window_troup_ajouter); 
    troup_ajouter_id_out = lookup_widget(window_troup_ajouter, "troup_ajouter_id_out");  
    gtk_label_set_text(troup_ajouter_id_out, id_str); 
       
  }
}


void
on_employer_button_disconnect_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}


gboolean
on_window_client_ajouter_delete_event  (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
  window_client_ajouter = NULL;
  return FALSE;
}


void
on_client_ajouter_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *client_ajout_cin;
  GtkWidget *client_ajout_prenom;
  GtkWidget *client_ajout_nom;
  GtkWidget *client_ajout_homme;
  GtkWidget *client_ajout_femme;
  GtkWidget *client_ajout_jour;
  GtkWidget *client_ajout_mois;
  GtkWidget *client_ajout_annee;
  GtkWidget *client_ajout_tel;
  GtkWidget *client_ajout_mail;
  GtkWidget *client_ajout_addresse;
  GtkWidget *client_ajout_especes;
  GtkWidget *client_ajout_cheque;
  GtkWidget *client_ajout_carte_bancaire;


  GtkWidget *client_treeview;
  GtkWidget *client_search_entry;
  char client_search_string[20];


  client tmp_cli;
  
if (splash_added_true == NULL && splash_added_false == NULL)
{




  client_ajout_cin = lookup_widget(window_client_ajouter, "client_ajouter_entry_cin");
  client_ajout_prenom = lookup_widget(window_client_ajouter, "client_ajouter_entry_prenom");
  client_ajout_nom = lookup_widget(window_client_ajouter, "client_ajouter_entry_nom");
  client_ajout_homme = lookup_widget(window_client_ajouter, "client_ajouter_radiobutton_homme");
  client_ajout_femme = lookup_widget(window_client_ajouter, "client_ajouter_radiobutton_femme");
  client_ajout_jour = lookup_widget(window_client_ajouter, "client_ajouter_spinbutton_jour");
  client_ajout_mois = lookup_widget(window_client_ajouter, "client_ajouter_comboboxentry_mois");
  client_ajout_annee = lookup_widget(window_client_ajouter, "client_ajouter_spinbutton_annee");
  client_ajout_tel = lookup_widget(window_client_ajouter, "client_ajouter_entry_tel");
  client_ajout_mail = lookup_widget(window_client_ajouter, "client_ajouter_entry_mail");
  client_ajout_addresse = lookup_widget(window_client_ajouter, "client_ajouter_entry_addr");
  client_ajout_especes = lookup_widget(window_client_ajouter, "client_ajouter_checkbutton_especes");
  client_ajout_cheque = lookup_widget(window_client_ajouter, "client_ajouter_checkbutton_cheque");
  client_ajout_carte_bancaire = lookup_widget(window_client_ajouter, "client_ajouter_checkbutton_cartebancaire");

  strcpy(tmp_cli.cin, gtk_entry_get_text(GTK_ENTRY(client_ajout_cin))); 
  strcpy(tmp_cli.prenom, gtk_entry_get_text(GTK_ENTRY(client_ajout_prenom)));
  strcpy(tmp_cli.nom, gtk_entry_get_text(GTK_ENTRY(client_ajout_nom)));
  strcpy(tmp_cli.cin, gtk_entry_get_text(GTK_ENTRY(client_ajout_cin)));
  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(client_ajout_homme))) strcpy(tmp_cli.sexe, "Homme"); 
  else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(client_ajout_femme))) strcpy(tmp_cli.sexe, "Femme");
  else strcpy(tmp_cli.sexe, "ERROR");
  tmp_cli.derniere_visite.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(client_ajout_jour)); 
  strcpy(tmp_cli.derniere_visite.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(client_ajout_mois)));
  tmp_cli.derniere_visite.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(client_ajout_annee));
  strcpy(tmp_cli.telnumbr, gtk_entry_get_text(GTK_ENTRY(client_ajout_tel)));
  strcpy(tmp_cli.mail, gtk_entry_get_text(GTK_ENTRY(client_ajout_mail)));
  strcpy(tmp_cli.adresse, gtk_entry_get_text(GTK_ENTRY(client_ajout_addresse)));
  strcpy(tmp_cli.paiment, "");
  if (gtk_toggle_button_get_active(client_ajout_especes)) 
   {
       strcat(tmp_cli.paiment,"Espèces "); 
   }
  if (gtk_toggle_button_get_active(client_ajout_cheque))
   {
       strcat(tmp_cli.paiment,"Chèque ");
   }
  if (gtk_toggle_button_get_active(client_ajout_carte_bancaire))
   {
       strcat(tmp_cli.paiment,"CB");
   }
      if (check_errors_client(tmp_cli) > 0 || phone_number_correct(tmp_cli.telnumbr) == 0 || empty_invalid_entry_client(tmp_cli) == 0)
   {
    splash_added_false = create_splash_added_false ();
    gtk_widget_show (splash_added_false);
    g_timeout_add_seconds(3, delay_destroy_added_false, NULL);
   }
   else
   {
    splash_added_true = create_splash_added_true ();
    gtk_widget_show (splash_added_true);
    ajouter_client(tmp_cli);
    g_timeout_add_seconds(2, delay_destroy_added_true, NULL);
    gtk_widget_destroy(window_client_ajouter);
    window_client_ajouter = NULL;

    client_search_entry = lookup_widget(window_employer, "employer_clients_entry_recherche");
    strcpy(client_search_string,gtk_entry_get_text(GTK_ENTRY(client_search_entry)));


    client_treeview = lookup_widget(window_employer, "employer_clients_treeview");
    afficher_client(client_treeview,client_search_string); 

   }
}
}


gboolean
on_window_client_m_s_delete_event      (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
  window_client_m_s = NULL;
  return FALSE;
}


void
on_client_m_s_button_modifier_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

    GtkWidget * client_treeview;
    GtkWidget * client_search_entry;
    char client_search_string[20];

    GtkWidget *client_m_s_cin;
    GtkWidget *client_m_s_prenom;
    GtkWidget *client_m_s_nom;
    GtkWidget *client_m_s_homme;
    GtkWidget *client_m_s_femme;
    GtkWidget *client_m_s_jour;
    GtkWidget *client_m_s_mois;
    GtkWidget *client_m_s_annee;
    GtkWidget *client_m_s_tel;
    GtkWidget *client_m_s_mail;
    GtkWidget *client_m_s_addresse;
    GtkWidget *client_m_s_especes;
    GtkWidget *client_m_s_cheque;
    GtkWidget *client_m_s_carte_bancaire;
    GtkWidget *client_m_s_id_out;
    client tmp_cli;
    gchar * id;
    char id_str[20];
    char * ptr;


    client_m_s_id_out = lookup_widget(window_client_m_s, "client_m_s_id_out");
    client_m_s_cin = lookup_widget(window_client_m_s, "client_m_s_entry_cin");
    client_m_s_prenom = lookup_widget(window_client_m_s, "client_m_s_entry_prenom");
    client_m_s_nom = lookup_widget(window_client_m_s, "client_m_s_entry_nom");
    client_m_s_homme = lookup_widget(window_client_m_s, "client_m_s_radiobutton_homme");
    client_m_s_femme = lookup_widget(window_client_m_s, "client_m_s_radiobutton_femme");
    client_m_s_jour = lookup_widget(window_client_m_s, "client_m_s_spinbutton_jour");
    client_m_s_mois = lookup_widget(window_client_m_s, "client_m_s_comboboxentry_mois");
    client_m_s_annee = lookup_widget(window_client_m_s, "client_m_s_spinbutton_annee");
    client_m_s_tel = lookup_widget(window_client_m_s, "client_m_s_entry_tel");
    client_m_s_mail = lookup_widget(window_client_m_s, "client_m_s_entry_mail");
    client_m_s_addresse = lookup_widget(window_client_m_s, "client_m_s_entry_addr");
    client_m_s_especes = lookup_widget(window_client_m_s, "client_m_s_checkbutton_especes");
    client_m_s_cheque = lookup_widget(window_client_m_s, "client_m_s_checkbutton_cheque");
    client_m_s_carte_bancaire = lookup_widget(window_client_m_s, "client_m_s_checkbutton_cartebancaire");


  id = gtk_label_get_text(client_m_s_id_out);
  strcpy(id_str, id);
  tmp_cli.id = strtoul(id_str, &ptr, 10);


  strcpy(tmp_cli.cin, gtk_entry_get_text(GTK_ENTRY(client_m_s_cin))); 
  strcpy(tmp_cli.prenom, gtk_entry_get_text(GTK_ENTRY(client_m_s_prenom)));
  strcpy(tmp_cli.nom, gtk_entry_get_text(GTK_ENTRY(client_m_s_nom)));
  strcpy(tmp_cli.cin, gtk_entry_get_text(GTK_ENTRY(client_m_s_cin)));
  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(client_m_s_homme))) strcpy(tmp_cli.sexe, "Homme"); 
  else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(client_m_s_femme))) strcpy(tmp_cli.sexe, "Femme");
  else strcpy(tmp_cli.sexe, "ERROR");
  tmp_cli.derniere_visite.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(client_m_s_jour)); 
  strcpy(tmp_cli.derniere_visite.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(client_m_s_mois))); 
  tmp_cli.derniere_visite.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(client_m_s_annee)); 
  strcpy(tmp_cli.telnumbr, gtk_entry_get_text(GTK_ENTRY(client_m_s_tel)));
  strcpy(tmp_cli.mail, gtk_entry_get_text(GTK_ENTRY(client_m_s_mail)));
  strcpy(tmp_cli.adresse, gtk_entry_get_text(GTK_ENTRY(client_m_s_addresse)));
  strcpy(tmp_cli.paiment, "");
  if (gtk_toggle_button_get_active(client_m_s_especes)) 
   {
       strcat(tmp_cli.paiment,"Espèces "); 
   }
  if (gtk_toggle_button_get_active(client_m_s_cheque))
   {
       strcat(tmp_cli.paiment,"Chèque "); 
   }
  if (gtk_toggle_button_get_active(client_m_s_carte_bancaire))
   {
       strcat(tmp_cli.paiment,"CB"); 
   }


   if (check_errors_client(tmp_cli) > 0 || phone_number_correct(tmp_cli.telnumbr) == 0 || empty_invalid_entry_client(tmp_cli) == 0) // verifie si il y a des erreur d'entree
   {
    splash_edited_false = create_splash_edited_false (); 
    gtk_widget_show (splash_edited_false); 
    g_timeout_add_seconds(3, delay_destroy_edited_false, NULL); 
   }
   else
   {
    splash_edited_true = create_splash_edited_true ();
    gtk_widget_show (splash_edited_true); // afficher la fenetre ajouter avec succée
    modifier_client(tmp_cli); // ajout du client dans le fichier clients.txt
    g_timeout_add_seconds(2, delay_destroy_edited_true, NULL); // fermer la fenetre cree avec succes apres 2 secondes
    gtk_widget_destroy(window_client_m_s); // fermer la fenetre ajout client
    window_client_m_s = NULL; // declarer que la fenetre modif client est fermer
 


    client_search_entry = lookup_widget(window_employer, "employer_clients_entry_recherche");
    strcpy(client_search_string,gtk_entry_get_text(GTK_ENTRY(client_search_entry)));


    client_treeview = lookup_widget(window_employer, "employer_clients_treeview");
    afficher_client(client_treeview,client_search_string); 

   }

}


void
on_client_m_s_button_supprimer_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *client_m_s_id_out;

  GtkWidget * client_search_entry;
  GtkWidget * client_treeview;

  gchar * id;
  char * ptr;
  char id_str[20];
  char client_search_string[20];
  unsigned int id_ul;
  client tmp_cli;
  int check_deleted_client;

  client_m_s_id_out = lookup_widget(window_client_m_s, "client_m_s_id_out");
  id = gtk_label_get_text(client_m_s_id_out);
  strcpy(id_str, id);
  tmp_cli.id = strtoul(id_str, &ptr, 10);
  check_deleted_client = supprimer_client(tmp_cli);
  gtk_widget_destroy(window_client_m_s);
  window_client_m_s = NULL;
  if (check_deleted_client == 1)
  {
    splash_deleted_true = create_splash_deleted_true ();
    gtk_widget_show (splash_deleted_true);
    g_timeout_add_seconds(2, delay_destroy_deleted_true, NULL);
  }
  else
  {
    splash_deleted_false = create_splash_deleted_false();
    gtk_widget_show (splash_deleted_false);
    g_timeout_add_seconds(3, delay_destroy_deleted_false, NULL);
  }

  client_search_entry = lookup_widget(window_employer, "employer_clients_entry_recherche");
  strcpy(client_search_string,gtk_entry_get_text(GTK_ENTRY(client_search_entry)));


  client_treeview = lookup_widget(window_employer, "employer_clients_treeview");
  afficher_client(client_treeview,client_search_string); 
}


gboolean
on_window_ouvrier_ajouter_delete_event (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
  window_ouvrier_ajouter = NULL;
  return FALSE;
}


void
on_ouvrier_ajouter_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_ouvrier;
GtkWidget *ajout_nom_ouvrier_entry;
GtkWidget *ajout_prenom_ouvrier_entry;
GtkWidget *ajout_tel_ouvrier_entry;
GtkWidget *ajout_adr_ouvrier_entry;
GtkWidget *ajout_jour_ouvrier_entry;
GtkWidget *ajout_mois_ouvrier_entry;
GtkWidget *ajout_annee_ouvrier_entry;
GtkWidget *ajout_sexef_ouvrier_entry;
GtkWidget *ajout_sexeh_ouvrier_entry;
GtkWidget *ajout_fonction_ouvrier_entry;
ouvrier ouv;
GtkWidget *ouvrier_treeview;
GtkWidget *ouvrier_search_entry;
char ouvrier_search_string[20];

if (splash_added_true == NULL && splash_added_false == NULL)
{
fenetre_ajouter_ouvrier = lookup_widget(button, "window_ouvrier_ajouter");
ajout_nom_ouvrier_entry = lookup_widget(fenetre_ajouter_ouvrier, "ouvrier_ajouter_entry_nom");
strcpy(ouv.nom, gtk_entry_get_text(GTK_ENTRY(ajout_nom_ouvrier_entry)));


ajout_prenom_ouvrier_entry = lookup_widget(fenetre_ajouter_ouvrier, "ouvrier_ajouter_entry_prenom");
strcpy(ouv.prenom, gtk_entry_get_text(GTK_ENTRY(ajout_prenom_ouvrier_entry)));



ajout_sexef_ouvrier_entry=lookup_widget(fenetre_ajouter_ouvrier, "ouvrier_ajouter_radiobutton_femme");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(ajout_sexef_ouvrier_entry))==TRUE)
{
   strcpy(ouv.sexe, "Femme");
}
ajout_sexeh_ouvrier_entry=lookup_widget(fenetre_ajouter_ouvrier, "ouvrier_ajouter_radiobutton_homme");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(ajout_sexeh_ouvrier_entry))==TRUE)
{
   strcpy(ouv.sexe, "Homme");
}

ajout_tel_ouvrier_entry = lookup_widget(fenetre_ajouter_ouvrier, "ouvrier_ajouter_entry_tel");
strcpy(ouv.tel, gtk_entry_get_text(GTK_ENTRY(ajout_tel_ouvrier_entry)));

ajout_jour_ouvrier_entry = lookup_widget(fenetre_ajouter_ouvrier, "ouvrier_ajouter_spinbutton_jour");
ajout_mois_ouvrier_entry = lookup_widget(fenetre_ajouter_ouvrier, "ouvrier_ajouter_combobox_mois");

ajout_annee_ouvrier_entry = lookup_widget(fenetre_ajouter_ouvrier, "ouvrier_ajouter_spinbutton_annee");


ouv.date.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ajout_jour_ouvrier_entry));
strcpy(ouv.date.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(ajout_mois_ouvrier_entry)));
ouv.date.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ajout_annee_ouvrier_entry));



ajout_fonction_ouvrier_entry= lookup_widget(fenetre_ajouter_ouvrier, "ouvrier_ajouter_checkbutton_ouvrier_agricole");
if (gtk_toggle_button_get_active(ajout_fonction_ouvrier_entry))
 {
       strcpy(ouv.fonction, "ouvrier agricole");
   }
else 
{
	 strcpy(ouv.fonction, "securite");
}
 
ajout_adr_ouvrier_entry = lookup_widget(fenetre_ajouter_ouvrier, "ouvrier_ajouter_entry_adresse");
strcpy(ouv.adresse, gtk_entry_get_text(GTK_ENTRY(ajout_adr_ouvrier_entry)));

if((strcmp(ouv.nom,"")==0)||(strcmp(ouv.prenom,"")==0)||(strcmp(ouv.sexe,"")==0)||( strcmp(ouv.tel,"")==0) ||(strcmp(ouv.adresse,"")==0) ||(strcmp(ouv.fonction,"")==0)||(strlen(ouv.tel)!=8))
{
splash_added_false = create_splash_added_false (); 
    gtk_widget_show (splash_added_false);  
    g_timeout_add_seconds(3, delay_destroy_added_false, NULL); 
}
else
   {
    splash_added_true = create_splash_added_true ();
    gtk_widget_show (splash_added_true); 
    ajouter_ouvrier(ouv);

    g_timeout_add_seconds(2, delay_destroy_added_true, NULL);
    gtk_widget_destroy(fenetre_ajouter_ouvrier); 
    window_ouvrier_ajouter = NULL;


    ouvrier_search_entry = lookup_widget(window_employer, "employer_ouvriers_entry_recherche");
    strcpy(ouvrier_search_string,gtk_entry_get_text(GTK_ENTRY(ouvrier_search_entry)));

    ouvrier_treeview = lookup_widget(window_employer, "employer_ouvriers_treeview");
    afficher_ouvrier(ouvrier_treeview,ouvrier_search_string);
  }

 }
}


gboolean
on_window_ouvrier_supprimer_delete_event
                                        (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
  window_ouvrier_supprimer=NULL;
  return FALSE;
}


void
on_ouvrier_supprimer_button_modifier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * ouvrier_treeview;
  GtkWidget * ouv_search_entry;
  char ouv_search_string[20];

 	GtkWidget *ouvrier_modif_id_out;
	GtkWidget *ouvrier_modif_nom;
	GtkWidget *ouvrier_modif_prenom;
	GtkWidget *ouvrier_modif_sexef;
	GtkWidget *ouvrier_modif_sexeh;
	GtkWidget *ouvrier_modif_tel;
	GtkWidget *ouvrier_modif_jour;
	GtkWidget *ouvrier_modif_mois;
	GtkWidget *ouvrier_modif_annee;
	GtkWidget *ouvrier_modif_adresse;
	GtkWidget *ouvrier_modif_ouvrier_agricole;
	GtkWidget *ouvrier_modif_securite;
  ouvrier md_ouv;
  gchar * id_ouv;
  char ouv_id_str[20];
  char * ptre;
	ouvrier_modif_id_out = lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_label_id_out"); 
     	 ouvrier_modif_nom = lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_entry_nom");
   	 ouvrier_modif_prenom = lookup_widget(window_ouvrier_supprimer, "entry6");
   	 ouvrier_modif_sexef=lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_radiobutton_femme");
   	 ouvrier_modif_sexeh=lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_radiobutton_homme");
	  ouvrier_modif_tel = lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_entry_tel");
	ouvrier_modif_jour = lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_spinbutton_jour");
 	 ouvrier_modif_mois = lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_comboboxentry_mois");
 	 ouvrier_modif_annee = lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_spinbutton_annee");
  	  
    	ouvrier_modif_ouvrier_agricole= lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_checkbutton_ouvrier_agricole");
   	 ouvrier_modif_securite = lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_checkbutton_securite");
ouvrier_modif_adresse= lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_entry_adresse");

  id_ouv = gtk_label_get_text(ouvrier_modif_id_out);
  strcpy(ouv_id_str, id_ouv);
 md_ouv.id = strtoul(ouv_id_str, &ptre, 10);

  strcpy(md_ouv.nom, gtk_entry_get_text(GTK_ENTRY(ouvrier_modif_nom)));
	  strcpy(md_ouv.prenom, gtk_entry_get_text(GTK_ENTRY(ouvrier_modif_prenom)));  
  strcpy(md_ouv.sexe,"");
  if (gtk_toggle_button_get_active(ouvrier_modif_sexef))
   {
       strcat(md_ouv.sexe,"Femme ");  
   }
  else{  strcat(md_ouv.sexe,"Homme "); 
   }
	     strcpy(md_ouv.tel, gtk_entry_get_text(GTK_ENTRY(ouvrier_modif_tel))); 	
      md_ouv.date.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ouvrier_modif_jour)); 
	strcpy(md_ouv.date.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(ouvrier_modif_mois)));
  
  md_ouv.date.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ouvrier_modif_annee)); 

 if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(ouvrier_modif_ouvrier_agricole)))
	 strcpy(md_ouv.fonction, "Ouvrier agricole");
  else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(ouvrier_modif_securite))) 
	strcpy(md_ouv.fonction, "Securite");
  
	else strcpy(md_ouv.fonction, "ERROR");
 
     strcpy(md_ouv.adresse, gtk_entry_get_text(GTK_ENTRY(ouvrier_modif_adresse))); 
  
      if((strcmp(md_ouv.nom,"")==0)||(strcmp(md_ouv.prenom,"")==0)||(strcmp(md_ouv.sexe,"")==0)||( strcmp(md_ouv.tel,"")==0) ||(strcmp(md_ouv.adresse,"")==0) ||(strcmp(md_ouv.fonction,"")==0)||(strlen(md_ouv.tel)!=8))
   {
    splash_added_false = create_splash_added_false (); 
    gtk_widget_show (splash_added_false); 
    g_timeout_add_seconds(3, delay_destroy_added_false, NULL); 
   }
   else
   {
    splash_edited_true = create_splash_edited_true ();
    gtk_widget_show (splash_edited_true); 
    modifier_ouvrier(md_ouv); 
    g_timeout_add_seconds(2, delay_destroy_edited_true, NULL); 
    gtk_widget_destroy(window_ouvrier_supprimer); 
    window_ouvrier_supprimer = NULL;

    ouv_search_entry = lookup_widget(window_employer, "employer_ouvriers_entry_recherche");
    strcpy(ouv_search_string,gtk_entry_get_text(GTK_ENTRY(ouv_search_entry)));

    ouvrier_treeview = lookup_widget(window_employer, "employer_ouvriers_treeview");
    afficher_ouvrier(ouvrier_treeview,ouv_search_string); 

   }
}


void
on_ouvrier_supprimer_button_supprimer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *ouvrier_supp_id_out;
  GtkWidget * ouv_search_entry;
  GtkWidget * ouvrier_treeview;
  ouvrier tmp_ouv;
  gchar * id_ouv;
  char * ptre;
  char ouv_id_str[20];
  char ouv_search_string[20];
  unsigned int ouv_id_ul;
  int check_deleted_ouv;

  ouvrier_supp_id_out = lookup_widget(window_ouvrier_supprimer, "ouvrier_supprimer_label_id_out");
  id_ouv = gtk_label_get_text( ouvrier_supp_id_out);
  strcpy(ouv_id_str, id_ouv);
  tmp_ouv.id = strtoul(ouv_id_str, &ptre, 10);
  check_deleted_ouv = supprimer_ouvrier(tmp_ouv);
  gtk_widget_destroy(window_ouvrier_supprimer);
  window_ouvrier_supprimer= NULL;

  if (check_deleted_ouv == 1)
  {
    splash_deleted_true = create_splash_deleted_true ();
    gtk_widget_show (splash_deleted_true);
    g_timeout_add_seconds(2, delay_destroy_deleted_true, NULL);
  }
  else
  {
    splash_deleted_false = create_splash_deleted_false();
    gtk_widget_show (splash_deleted_false);
    g_timeout_add_seconds(3, delay_destroy_deleted_false, NULL);
  }

  ouv_search_entry = lookup_widget(window_employer, "employer_ouvriers_entry_recherche");
  strcpy(ouv_search_string,gtk_entry_get_text(GTK_ENTRY(ouv_search_entry)));

   ouvrier_treeview = lookup_widget(window_employer, "employer_ouvriers_treeview");
    afficher_ouvrier(ouvrier_treeview,ouv_search_string); 
}


gboolean
on_window_capteur_ajouter_delete_event (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
    window_capteur_ajouter = NULL;
  return FALSE;
}


void
on_capteur_ajouter_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id_capteur_entry;
GtkWidget *precesion_capteur_entry;
GtkWidget *jour_capteur_entry;
GtkWidget *mois_capteur_entry;
GtkWidget *annee_capteur_entry;
GtkWidget *temperature_capteur_entry;
GtkWidget *humidite_capteur_entry;
GtkWidget *simens_capteur_entry;
GtkWidget *schneider_capteur_entry;
capteur cap;

  GtkWidget *capteur_treeview;
  GtkWidget *capteur_search_entry;
  char capteur_search_string[20];



precesion_capteur_entry = lookup_widget(window_capteur_ajouter, "capteur_ajouter_entry_nom");// ajout précision
strcpy(cap.precision, gtk_entry_get_text(GTK_ENTRY(precesion_capteur_entry)));


simens_capteur_entry = lookup_widget(window_capteur_ajouter, "capteur_ajouter_radiobutton_simens");
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(simens_capteur_entry))==TRUE)
strcpy(cap.marque, "Simens");
else strcpy(cap.marque, "Shneider");

jour_capteur_entry = lookup_widget(window_capteur_ajouter, "capteur_ajouter_spinbutton_jour");
cap.date.day=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour_capteur_entry));

mois_capteur_entry = lookup_widget(window_capteur_ajouter, "capteur_ajouter_comboboxentry_mois");
//
strcpy(cap.date.month,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois_capteur_entry)));
annee_capteur_entry = lookup_widget(window_capteur_ajouter, "capteur_ajouter_spinbutton_annee");
cap.date.year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee_capteur_entry));

temperature_capteur_entry= lookup_widget(window_capteur_ajouter, "capteur_ajouter_checkbutton_temperature");
strcpy(cap.type, "");
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(temperature_capteur_entry)))
   {
       strcat(cap.type,"Temperature");
   }
 humidite_capteur_entry= lookup_widget(window_capteur_ajouter, "capteur_ajouter_checkbutton_humidite");
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(humidite_capteur_entry)))
   {
       strcat(cap.type, "Humidite");}


ajou_capt( cap);

gtk_widget_destroy(window_capteur_ajouter);
window_capteur_ajouter = NULL;


    capteur_search_entry = lookup_widget(window_employer, "employer_capteurs_entry_recherche");
    strcpy(capteur_search_string,gtk_entry_get_text(GTK_ENTRY(capteur_search_entry)));

    capteur_treeview = lookup_widget(window_employer, "employer_capteurs_treeview");
    afficher_capteur(capteur_treeview,capteur_search_string);

}


gboolean
on_window_capteur_modifier_supprimer_delete_event
                                        (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
  window_capteur_modifier_supprimer = NULL;
  return FALSE;
}


void
on_capteur_m_s_button_suprimer_clicked (GtkButton       *button,
                                        gpointer         user_data)
{


 GtkWidget *capteur_m_s_id_out;

  GtkWidget * capteur_search_entry;
  GtkWidget * capteur_treeview;

  gchar * id;
  char * ptr;
  char id_str[20];
  char capteur_search_string[20];
  unsigned int id_ul;
  capteur tmp_cap;
  int check_deleted_capteur;

  capteur_m_s_id_out = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_label_id_out");
  id = gtk_label_get_text(capteur_m_s_id_out);

  strcpy(id_str, id);
  tmp_cap.ID = strtoul(id_str, &ptr, 10);
  
  check_deleted_capteur = supprimer_capteur(tmp_cap);

  gtk_widget_destroy(window_capteur_modifier_supprimer);
  window_capteur_modifier_supprimer = NULL;
  if (check_deleted_capteur == 1)
  {
    splash_deleted_true = create_splash_deleted_true ();
    gtk_widget_show (splash_deleted_true);
    g_timeout_add_seconds(2, delay_destroy_deleted_true, NULL);
  }
  else
  {
    splash_deleted_false = create_splash_deleted_false();
    gtk_widget_show (splash_deleted_false);
    g_timeout_add_seconds(3, delay_destroy_deleted_false, NULL);
  }

  
  
  capteur_search_entry = lookup_widget(window_employer, "employer_capteurs_entry_recherche");
  strcpy(capteur_search_string,gtk_entry_get_text(GTK_ENTRY(capteur_search_entry)));


  capteur_treeview = lookup_widget(window_employer, "employer_clients_treeview");
  afficher_capteur(capteur_treeview,capteur_search_string);


}


void
on_capteur_m_s_button_modifier_clicked (GtkButton       *button,
                                        gpointer         user_data)
{


  GtkWidget *capteur_m_s_id_out;
  GtkWidget *capteur_m_s_precision;
  GtkWidget *capteur_m_s_schneider;
  GtkWidget *capteur_m_s_simens;
  GtkWidget *capteur_m_s_temperature;
  GtkWidget *capteur_m_s_humidite;
  GtkWidget *capteur_m_s_jour;
  GtkWidget *capteur_m_s_mois;
  GtkWidget *capteur_m_s_annee;
  GtkWidget *capteur_treeview;
  GtkWidget *capteur_search_entry;
  char capteur_search_string[20];
  
  capteur tmp_cap;
  gchar * id;
  char id_str[20];
  char * ptr;


 capteur_m_s_id_out = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_label_id_out");
    capteur_m_s_precision = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_entry_nom");//precision
    capteur_m_s_simens = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_radiobutton_simens");
    capteur_m_s_schneider = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_radiobutton_schneider");
    capteur_m_s_jour = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_spinbutton_jour");
    capteur_m_s_mois = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_comboboxentry_mois");
    capteur_m_s_annee = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_spinbutton_annee");
     capteur_m_s_temperature = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_checkbutton_temperature");
    capteur_m_s_humidite = lookup_widget(window_capteur_modifier_supprimer, "capteur_m_s_checkbutton_humidite");

    id = gtk_label_get_text(capteur_m_s_id_out);
  strcpy(id_str, id);
  tmp_cap.ID = strtoul(id_str, &ptr, 10);


  strcpy(tmp_cap.precision, gtk_entry_get_text(GTK_ENTRY(capteur_m_s_precision))); 
 
  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(capteur_m_s_simens))) strcpy(tmp_cap.marque, "Simens");
else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(capteur_m_s_schneider))) strcpy(tmp_cap.marque, "Schneider");
else strcpy(tmp_cap.marque, "ERROR");

  tmp_cap.date.day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capteur_m_s_jour)); 
  strcpy(tmp_cap.date.month, gtk_combo_box_get_active_text(GTK_COMBO_BOX(capteur_m_s_mois))); 
  tmp_cap.date.year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capteur_m_s_annee)); 

  strcpy(tmp_cap.type, "");



if (gtk_toggle_button_get_active(capteur_m_s_temperature)) 
   {
       strcat(tmp_cap.marque,"Temperature "); 
   }
  if (gtk_toggle_button_get_active(capteur_m_s_humidite))
   {
       strcat(tmp_cap.marque,"Humidite "); 
   }
 

   if (empty_invalid_entry_capteur(tmp_cap) == 0) // verifie si il y a des erreur d'entree
   {
    splash_edited_false = create_splash_edited_false (); 
    gtk_widget_show (splash_edited_false); 
    g_timeout_add_seconds(3, delay_destroy_edited_false, NULL); 
   }
   else
   {
    splash_edited_true = create_splash_edited_true ();
    gtk_widget_show (splash_edited_true); // afficher la fenetre ajouter avec succée
    modifier_capteur(tmp_cap); // ajout du client dans le fichier clients.txt
    g_timeout_add_seconds(2, delay_destroy_edited_true, NULL); // fermer la fenetre cree avec succes apres 2 secondes
    gtk_widget_destroy(window_capteur_modifier_supprimer); // fermer la fenetre ajout client
    window_capteur_modifier_supprimer = NULL; // declarer que la fenetre modif client est fermer
 


    capteur_search_entry = lookup_widget(window_employer, "employer_capteurs_entry_recherche");
    strcpy(capteur_search_string,gtk_entry_get_text(GTK_ENTRY(capteur_search_entry)));


    capteur_treeview = lookup_widget(window_employer, "employer_capteurs_treeview");
    afficher_capteur(capteur_treeview,capteur_search_string); 

   }

}


gboolean
on_window_equipement_ajouter_delete_event
                                        (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
  window_equipement_ajouter = NULL;
  return FALSE;
}


void
on_equipement_ajouter_button_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *equipement_ajout_nom;
  GtkWidget *equipement_ajout_machine;
  GtkWidget *equipement_ajout_instrument;
  GtkWidget *equipement_ajout_mauvais;
  GtkWidget *equipement_ajout_bon;
  GtkWidget *equipement_ajout_excellent;
  GtkWidget *equipement_ajout_jour;
  GtkWidget *equipement_ajout_mois;
  GtkWidget *equipement_ajout_annee;
  GtkWidget *equipement_ajout_jour2;
  GtkWidget *equipement_ajout_mois2;
  GtkWidget *equipement_ajout_annee2;

  GtkWidget *equip_agri_treeview;
  GtkWidget *equip_agri_search_entry;
  char equip_agri_search_string[20];

  equipement tmp_equi;

if (splash_added_true == NULL && splash_added_false == NULL)
{

//nom
  equipement_ajout_nom = lookup_widget(window_equipement_ajouter, "equipement_ajouter_entry_nom");
//type
  equipement_ajout_machine = lookup_widget(window_equipement_ajouter, "equipement_ajouter_checkbutton_machine");
  equipement_ajout_instrument = lookup_widget(window_equipement_ajouter, "equipement_ajouter_checkbutton_instrument");
//etat
  equipement_ajout_excellent = lookup_widget(window_equipement_ajouter, "equipement_ajouter_radiobutton_excellent");
  equipement_ajout_bon = lookup_widget(window_equipement_ajouter, "equipement_ajouter_radiobutton_bon");
  equipement_ajout_mauvais = lookup_widget(window_equipement_ajouter, "equipement_ajouter_radiobutton_mauvais");
//date ajout
  equipement_ajout_jour = lookup_widget(window_equipement_ajouter, "equipement_ajouter_ajout_spinbutton_jour");
  equipement_ajout_mois = lookup_widget(window_equipement_ajouter, "equipement_ajouter_ajout_comboboxentry_mois");
  equipement_ajout_annee = lookup_widget(window_equipement_ajouter, "equipement_ajouter_ajout_spinbutton_annee");
//date main
  equipement_ajout_jour2 = lookup_widget(window_equipement_ajouter, "equipement_ajouter_main_spinbutton_jour");
  equipement_ajout_mois2 = lookup_widget(window_equipement_ajouter, "equipement_ajouter_main_comboboxentry_mois");
  equipement_ajout_annee2 = lookup_widget(window_equipement_ajouter, "equipement_ajouter_main_spinbutton_annee");

//saisie du nom
  strcpy(tmp_equi.nom, gtk_entry_get_text(GTK_ENTRY(equipement_ajout_nom))); // lecture depuis entry de l'interface glade vers la structure equipement 

//saisie de type
  strcpy(tmp_equi.type, "");
  if (gtk_toggle_button_get_active(equipement_ajout_machine)) // verifie si checkbox machine est selectionner
   {
       strcat(tmp_equi.type,"Machine "); // ajout (pas remplacement ) du mot machine dans la structure equipement
   }
  if (gtk_toggle_button_get_active(equipement_ajout_instrument))
   {
       strcat(tmp_equi.type,"Instrument "); // ajout du mot Instrument dans la structure equipement
   }

//saisie de etat
  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(equipement_ajout_excellent))) strcpy(tmp_equi.etat, "Excellent"); // verifie si le botton radio excellent est selectionner si oui exrire excellent dans etat
  else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(equipement_ajout_bon))) strcpy(tmp_equi.etat, "Bon");
  else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(equipement_ajout_mauvais))) strcpy(tmp_equi.etat, "Mauvais");
	else strcpy(tmp_equi.etat, "ERROR");

//saisie de date ajout
  tmp_equi.date_ajout.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(equipement_ajout_jour)); // lecture de la valeur de button spin et l'enregister dans structure equipement
  strcpy(tmp_equi.date_ajout.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(equipement_ajout_mois))); // lecture du choix du combo box et l'enregister 
  tmp_equi.date_ajout.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(equipement_ajout_annee)); // lecture de la valeur de button spin et l'enregister

//saisie date main
  tmp_equi.date_dernier_maintenance.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(equipement_ajout_jour2)); 
  strcpy(tmp_equi.date_dernier_maintenance.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(equipement_ajout_mois2)));  
  tmp_equi.date_dernier_maintenance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(equipement_ajout_annee2)); 

      if  ( empty_invalid_entry_equipement(tmp_equi) == 0) // verifie si il y a des erreur d'entree
   {
    splash_added_false = create_splash_added_false (); // affichage du fenetre erreur
    gtk_widget_show (splash_added_false); // affichage du fenetre erreur
    g_timeout_add_seconds(3, delay_destroy_added_false, NULL); // fermer la fenetre erreur aprés un retard de 3 secondes
   }
   else
   {
    splash_added_true = create_splash_added_true ();
    gtk_widget_show (splash_added_true); // afficher la fenetre ajouter avec succée
    ajouter_equipement(tmp_equi); // ajout du equipement dans le fichier equipement.txt
    g_timeout_add_seconds(2, delay_destroy_added_true, NULL); // fermer la fenetre cree avec succes apres 2 secondes
    gtk_widget_destroy(window_equipement_ajouter); // fermer la fenetre ajout equipement
    window_equipement_ajouter = NULL; // declarer que la fenetre ajout equipement est fermer


    equip_agri_search_entry = lookup_widget(window_employer, "employer_equip_agri_entry_recherche");
    strcpy(equip_agri_search_string,gtk_entry_get_text(GTK_ENTRY(equip_agri_search_entry)));

//search string not very clear !!
    equip_agri_treeview = lookup_widget(window_employer, "employer_equip_agri_treeview");
    afficher_equipement(equip_agri_treeview,equip_agri_search_string); 

   }
}

}


gboolean
on_window_equipement_mod_sup_delete_event
                                        (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
  window_equipement_mod_sup = NULL;
  return FALSE;
}


void
on_equipement_mod_button_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * equip_agri_treeview;
  GtkWidget * equip_agri_search_entry;
  char equipement_search_string[20];

  GtkWidget *equipement_ms_nom;
  GtkWidget *equipement_ms_machine;
  GtkWidget *equipement_ms_instrument;
  GtkWidget *equipement_ms_mauvais;
  GtkWidget *equipement_ms_bon;
  GtkWidget *equipement_ms_excellent;
  GtkWidget *equipement_ms_jour;
  GtkWidget *equipement_ms_mois;
  GtkWidget *equipement_ms_annee;
  GtkWidget *equipement_ms_jour2;
  GtkWidget *equipement_ms_mois2;
  GtkWidget *equipement_ms_annee2;
  GtkWidget *equipement_ms_id_out;

  equipement tmp_equi;
  gchar * id_equi;
  char equi_id_str[20];
  char * ptre;

   		equipement_ms_id_out = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_id_out"); 
      equipement_ms_nom = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_entry_nom");
    equipement_ms_machine = lookup_widget(window_equipement_mod_sup, "equipemeny_mod_sup_checkbutton_machine");
    equipement_ms_instrument = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_checkbutton_instrument");

    equipement_ms_excellent = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_radiobutton_excellent");
    equipement_ms_bon = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_radiobutton_bon");
    equipement_ms_mauvais = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_radiobutton_mauvais");

    equipement_ms_jour = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_ajout_spinbutton_jour");
    equipement_ms_mois = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_ajout_comboboxentry_mois");
    equipement_ms_annee = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_ajout_spinbutton_annee");

    equipement_ms_jour2 = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_main_spinbutton_jour");
    equipement_ms_mois2 = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_main_comboboxentry_mois");
    equipement_ms_annee2 = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_main_spinbutton_annee");

  id_equi = gtk_label_get_text(equipement_ms_id_out);
  strcpy(equi_id_str, id_equi);
  tmp_equi.id = strtoul(equi_id_str, &ptre, 10);

  strcpy(tmp_equi.nom, gtk_entry_get_text(GTK_ENTRY(equipement_ms_nom))); 
  strcpy(tmp_equi.type, "");
  if (gtk_toggle_button_get_active(equipement_ms_machine))
   {
       strcat(tmp_equi.type,"Machine ");  
   }
  if (gtk_toggle_button_get_active(equipement_ms_instrument))
   {
       strcat(tmp_equi.type,"Instrument ");
   }

  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(equipement_ms_excellent))) strcpy(tmp_equi.etat, "Excellent");
  else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(equipement_ms_bon))) strcpy(tmp_equi.etat, "Bon");
  else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(equipement_ms_mauvais))) strcpy(tmp_equi.etat, "Mauvais");
	else strcpy(tmp_equi.etat, "ERROR");

  tmp_equi.date_ajout.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(equipement_ms_jour)); 
  strcpy(tmp_equi.date_ajout.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(equipement_ms_mois)));
  tmp_equi.date_ajout.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(equipement_ms_annee)); 


  tmp_equi.date_dernier_maintenance.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(equipement_ms_jour2)); 
  strcpy(tmp_equi.date_dernier_maintenance.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(equipement_ms_mois2)));  
  tmp_equi.date_dernier_maintenance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(equipement_ms_annee2)); 

      if  ( empty_invalid_entry_equipement(tmp_equi) == 0)
   {
    splash_added_false = create_splash_added_false (); 
    gtk_widget_show (splash_added_false); 
    g_timeout_add_seconds(3, delay_destroy_added_false, NULL); 
   }
   else
   {
    splash_edited_true = create_splash_edited_true ();
    gtk_widget_show (splash_edited_true); 
    modifier_equipement(tmp_equi); 
    g_timeout_add_seconds(2, delay_destroy_edited_true, NULL); 
    gtk_widget_destroy(window_equipement_mod_sup); 
    window_equipement_mod_sup = NULL;

    equip_agri_search_entry = lookup_widget(window_employer, "employer_equip_agri_entry_recherche");
    strcpy(equipement_search_string,gtk_entry_get_text(GTK_ENTRY(equip_agri_search_entry)));

    equip_agri_treeview = lookup_widget(window_employer, "employer_equip_agri_treeview");
    afficher_equipement(equip_agri_treeview,equipement_search_string); 

   }


}


void
on_equipement_sup_button_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *equipement_ms_id_out;

  GtkWidget * equip_agri_search_entry;
  GtkWidget * equip_agri_treeview;

  gchar * id_equi;
  char * ptre;
  char equi_id_str[20];
  char equi_search_string[20];
  unsigned int equi_id_ul;
  equipement tmp_equi;
  int check_deleted_equipement;

  equipement_ms_id_out = lookup_widget(window_equipement_mod_sup, "equipement_mod_sup_id_out");
  id_equi = gtk_label_get_text(equipement_ms_id_out);
  strcpy(equi_id_str, id_equi);
  tmp_equi.id = strtoul(equi_id_str, &ptre, 10);
  check_deleted_equipement = supprimer_equipement(tmp_equi);
  gtk_widget_destroy(window_equipement_mod_sup);
  window_equipement_mod_sup = NULL;

  if (check_deleted_equipement == 1)
  {
    splash_deleted_true = create_splash_deleted_true ();
    gtk_widget_show (splash_deleted_true);
    g_timeout_add_seconds(2, delay_destroy_deleted_true, NULL);
  }
  else
  {
    splash_deleted_false = create_splash_deleted_false();
    gtk_widget_show (splash_deleted_false);
    g_timeout_add_seconds(3, delay_destroy_deleted_false, NULL);
  }

  equip_agri_search_entry = lookup_widget(window_employer, "employer_equip_agri_entry_recherche");
  strcpy(equi_search_string,gtk_entry_get_text(GTK_ENTRY(equip_agri_search_entry)));

	equip_agri_treeview = lookup_widget(window_employer, "employer_equip_agri_treeview");
    afficher_equipement(equip_agri_treeview,equi_search_string); 

}


gboolean
on_window_troup_ajouter_delete_event   (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
  window_troup_ajouter = NULL;
  return FALSE;
}


void
on_troup_button_ajouter_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *troup_ajouter_nom;
  GtkWidget *troup_ajouter_type;
  GtkWidget *troup_ajouter_sante;
  GtkWidget *troup_ajouter_ble;
  GtkWidget *troup_ajouter_haricot;
  GtkWidget *troup_ajouter_eau;
  GtkWidget *troup_ajouter_herbe;
  GtkWidget *troup_ajouter_masculin;
  GtkWidget *troup_ajouter_feminin;
  GtkWidget *troup_ajouter_jour;
  GtkWidget *troup_ajouter_mois;
  GtkWidget *troup_ajouter_annee;
  


  GtkWidget *troup_treeview;
  GtkWidget *troup_search_entry;
  char troup_search_string[20];


  troup tmp_trou;
  
if (splash_added_true == NULL && splash_added_false == NULL)
{




  troup_ajouter_nom = lookup_widget(window_troup_ajouter, "troup_ajouter_entry_nom");
  troup_ajouter_type = lookup_widget(window_troup_ajouter, "troup_ajouter_comboboxentry_type");
  troup_ajouter_sante = lookup_widget(window_troup_ajouter, "troup_ajouter_combobox_sante");
  troup_ajouter_ble = lookup_widget(window_troup_ajouter, "troup_ajouter_checkbutton_ble");
  troup_ajouter_haricot = lookup_widget(window_troup_ajouter, "troup_ajouter_checkbutton_haricot");
  troup_ajouter_eau = lookup_widget(window_troup_ajouter, "troup_ajouter_checkbutton_eau");
  troup_ajouter_herbe = lookup_widget(window_troup_ajouter, "troup_ajouter_checkbutton_herbe");
  troup_ajouter_masculin = lookup_widget(window_troup_ajouter, "troup_ajouter_radiobutton_masculin");
  troup_ajouter_feminin = lookup_widget(window_troup_ajouter, "troup_ajouter_radiobutton_feminin");
  troup_ajouter_jour = lookup_widget(window_troup_ajouter, "troup_ajouter_spinbutton_jour");
  troup_ajouter_mois = lookup_widget(window_troup_ajouter, "troup_ajouter_comboboxentry_mois");
  troup_ajouter_annee = lookup_widget(window_troup_ajouter, "troup_ajouter_spinbutton_annee");
  
  
  strcpy(tmp_trou.nom, gtk_entry_get_text(GTK_ENTRY(troup_ajouter_nom))); 

  strcpy(tmp_trou.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(troup_ajouter_type)));

  strcpy(tmp_trou.sante, gtk_combo_box_get_active_text(GTK_COMBO_BOX(troup_ajouter_sante)));

  strcpy(tmp_trou.nourriture, "");
  if (gtk_toggle_button_get_active(troup_ajouter_ble)) 
   {
       strcat(tmp_trou.nourriture,"son de blé "); 
   }
  if (gtk_toggle_button_get_active(troup_ajouter_haricot))
   {
       strcat(tmp_trou.nourriture,"haricot");
   }
  if (gtk_toggle_button_get_active(troup_ajouter_eau))
   {
       strcat(tmp_trou.nourriture,"eau"); 
   }
    if (gtk_toggle_button_get_active(troup_ajouter_herbe))
   {
       strcat(tmp_trou.nourriture,"herbe"); 
   }

  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(troup_ajouter_masculin))) strcpy(tmp_trou.sexe, "Masculin"); 
  else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(troup_ajouter_feminin))) strcpy(tmp_trou.sexe, "Féminin");



  tmp_trou.naissance.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(troup_ajouter_jour));
  strcpy(tmp_trou.naissance.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(troup_ajouter_mois))); 
  tmp_trou.naissance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(troup_ajouter_annee));
  
  

    splash_added_true = create_splash_added_true ();
    gtk_widget_show (splash_added_true);
    ajouter_troup(tmp_trou);
    g_timeout_add_seconds(2, delay_destroy_added_true, NULL);
    gtk_widget_destroy(window_troup_ajouter); 
    window_troup_ajouter = NULL; 
    


    troup_search_entry = lookup_widget(window_employer, "employer_troup_entry_recherche");
    strcpy(troup_search_string,gtk_entry_get_text(GTK_ENTRY(troup_search_entry)));


    troup_treeview = lookup_widget(window_employer, "employer_troup_treeview");
    afficher_troup(troup_treeview,troup_search_string); 

   }
}


gboolean
on_window_troup_modifier_delete_event  (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
  window_troup_modifier = NULL;
  return FALSE;
}


void
on_troup_button_modifier_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * troup_treeview;
    GtkWidget * troup_search_entry;
    char troup_search_string[20];

    GtkWidget *troup_modifier_nom;
    GtkWidget *troup_modifier_type;
    GtkWidget *troup_modifier_sante;
    GtkWidget *troup_modifier_ble;
    GtkWidget *troup_modifier_haricot;
    GtkWidget *troup_modifier_eau;
    GtkWidget *troup_modifier_herbe;
    GtkWidget *troup_modifier_masculin;
    GtkWidget *troup_modifier_feminin;
    GtkWidget *troup_modifier_jour;
    GtkWidget *troup_modifier_mois;
    GtkWidget *troup_modifier_annee;
    GtkWidget *troup_modifier_id_out;
    
    
    troup tmp_trou;
    gchar * id;
    char id_str[20];
    char * ptr;


  
if (splash_edited_true == NULL && splash_edited_false == NULL)
{





  troup_modifier_id_out = lookup_widget(window_troup_modifier, "troup_modifier_id_out");
  troup_modifier_nom = lookup_widget(window_troup_modifier, "troup_modifier_entry_nom");
  
  troup_modifier_type = lookup_widget(window_troup_modifier, "troup_modifier_comboboxentry_type");
  
  troup_modifier_sante = lookup_widget(window_troup_modifier, "comboboxentry1");

  troup_modifier_ble = lookup_widget(window_troup_modifier, "troup_modifier_checkbutton_ble");
  troup_modifier_haricot = lookup_widget(window_troup_modifier, "troup_modifier_checkbutton_haricot");
  troup_modifier_eau = lookup_widget(window_troup_modifier, "troup_modifier_checkbutton_eau");
  troup_modifier_herbe = lookup_widget(window_troup_modifier, "troup_modifier_checkbutton_herbe");
 
  troup_modifier_masculin = lookup_widget(window_troup_modifier, "troup_modifier_radiobutton_masculin");
  troup_modifier_feminin = lookup_widget(window_troup_modifier, "troup_modifier_radiobutton_feminin");

  troup_modifier_jour = lookup_widget(window_troup_modifier, "troup_modifier_spinbutton_jour");
  troup_modifier_mois = lookup_widget(window_troup_modifier, "troup_modifier_comboboxentry_mois");
  troup_modifier_annee = lookup_widget(window_troup_modifier, "troup_modifier_spinbutton_annee");
  
  id = gtk_label_get_text(troup_modifier_id_out);
  
  strcpy(id_str, id);
 
  tmp_trou.id = strtoul(id_str, &ptr, 10);

  strcpy(tmp_trou.nom, gtk_entry_get_text(GTK_ENTRY(troup_modifier_nom))); // lecture depuis entry de l'interface glade vers la structure client 

  strcpy(tmp_trou.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(troup_modifier_type)));

  strcpy(tmp_trou.sante, gtk_combo_box_get_active_text(GTK_COMBO_BOX(troup_modifier_sante)));

  strcpy(tmp_trou.nourriture, "");
  if (gtk_toggle_button_get_active(troup_modifier_ble)) // verifie si checkbox especes est selectionner
   {
       strcat(tmp_trou.nourriture,"son de blé "); 
   }
  if (gtk_toggle_button_get_active(troup_modifier_haricot))
   {
       strcat(tmp_trou.nourriture,"haricot"); // ajout du mot cheque dans la structure client
   }
  if (gtk_toggle_button_get_active(troup_modifier_eau))
   {
       strcat(tmp_trou.nourriture,"eau"); 
   }
    if (gtk_toggle_button_get_active(troup_modifier_herbe))
   {
       strcat(tmp_trou.nourriture,"herbe"); 
   }

  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(troup_modifier_masculin))) strcpy(tmp_trou.sexe, "Masculin"); // verifie si le botton radio homme est selectionner si oui exrire homme dans sexe
  else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(troup_modifier_feminin))) strcpy(tmp_trou.sexe, "Féminin");


  
  tmp_trou.naissance.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(troup_modifier_jour)); // lecture de la valeur de button spin et l'enregister dans structure client
   
  strcpy(tmp_trou.naissance.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(troup_modifier_mois))); // lecture du choix du combo box et l'enregister dans structure client
   
  tmp_trou.naissance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(troup_modifier_annee)); // lecture de la valeur de button spin et l'enregister dans structure client
  
  

    splash_edited_true = create_splash_edited_true ();
    gtk_widget_show (splash_edited_true); // afficher la fenetre ajouter avec succée
    modifier_troup(tmp_trou); // ajout du client dans le fichier clients.txt
    g_timeout_add_seconds(2, delay_destroy_edited_true, NULL); // fermer la fenetre cree avec succes apres 2 secondes
    gtk_widget_destroy(window_troup_modifier); // fermer la fenetre ajout client
    window_troup_modifier = NULL; // declarer que la fenetre ajout client est fermer
    


    troup_search_entry = lookup_widget(window_employer, "employer_troup_entry_recherche");
    strcpy(troup_search_string,gtk_entry_get_text(GTK_ENTRY(troup_search_entry)));

    troup_treeview = lookup_widget(window_employer, "employer_troup_treeview");
    afficher_troup(troup_treeview,troup_search_string); 
   }
 
}


void
on_troup_button_supprimer_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *troup_modifier_id_out;

  GtkWidget * troup_search_entry;
  GtkWidget * troup_treeview;

  gchar * id;
  char * ptr;
  char id_str[20];
  char troup_search_string[20];
  unsigned int id_ul;
  troup tmp_trou;
  int check_deleted_troup;
  troup_modifier_id_out = lookup_widget(window_troup_modifier, "troup_modifier_id_out");
  id = gtk_label_get_text(troup_modifier_id_out);
  strcpy(id_str, id);
  tmp_trou.id = strtoul(id_str, &ptr, 10);
  g_print("%u\n", tmp_trou.id);
  check_deleted_troup = supprimer_troup(tmp_trou);
  
  gtk_widget_destroy(window_troup_modifier);
  window_troup_modifier = NULL;
  
  if (check_deleted_troup == 1)
  {
    splash_deleted_true = create_splash_deleted_true ();
    gtk_widget_show (splash_deleted_true);
    g_timeout_add_seconds(2, delay_destroy_deleted_true, NULL);
  }
  
  else
  {
    splash_deleted_false = create_splash_deleted_false();
    gtk_widget_show (splash_deleted_false);
    g_timeout_add_seconds(3, delay_destroy_deleted_false, NULL);
  }

  troup_search_entry = lookup_widget(window_employer, "employer_troup_entry_recherche");
    strcpy(troup_search_string,gtk_entry_get_text(GTK_ENTRY(troup_search_entry)));

    troup_treeview = lookup_widget(window_employer, "employer_troup_treeview");
    afficher_troup(troup_treeview,troup_search_string); 


 
}

gboolean
on_employ_add_window_delete_event      (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_employ_add_window_button_add_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


gboolean
on_employ_modif_supp_window_delete_event
                                        (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_employ_modif_supp_window_button_modifer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_employ_modif_supp_window_button_supprimer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}



void
on_auth_login_button_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *username_entry;
    GtkWidget *password_entry;
    GtkWidget *auth_window;
    GtkWidget *label_error;
    int role;
    char username[20] = "";
    char password[20] = "";
    
    
    username_entry = lookup_widget(button, "auth_id_entry");
    password_entry = lookup_widget(button, "auth_pass_entry");
    auth_window = lookup_widget(button, "window_auth");
    
    
    strcpy(username, gtk_entry_get_text(GTK_ENTRY(username_entry)));
    strcpy(password, gtk_entry_get_text(GTK_ENTRY(password_entry)));

    role = user_type(username, password);
    
    if ((role == 1) || (role == 4))
    {
        window_employer = create_window_employer ();
        gtk_widget_show (window_employer);
    }
    if ((role == 4) || (role == 2))
    {
        admin_screen = create_admin_screen ();
        gtk_widget_show (admin_screen);
    }
    if (role == 4  || role == 2 || role == 1) gtk_widget_destroy(auth_window);
    if (role == 5)
    {
        if ((strcmp(username,"admin") != 0) && (strcmp(username,"employer") != 0))
        {
            splash_login_false = create_splash_login_false();
            gtk_widget_show (splash_login_false);
            label_error = lookup_widget(splash_login_false, "splash_login_false_label");
            gtk_label_set_markup (label_error, g_markup_printf_escaped ("<big><big><span foreground=\"red\">%s</span></big></big><big>%s</big><big>%s</big><big>%s</big>", "Pas de ficher de connexion\n","Vous pouvez Utiliser:\n", "admin:admin (Espace Admin)\n", "employer:employer (Espace Employer)\n"));
            g_timeout_add_seconds(3, delay_destroy_login_false, NULL);
        }
        else if ((strcmp(username,"admin") == 0) && (strcmp(password,"admin") == 0))
        {
            admin_screen = create_admin_screen ();
            gtk_widget_show (admin_screen); 
            
        }
        else if ((strcmp(username,"employer") == 0) && (strcmp(password,"employer") == 0))
        {
            window_employer = create_window_employer ();
            gtk_widget_show (window_employer);            
        }
        else if ((strcmp(username,"admin") == 0) || (strcmp(username,"employer") == 0))
        {
            role = 3;
        }
    }
    if (role == 3)
    {
        splash_login_false = create_splash_login_false();
        gtk_widget_show (splash_login_false);
        label_error = lookup_widget(splash_login_false, "splash_login_false_label");
        gtk_label_set_markup (label_error, g_markup_printf_escaped ("<big><big><span foreground=\"red\">%s</span></big></big>", "Mauvais mot de passe"));
        g_timeout_add_seconds(3, delay_destroy_login_false, NULL);
        
    }
    if (role == -1)
    {
        splash_login_false = create_splash_login_false();
        gtk_widget_show (splash_login_false);
        label_error = lookup_widget(splash_login_false, "splash_login_false_label");
        gtk_label_set_markup (label_error, g_markup_printf_escaped ("<big><big><span foreground=\"red\">%s</span></big></big>", "Identifiant non trouvée"));
        g_timeout_add_seconds(3, delay_destroy_login_false, NULL);
        
    }
    if (role == 0)
    {
        splash_login_false = create_splash_login_false();
        gtk_widget_show (splash_login_false);
        label_error = lookup_widget(splash_login_false, "splash_login_false_label");
        gtk_label_set_markup (label_error, g_markup_printf_escaped ("<big><big><span foreground=\"red\">%s</span></big></big>", "Accée Refusé"));
        g_timeout_add_seconds(3, delay_destroy_login_false, NULL);
        
    }

}
void
on_admin_meilleur_ouv_spin_changed     (GtkEditable     *editable,
                                        gpointer         user_data)
{
   GtkWidget *meilleur_ouvrier_out;
   GtkWidget *mei_spin;
    char m_nom[20] = "";
    char m_prenom[20] = "Aucun";
    unsigned int mei_ouv;
    int annee_search;
    
    meilleur_ouvrier_out = lookup_widget(admin_screen, "admin_scr_out_meilleur_ouvrier");
        mei_spin = lookup_widget(admin_screen, "admin_meilleur_ouv_spin");

    annee_search = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mei_spin)); 
    mei_ouv = meilleur_ouvrier(m_prenom, m_nom, annee_search);
    if (mei_ouv != 4294967295)
    { 
        gtk_label_set_markup (meilleur_ouvrier_out, g_markup_printf_escaped ("<span foreground=\"black\">(%u) %s %s</span>",mei_ouv ,m_prenom, m_nom));

    }
    else
    {
        gtk_label_set_markup (meilleur_ouvrier_out, g_markup_printf_escaped ("<span foreground=\"black\">%s %s</span>", "Aucun", ""));
    }
    
    }

