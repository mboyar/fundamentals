/*----------------------------------------------------------------------------------------------------------------------
    Yazıyı tersine çeviren fonksiyon
----------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

static void mystrrev_recur(char *str, size_t left, size_t right)
{
    char temp;

    if (left >= right)
        return;

    temp = str[right];
    str[right] = str[left];
    str[left] = temp;

    mystrrev_recur(str, ++left, --right);
}

void mystrrev(char *str)
{
    mystrrev_recur(str, 0, strlen(str) - 1);
}



int main(void)
{
    char str[] = "ankara";

    mystrrev(str);
    puts(str);

    return 0;
}
