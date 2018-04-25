/*
 * segfault
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){

    char *ch = (char *)0x34756457;

    putchar(*ch);

    return 0;
}
