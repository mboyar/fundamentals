/*
 * set/get env
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    char *value;
    char *value2;
    if (setenv("CITY", "Istanbul", 1) < 0) {
        perror("setenv");
        exit(EXIT_FAILURE);
    }
    if ((value = getenv("CITY")) == NULL) {
        perror("getenv value");
        exit(EXIT_FAILURE);
    }

    if ((value2 = getenv("CITY2")) == NULL) {
        perror("getenv value2");

        exit(EXIT_FAILURE);
    }

    printf("CITY=%s\nCITY2=%s\n", value, value2);
    //puts(value);
    return 0;
}
