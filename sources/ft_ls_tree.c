/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:57:29 by jfelty            #+#    #+#             */
/*   Updated: 2020/01/28 16:30:01 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		free_tree(t_lsnode *curr)
{
    if (!curr)
        return ;
	if (curr->left)
		free_tree(curr->left);
	if (curr->right)
		free_tree(curr->right);
	ft_strdel(&curr->name);
	ft_strdel(&curr->working_dir);
	free(curr);
}

int	        sort_compare(t_lsnode *parent, t_lsnode *new, char *flags)
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
	if (currdir)
		lsnode->working_dir = full_path(lsnode->name, currdir);
	else
		lsnode->working_dir = ft_strdup(de_name);
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