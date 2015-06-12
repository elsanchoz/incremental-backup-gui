#include <gtk/gtk.h>
#include <glib.h>
#include "main.h"

void assign_stuff()
{ 
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	button_path = gtk_file_chooser_button_new("Select a directory", GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
	button_source = gtk_file_chooser_button_new("Select a directory", GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
	button_index = gtk_file_chooser_button_new("Select a directory", GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
	header_bar = gtk_header_bar_new ();
	cb_algorithm = gtk_combo_box_text_new ();
	cb_skip_hidden = gtk_check_button_new_with_label("Skip hidden files. (leading '.' in file name)");
	cb_full = gtk_check_button_new_with_label("Ignore index file and make a full backup");
	label_path = gtk_label_new("Path to generated archive file:");
	label_algorithm = gtk_label_new("Compression algorithm:");
	label_source = gtk_label_new("Path to the directory which should be backuped:");
	label_index = gtk_label_new("Path to the index directory:");
	spinner = gtk_spinner_new();
	startba = gtk_button_new_with_label("Backup!");
	sizegroup1 = gtk_size_group_new(GTK_SIZE_GROUP_HORIZONTAL);
	sizegroup2 = gtk_size_group_new(GTK_SIZE_GROUP_HORIZONTAL);
	sizegroup3 = gtk_size_group_new(GTK_SIZE_GROUP_HORIZONTAL);

	scrolled_window = gtk_scrolled_window_new(NULL,NULL);
	vertical = gtk_box_new (GTK_ORIENTATION_VERTICAL, 15);
	horizontal1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	horizontal2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	horizontal3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	horizontal4 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	horizontal5 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	horizontal6 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	horizontal7 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	horizontal8 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	horizontal9 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	horizontal10 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	horizontal11 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	horizontal12 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	horizontal13 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
}