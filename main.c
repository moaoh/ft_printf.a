#include "ft_printf.h"

int		main(void)
{
	char	*f = "!c = %10c";
	char	*s = "a";
	char	x[2] = "a";
	printf("%%");
	// printf("%%\n");
	ft_printf("%%");

	// printf(f, *s);
	// printf("\n");
	// ft_printf(f, *s);

	// x[0] != s

	return (0);
}
