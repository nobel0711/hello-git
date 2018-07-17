#include <stdio.h>
//#define SQUARE(X) X*X
#define SQUARE(X) ((X)*(X))
#define PR(X) printf("The result is %d\n", X)
int main(void)
{
        int x = 4;
        int z;
        printf("x = %d\n", x);
        z = SQUARE(x);
        printf("SQUARE(x) : ");
        PR(z);
        z = SQUARE(2);
        printf("SQUARE(2) : ");
        PR(z);
        printf("SQUARE(x+2) : ");
        PR(SQUARE(x+2));
        printf("100/SQUARE(2) : ");
        PR(100/SQUARE(2));
        printf("x = %d\n", x);
        printf("SQUARE(x++) : ");
        PR(SQUARE(x++));
        printf("After x++, x is %d\n", x);
        return 0;
}

