#include <stdio.h>

/*
 *  thx to:
 *      https://gcc.gnu.org/onlinedocs/gcc-4.7.0/gcc/Function-Attributes.html
 *      https://stackoverflow.com/questions/2053029/how-exactly-does-attribute-constructor-work
 *      https://askubuntu.com/questions/277288/dlclose-does-not-call-library-destructors-dlopen-called-just-once
 */

void cConstructor(void);
void cDestructor(void);

int main()
{
    /*
     * you can call con/dest c funcs seperatly
     */
    //x_fini();
    printf("Hello World!\n");
    return 0;
}

void __attribute__((constructor)) cConstructor(void)
{
    printf("%s is called\n", __FUNCTION__);
}

void __attribute__((destructor)) cDestructor(void)
{
    printf("%s is called\n", __FUNCTION__);
}
