#include "FileManager.h"
#include <stdio.h>
#include "map.h"
#include <string.h>
#include <stdlib.h>
int count_number_of_fields;
int countFieldsInFile(char *filename) {
    FILE *Fptr = fopen(filename, "r");
    if (Fptr == NULL) {
        printf("Error: Unable to extract fields from %s", filename);
        exit(1);
    } else {
        FILE *Fptr2 = fopen("temporaly_file.txt", "w");
        int count = 0;
        char line[200];
        while (fgets(line, 200, Fptr)) {
            count++;
            if (count == 1) {
                fprintf(Fptr2, "%s\n", line);
            }
        } fclose(Fptr2);
        FILE *Fptr3 = fopen("temporaly_file.txt", "r");
        if (Fptr3 == NULL) {
            printf("Error: Unable to extract fields from %s", filename);
            exit(1);
        } else {
          char otherline[200];
            while (fgets(otherline, 200, Fptr3)) {
                count_number_of_fields = 0;
                for (int lidx = 0; lidx < strlen(otherline); lidx++) {
                    if (otherline[lidx] == ',') {
                        count_number_of_fields++;
                    }
                }
            }
            return count_number_of_fields;
        } fclose(Fptr3);
    } fclose(Fptr);
}

bool register_user
    (char *username, char *pin, char *id, char *first_name,
	char *last_name, char *gender, char *dob, char *phone_number, char *value) {
    FILE *Fptr = fopen("user_data.txt", "a");
    if (Fptr == NULL) {
        printf("Unable to add details in the user data file\n");
        exit(1);
    } else {
        fprintf
          (Fptr, "%s,%s,%s,%s,%s,%s,%s,%s,%s", value, username, pin, id, first_name, last_name, gender, dob, phone_number);
        fclose(Fptr);
        printf("Successfully added details in the user data file\n");
        return true;
    }
}

void checkResult(const map_element_t result) {
    if(result.was_inserted) {
    //    printf("Insertion of details successful! Key: %d, Value: '%s'\n", result.key, result.value->password);
    } else {
        printf("Insertion failed! Key %d already exists with Value: '%s'\n", result.key, result.value->first_name);
    }
}

bool loading_in_map(map_t* user_details) {
    FILE *Fptr = fopen("user_data.txt", "r");
    if (Fptr == NULL) {
        printf("Error: Unable to open the user data file inorder to load the data in the map\n");
        return false;
    } else {
        char line[100];
        while (fgets(line, 100, Fptr)) {
            char *details_field1 = strtok(line, ",");
            char *details_field2 = strtok(NULL, ",");
            char *details_field3 = strtok(NULL, ",");
            char *details_field4 = strtok(NULL, ",");
            char *details_field5 = strtok(NULL, ",");
            char *details_field6 = strtok(NULL, ",");
            char *details_field7 = strtok(NULL, ",");
            char *details_field8 = strtok(NULL, "\n");

            struct user_details *userDetails = malloc(sizeof(struct user_details));
            userDetails->username = strdup(details_field1);
            userDetails->pin = strdup(details_field2);
            userDetails->id = strdup(details_field3);
            userDetails->first_name = strdup(details_field4);
            userDetails->last_name = strdup(details_field5);
            userDetails->gender = strdup(details_field6);
            userDetails->dob = strdup(details_field7);
            userDetails->phone_number = strdup(details_field8);

            map_element_t result = map_insert(user_details, atoi(details_field1), userDetails);
            checkResult(result);
        }
        fclose(Fptr);
    }
    return true;
}

bool authenticate(char *filename,char* details_field1, char *pin, int num_of_fields_in_file) {
    int number = countFieldsInFile(filename);
    if (number == num_of_fields_in_file) {
        if (num_of_fields_in_file == 1) {
            return true;
        } else if (num_of_fields_in_file == 2) {
            return true;
        } else if (num_of_fields_in_file == 7) {
            map_t* user_details = map_new();
            map_ctr(user_details);
            if (loading_in_map(user_details)) {
            //    printf("The function load in map is loaded successfully\n");
            } else {
                printf("Error: Unable to successfully load the function load in map\n");
                return false;
            }
            map_element_t result = map_find(user_details, atoi(details_field1));
            if( result.value != NULL && strcmp(result.value->username, details_field1) == 0 && strcmp(result.value->pin, pin) == 0) {
            //    printf("Successfully authenticated the user\n");
                return true;
            } else {
                printf("Oops unable to authenticate the user, because the credentials don't match our records\n");
                return false;
            }
        }
    } else {
        printf("The count of the fields in the file is not equal to %d\n", number);
        printf("Please contact the developers to fix the issue\n");
        printf("%d\n", count_number_of_fields);
        return false;
    }
    return true;
}

