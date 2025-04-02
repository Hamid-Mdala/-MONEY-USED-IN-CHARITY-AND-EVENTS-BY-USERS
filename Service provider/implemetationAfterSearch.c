#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ValidationCheck.h>
#include "implementationAfterSearch.h"
#include "FileManager.h"
char pin[20];
bool exists;
char phone_number[20];
bool functionalitiesAfterNavigationDashboard(int choice, char stored_field1[20]) {
    switch (choice) {
        case 1:
            printf("You have selected to buy bundles.\n");
            printf("1. Buy bundles\n");
            printf("2. Buy airtime bundles\n");
            printf("Enter your choice option: ");
            scanf("%d", &choice);
            system("CLS");
            if (choice == 1) {
                printf("You have selected to buy data bundles.\n");
                printf("1. For your number\n");
                printf("2. For another number\n");
                printf("Enter your choice option: ");
                scanf("%d", &choice);
                system("CLS");
                switch(choice) {
                    case 1:
                        printf("You have selected to buy data bundles for your number.\n");
                        printf("1. Internet bundles\n");
                        printf("2. Voice bundles\n");
                        printf("3. SMS bundles\n");
                        printf("Enter your choice option: ");
                        scanf("%d", &choice);
                        system("CLS");
                        if(choice == 1) {
                            printf("You have selected to buy internet bundles.\n");
                            printf("1. Purchase internet daily bundle package\n");
                            printf("2. Purchase internet weekly bundle package\n");
                            printf("3. Purchase internet monthly bundle package\n");
                            printf("Enter your choice option: ");
                            scanf("%d", &choice);
                            system("CLS");
                            if(choice == 1) {
                                printf("You have selected to purchase daily bundle package.\n");
                                printf("1. Purchase internet daily bundle at MK500 for 1GB\n");
                                printf("2. Purchase internet daily bundle at MK750 for 2GB\n");
                                printf("3. Purchase internet daily bundle at MK1000 for 3GB\n");
                                scanf("%d", &choice);
                                printf("Enter your choice option: ");
                                scanf("%d", &choice);
                                system("CLS");
                                if(choice == 1) {
                                    while(true) {
                                    	printf("Enter your password to make payment: ");
                                    	scanf("%s", pin);
                                    	exists = authenticate("user_data.txt", stored_field1, pin, 7);
                                    	if(exists) {
                                          	//check and dodut from the account
                                            FILE* Fptr = fopen("user_data.txt", "r");
                                            if(Fptr == NULL) {
                                              printf("Error: Unable to open the user data file\n");
                                              return false;
                                            } else {

                                            }
                                    		printf("You have successfully purchased 1GB of internet bundles");
                                            notification(choice, "bundles_internet", stored_field1);
                                        	break;
                                    	} else {
                                          	system("CLS");
                                        	printf("Error: the password is invalid.\n");
										}
                                   }
                                } else if(choice == 2) {
                                  while(true) {
                                    printf("Enter your password to make payment: ");
                                    scanf("%s", pin);
                                    exists = authenticate("user_data.txt", stored_field1, pin, 7);
                                    if(exists) {
                                      notification(choice, "bundles_internet", stored_field1);
                                    }
                                  }
                                } else if(choice == 3) {
                                  while(true) {
                                    printf("Enter your password to make payment: ");
                                    scanf("%s", pin);
                                    exists = authenticate("user_data.txt", stored_field1, pin, 7);
                                    if(exists) {
                                      notification(choice, "bundles_internet", stored_field1);
                                } else {
                                    printf("Invalid choice option.\n");
                                    return false;
                                }
                            } else if(choice == 2) {
                                printf("You have selected to purchase weekly bundle package.\n");
                            } else if(choice == 3) {
                                printf("You have selected to purchase monthly bundle package.\n");
                            } else {
                                printf("Invalid choice option.\n");
                                return false;
                            }
                        } else {
                            printf("Invalid choice option.\n");
                            return false;
                        }
                        break;
                    case 2:
                        printf("Enter your phone number: ");
                        break;
                    default:
                        printf("Invalid choice option.\n");
                        return false;
                }
            } else if (choice == 2) {
                printf("You have selected to buy airtime bundles.\n");
                printf("1. For your number\n");
                printf("2. For another number\n");
                printf("Enter your choice option: ");
                scanf("%d", &choice);
                system("CLS");
                if(choice == 1) {
                    printf("You have selected to buy airtime bundles for your number.\n");
                } else if(choice == 2) {
                    printf("You have selected to buy airtime bundles for another number.\n");
                } else {
                    printf("Invalid choice option.\n");
                    return false;
                }
            } else {
                printf("Invalid choice option.\n");
                return false;
            }
        case 2:
            printf("You have selected to pay bills.\n");
            break;
        case 3:
            printf("You have selected to send cash.\n");
            break;
        case 4:
            printf("You have selected to view account details.\n");
            break;
        case 5:
            printf("You have selected to view/book into events.\n");
            break;
        case 6:
          	printf("agent will send money to an existing number\n");
            printf("please enter the phone number: ");
            scanf("%s", phone_number);
            char *return_phone_number = search_for_field("user_data.txt", phone_number);
            int amount;
            if(strcmp(phone_number, return_phone_number)) {
            	printf("enter amount of cash: ");
                scanf("%d", &amount);
                exists = validateAmount(amount);
                if(exists) {
                   save_money_into_a_sheet();
                   notification(choice, "agent_send_cash", phone_number);
                }

            }
          	break;
        case 7:
        	exit(1);
            break;
        default:
            printf("Invalid choice option.\n");
            return false;
    }
    return true;
}