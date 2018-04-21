/*
 * environ (~ env command)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;
int main(void)
{
    int i;
    for (i = 0; environ[i] != NULL; ++i)
        puts(environ[i]);
    return 0;
}
