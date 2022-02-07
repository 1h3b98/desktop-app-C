#include <gtk/gtk.h>


gboolean
on_auth_seconnecter_image_button_release_event
                                        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_notebook1_switch_page               (GtkNotebook     *notebook,
                                        GtkNotebookPage *page,
                                        guint            page_num,
                                        gpointer         user_data);

gboolean
on_notebook1_select_page               (GtkNotebook     *notebook,
                                        gboolean         move_focus,
                                        gpointer         user_data);

void
on_admin_scr_ges_employ_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_admin_scr_ges_employ_search_entry_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_admin_scr_ges_employ_button_add_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_employer_notebook_switch_page       (GtkNotebook     *notebook,
                                        GtkNotebookPage *page,
                                        guint            page_num,
                                        gpointer         user_data);

void
on_employer_capteurs_entry_recherche_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_employer_capteurs_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_employer_capteurs_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_employer_capteurs_radiobutton_humi_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_employer_capteurs_radiobutton_temp_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_employer_ouvriers_entry_recherche_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_employer_ouvriers_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_employer_ouvriers_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_employer_equip_agri_entry_recherche_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_employer_equip_agri_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_employer_equip_agri_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_employer_clients_entry_recherche_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_employer_clients_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_employer_clients_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_employer_troup_entry_recherche_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_employer_troup_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_employer_troup_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_employer_button_disconnect_clicked  (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window_client_ajouter_delete_event  (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_client_ajouter_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window_client_m_s_delete_event      (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_client_m_s_button_modifier_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_client_m_s_button_supprimer_clicked (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window_ouvrier_ajouter_delete_event (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_ouvrier_ajouter_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window_ouvrier_supprimer_delete_event
                                        (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_ouvrier_supprimer_button_modifier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_ouvrier_supprimer_button_supprimer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window_capteur_ajouter_delete_event (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_capteur_ajouter_button_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window_capteur_modifier_supprimer_delete_event
                                        (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_capteur_m_s_button_suprimer_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_capteur_m_s_button_modifier_clicked (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window_equipement_ajouter_delete_event
                                        (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_equipement_ajouter_button_clicked   (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window_equipement_mod_sup_delete_event
                                        (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_equipement_mod_button_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_equipement_sup_button_clicked       (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window_troup_ajouter_delete_event   (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_troup_button_ajouter_clicked        (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window_troup_modifier_delete_event  (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_troup_button_modifier_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_troup_button_supprimer_clicked      (GtkButton       *button,
                                        gpointer         user_data);
