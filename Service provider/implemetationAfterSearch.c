#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "ValidationCheck.h"
#include "implementationAfterSearch.h"
#include "FileManager.h"
char password[20];
bool exists;
int amount;
bool functionalitiesAfterNavigationDashboard(int choice, char *phone_number, char *filename, map_t* user_details) {
    switch (choice) {
        case 1: //BUY BUNDLES
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
                        printf("1. Internet Daily bundles\n");
                        printf("2. Voice Daily bundles\n");
                        printf("3. SMS Daily bundles\n");
                        printf("Enter your choice option: ");
                        scanf("%d", &choice);
                        int *choicePtr3 = &choice;
                        system("CLS");
                        if(choice == 1) {
                          	printf("1. Purchase internet daily bundles at MK500 for 1 GB.\n");
                        	printf("2. Purchase internet daily bundle at MK750 for 2GB\n");
                        	printf("3. Purchase internet daily bundle at MK1000 for 3GB\n");
                            printf("Enter your choice option: ");
                            scanf("%d", &choice);
                            int *choicePtr4 = &choice;
                            system("CLS");
                            if(choice == 1 || choice == 2 || choice == 3) {
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
													choicePtr4, current_balance, deduct_amount);
                                                    break;
                                                } else {
                                                	printf("Error: Insufficient funds in your acount.\n");
                                                }
                                            } else {
                                            	printf("Error: Unable to get the your current amount from your money balancesheet.\n");
                                            }
                                        } else {
										 	printf("Error: Failed to find your number in the Query file.\n");
										}
                                    } else {
                                        printf("Error: Invalid phone number is entered.\n");
                                    }
                                }
                            } else {
                            	printf("Error: Invalid choice option.\n");
                            }
                        } else if(choice == 2) {
                            printf("1. Purchase voice daily bundles at MK200 for 20min.\n");
                            printf("2. Purchase voice daily bundles at Mk400 for 40min.\n");
                            printf("3. Purchasw voice dailly bundles at MK550 for 100min.\n");
                            printf("Enter your choice option: ");
                            scanf("%d", &choice);
                            int *choicePtr4 = &choice;
                            system("CLS");
                            if(choice == 1 || choice == 2 || choice == 3) {
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
													choicePtr4, current_balance, deduct_amount);
                                                    break;
                                                } else {
                                                	printf("Error: Insufficient funds in your acount.\n");
                                                }
                                            } else {
                                            	printf("Error: Unable to get the your current amount from your money balancesheet.\n");
                                            }
                                        } else {
										 	printf("Error: Failed to find your number in the Query file.\n");
										}
                                    } else {
                                        printf("Error: Invalid phone number is entered.\n");
                                    }
                                }
                            } else {
                            	printf("Error: Invalid choice option");
                            }
                        } else if(choice == 3) {
                        	printf("Purchase SMS daily bundles at MK100 for 10 SMS.\n");
                        	printf("Purchase SMS daily bundles at MK200 for 20 SMS.\n");
                        	printf("Purchase SMS daily bundles at MK300 for 30 SMS.\n");
							printf("Enter your choice option: ");
                            scanf("%d", &choice);
                            int *choicePtr4 = &choice;
                            system("CLS");
                            if(choice == 1 || choice == 2 || choice == 3) {
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
													choicePtr4, current_balance, deduct_amount);
                                                	break;
                                                } else {
                                                	printf("Error: Insufficient funds in your acount.\n");
                                                }
                                            } else {
                                            	printf("Error: Unable to get the your current amount from your money balancesheet.\n");
                                            }
                                        } else {
                                        	printf("Error: Failed to find your number in the Query file.\n");
                                        }
                                    } else {
                                    	printf("Error: Invalid phone number is entered.\n");
                                    }
                            	}
                            } else {
                            	printf("Error: Invalid choice option.\n");
                            }
                        } else {
                        	printf("Error: Invalid choice option.\n");
                        }
                        break;
            		case 2:
                        printf("Enter the  phone number to make purchase bundles for someone: ");
                        scanf("%s", phone_number);
                        system("CLS");
                        exists = search_for_field(phone_number, "user_data.txt");
                        if(exists) {
                        	printf("1. Internet Daily bundles\n");
                            printf("2. Voice Daily bundles\n");
                            printf("3. SMS Daily bundles\n");
                            printf("Enter your choice option: ");
                            scanf("%d", &choice);
                            int *choiceOtherPtr3 = &choice;
                            system("CLS");
                            if(choice == 1) {
								printf("1. Purchase internet daily bundles at MK500 for 1 GB.\n");
                        		printf("2. Purchase internet daily bundle at MK750 for 2GB\n");
                        		printf("3. Purchase internet daily bundle at MK1000 for 3GB\n");
	                            printf("Enter your choice option: ");
	                            scanf("%d", &choice);
	                            int *choiceOtherPtr4 = &choice;
	                            system("CLS");
	                            if(choice == 1 || choice == 2 || choice == 3) {
	                                while(true) {
	                                    printf("Enter your password to make payment: ");
	                                    scanf("%s", password);
	                                    exists = validatePassword(password);
	                                    if(exists) {
                                    		exists = search_for_field("Query.txt", "service_provider");
	                                        if(exists) {
                                        		exists = getAmountInSheet(phone_number, "money_sheet.txt");
	                                            if(exists) {
                                             		int extracted_amount = getAmountInSheet(password, "money_sheet.txt");
	                                                if(extracted_amount >= 500) {
                                         				int *deduct_amount = &extracted_amount;
	                                                    *deduct_amount -= 500;
	                                                    int *current_balance = deduct_amount; //double pointer of the current balance
                                                		handlingNotification
														(choicePtr1, choicePtr2, choiceOtherPtr3,
														choiceOtherPtr4, current_balance, deduct_amount);
	                                                    break;
	                                                } else {
                                                		printf("Error: Insufficient funds in your acount.\n");
	                                                }
	                                            } else {
                                            		printf("Error: Unable to get the your current amount from your money balancesheet.\n");
	                                            }
	                                        } else {
										 		printf("Error: Failed to find your number in the Query file.\n");
											}
	                                    } else {
	                                        printf("Error: Invalid phone number is entered.\n");
	                                    }
	                                }
	                            } else {
                            		printf("Error: Invalid choice option.\n");
	                            }
	                        } else if(choice == 2) {
	                            printf("1. Purchase voice daily bundles at MK200 for 20min.\n");
	                            printf("2. Purchase voice daily bundles at Mk400 for 40min.\n");
	                            printf("3. Purchasw voice dailly bundles at MK550 for 100min.\n");
	                            printf("Enter your choice option: ");
	                            scanf("%d", &choice);
	                            int *choiceOtherPtr4 = &choice;
	                            system("CLS");
	                            if(choice == 1 || choice == 2 || choice == 3) {
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
														(choicePtr1, choicePtr2, choiceOtherPtr3,
														choiceOtherPtr4, current_balance, deduct_amount);
	                                                    break;
	                                                } else {
                                                		printf("Error: Insufficient funds in your acount.\n");
	                                                }
	                                            } else {
                                            		printf("Error: Unable to get the your current amount from your money balancesheet.\n");
	                                            }
	                                        } else {
										 		printf("Error: Failed to find your number in the Query file.\n");
											}
	                                    } else {
	                                        printf("Error: Invalid phone number is entered.\n");
	                                    }
	                                }
	                            } else {
                            		printf("Error: Invalid choice option");
	                            }
	                        } else if(choice == 3) {
                        		printf("Purchase SMS daily bundles at MK100 for 10 SMS.\n");
                        		printf("Purchase SMS daily bundles at MK200 for 20 SMS.\n");
                        		printf("Purchase SMS daily bundles at MK300 for 30 SMS.\n");
								printf("Enter your choice option: ");
	                            scanf("%d", &choice);
	                            int *choiceOtherPtr4 = &choice;
	                            system("CLS");
	                            if(choice == 1 || choice == 2 || choice == 3) {
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
                                                		(choicePtr1, choicePtr2, choiceOtherPtr3,
														choiceOtherPtr4, current_balance, deduct_amount);
                                                		break;
	                                                } else {
                                                		printf("Error: Insufficient funds in your acount.\n");
	                                                }
	                                            } else {
                                            		printf("Error: Unable to get the your current amount from your money balancesheet.\n");
	                                            }
	                                        } else {
                                        		printf("Error: Failed to find your number in the Query file.\n");
	                                        }
	                                    } else {
                                    		printf("Error: Invalid phone number is entered.\n");
	                                    }
                            		}
	                            } else {
                            		printf("Error: Invalid choice option.\n");
	                            }
                            } else {
                            	printf("Error: Invalid choice option.\n");
                            }
                        }
                        break;
                    default :
                        printf("Invalid choice option.\n");
                        return false;
                }
            } else if(choice == 2) {
            	printf("1. Buy airtime for your number\n");
                printf("2. Buy airtime for another number\n");
                printf("Enter your choice option: ");
                scanf("%d", &choice);
                system("CLS");
                if(choice == 1) {
                	  printf("Enter the amount of airtime you want to buy: ");
                      scanf("%d", &amount);
                      system("CLS");
                      exists = validateAmount(amount);
                      if(exists) {
                      		printf("Enter your password:  ");
	                        scanf("%s", password);
	                        system("CLS");
	                        exists = validatePassword(password);
	                        if(exists) {
                        		exists = search_for_field("Query.txt", "service_provider");
	                            if(exists) {
                            		exists = getAmountInSheet(phone_number, "airtime_sheet.txt");
	                                if(exists) {
                                		int extracted_amount = getAmountInSheet(phone_number, "airtime_sheet.txt");
	                                    if(extracted_amount > 500) {
                                    		int *deduct_amount = &extracted_amount;
	                                        *deduct_amount -= amount;
	                                        int *current_balance = deduct_amount; //double pointer of the current balance
                                             /* have to rewrite the airtime sheet so that the line withe phone number is not
                                                extracted while the rest is*/

	                                    } else if(extracted_amount == 500) {
                                    		printf("Our airtime services start from above 500\n");
	                                    } else {
                                    		printf("Sorry you have insuffient funds in your airtime balance\n");
	                                    }
	                                } else {
	                                  printf("Failed to get airtime balances,"
									  "because of the phone number doesn't exists in the airtime sheet\n");
                            		}
	                            } else {
                            		printf("Error: if these happens report this issue to the developers maintaing the code.\n");
                         		}
	                        } else {
                        		printf("Error: Invalid password is entered.\n");
	                        }
                      } else {
                      		printf("Error: Invalid amount is entered.\n");
                      }
                } else if(choice == 2) {

                }
            }
        	break;
        case 2: //PAY BILLS
            printf("You have selected to pay bills.\n");
            printf("1. Pay electricity bill\n");
            printf("2. Pay water bill\n");
            printf("3. Pay internet bill\n");
            printf("Enter your choice option: ");
            scanf("%d", &choice);
            system("CLS");
            if(choice == 1) {
            	printf("You have selected to pay electricity bill.\n");
            	// Add your code here
            } else if(choice == 2) {
            	printf("You have selected to pay water bill.\n");
            	// Add your code here
            } else if(choice == 3) {
            	printf("You have selected to pay internet bill.\n");
            	// Add your code here
            } else {
            	printf("Invalid choice option.\n");
            	return false;
            }
			break;
 		case 3: //SEND CASH TO ANOTHER NUMBER
            // Add your code here
            break;
        case 4: //VIEW ACCOUNT DETAILS
            // Add your code here
            break;
        case 5: //VIEW BOOK INTO EVENTS
            // Add your code here
            break;
        case 6: //SERVICES
          ///users who have are registered into the user data file will be able to do this
          //only those who are registered but how will the money agent be registered and how will the he send the money to
          //users...How will we have value before this????????cause if the is no way of registering the money agent we are in trouble
          //if the phone number is starting with a 0994500600 is 10 digits while if the number is 7 digits then we will accume that
          //the user is an agent and will have to put in money into his agent data file so that we could use it in to send money same applies with airtime
          //The agent is another user of the service we are offfering 
            printf("1. Send money\n");
            printf("2. Send airtime\n");
            printf("Enter your choice option: ");
            scanf("%d", &choice);
            system("CLS");
            if(choice == 1) {
            	printf("Enter the phone number to send money to: ");
                scanf("%s", phone_number);
                exists = validatePhoneNumber(phone_number);
                if(exists) {
                    exists = loading_in_map(user_details);
                    if(exists) {
                    	const map_element_t result = map_find(user_details, atoi(phone_number));
                        if(strcmp(result.value->details_field8,phone_number) {
                        	printf("Enter the amount of cash you want to send: ";
							scanf("%d", amount);
                            system("CLS");
							exists = validateAmount(amount);
                            if(exists) {

}
						}
                    }
                    exists = search_for_field(result.value->details_field1, "user_data.txt");

                	printf("Enter the amount of cash you want to send: ");
                    scanf("%d", &amount);
                    exists = validateAmount(amount);
                    if(exists) {

                    }
                }
            }
            break;
        case 7: //NOTIFICATION
            // Add your code here
            break;
        case 8: //EXIT
            printf("Exiting the program.\n");
            return false;
        default:
            printf("Invalid choice option.\n");
            return false;
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