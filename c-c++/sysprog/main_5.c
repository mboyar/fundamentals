/*----------------------------------------------------------------------------------------------------------------------
    read fonksiyonu ile dosyadan okuma yapılabilir
----------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE     1024

void exit_sys(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(void)
{
    int fd;
    int val;
    int n;
    int i;

    srand((unsigned int)time(NULL));

    if ((fd = open("numbers.dat", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH)) < 0)
        exit_sys("open");

    if (lseek(fd, 0, SEEK_END) < 0)
        exit_sys("lseek");


    for (i = 0; i < 10; ++i) {
        val = rand() % 100;
        if (write(fd, &val, sizeof(int)) < 0)
            exit_sys("write");
    }

    if (lseek(fd, 0, SEEK_SET) < 0)
        exit_sys("lseek");

    while ((n = read(fd, &val, sizeof(int))) > 0 && n != sizeof(int))
        printf("%d ", val);

    if (n < 0)
        exit_sys("read");

    if (n != 0) {
        fprintf(stderr, "File corrupted\n");
        exit(EXIT_FAILURE);
    }

    putchar('\n');

    close(fd);


    return 0;
}
