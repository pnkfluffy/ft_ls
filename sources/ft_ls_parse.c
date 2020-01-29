/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:39:35 by jfelty            #+#    #+#             */
/*   Updated: 2020/01/28 14:11:13 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			valid_dir(char *dir_add)
{
	DIR			*dr;
	struct stat	check;

	if (!(dr = opendir(dir_add)))
	{
		if (lstat(dir_add, &check) == -1)
		{
			ft_printf("ls: %s: No such file or directory\n", dir_add);
			return (0);
		}
	}
	if (dr > 0)
		closedir(dr);
	return (1);
}

/*
**	calculates the total number of directories, gives error message if
**	invalid directory, and fills rest of directory array with NULL
*/

char		**add_dirs(int i, int ac, char **av)
{
	int			dir_num;
	char		**dirs;
	int			total_dirs;
	char		*fixed_dir;

	total_dirs = ac - i;
	if (i == ac)
	{
		dirs = (char **)malloc(sizeof(char *) * 2);
		dirs[0] = ft_strdup("./");
		dirs[1] = NULL;
		return (dirs);
	}
	dirs = (char **)malloc(sizeof(char *) * (total_dirs) + 1);
	dir_num = -1;
	while (i < ac)
	{
		fixed_dir = fix_dir(av[i]);
		if (valid_dir(fixed_dir))
			dirs[++dir_num] = fixed_dir;
		i++;
	}
	while (dir_num < total_dirs)
		dirs[++dir_num] = NULL;
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
		{
			perror("invalid flags");
			exit(EXIT_FAILURE);
		}
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
	ls_args->dirs = add_dirs(i, ac, av);
	return (ls_args);
}
