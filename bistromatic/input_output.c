#include "bistro.h"

void	read_base(char *base, t_bistro *bistro)
{
	bistro->base = ft_strdup(base);
	bistro->base_size = ft_strlen(bistro->base);
	if (bistro->base_size < 2)
		return ; //Handle Error
}

void	read_stdin(int exp_size, t_bistro *bistro)
{
	if (!exp_size)
		return ; //Handle Error
	if (get_next_line(0, &(bistro->exp)) != 1)
		return ; //Handle Error
	if (exp_size != ft_strlen(bistro->exp))
		return ; //Handle Error
}

void	digitizer(int num, t_bistro *bistro)
{
	if (num >= bistro->base_size)
		digitizer(num / bistro->base_size, bistro);
	digit_printer(num % bistro->base_size, bistro);
}

void	digit_printer(int num, t_bistro *bistro)
{
	ft_putchar(bistro->base[num]);
}