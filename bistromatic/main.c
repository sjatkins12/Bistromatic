#include "bistro.h"

int	main(int argc, char **argv)
{
	t_bistro	*bistro;
	int			result;

	bistro = ft_memalloc(sizeof(t_bistro));
	if (!bistro || argc != 3)
		return (0);
	read_base(argv[1], bistro);
	read_stdin(ft_atoi(argv[2]), bistro);
	//create_btree(bistro);
	//result = eval_btree(bistro);
	digitizer(result, bistro);
	return (0);
}
