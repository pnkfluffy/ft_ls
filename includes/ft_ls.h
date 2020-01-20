/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 12:43:09 by jfelty            #+#    #+#             */
/*   Updated: 2020/01/19 19:07:59 by jfelty           ###   ########.fr       */
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
	char			*path;
	struct stat		stat;
	int				dir;
	struct s_node	*left;
	struct s_node	*right;
}					t_lsnode;

typedef struct		s_lsargs
{
	char			*flags;
	char			**dirs;
	t_lsnode		*head;
}					t_lsargs;

#endif