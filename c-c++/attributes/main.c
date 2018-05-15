#include <stdio.h>

int __attribute__((constructor)) x_init(void)
{
    puts("init() works");
    return 0;
}

int __attribute__((destructor)) x_fini(void)
{
    puts("fini() works");
    return 0;
}

int main()
{
    printf("Hello World!\n");
    return 0;
}
