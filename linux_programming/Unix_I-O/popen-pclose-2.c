#include <stdio.h>
#define N 1024
int main(void)
{
        char szdate[N];
        FILE *pf=fopen("a.c", "r");
        fread(szdate, sizeof(char), N, pf);
        pf=popen("grep pf", "w");
        if(pf && fputs(szdate, pf))
        {
                pclose(pf);
                return 0;
        }
        return 1;
}

