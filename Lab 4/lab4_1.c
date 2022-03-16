#include <stdlib.h>
#include <stdio.h>

int main()
{
	int *pt = (int *)malloc(4*sizeof(int));
	int *p = pt;

	int i;
	for(i=0;i<4;i++)
		p++;

	*p = 5;
	printf("%d\n", *p);
	free(pt);
	return 0;
}
