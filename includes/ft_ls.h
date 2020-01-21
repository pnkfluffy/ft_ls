/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 12:43:09 by jfelty            #+#    #+#             */
/*   Updated: 2020/01/20 19:23:46 by jfelty           ###   ########.fr       */
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

typedef struct		s_lsnode
{
	char			*name;
	int				is_dir;
	struct stat		stat;
	struct s_node	*left;
	struct s_node	*right;
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
**	ft_ls.c
*/

void		ft_ls(t_lsargs *ls_args, char *currdir);

#endif