#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ValidationCheck.h"
#include "implementationAfterSearch.h"
#include "FileManager.h"
char password[20];
bool exists;
char phone_number[20];
int amount;
bool functionalitiesAfterNavigationDashboard(int choice, char *details_field8, char *filename) {
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
                                    	scanf("%s", password);
                                        exists = validatePassword(password);
                                        if(exists) {
                                          exists = search_for_field(password, "Query.txt");
                                          if(exists) {
                                          	 exists = getAmountInSheet(password, "money_sheet.txt");
                                            if(exists) {
                                             	int extracted_amount = getAmountInSheet(password, "money_sheet.txt");
                                                if(extracted_amount >= 500) {
                                         			//NOW DUDUCT MONEY FROM THE ACCOUNT PLEASE
                                                } else {
                                                	printf("Error: Insufficient funds in your acount.\n");
                                                }
                                             } else {
                                             	printf("Error: Failed to get amount in sheet");
                                             }
                                          } else {
                                            printf("Error: the phone number doesn't belong to you");
										  }
                                        } else {
                                        	printf("Error: Invalid phone number is entered.\n");
                                        }
                                            		printf("Error: Insufficient funds in your account.\n");
                                            		break;
                                            	} else {
                                            		//deduct 500 from the account
                                            		amount -= 500;
                                                	//save details into the files
                                                	exists = search_for_field(stored_field1);
                                            		save_details_into_a_sheet("money_sheet.txt", stored_field1, amount);
                                            	}
                                            	//notification of bought bundles
                                            	notification(choice, "bundles_internet", stored_field1);
                                        		break;
                                    		} else {
                                          		system("CLS");
                                        		printf("Error: the password is invalid.\n");
											}
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