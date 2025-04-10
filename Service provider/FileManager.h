#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "map.h"
#include <stdbool.h>
bool register_user
(char *username, char *pin, char *id, char *first_name,
char *last_name, char *gender, char *dob, char *phone_number);
bool authenticate(char *details_field1, char *details_field2);
int count_fields_in_file(char *filename);
bool search_for_field(const char *details_field8, char *filename);
bool loading_in_map(map_t* user_details);
bool handlingNotification
(int *choicePtr1, int *choicePtr2, int *choicePtr3,
int *choicePtr4, int *current_balance, int *deducted_amount);
bool handles_the_money_balancing_sheet(char *field_name);
bool save_details_into_a_sheet(char *filename, char *field_name, int amount);
bool counting_notification();
char* get_details_field2(const map_element_t result);
int getAmountInSheet(char *details_field8, char *filename);
#endif // FILEMANAGER_H
