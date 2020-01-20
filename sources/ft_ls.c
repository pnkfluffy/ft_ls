/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 12:43:24 by jfelty            #+#    #+#             */
/*   Updated: 2020/01/19 19:20:23 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		**add_dirs(int i, int ac, char **av)
{
	int			dir_num;
	char		**dirs;

	dirs = malloc(sizeof(ac - i));
	dir_num = 0;
	while (i < ac)
	{
		dirs[dir_num] = ft_strdup(av[i]);
		i++;
		dir_num++;
	}
	return (dirs);
}

void		ft_straddflag(char *flags, char flag)
{
	int i;

	i = -1;
	if (ft_strchr(flags, flag))
		return ;
	while (flags[++i])
		;
	flags[i] = flag;
}

void		parse_flags(char *flags, char *arg)
{
	int		i;

	i = 0;
	while (arg[++i])
	{
		if (ft_strchr(LS_FLAGS, arg[i]))
			ft_straddflag(flags, arg[i]);
		else
			perror("invalid flags");
	}
}

t_lsargs	*parse_input(int ac, char **av)
{
	t_lsargs		*ls_args;
	int				i;
	int				done_flags;

	i = 1;
	done_flags = 0;
	ls_args = malloc(sizeof(t_lsargs));
	ls_args->flags = ft_strnew(ft_strlen(LS_FLAGS));

	while (i < ac && av[i][0] == '-')
	{
		parse_flags(ls_args->flags, av[i]);
		i++;
	}
	ls_args->dirs = (i < ac) ? add_dirs(i, ac, av) : NULL;
	return (ls_args);
}

int		main(int ac, char **av)
{
	t_lsargs		*ls_args;
	struct dirent	*de;
	DIR				*dr;

	if (ac == 0)
		return (0);
	ls_args = parse_input(ac, av);

	dr = opendir("../");
	if (dr == NULL)
	{
		printf("Error loading current directory");
		return (0);
	}
	while ((de = readdir(dr)) != NULL)
		printf("%s\n", de->d_name);
	closedir(dr);
	return (0);
}