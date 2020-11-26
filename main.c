#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int i = -24;
//	printf("%-2.3d\n", i);
	printf("-015p", &i);
	return (0);
}