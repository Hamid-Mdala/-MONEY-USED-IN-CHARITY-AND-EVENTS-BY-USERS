#include "FileManager.h"
#include <stdio.h>
#include "map.h"
#include <string.h>
#include <stdlib.h>
int count_number_of_fields;
int notification_count = 0;
int count_fields_in_file(char *filename) {
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
            } return count_number_of_fields;
        } fclose(Fptr3);
    } fclose(Fptr);
}
bool make_the_query(char *username) {
  FILE *fptr = fopen("MakeQuery.txt", "a");
  if(fptr == NULL) {
    printf("Error: Unable to open the file MakeQuery\n");
    return false;
  } else {
    char line[200];
    fprintf(fptr,"Service provider,User_%s", username);
    fclose(fptr);
    printf("You have successfully saved the username into the Query file");
  } return true;
}
bool register_user
    (char *username, char *pin, char *id, char *first_name,
	char *last_name, char *gender, char *dob, char *phone_number) {
    FILE *Fptr = fopen("user_data.txt", "a");
    if (Fptr == NULL) {
        printf("Unable to add details in the user data file\n");
        exit(1);
    } else {
        fprintf
          (Fptr, "%s,%s,%s,%s,%s,%s,%s,%s", username, pin, id, first_name, last_name, gender, dob, phone_number);
        fclose(Fptr);
        printf("Successfully added details in the user data file\n");
        make_the_query(username);
        return true;
    }
    FILE *Fptr2 = fopen("Query.txt", "a");
    if(Fptr2 == NULL) {
    	printf("Error: Unable to open the Query file\n");
        exit(1);
    } else {
      	fprintf(Fptr2, "service provider,%s", username);
        fclose(Fptr2);
        printf("Successfully added details in the Query file\n");
        return true;
	}
}
bool counting_notification() {
	FILE *Fptr = fopen("notification.txt", "r");
    if (Fptr == NULL) {
        printf("Error: Unable to open the notification file\n");
        return false;
    } else {
        char line[200];
        while (fgets(line, 200, Fptr)) {
            notification_count++;
        } fclose(Fptr);
    } return notification_count;
}
void checkResult(const map_element_t result) {
    if(result.was_inserted) {
    //    printf("Insertion of details successful! Key: %d, Value: '%s'\n", result.key, result.value->password);
    } else {
        printf("Insertion failed! Key %d already exists with Value: '%s'\n", result.key, result.value->details_field4);
    }
}

bool loading_in_map(map_t* user_details) {
    FILE *MakeFile = fopen("user_data.txt", "a");
    FILE *otherMake = fopen("handling_the_money_balancing_sheet.txt", "a");
  	FILE *Fptr = fopen("user_data.txt", "r");
    if (Fptr == NULL) {
        printf("Error: Unable to open the user data file inorder to load the data in the map\n");
        return false;
    } else {
      int number = count_fields_in_file("handling_the_money_balancing_sheet.txt");
      int number2 = count_fields_in_file("user_data.txt");
      if(number == 2) {
        char line[100];
        while(fgets(line, 100, Fptr)) {
            char *details_field1 = strtok(line, ",");
            char *details_field2 = strtok(NULL, "\n");
            struct user_details *userDetails = malloc(sizeof(struct user_details));
            userDetails->details_field1 = strdup(details_field1);
            userDetails->details_field2 = strdup(details_field2);
            map_element_t result = map_insert(user_details, atoi(details_field1), userDetails);
            checkResult(result);
        } fclose(Fptr);
      } else if(number2 == 8) {
      	char line[100];
        while (fgets(line, 100, Fptr)) {
            char *details_field1 = strtok(line,",");
            char *details_field2 = strtok(line, ",");
            char *details_field3 = strtok(NULL, ",");
            char *details_field4 = strtok(NULL, ",");
            char *details_field5 = strtok(NULL, ",");
            char *details_field6 = strtok(NULL, ",");
            char *details_field7 = strtok(NULL, ",");
            char *details_field8 = strtok(NULL, "\n");
            struct user_details *userDetails = malloc(sizeof(struct user_details));
            userDetails->details_field1 = strdup(details_field1);
            userDetails->details_field2 = strdup(details_field2);
            userDetails->details_field3 = strdup(details_field3);
            userDetails->details_field4 = strdup(details_field4);
            userDetails->details_field5 = strdup(details_field5);
            userDetails->details_field6 = strdup(details_field6);
            userDetails->details_field7 = strdup(details_field7);
            userDetails->details_field8 = strdup(details_field8);
            map_element_t result = map_insert(user_details, atoi(details_field8), userDetails);
            checkResult(result);
        } fclose(Fptr);
      } else if(number2 == 0 || number == 0) {
      	//printf("These step allows user's data to be categorized into files\n");
      } else {
      	printf("The count of fields in the file is not equal to the expected fields needed in the system\n");
        printf("Please contact the developers to fix the issue\n");
        return false;
      }
    } return true;
}

