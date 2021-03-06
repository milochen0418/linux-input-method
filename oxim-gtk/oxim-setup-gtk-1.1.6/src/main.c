/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */
#if 0
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#endif 

#include <gtk/gtk.h>
#include <glade/glade.h>



void on_window_destroy (GtkWidget*, gpointer);
gboolean on_window_delete_event (GtkWidget*, GdkEvent*, gpointer);

void on_OkButton_clicked(GtkButton*);






enum
{ 
  BUY_IT = 0,
  QUANTITY,
  PRODUCT,
  TEST_OK,
  COLUMNS
};

typedef struct
{
  gboolean buy;
  //gint quantity;
  gchar* quantity;
  gchar* product;
  //gboolean test_ok;
  gchar* test_ok;
} GroceryItem;

const GroceryItem list[] = 
{ 
  { TRUE, "Uni蝦米","無", "  "}, 
  { FALSE, "中標注音", "無","<內建>" },
  { FALSE, "中標倉頡","無","<內建>" },
  { FALSE, "新酷音","Ctrl+Alt+7","<內建>" },
  { FALSE, "萬國碼","Ctrl+Alt+0","<內建>" },

};

guint list_size = sizeof(list)/sizeof(list[0]);

static void setup_tree_view (GtkWidget*);
static GtkTreeModel * create_model (void);
static void fixed_toggled ( GtkCellRendererToggle *cell, gchar *path_str, gpointer data);












int main (int argc, char *argv[])
{

  gtk_rc_parse("/usr/share/oxim-setup-gtk/gtkrc");
  GtkWidget *window;
  GladeXML *xml;

  GtkWidget *treeview, *scrolled_win;
  GtkListStore *store;
  //GtkTreeIter iter;
  //guint i = 0;



  gtk_init (&argc, &argv);

  xml = glade_xml_new ("/usr/share/oxim-setup-gtk/oxim-setup-glade.glade", NULL, NULL);
  window = glade_xml_get_widget (xml, "window");
  scrolled_win  = glade_xml_get_widget (xml, "scrolled_window");
  
  glade_xml_signal_autoconnect (xml);


  treeview = gtk_tree_view_new ();
  store = GTK_LIST_STORE(create_model());
  treeview = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));
  setup_tree_view(treeview);
  gtk_container_add (GTK_CONTAINER (scrolled_win), treeview);

//  gtk_container_add (GTK_CONTAINER (scrolled_win), treeview);




  gtk_widget_show_all (window);
  gtk_main ();
  
  return 0;

} //main()





/* Stop the GTK+ main loop function. */
void on_window_destroy (GtkWidget *window, gpointer data)
{
  gtk_main_quit ();
} //destory()

/* Return FALSE to destroy the widget. By returning TRUE, you can cancel
 * a delete-event. This can be used to confirm quitting the application. */
gboolean on_window_delete_event (GtkWidget *window,
              GdkEvent *event,
              gpointer data)
{
  return FALSE;
} //delete_event()



void on_OkButton_clicked(GtkButton* button) { }






/* Add three columns to the GtkTreeView. All three of the columns will be
 * displayed as text, although one is a gboolean value and another is
 * an integer. */
static void setup_tree_view (GtkWidget *treeview)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeModel *model = gtk_tree_view_get_model( GTK_TREE_VIEW(treeview)) ;



  /* Create a new GtkCellRendererText, add it to the tree view column and
   * append the column to the tree view. */
#define TOGGLE_BUTTON
#ifndef TOGGLE_BUTTON
  renderer = gtk_cell_renderer_text_new ();
  column = gtk_tree_view_column_new_with_attributes
                         ("Buy", renderer, "text", BUY_IT, NULL);
  gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

#else
  renderer = gtk_cell_renderer_toggle_new();
  g_signal_connect ( renderer, "toggled", G_CALLBACK( fixed_toggled), model);
  column = gtk_tree_view_column_new_with_attributes("輪換", renderer, "active", BUY_IT,NULL);

  //gtk_tree_view_column_set_sizing(GTK_TREE_VIEW_COLUMN(column), GTK_TREE_VIEW_COLUMN_FIXED);
  //gtk_tree_view_column_set_fixed_width( GTK_TREE_VIEW_COLUMN(column), 50);
  gtk_tree_view_append_column (GTK_TREE_VIEW(treeview), column);

#endif //TOGGLE_BUTTON
  renderer = gtk_cell_renderer_text_new ();
  column = gtk_tree_view_column_new_with_attributes ("輸入法名稱", renderer, "text", QUANTITY, NULL);
  gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
  
  renderer = gtk_cell_renderer_text_new ();
  column = gtk_tree_view_column_new_with_attributes ("快速鍵", renderer, "text", PRODUCT, NULL);
  gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

#if 0
  renderer = gtk_cell_renderer_text_new ();
  column = gtk_tree_view_column_new_with_attributes
                         ("TestOK?", renderer, "text", TEST_OK, NULL);
  gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
#endif //if0  

  renderer = gtk_cell_renderer_text_new ();
  column = gtk_tree_view_column_new_with_attributes ("==   ", renderer, "text", TEST_OK, NULL);
  gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);


} //setup_tree_view()


static GtkTreeModel * create_model (void)
{
	gint i = 0;
	GtkListStore *store;
	GtkTreeIter iter;
	/* create list store*/
#if 0	
	store = gtk_list_store_new (COLUMNS,
	G_TYPE_BOOLEAN, //Buy
	G_TYPE_INT, 
	G_TYPE_STRING,
	G_TYPE_BOOLEAN);
#endif //if0

	store = gtk_list_store_new (COLUMNS,
	G_TYPE_BOOLEAN, //Buy
	G_TYPE_STRING, 
	G_TYPE_STRING,
	G_TYPE_STRING);

	/* add data to the list store */
	for (i=0; i<list_size; i++ )
	{
	 // while (list[i].product != NULL)
	 // {
	    gtk_list_store_append (store, &iter);
		    gtk_list_store_set (store, &iter,
			BUY_IT,		list[i].buy, 
                        QUANTITY,	list[i].quantity, 
			PRODUCT,	list[i].product,
			TEST_OK,	list[i].test_ok,
			 -1);

	   // i++;
	  //} // while(list[i].product!=NULL)
	} //for
 	return GTK_TREE_MODEL(store);
} //create_model()

static void fixed_toggled ( GtkCellRendererToggle *cell, gchar *path_str, gpointer data)
{
	GtkTreeModel *model = (GtkTreeModel *)data;
	GtkTreeIter iter;
	GtkTreePath *path = gtk_tree_path_new_from_string(path_str);
	gboolean fixed;

	/* get toggled iter */
	gtk_tree_model_get_iter( model,&iter,path);
	gtk_tree_model_get(model, &iter, BUY_IT,&fixed, -1);
	
	/* do something with the value */
	fixed ^= 1 ;

	/* set new value */
	gtk_list_store_set (GTK_LIST_STORE(model), &iter, BUY_IT,fixed, -1);

	/* clean up */
	gtk_tree_path_free (path);
}//fixed_toggled ()


