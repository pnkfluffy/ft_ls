/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:24:48 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:22:29 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"

/*
**		ascii
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isspace(int c);

/*
**		strings
*/

size_t				ft_strlen(const char *src);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *source);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *str, const char *substr);
char				*ft_strnstr(const char *str, const char *substr, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strnew(size_t len);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					ft_wordcount(char const *s, char c);
int					get_next_line(int const fd, char **line);
char				*ft_push_to_str_front(char *str, char c);
int					ft_strnchr(const char *str, int c);
char				*ft_replacechr(char *s, char old, char new);
char				*ft_fillstrnew(int width, char fill);
char				*ft_strrev(char *str);

/*
**		conversions
*/

int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_lltoa_base(int64_t n, int base, int return_upper);
char				*ft_ulltoa_base(uint64_t n, int base, int return_upper);
int					ft_atoi_base(const char *str, int str_base);
char				*ft_itoa_base(int n, int base, int return_upper);

/*
**		memory
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t n);
void				ft_memdel(void **ap);

/*
**		print
*/

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
**		numbers
*/

int					ft_numlen(int n);
int					ft_isneg(int64_t a);
int					ft_largest_int(int a, int b);
int64_t				ft_makepos(int64_t a);
int					ft_getnxtnbr(char *str, char c);
int					ft_power(int nb, int power);
double				ft_dblpower(double num, int pow);

#endif
