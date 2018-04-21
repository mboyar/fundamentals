/*----------------------------------------------------------------------------------------------------------------------
    Bir sayının bitlerini ekrana basan
----------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>

/*
 * normal
 */
//void print_bits(int val)
//{
//    int i;

//    for (i = sizeof(int) * 8 - 1; i >= 0; --i)
//        putchar(((val >> i) & 1) + '0');
//}

/*
 *  recursive
 */
void print_bits(int val)
{
    if (val == 0)
        return;

    print_bits(val >> 1);
    putchar((val & 1) + '0');
}

int main(void)
{
    int val;

    printf("Bir sayı giriniz\n");
    scanf("%d", &val);

    print_bits(val);
    putchar('\n');

    return 0;
}

/*
 * note: gcc -S main.c => main.s üretir (Compile only; do not assemble or link)
 */
