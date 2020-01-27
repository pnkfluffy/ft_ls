/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 12:43:24 by jfelty            #+#    #+#             */
/*   Updated: 2020/01/26 20:00:52 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*full_path(char *file_name, char *working_dir)
{
	char	*full_path;
	char	*tmp;

	if (working_dir[ft_strlen(working_dir) - 1] != '/')
	{
		tmp = ft_strjoin(working_dir, "/");
		full_path = ft_strjoin(tmp, file_name);
		free(tmp);
		return (full_path);
	}
	full_path = ft_strjoin(working_dir, file_name);
	return (full_path);
}

void		print_tree(t_lsnode *curr, t_lsargs *ls_args)
{
	if (curr->left)
		print_tree(curr->left, ls_args);
	ft_printf("%s\t", curr->name);
	if (ft_strlen(curr->name) < 8)
		ft_printf("\t");
	if (curr->right)
		print_tree(curr->right, ls_args);
}

/*
**	return 1 to send left, 0 to send right. Tree reads from left to right
*/

int	sort_compare(t_lsnode *parent, t_lsnode *new, char *flags)
{
	int		reverse;

	reverse = ft_strchr(flags, 'r') ? 1 : 0;
	if (ft_strchr(flags, 't'))
	{
		if (new->lstat.st_mtime > parent->lstat.st_mtime)
			return (reverse ? 0 : 1);
		else
			return (reverse ? 1 : 0);
	}
	else
	{
		if (ft_strcmp(new->name, parent->name) < 0)
			return (reverse ? 0 : 1);
		else
			return (reverse ? 1 : 0);
	}
}

void		fill_sort_tree(t_lsnode **root, t_lsnode *new, char *flags)
{
	if (!(*root))
	{
		*root = new;
		return ;
	}
	if (sort_compare(*root, new, flags))
		fill_sort_tree(&((*root)->left), new, flags);
	else
		fill_sort_tree(&((*root)->right), new, flags);
}

t_lsnode	*make_node(char *de_name, char *currdir)
{
	t_lsnode	*lsnode;

	if (!(lsnode = (t_lsnode *)malloc(sizeof(t_lsnode))))
		return (NULL);
	lsnode->name = ft_strdup(de_name);
	lsnode->working_dir = full_path(lsnode->name, currdir);
	if (lstat(lsnode->working_dir, &lsnode->lstat) == -1)
	{
		perror("lstat error");
		exit(EXIT_FAILURE);
	}
	lsnode->is_dir = S_ISDIR(lsnode->lstat.st_mode) ? 1 : 0;
	lsnode->left = 0;
	lsnode->right = 0;
	return (lsnode);
}

void	ft_ls(t_lsargs *ls_args, char *currdir)
{
	struct dirent	*de;
	DIR				*dr;
	t_lsnode		*root;

	root = NULL;
	if (!(dr = opendir(currdir)))
	{
		print_tree(make_node(&currdir[2], "./"), ls_args);
		return ;
	}
	while ((de = readdir(dr)) != NULL)
		fill_sort_tree(&root, make_node(de->d_name, currdir), ls_args->flags);
	print_tree(root, ls_args);
	// if (ft_strchr(ls_args->flags, 'R'))
	// 	ft_ls_R(ls_args, currdir);
	closedir(dr);
}

int		main(int ac, char **av)
{
	t_lsargs		*ls_args;
	struct dirent	*de;
	DIR				*dr;
	int				i;

	i = -1;
	if (ac == 0)
		return (0);
	ls_args = parse_input(ac, av);

	while (ls_args->dirs[++i])
	{
		ft_ls(ls_args, ls_args->dirs[i]);
		if (ls_args->dirs[i + 1])
			ft_printf("\n\n");
	}
	return (0);
}
