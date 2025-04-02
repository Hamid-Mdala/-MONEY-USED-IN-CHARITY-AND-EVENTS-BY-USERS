#include <stdio.h>
#include <stdlib.h>
#include "FileManager.h"
#include "ValidationCheck.h"
#include <stdbool.h>
#include "implementationAfterSearch.h"
bool exists;
int choice;
char phone_number[10];
const char value[20] = "user";
void registration_form() {
  //registration_form
  printf("Welcome to the reliable internet service provider system.\n");
  printf("To use these service, please register the required details\n");
  char username[100];
  printf("Enter username: ");
  scanf("%s", username);
  exists = validateUsername(username);
  if(exists) {
    char pin[20];
    printf("Enter password: ");
    scanf("%d", pin);
    exists = validatePin(pin);
    if(exists) {
      char id[100];
      printf("Enter admin-ID: ");
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
                  exists = search_for_field("user_data.txt", phone_number);
                  if(exists) {
                    printf("The phone number already exists in the user data");
                  }
                  register_user(username, pin, id, first_name, last_name, gender, dob, phone_number, value);
                } else {
                  printf("Invalid phone number.\n");
                }
              } else {
                printf("Invalid date of birth.\n");
              }
            } else {
              printf("Invalid gender.\n");
            }
          } else {
            printf("Invalid last name.\n");
          }
        } else {
          printf("Invalid first name.\n");
        }
      } else {
        printf("Invalid ID.\n");
      }
    } else {
      printf("Invalid password.\n");
    }
  } else {
    printf("Invalid username.\n");
  }
}

bool first_page() {
  printf("Welcome to the most reliable internet service provider's navigation dashboard.\n");
  printf("1. buy bundles\n");
  printf("2. pay bills\n");
  printf("3. send cash to another number\n");
  printf("4. view account details\n");
  printf("5. view/book into events\n");
  printf("6. services\n");
  printf("7. EXIT\n");
  printf("Enter your choice option: ");
  scanf("%d", &choice);
  system("CLS");
  char *stored_field1 = search_for_field("user_data.txt", phone_number); //get the return
  return functionalitiesAfterNavigationDashboard(choice, stored_field1);
}
bool before_navigation_dashboard(char *phone_number) {
  exists = search_for_field("user_data.txt", value);
  if(exists) {
    printf("2. BUNDLES");
    printf("3. PAY BILLS");
    printf("4. SEND CASH");
    printf("5. VIEW ACCOUNT DETAILS");
    printf("6. VIEW/BOOK INTO EVENTS");
    printf("7. EXIT");
    printf("Enter your choice option: ");
    scanf("%d", &choice);


  } else {

  }
  printf("1. continue\n");
  printf("2. EXIT\n");
  printf("Enter your choice option: ");
  scanf("%d", &choice);
  system("CLS");
  if(choice == 1)  {
    printf("Enter your phone number: ");
    scanf("%s", phone_number);
    exists = validatePhoneNumber(phone_number);
    if(exists) {
      exists = search_for_field("user_data.txt", phone_number);
      if(exists) {
        while(true) {
          printf("To claim that you are the owner of this number\n");
          printf("1. continue\n");
          printf("2. EXIT\n");
          printf("Enter your choice option: ");
          scanf("%d", &choice);
          system("CLS");
          if(choice == 1) {
            char username[20];
            printf("Enter your username: ");
            scanf("%s", username);
            exists = validateUsername(username);
            if(exists) {
              char pin[20];
              printf("Enter your password: ");
              scanf("%s", pin);
              exists = validatePin(pin);
              system("CLS");
              if(exists) {
                exists = authenticate("user_data.txt", username, pin, 7);
                if(exists) {
                  if(first_page()) {
                    break;
                  }
                }
              } else {
                printf("Error: the password is invalid");
                break;
              }
            } else {
              printf("Error: the username is invalid");
              break;
            }
          } else if (choice == 2) {
            break;
          } else {
            system("CLS");
            printf("Error: Invalid choice option");
            break;
          }
        }
      } else {
        registration_form();
      }
    } else {
      printf("Invalid phone number.\n");
    }
  } else if(choice == 2) {
    return true;
  } else {
    printf("Error: invalid choice option");
  } return 5;
}



int main(int argc, char **argv[]) {
  printf("Welcome to reliable internet service provider.\n");
  map_t* user_details = map_new();
  map_ctr(user_details);
  before_navigation_dashboard(phone_number);
  map_dtr(user_details);
  return 0;
}
/*what when I search for the number in the user data file
and if the number exists then able to view the dashboard
else the number has to register
*/
