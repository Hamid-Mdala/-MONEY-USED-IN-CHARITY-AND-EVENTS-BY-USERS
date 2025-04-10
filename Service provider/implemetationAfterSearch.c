#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ValidationCheck.h"
#include "implementationAfterSearch.h"
#include "FileManager.h"
char password[20];
bool exists;
int amount;
bool functionalitiesAfterNavigationDashboard(int choice, char *phone_number, char *filename) {
    switch (choice) {
        case 1:
            printf("You have selected to buy bundles.\n");
            printf("1. Buy bundles\n");
            printf("2. Buy airtime bundles\n");
            printf("Enter your choice option: ");
            scanf("%d", &choice);
            int *choicePtr1 = &choice;
            system("CLS");
            if (choice == 1) {
                printf("You have selected to buy data bundles.\n");
                printf("1. For your number\n");
                printf("2. For another number\n");
                printf("Enter your choice option: ");
                scanf("%d", &choice);
                int *choicePtr2 = &choice;
                system("CLS");
                switch(choice) {
                    case 1:
                        printf("You have selected to buy data bundles for your number.\n");
                        printf("1. Internet bundles\n");
                        printf("2. Voice bundles\n");
                        printf("3. SMS bundles\n");
                        printf("Enter your choice option: ");
                        scanf("%d", &choice);
                        int *choicePtr3 = &choice;
                        system("CLS");
                        if(choice == 1) {
                            printf("You have selected to buy internet bundles.\n");
                            printf("1. Purchase internet daily bundle package\n");
                            printf("2. Purchase internet weekly bundle package\n");
                            printf("3. Purchase internet monthly bundle package\n");
                            printf("Enter your choice option: ");
                            scanf("%d", &choice);
                            int *choicePtr4 = &choice;
                            system("CLS");
                            if(choice == 1) {
                                printf("You have selected to purchase daily bundle package.\n");
                                printf("1. Purchase internet daily bundle at MK500 for 1GB\n");
                                printf("2. Purchase internet daily bundle at MK750 for 2GB\n");
                                printf("3. Purchase internet daily bundle at MK1000 for 3GB\n");
                                printf("Enter your choice option: ");
                                scanf("%d", &choice);
                                int *choicePtr5 = &choice;
                                system("CLS");
                                if(choice == 1) {
                                    while(true) {
                                    	printf("Enter your password to make payment: ");
                                    	scanf("%s", password);
                                        exists = validatePassword(password);
                                        if(exists) {
                                          exists = search_for_field(password, "Query.txt");
                                          if(exists) {
                                          	 exists = getAmountInSheet(phone_number, "money_sheet.txt");
                                            if(exists) {
                                             	int extracted_amount = getAmountInSheet(password, "money_sheet.txt");
                                                if(extracted_amount >= 500) {
                                         			int *deduct_amount = &extracted_amount;
                                                    *deduct_amount -= 500;
                                                    int *current_balance = deduct_amount; //double pointer of the current balance
                                                	handlingNotification
													(choicePtr1, choicePtr2, choicePtr3,
													choicePtr4, choicePtr5, current_balance, deduct_amount);
                                                    break;
                                                } else {
                                                	printf("Error: Insufficient funds in your acount.\n");
                                                }
                                            } else {
                                            	printf("Error: Unable to get the your current amount from your money balancesheet.\n");
                                            }
                                          } else {
                                            printf("Error: Invalid pin.\n");
										  }
                                        } else {
                                        	printf("Error: Invalid phone number is entered.\n");
                                        }
                                    }
                                } else if(choice == 2) {
                                  while(true) {
                                    printf("Enter your password to make payment: ");
                                    scanf("%s", password);
                                    exists = validatePassword(password);
                                    if(exists) {
                                      notification(choice, "bundles_internet", password);
                                    }
                                  }
                                } else if(choice == 3) {
                                  while(true) {
                                    printf("Enter your password to make payment: ");
                                    scanf("%s", pin);
                                    exists = authenticate(stored_field1, pin);
                                    if(exists) {
                                      	notification(choice, "bundles_internet", stored_field1);
                                	} else {
                                    	printf("Invalid choice option.\n");
                                    	return false;
                                	}
                                  }
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
          	printf("agent will send money or airtime to an existing number\n");
            printf("1. send money\n");
            printf("2. send airtime\n");
            printf("Enter your choice option: ");
            scanf("%d", &choice);
            if(choice == 1) {
             printf("enter the phone number you want to send money to: ");
			 scanf("%s", phone_number);
             char *extract_phone_number = search_for_field(stored_field1);

             if(strcmp(extract_phone_number, phone_number) != 0) {
             	printf("enter the amount of cash you want to send: ");
             	scanf("%d", &amount);
             	exists = validateAmount(amount);
             	if(exists) {
              		save_details_into_a_sheet("money_sheet.txt", stored_field1, amount);
              		notification(choice, "agent_send_cash", stored_field1);
                } else {
                	printf("Error: Invalid amount entered");
                }
             } else {
             	printf("Error: The phone number does not exist in the user data file\n");
             }
            } else if(choice == 2) {
             printf("enter the amount of airtime you want to send: ");
             scanf("%d", &amount);
             exists = validateAmount(amount);
             if(exists) {
                save_details_into_a_sheet("airtime_sheet.txt", stored_field1, amount);
                notification(choice, "agent_send_cash", stored_field1);
             } else {
                printf("Error: Invalid amount entered");
             }
            } else {
             printf("Invalid choice option.\n");
             return false;
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
/*
bool bundles(int choice, char *stored_field1) {

  if(choice == 1) {
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
					exists = authenticate(stored_field1, pin);
					if(exists) {
					//check and dodut from the account
					char *amount_in_wallet = search_for_field(stored_field1);
					amount = atoi(amount_in_wallet);
					if(amount < 500) {
						printf("Error: Insufficient funds in your account.\n");
					} else {
						//deduct 500 from the account
						amount -= 500;
						//save details into the files
						exists = search_for_field(stored_field1);
                        save_details_into_a_sheet("money_sheet.txt", stored_field1, amount);
                        notification(choice, "bundles_internet", stored_field1);
                        break;
                    }
                }
            } else if(choice == 2) {
              while(true) {
				printf("Enter your password to make payment: ");
				scanf("%s", pin);
				exists = authenticate(stored_field1, pin);
				if(exists) {
					notification(choice, "bundles_internet", stored_field1);
                }
              }
            } else if(choice == 3) {
                                  while(true) {
                                    printf("Enter your password to make payment: ");
                                    scanf("%s", pin);
                                    exists = authenticate(stored_field1, pin);
                                    if(exists) {
                                      	notification(choice, "bundles_internet", stored_field1);
                                	} else {
                                    	printf("Invalid choice option.\n");
                                    	return false;
                                	}
                                  }
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
  } else if(choice == 2) {

  } return true;
}

	 */