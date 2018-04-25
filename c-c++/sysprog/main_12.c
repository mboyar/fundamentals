/*
 * wait
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    pid_t pid;
    char *env[] = { "CSD_City=Dublin", "CSD_Name=Cork", NULL };
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

//    if (pid == 0 && execle("./sample", "./sample", "arg1", "arg2", "arg3", (char *)NULL, env) < 0) {
//        perror("execle");
//        exit(EXIT_FAILURE);
//    }

    char *args[] = {"./sample", "arg1", "arg2", "arg3", (char *)NULL};

    if(pid == 0 && execvpe("./sample", args, env) < 0){
//    if(pid == 0 && execvp("./sample", args) < 0){

        perror("execle");
        exit(EXIT_FAILURE);
    }

    int status;
    wait(&status);

    if(WIFEXITED(status))
        printf("WEXITSTATUS: %d\n" , WEXITSTATUS(status));

    printf("parent continues...\n");

    return 0;
}
