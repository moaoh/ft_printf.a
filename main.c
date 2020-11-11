#include "ft_printf.h"
/*
width

%07d , -54
>>"-000054"
%08.5d , 34
>>"   00034"
*/
int		main(void)
{
	int d = 0;
	char *s = "%5.0d";
	printf(s, d);
	printf("%%\n");
	ft_printf(s, d);

	return (0);
}
