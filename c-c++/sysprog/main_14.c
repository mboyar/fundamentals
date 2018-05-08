///* process1.c */
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <fcntl.h>
//#include <unistd.h>
//#include <sys/stat.h>
//#include <sys/mman.h>


//void exit_sys(const char *msg);
//int main(void)
//{
//    int fd;
//    char *addr;
//    char buf[4096 - 1];
//    if ((fd = shm_open("/ThisIsATeest", O_CREAT|O_RDWR,
//                       S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)) < 0)
//        exit_sys("shm_open");
//    if (ftruncate(fd, 4096) < 0)
//        exit_sys("ftruncate");
//    if ((addr = (char *)mmap(NULL, 4096, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED)
//        exit_sys("mmap");
//    printf("Enter text:");
//    gets(buf);
//    strcpy(addr, buf);
//    printf("Press ENTER to exit!\n");
//    getchar();
//    munmap(addr, 4096);
//    close(fd);
//    return 0;
//}
//void exit_sys(const char *msg)
//{
//    perror(msg);
//    exit(EXIT_FAILURE);
//}

/* process2.c */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

void exit_sys(const char *msg);
int main(void)
{
    int fd;
    char *addr;
    if ((fd = shm_open("/ThisIsATeest", O_CREAT | O_RDWR,
                       S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
        exit_sys("shm_open");
    if (ftruncate(fd, 4096) < 0)
        exit_sys("ftruncate");
    if ((addr = (char *)mmap(NULL, 4096, PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED)
        exit_sys("ftruncate");
    printf("Press ENTER to read from shared memory!\n");
    getchar();
    puts(addr);
    printf("Press ENTER to exit!\n");
    getchar();
    munmap(addr, 4096);
    close(fd);
    return 0;
}
void exit_sys(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

