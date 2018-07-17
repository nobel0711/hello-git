#include <stdio.h>
//#define CHECKING
#define N 5

int main(void)
{
        int i;
        int a[N]={1,2,3,4,5};
        int total=0;
        for(i=0; i<N; i++)
        {
                total += N;
        #ifdef CHECKING
                printf("i=%d, total=%d\n", i, total);
        #endif
        }
        printf("total=%d\n", total);
        return 0;
}
// To define the symbol CHECKING, compile the program with the command :
// gcc ifdef1.c ¡VD CHECKING

