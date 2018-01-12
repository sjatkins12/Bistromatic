#include "bistro.h"

void	read_base(char *base, t_bistro *bistro)
{
	bistro->base = ft_strdup(base);
	bistro->base_size = ft_strlen(bistro->base);
	if (bistro->base_size < 2)
		return ; //Handle Error
}

void	read_stdin(size_t exp_size, t_bistro *bistro)
{
	if (!exp_size)
		return ; //Handle Error
	if (get_next_line(0, &(bistro->exp)) != 1)
		return ; //Handle Error
	if (exp_size != ft_strlen(bistro->exp))
		return ; //Handle Error
}

void	digit_printer(char *num)
{
	char c;

	c = *num;
	ft_putchar(c);
}

void	digitizer(t_list *num)
{
	if (num->next)
		digitizer(num->next);
	digit_printer(num->content);
}
