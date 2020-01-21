/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 12:43:24 by jfelty            #+#    #+#             */
/*   Updated: 2020/01/20 19:22:06 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	t_lsargs		*ls_args;
	struct dirent	*de;
	DIR				*dr;
	int 			i;

	i = -1;
	if (ac == 0)
		return (0);
	ls_args = parse_input(ac, av);

	if (!ls_args->dirs[0])
		return (0);
	while (ls_args->dirs[++i])
		ft_ls(ls_args, ls_args->dirs[i]);

	return (0);
}

void		print_sort()
{
	
}

void		fill_tree()
{
	
}

t_lsnode	*make_node()
{
	
}

void	ft_ls(t_lsargs *ls_args, char *currdir)
{
	struct dirent	*de;
	DIR				*dr;
	t_lsnode		*root;

	dr = opendir(currdir);
	while ((de = readdir(dr)) != NULL)
	{
		fill_tree(&root, make_node(de));
		printf("%s\n", de->d_name);
	}
	print_sort(root, ls_args);
	closedir(dr);
}