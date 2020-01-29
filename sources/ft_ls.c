/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 12:43:24 by jfelty            #+#    #+#             */
/*   Updated: 2020/01/28 15:13:06 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
**	return 1 to send left, 0 to send right. Tree reads from left to right.
**	organizes by sort order depending on flags
*/

void		ft_ls_recur(t_lsargs *ls_args, char *currdir)
{
	struct dirent	*de;
	DIR				*dr;
	struct stat		check;
	char			*tmp;
	t_lsnode		*root;

	root = NULL;
	ft_ls(ls_args, currdir);
	dr = opendir(currdir);
	while ((de = readdir(dr)) != NULL)
	{
		tmp = full_path(de->d_name, currdir);
		lstat(tmp, &check);
		if (S_ISDIR(check.st_mode) && ft_strcmp(de->d_name, ".") && ft_strcmp(de->d_name, ".."))
			if (de->d_name[0] != '.' || ft_strchr(ls_args->flags, 'a'))
				fill_sort_tree(&root, make_node(de->d_name, currdir), \
				ls_args->flags);
		free(tmp);
	}
	print_dir_tree(root, ls_args);
	free_tree(root);
	if (dr > 0)
		closedir(dr);
}

void		ft_ls(t_lsargs *ls_args, char *currdir)
{
	struct dirent	*de;
	DIR				*dr;
	t_lsnode		*root;

	root = NULL;
	dr = opendir(currdir);
	while ((de = readdir(dr)) != NULL)
		if (de->d_name[0] != '.' || ft_strchr(ls_args->flags, 'a'))
			fill_sort_tree(&root, make_node(de->d_name, currdir), ls_args->flags);
	print_tree(root, ls_args);
	closedir(dr);
}

/*
**	parses for specified files, then directories
*/

void		ls_order(t_lsargs *ls_args)
{
	int			i;
	DIR			*dr;
	t_lsnode	*root;

	root = NULL;
	i = -1;
	while (ls_args->dirs[++i])
	{
		if (!(dr = opendir(ls_args->dirs[i])))
		{
			fill_sort_tree(&root, make_node(ls_args->dirs[i], NULL), \
			ls_args->flags);
		}
		if (dr > 0)
			closedir(dr);
	}
	if (root)
	{
		print_tree(root, ls_args);
		free_tree(root);
	}
	i = -1;
	while (ls_args->dirs[++i] && (dr = opendir(ls_args->dirs[i])))
	{
		if (ft_strchr(ls_args->flags, 'R'))
			ft_ls_recur(ls_args, ls_args->dirs[i]);
		else
			ft_ls(ls_args, ls_args->dirs[i]);
		if (ls_args->dirs[i + 1])
			ft_printf("\n\n");
		if (dr > 0)
			closedir(dr);
	}
}

void		free_ls_args(t_lsargs *ls_args)
{
	int i;

	i = -1;
	while (ls_args->dirs[++i])
		free(ls_args->dirs[i]);
	free(ls_args->dirs);
	ft_strdel(&ls_args->flags);
	free_tree(ls_args->head);
	free(ls_args);
}

int			main(int ac, char **av)
{
	t_lsargs		*ls_args;

	ls_args = parse_input(ac, av);
	ls_order(ls_args);
	free_ls_args(ls_args);
	return (0);
}
