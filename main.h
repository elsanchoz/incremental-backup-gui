#define UNUSED(x) (void)(x)
#define COMMAND_LEN 50
#define DATA_SIZE 512

GtkWidget *window;
GtkWidget *button_path;
GtkWidget *button_source;
GtkWidget *button_index;
GtkWidget *header_bar;
GtkWidget *cb_algorithm;
GtkWidget *cb_skip_hidden;
GtkWidget *cb_full;
GtkWidget *label_path;
GtkWidget *label_algorithm;
GtkWidget *label_source;
GtkWidget *label_index;
GtkWidget *spinner;
GtkWidget *startba;
GtkSizeGroup *sizegroup1;
GtkSizeGroup *sizegroup2;
GtkSizeGroup *sizegroup3;

GtkWidget *scrolled_window;
GtkWidget *vertical;
GtkWidget *horizontal1;
GtkWidget *horizontal2;
GtkWidget *horizontal3;
GtkWidget *horizontal4;
GtkWidget *horizontal5;
GtkWidget *horizontal6;
GtkWidget *horizontal7;
GtkWidget *horizontal8;
GtkWidget *horizontal9;
GtkWidget *horizontal10;
GtkWidget *horizontal11;
GtkWidget *horizontal12;
GtkWidget *horizontal13;

FILE *version;
char command_version[COMMAND_LEN];
char data_version[DATA_SIZE];

void assign_stuff();