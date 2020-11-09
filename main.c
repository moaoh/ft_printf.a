#include "ft_printf.h"


// %0-10.0d"
// "%10.d"
int		main(void)
{
	char	*f = "%-10c";
	char	c = '\0';
	int		printf_len;
	int		ft_printf_len;
	int		a =	123;

	printf("format = %s , %d", f, c);
	printf("\n------------------------\n");
	printf("printf : \n");
	printf_len = printf(f, c);
	printf("%%\n\n");
	printf("printf_len = %d\n", printf_len);
	printf("\n------------------------\n");
	printf("ft_printf : \n");
	ft_printf_len = ft_printf(f, c);
	printf("%%\n\n");
	printf("ft_printf_len = %d\n", ft_printf_len);

	return (0);
}
