#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "map.h"
#include <stdbool.h>
bool register_user
    (char *username, char *pin, char *id, char *first_name,
    char *last_name, char *gender, char *dob, char *phone_number, char *value);
bool authenticate(char *filename, char *details_field1, char *pin, int num_of_fields_on_line);
char *search_for_field(char *filename, char details_field[10]);
bool loading_in_map(map_t* user_details);
bool notification(int choice, char *field_name, char *username);
bool handles_the_money_balancing_sheet(char *field_name);
bool money_sheet(char *field_name);
#endif // FILEMANAGER_H
