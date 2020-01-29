/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:08:26 by jfelty            #+#    #+#             */
/*   Updated: 2020/01/28 16:56:56 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		print_tree(t_lsnode *curr, t_lsargs *ls_args)
{
	if (!curr)
		return ;
	if (curr->left)
		print_tree(curr->left, ls_args);
	ft_printf("%s\t", curr->name);
	if (ft_strlen(curr->name) < 8)
		ft_printf("\t");
	if (curr->right)
		print_tree(curr->right, ls_args);
}

void		print_dir_tree(t_lsnode *curr, t_lsargs *ls_args)
{
	if (!curr)
		return ;
	if (curr->left)
		print_dir_tree(curr->left, ls_args);
	ft_printf("\n\n%s:\n", curr->working_dir);
	ft_ls_recur(ls_args, curr->working_dir);
	if (curr->right)
		print_dir_tree(curr->right, ls_args);
}

//WORK ON PRINT LONG, print working on symbolic links, print @ sign at the end of permissions