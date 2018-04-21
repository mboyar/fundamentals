/*
 * set/get env
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *value;
    if (setenv("CITY", "Istanbul", 1) < 0) {
        perror("setenv");
        exit(EXIT_FAILURE);
    }
    if ((value = getenv("CITY")) == NULL) {
        perror("getenv");
        exit(EXIT_FAILURE);
    }


    puts(value);
    return 0;
}
