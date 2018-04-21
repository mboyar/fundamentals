/*
 *int al char bas  - özyinelemeli
 */

#include <stdio.h>

void put_num(int val)
{
    if (val < 0) {
        putchar('-');
        val = -val;
    }

    if (val / 10)
        put_num(val / 10);

    putchar(val % 10 + '0');
}

int main(void)
{
    int val;

    printf("Bir sayı giriniz\n");
    scanf("%d", &val);

    put_num(val);
    putchar('\n');


    return 0;
}