bool authenticate(char* details_field1, char *details_field8) {
    map_t* user_details = map_new();
    map_ctr(user_details);
    if (loading_in_map(user_details)) {
      printf("The function load in map is loaded successfully\n");
    } else {
      printf("Error: Unable to successfully load the function load in map\n");
      return false;
    }
    map_element_t result = map_find(user_details, atoi(details_field8));
    if( result.value != NULL && strcmp(result.value->details_field8, details_field8) == 0) {
    	printf("Successfully authenticated the user\n");
        return true;
    } else {
      	printf("Oops unable to authenticate the user, because the credentials don't match our records\n");
        return false;
    }
}
bool search_for_field(const char *details_field8, char *filename) {
  map_t* user_details = map_new();
  map_ctr(user_details);
  loading_in_map(user_details);
    map_element_t result = map_find(user_details, atoi(details_field8));
    if (result.value != NULL && strcmp(result.value->details_field8, details_field8) == 0) {
    	return true;
    } else {
        printf("The user doesn't exists in our credentials\n");
        return false;
    }
}
int getAmountInSheet(char *details_field8, char *filename) {
    char *get_phone_number;
    char *get_amount_number;
    bool exists = search_for_field(details_field8, filename);
	if(exists) {
    	FILE *Fptr = fopen(filename, "r");
        if(Fptr == NULL) {
        	printf("Error: Unable to open the file %s", filename);
        	exit(1);
        } else {
        	char line[200];
            while(fgets(line, sizeof(line), Fptr)) {
              get_phone_number = strtok(line,",");
              get_amount_number = strtok(NULL, "\n");
            }
        } return atoi(get_amount_number);
    } else {
    	printf("Sorry failed to find the phone number, maybe it does't exists");
    } return false;
}
bool handlingNotification(int *choicePtr1, int *choicePtr2, int *choicePtr3,
int *choicePtr4, int *choicePtr5, int *current_balance, int *deducted_amount) {
  	const map_element_t result;
    char *username = result.value->details_field1;
    FILE *Fptr = fopen("notification_history.txt", "a");
    if(Fptr == NULL) {
    	printf("Error: Unable to open the notification file\n");
        return false;
    } else {
      FILE *fptr = fopen("notification_of_purchased_bundles.txt", "w");
      FILE *otherFptr = fopen("notification_for_deduction_of_money", "w");
      if(*choicePtr1 == 1 && *choicePtr2 == 1 && *choicePtr3 == 1 && *choicePtr4 == 1 && *choicePtr5 == 1) {
      	printf("Dear Customer, Your request is being processed. You will receive a confirmation message shortly");
        fprintf(fptr, "You have successfully purchased 1GB of daily internet bundles");
 		fprintf(otherFptr, "Dear Customer, Your current balance is: %d\n"
		"\t\tThe amount removed from your account was: %d", *current_balance, *deducted_amount);
      } else if(choicePtr2 == 2 && strcmp(type_of_service, "bundles_internet")) {
        printf("you have successufully purchased 2GB of internet bundles");
        fprintf(Fptr, "%s, you have successfully purchased 2GB of internet bundles", result.value->details_field1);
      } else if(choice == 3 && strcmp(type_of_service, "bundles_internet")) {
        printf("you have successfully purchased 3GB of internet bundles");
        fprintf(Fptr, "%s, you have successfully purchased 3GB of internet bundles", result.value->details_field1);
      } else if(choice == 1 && strcmp(type_of_service, "bundles_voice")) {
        printf("you have successfully purchased 1GB of voice bundles");
        fprintf(Fptr, "%s, you have successfully purchased 1GB of voice bundles", result.value->details_field1);
      } else if(choice == 2 && strcmp(type_of_service, "bundles_voice")) {
        printf("you have successfully purchased 2GB of voice bundles");
        fprintf(Fptr, "%s, you have successfully purchased 2GB of voice bundles", result.value->details_field1);
      } else if(choice == 3 && strcmp(type_of_service, "bundles_voice")) {
        printf("you have successfully purchased 3GB of voice bundles");
        fprintf(Fptr, "%s, you have successfully purchased 3GB of voice bundles", result.value->details_field1);
      } else if(choice == 1 && strcmp(type_of_service, "bundles_sms")) {
        printf("you have successfully purchased 1GB of sms bundles");
        fprintf(Fptr, "%s, you have successfully purchased 1GB of sms bundles", result.value->details_field1);
      } else if(choice == 2 && strcmp(type_of_service, "bundles_sms")) {
        printf("you have successfully purchased 2GB of sms bundles");
      } else if(choice == 3 && strcmp(type_of_service, "bundles_sms")) {
        printf("you have successfully purchased 3GB of sms bundles");
        fprintf(Fptr, "%s, you have successfully purchased 3GB of sms bundles", result.value->details_field1);
      } else if(choice == 1 && strcmp(type_of_service, "bundles_airtime")) {
        printf("you have successfully purchased K500 of airtime bundles");
        fprintf(Fptr, "%s, you have successfully purchased K500 of airtime bundles", result.value->details_field1);
      } else if(choice == 2 && strcmp(type_of_service, "bundles_airtime")) {
        printf("you have successfully purchased K750 of airtime bundles");
        fprintf(Fptr, "%s, you have successfully purchased K750 of airtime bundles", result.value->details_field1);
      } else if(choice == 3 && strcmp(type_of_service, "bundles_airtime")) {
        printf("you have successfully purchased K1000 of airtime bundles");
        fprintf(Fptr, "%s, you have successfully purchased K1000 of airtime bundles", result.value->details_field1);
      } else if(choice == 6 && strcmp(type_of_service, "agent_send_cash")) {
        printf("you have successfully sent money to %s", username);
        fprintf(Fptr, "you have successfully sent money to %s", username);
       } else if(choice == 7) {

       }//find time
       fprintf(Fptr, "You successfully purchased 1GB of daily internet bundles on \nYour current balance was: %d\n"
		"\t\tThe amount removed that day from your account was: %d", day, *current_balance, *deducted_amount);
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
bool save_details_into_a_sheet(char *filename,char *phone_number, int amount) {
 if(strcmp(filename,"money_sheet.txt")) {
   FILE *Fptr = fopen(filename, "a");
   if(Fptr == NULL) {
    printf("Error: Unable to open the money sheet file\n ");
   } else {
      fprintf(Fptr, "%s,%d", phone_number, amount);
      fclose(Fptr);
      return true;
   }
 } else if(strcmp(filename, "airtime_sheet.txt")) {
     FILE *Fptr = fopen("airtime_sheet.txt", "w");
     if(Fptr == NULL) {
      printf("Error: Unable to open the airtime sheet file\n");
     } else {
       fprintf(Fptr, "%s,%d", phone_number, amount);
       fclose(Fptr);
       return true;
     }
 } else {
   printf("Error: Unable to open the any sheet file\n");
   exit(1);
 } return true;
}