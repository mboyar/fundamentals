/*----------------------------------------------------------------------------------------------------------------------
    cp programına benzer bir program
----------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE     4096

void exit_sys(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    int fds, fdd;
    ssize_t n;
    char buf[BUFSIZE];

    if (argc != 3) {
        fprintf(stderr, "Wrong number of arguments\n");
        fprintf(stderr, "usage: mycp <src file> <dest file>\n");
        exit(EXIT_FAILURE);
    }

    if ((fds = open(argv[1], O_RDONLY)) < 0)
        exit_sys("open src");

    if ((fdd = open(argv[2], O_WRONLY|O_CREAT|O_EXCL, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH)) < 0)
        exit_sys("open dst");

    while ((n = read(fds, buf, BUFSIZE)) > 0)
        if (write(fdd, buf, n) < 0)
            exit_sys("write");

    if (n < 0)
        exit_sys("read");

    printf("%s file copied\n", argv[1]);

    close(fds);
    close(fdd);

    return 0;
}
