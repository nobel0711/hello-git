#include <stdio.h>
inline int squarein(int x)
{
        return x*x;
}
int main(void)
{
        int x=20;
        printf("x*x = %d\n", squarein(x));
        return 0;
}

