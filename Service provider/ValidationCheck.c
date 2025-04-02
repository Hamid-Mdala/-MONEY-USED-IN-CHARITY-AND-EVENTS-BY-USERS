#include "ValidationCheck.h"
#include <string.h>
bool validateUsername(char *username){
  if(username == NULL){
    return false;
  } else {
    if(strlen(username) > 10 && strlen(username) <= 20) {
    	return true;
    } else {
		return false;
    }
  }
}
bool validatePin(char *pin){
  if(pin == NULL){
    return false;
  } else {
    if(strlen(pin) > 10 && strlen(pin) <= 20) {
      return true;
    } else {
      return false;
    }
  }
}
bool validateId(char *id) {
  if(id == NULL){
    return false;
  } else {
    if(strlen(id) > 10 && strlen(id) <= 20) {
      return true;
    } else {
      return false;
    }
  }
}
bool validateFirstName(char *first_name){
  if(first_name == NULL){
    return false;
  } else {
    if(strlen(first_name) > 2 && strlen(first_name) <= 20) {
      return true;
    } else {
      return false;
    }
  }
}
bool validateLastName(char *last_name) {
	if(last_name == NULL){
      return false;
	} else {
       if(strlen(last_name) > 2 && strlen(last_name) <= 20) {
         return true;
       } else {
         return false;
       }
	}
}
bool validateGender(char *gender){
  if(gender == NULL){
    return false;
  } else {
    if(strlen(gender) == 1) {
      return true;
    } else {
      return false;
    }
  }
}
bool validateDOB(char *dob){
  if(dob == NULL){
    return false;
  } else {
    if(strlen(dob) == 10) {
      return true;
    } else {
      return false;
    }
  }
}
bool validatePhoneNumber(char *phone_number) {
  if(phone_number == NULL){
    return false;
  } else {
    if(strlen(phone_number) == 10) {
      return true;
    } else {
      return false;
    }
  }
}
bool validateAmount(int amount) {
 if(amount == '\0') {
  return false;
 } else {
  if(amount > 0) {
   return true;
  } else {
   return false;
  }
 }
}