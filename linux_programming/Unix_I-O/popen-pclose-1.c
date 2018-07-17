#include <stdio.h>
#define N 32
int main(void)
{
	char szdate[N];
	FILE *pf = popen("date", "r");
	if(pf && fgets(szdate, N, pf))
	{
		fputs(szdate, stdout);
		pclose(pf);
		return 0;
	}
	return 1;
}