char *search_for_field(char *filename, char details_field[10]) {
    FILE *Fptr = fopen(filename, "r");
    FILE *Fptr2 = fopen(filename, "a");
    if (Fptr == NULL) {
        printf("Error: Unable to open the file\n");
        return false;
    } else {
      char line[100];
        while (fgets(line, 100, Fptr)) {
            char *field1 = strtok(line, ",");
            char *field2 = strtok(NULL, ",");
            char *field3 = strtok(NULL, ",");
            char *field4 = strtok(NULL, ",");
            char *field5 = strtok(NULL, ",");
            char *field6 = strtok(NULL, ",");
            char *field7 = strtok(NULL, ",");
            char *field8 = strtok(NULL, "\n");
            if (strcmp(field1, details_field) == 0) {
                return field8;    //return phone number 
            }
        } return false;
    }
}
bool notification(int choice, char *field_name, char *username) {
	FILE *Fptr = fopen("notification.txt", "o");
    if(Fptr == NULL) {
    	printf("Error: Unable to open the notification file\n");
        return false;
    } else {
      if(choice == 1 && strcmp(field_name, "bundles_internet")) {
      	printf("you have successfully purchased 1GB of internet bundles");
        fprintf(Fptr, "%s,you have successfully purchased 1GB of internet bundles", username);
      } else if(choice == 2 && strcmp(field_name, "bundles_internet")) {
        printf("you have successufully purchased 2GB of internet bundles");
        fprintf(Fptr, "%s, you have successfully purchased 2GB of internet bundles", username);
      } else if(choice == 3 && strcmp(field_name, "bundles_internet")) {
        printf("you have successfully purchased 3GB of internet bundles");
        fprintf(Fptr, "%s, you have successfully purchased 3GB of internet bundles", username);
      } else if(choice == 1 && strcmp(field_name, "bundles_voice")) {
        printf("you have successfully purchased 1GB of voice bundles");
        fprintf(Fptr, "%s, you have successfully purchased 1GB of voice bundles", username);
      } else if(choice == 2 && strcmp(field_name, "bundles_voice")) {
        printf("you have successfully purchased 2GB of voice bundles");
        fprintf(Fptr, "%s, you have successfully purchased 2GB of voice bundles", username);
      } else if(choice == 3 && strcmp(field_name, "bundles_voice")) {
        printf("you have successfully purchased 3GB of voice bundles");
        fprintf(Fptr, "%s, you have successfully purchased 3GB of voice bundles", username);
      } else if(choice == 1 && strcmp(field_name, "bundles_sms")) {
        printf("you have successfully purchased 1GB of sms bundles");
        fprintf(Fptr, "%s, you have successfully purchased 1GB of sms bundles", username);
      } else if(choice == 2 && strcmp(field_name, "bundles_sms")) {
        printf("you have successfully purchased 2GB of sms bundles");
        fprintf(Fptr, "%s, you have successfully purchased 2GB of sms bundles", username);
      } else if(choice == 3 && strcmp(field_name, "bundles_sms")) {
        printf("you have successfully purchased 3GB of sms bundles");
        fprintf(Fptr, "%s, you have successfully purchased 3GB of sms bundles", username);
      } else if(choice == 1 && strcmp(field_name, "bundles_airtime")) {
        printf("you have successfully purchased K500 of airtime bundles");
        fprintf(Fptr, "%s, you have successfully purchased K500 of airtime bundles", username);
      } else if(choice == 2 && strcmp(field_name, "bundles_airtime")) {
        printf("you have successfully purchased K750 of airtime bundles");
        fprintf(Fptr, "%s, you have successfully purchased K750 of airtime bundles", username);
      } else if(choice == 3 && strcmp(field_name, "bundles_airtime")) {
        printf("you have successfully purchased K1000 of airtime bundles");
        fprintf(Fptr, "%s, you have successfully purchased K1000 of airtime bundles", username);
      } else if(choice == 6 && strcmp(field_name, "agent_send_cash")) {
        printf("you have successfully sent money to %s", username);
        fprintf(Fptr, "you have successfully sent money to %s", username);
       } else if(choice == 7) {

       } fclose(Fptr);
    }  return true;
}
bool handles_the_money_balancing_sheet(char *field_name) {
   FILE* Fptr = fopen("money_balacing_sheet.txt", "r");
   if(Fptr == NULL) {
    printf("Error: Unable to open the user data file\n");
    return false;
   } else {

   } return true;
}
bool save_money_into_a_sheet(char *field_name, int amount) {
 FILE *Fptr = fopen("money_sheet.txt", "w");
 if(Fptr == NULL) {
  printf("Error: Unable to open the money sheet file\n ");
 } else {
    fprintf(Fptr, "%s,%d", field_name, amount);
    fclose(Fptr);
    return true;
 }
}
