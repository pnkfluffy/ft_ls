/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 12:43:09 by jfelty            #+#    #+#             */
/*   Updated: 2020/01/28 12:08:21 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <errno.h>
# include <stdint.h>
# include <limits.h>
# include <stdio.h>
# include "../sources/libft/libft.h"

# define LS_FLAGS "lRart"
# define VALID_DIR "~./"

typedef struct		s_lsnode
{
	char			*name;
	char			*working_dir;
	int				is_dir;
	struct stat		lstat;
	struct s_lsnode	*left;
	struct s_lsnode	*right;
}					t_lsnode;

typedef struct		s_lsargs
{
	char			*flags;
	char			**dirs;
	t_lsnode		*head;
}					t_lsargs;

/*
**	parse_arguments.c
*/

int			valid_dir(char *dir_add);
char		**add_dirs(int i, int ac, char **av);
void		ft_straddflag(char *flags, char flag);
void		parse_flags(char *flags, char *arg);
t_lsargs	*parse_input(int ac, char **av);

/*
**	ft_ls_h.c
*/

void		free_tree(t_lsnode *curr);
void		print_tree(t_lsnode *curr, t_lsargs *ls_args);
int			sort_compare(t_lsnode *parent, t_lsnode *new, char *flags);
void		fill_sort_tree(t_lsnode **root, t_lsnode *new, char *flags);
t_lsnode	*make_node(char *de_name, char *currdir);


/*
**	ft_ls.c
*/

void		ft_ls(t_lsargs *ls_args, char *currdir);
void		ft_ls_R(t_lsargs *ls_args, char *currdir);
void		ls_order(t_lsargs *ls_args);

char		*full_path(char *file_name, char *working_dir);

#endif