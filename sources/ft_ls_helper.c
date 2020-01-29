/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:10:57 by jfelty            #+#    #+#             */
/*   Updated: 2020/01/28 14:12:05 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*fix_dir(char *dir)
{
	char	*tmp;
	char	*fixed_dir;

	if (ft_strchr(VALID_DIR, dir[0]) && dir[ft_strlen(dir) - 1] == '/')
		return (ft_strdup(dir));
	else
		return(ft_strjoin("./", dir));
}

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
