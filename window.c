#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <glib.h>
#include "main.h"

void toggle_hidden(GtkWidget *widget, gpointer *data)
{
	UNUSED(data);
	UNUSED(widget);

    printf("Alle meine Entchen\n");
}

void toggle_full(GtkWidget *widget, gpointer *data)
{
	UNUSED(data);
	UNUSED(widget);

	printf("Schwimmen auf dem See\n");
}

// GTK FILE CHOOSER
void filechooser()
{
	gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(button_path), "/home/");
	gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(button_source), "/");
	gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(button_source), "/home/");
}

// GTK SIZE GROUP
void sizegroup()
{
	gtk_size_group_add_widget(GTK_SIZE_GROUP(sizegroup1), label_path);
	gtk_size_group_add_widget(GTK_SIZE_GROUP(sizegroup1), label_algorithm);
	gtk_size_group_add_widget(GTK_SIZE_GROUP(sizegroup1), label_index);
	gtk_size_group_add_widget(GTK_SIZE_GROUP(sizegroup1), label_source);

	gtk_size_group_add_widget(GTK_SIZE_GROUP(sizegroup2), cb_skip_hidden);
	gtk_size_group_add_widget(GTK_SIZE_GROUP(sizegroup2), cb_full);

	gtk_size_group_add_widget(GTK_SIZE_GROUP(sizegroup3), button_path);
	gtk_size_group_add_widget(GTK_SIZE_GROUP(sizegroup3), cb_algorithm);
	gtk_size_group_add_widget(GTK_SIZE_GROUP(sizegroup3), button_index);
	gtk_size_group_add_widget(GTK_SIZE_GROUP(sizegroup3), button_source);
	gtk_size_group_add_widget(GTK_SIZE_GROUP(sizegroup3), startba);
}

// GTK COMBO BOX
void combobox()
{
	gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(cb_algorithm), 0, "id1", "b64encode");
	gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(cb_algorithm), 1, "id2", "bzip2");
	gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(cb_algorithm), 2, "id3", "compress");
	gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(cb_algorithm), 3, "id4", "grzip");
	gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(cb_algorithm), 4, "id5", "gzip");
	gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(cb_algorithm), 5, "id6", "lrzip");
	gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(cb_algorithm), 6, "id7", "lzip");
	gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(cb_algorithm), 7, "id8", "lzop");
	gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(cb_algorithm), 8, "id9", "uuencode");
	gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(cb_algorithm), 9, "id10", "xz");
	gtk_combo_box_set_active(GTK_COMBO_BOX(cb_algorithm), 4);
}

// GTK BOX
void gtkbox()
{
	gtk_box_pack_start(GTK_BOX(horizontal1), label_path, TRUE, TRUE,0);
	gtk_box_pack_start(GTK_BOX(horizontal1), button_path, TRUE, TRUE,30);
	gtk_box_pack_start(GTK_BOX(horizontal2), label_algorithm, TRUE, TRUE,0);
	gtk_box_pack_start(GTK_BOX(horizontal2), cb_algorithm, TRUE, TRUE,30);
	gtk_box_pack_start(GTK_BOX(horizontal3), label_index, TRUE, TRUE,30);
	gtk_box_pack_start(GTK_BOX(horizontal3), button_index, TRUE, TRUE,30);
	gtk_box_pack_start(GTK_BOX(horizontal4), label_source, TRUE, TRUE,30);
	gtk_box_pack_start(GTK_BOX(horizontal4), button_source, TRUE, TRUE,30);
	gtk_box_pack_start(GTK_BOX(horizontal6), cb_skip_hidden, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(horizontal7), cb_full, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(horizontal11), startba, TRUE, TRUE,30);
	gtk_box_pack_start(GTK_BOX(horizontal13), spinner, TRUE, TRUE,0);
}

void pack_box()
{
	gtk_container_add(GTK_CONTAINER(window), scrolled_window);
	gtk_container_add(GTK_CONTAINER(scrolled_window), vertical);
	gtk_box_pack_start(GTK_BOX(vertical), horizontal1, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vertical), horizontal2, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vertical), horizontal3, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vertical), horizontal4, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vertical), horizontal5, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vertical), horizontal6, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vertical), horizontal7, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vertical), horizontal8, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vertical), horizontal9, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vertical), horizontal10, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vertical), horizontal11, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vertical), horizontal12, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vertical), horizontal13, FALSE, FALSE, 0);
}

int main()
{
	gtk_init(NULL, NULL);

	assign_stuff();
	filechooser();
	sizegroup();	
	combobox();
	gtkbox();

	// GTK HEADER BAR	
	sprintf(command_version, "/usr/bin/incremental-backup -V");
	version = popen(command_version, "r");
	fgets(data_version, DATA_SIZE, version);
	data_version[strlen(data_version) - 1] = '\0'; // remove trailing newline
	fprintf(stdout, "'%s'\n", data_version);
	pclose(version);

	gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header_bar), TRUE);
	gtk_window_set_titlebar(GTK_WINDOW(window), header_bar);
	gtk_header_bar_set_title(GTK_HEADER_BAR(header_bar), "Incremental Backup GUI");
	gtk_header_bar_set_subtitle(GTK_HEADER_BAR(header_bar), data_version);

	//GTK WINDOW
	gtk_window_set_default_size((GTK_WINDOW(window)), 800, 800);

	// GTK LABEL
	gtk_widget_set_halign(label_path, GTK_ALIGN_START);
	gtk_widget_set_halign(label_algorithm, GTK_ALIGN_START);
	gtk_widget_set_halign(label_index, GTK_ALIGN_START);
	gtk_widget_set_halign(label_source, GTK_ALIGN_START);

	// TOGGLE BUTTON
	g_signal_connect(cb_skip_hidden, "toggled", G_CALLBACK(toggle_hidden), NULL);
	g_signal_connect(cb_full, "toggled", G_CALLBACK(toggle_full), NULL);

	pack_box();
	
	gtk_container_set_border_width(GTK_CONTAINER(vertical),15);

	g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}
