#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

void exitsys(const char *msg);
int main(int argc, char *argv[])
{
    int fd;
    char *str;
    int i;
    if ((fd = open("test.txt", O_RDWR)) < 0)
        exitsys("open");
    if ((str = (char *)mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == NULL)
        exitsys("mmap");
    for (i = 0; i < 20; ++i)
        putchar(str[i]);
    putchar('\n');
    memcpy(str, "ankara", 8);
    munmap(str, 4096);
    close(fd);
    return 0;
}

void exitsys(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}
