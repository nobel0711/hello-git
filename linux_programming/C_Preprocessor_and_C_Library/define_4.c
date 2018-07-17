#include <stdio.h>
#define XNAME(n) x##n
#define PRINT_XN(n) printf("x" #n " is %d\n", x##n);
int main(void)
{
        int XNAME(1) = 14;
        int XNAME(2) = 20;
        PRINT_XN(1);
        PRINT_XN(2);
        x2 = x1+20;
        PRINT_XN(2);
        return 0;
}

