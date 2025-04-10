#include <stdio.h>
#include <stdlib.h>
#include "FileManager.h"
#include "ValidationCheck.h"
#include <stdbool.h>
#include "implementationAfterSearch.h"
#include "map.h"
#include <string.h>
bool exists;
int choice;
char phone_number[10];
const char value[20] = "user";
bool make_search_query() {
  FILE* fptr = fopen("Query.txt", "r");
  if(fptr == NULL) {
    printf("Error: Unable to open the Query file");
  } else {
    char line[300];
    while(fgets(line, sizeof(line), fptr)) {
      const char *field1 = strtok(line, ",");
      const char *field2 = strtok(NULL, "\n");
      if(strstr(field2, "User_") != NULL) {
        return true;
      }
    } return false;
  }return true;
}



void registration_form() {
  //registration_form
  char username[100];
  printf("Enter username: ");
  scanf("%s", username);
  sprintf(username, "User_%s", username);
  exists = validateUsername(username);
  if(exists) {
    char pin[100];
    printf("Enter password: ");
    scanf("%s", pin);
    exists =



    if(exists) {
      char id[100];
      printf("Enter ID: ");
      scanf("%s", id);
      exists = validateId(id);
      if(exists) {
        char first_name[100];
        printf("Enter First Name: ");
        scanf("%s", first_name);
        exists = validateFirstName(first_name);
        if(exists) {
          char last_name[100];
          printf("Enter Last Name: ");
          scanf("%s", last_name);
          exists = validateLastName(last_name);
          if(exists) {
            char gender[100];
            printf("Enter Gender: ");
            scanf("%s", gender);
            exists = validateGender(gender);
            if(exists) {
              char dob[100];
              printf("Enter Date Of Birth: ");
              scanf("%s", dob);
              exists = validateDOB(dob);
              if(exists) {
                printf("Enter Phone Number: ");
                scanf("%s", phone_number);
                exists = validatePhoneNumber(phone_number);
                if(exists) {
                  exists = search_for_field(phone_number, "user_data.txt");
                  if (exists) {
                    printf("The phone doesn't belong to you, someone is having these number in our records.\n");
                  } else {
                    register_user(username, pin, id, first_name, last_name, gender, dob, phone_number);
                  }
                } else {
                  printf("Error: Invalid phone number.\n");
                }
              } else {
                printf("Error: Invalid date of birth.\n");
              }
            } else {
              printf("Error: Invalid gender.\n");
            }
          } else {
            printf("Error: Invalid last name.\n");
          }
        } else {
          printf("Error: Invalid first name.\n");
        }
      } else {
        printf("Error: Invalid ID.\n");
      }
    } else {
      printf("Error: Invalid password.\n");
    }
  } else {
    printf("Error: Invalid username.\n");
  }
}

bool first_page() {
  printf("Enter your choice option: ");
  scanf("%d", &choice);
  system("CLS");
  char *filename;
  char *details_field8;
  return functionalitiesAfterNavigationDashboard(choice, details_field8, filename);
}
bool before_navigation_dashboard() {
 exists = make_search_query();
  if(exists) {
    const int number = counting_notification();
    printf("1. BUY BUNDLES\n");
    printf("2. PAY BILLS\n");
    printf("3. SEND CASH TO ANOTHER NUMBER\n");
    printf("4. VIEW ACCOUNT DETAILS\n");
    printf("5. VIEW BOOK INTO EVENTS\n");
    printf("6. SERVICES\n");
    printf("7. NOTIFICATION(%d)\n", number);
    printf("8. EXIT\n");
    first_page();
  } else {
    registration_form();
  } return true;
}
int main(int argc, char **argv[]) {
  printf("Welcome to reliable internet service provider.\n");
  map_t* user_details = map_new();
  map_ctr(user_details);
  before_navigation_dashboard(user_details);
  map_dtr(user_details);
  return 0;
}
/*what when I search for the number in the user data file
and if the number exists then able to view the dashboard
else the number has to register
*/
