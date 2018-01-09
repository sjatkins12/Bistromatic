#ifndef BISTRO_H

# define BISTRO_H

typedef struct		s_btree
{
	void			*data;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

typedef struct	s_bistro
{
	char		*base;
	int			base_size;
	char		*exp;
	int			exp_size;
	t_btree		*tree;
}				t_bistro;

#endif