#include "ft_printf.h"

int		main(void)
{
	char	*f = "%u";
	char	*s = "";
	int		printf_len;
	int		ft_printf_len;
	int		a =	-320;

	printf("format = %s , %d", f, a);
	printf("\n------------------------\n");
	printf("printf : \n");
	printf_len = printf(f, a);
	printf("%%\n\n");
	printf("printf_len = %d\n", printf_len);
	printf("\n------------------------\n");
	printf("ft_printf : \n");
	ft_printf_len = ft_printf(f, a);
	printf("%%\n\n");
	printf("ft_printf_len = %d\n", ft_printf_len);

	return (0);
}
