#include <stdio.h>

#include "stack.h"

int main(void)
{
    Stack s;
    initStack(&s);

    // program utama
    int n = 0;
    printf("INput angka yang akan diconvert menjadi binary: ");
    scanf("%d", &n);

    while (n != 0)
    {
        push(&s, n % 2);
        n  = n / 2;
    }

    // tampilkan
    while (!isEmpty(&s))
    {
        printf("%d ", pop(&s));
    }
    printf("\n");
    return 0;
}