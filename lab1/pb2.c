#include <stdio.h>

int main()
{
    int a, b;

    if(scanf("%d %d", &a, &b) == 2)
    {
        printf("%d", a + b);
    }
    return 0;
}
