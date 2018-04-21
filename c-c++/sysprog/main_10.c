/*
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
//    pid_t pid;
//    char *env[] = { "City=Istanbul", "Name=Ali", NULL };
//    if ((pid = fork()) < 0) {
//        perror("fork");
//        exit(EXIT_FAILURE);
//    }
//    if (pid == 0 && execle("app", "app", (char *)NULL, env) < 0) {
//        perror("execle");
//        exit(EXIT_FAILURE);
//    }
//    wait(NULL);

    pid_t pid;
    int i;
    for(i = 0; i < 3; ++i)
        pid = fork();

    printf("tst child-pid:%d, parent-pid:%d\n", pid, getpid());

    return 0;
}
