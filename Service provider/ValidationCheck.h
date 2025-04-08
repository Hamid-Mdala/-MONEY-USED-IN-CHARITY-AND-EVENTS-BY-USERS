#ifndef VALIDATIONCHECK_H
#define VALIDATIONCHECK_H
#include <stdbool.h>
bool validateUsername(char *username);
bool validatePassword(char *password);
bool validateId(char *id);
bool validateFirstName(char *first_name);
bool validateLastName(char *last_name);
bool validateGender(char *gender);
bool validateDOB(char *dob);
bool validatePhoneNumber(char *phone_number);
bool validateAmount(int amount);
#endif //VALIDATIONCHECK_H
