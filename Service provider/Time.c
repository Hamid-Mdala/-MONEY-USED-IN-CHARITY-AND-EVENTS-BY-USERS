#include "Time.h"
char *findTime() {
    struct tm *ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    return asctime(ptr);
}