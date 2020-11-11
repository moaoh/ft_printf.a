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
	int d = 10;
	int one_len = 0;
	int	two_len = 0;
	char *s = "%00s";
	char *c = "hi low";
	// one_len = printf("%-05");
	// printf("%%\n");
	two_len = ft_printf("%-05");
	// printf("%%\n");
	// printf("%d, %d", one_len, two_len);

	return (0);
}
