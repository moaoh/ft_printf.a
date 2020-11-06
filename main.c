#include "ft_printf.h"

int		main(void)
{
	char	*f = "!c = %10c";
	char	*s = "a";

	printf(f, *s);
	printf("%%\n");
	ft_printf(f, *s);

	return (0);
}
