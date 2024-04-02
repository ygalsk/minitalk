/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:28:54 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/16 15:17:28 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// CHAR FUNCTIONS

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int a);
int		ft_isdigit(int i);
int		ft_isprint(int p);
int		ft_tolower(int c);
int		ft_toupper(int c);

// MEMORY FUNCTIONS

void	*ft_memset(void *ptr, int value, size_t num);
void	ft_bzero(void *s, unsigned int n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, unsigned int len);
void	*ft_memchr(const void *s, int c, unsigned int n);
int		ft_memcmp(const void *s1, const void *s2, unsigned int n);
void	*ft_calloc(size_t count, size_t size);

// STRING FUNCTIONS

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *hay, const char *nee, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// FD FUNCTIONS

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// CONVERSION FUNCTIONS

int		ft_atoi(const char *str);
char	*ft_itoa(long n);

// GET NEXT LINE FUNCTIONS

int		ft_len_nl(char *str);
char	*read_line(int fd, char *nx_line);
char	*ft_nx_line(char *nx_line);
char	*ft_leftover(char *nx_line);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *save, char *buf);

// PRINTF FUNCTIONS

int		ft_printf_char(int c);
int		ft_printf_formats(char str, va_list args);
int		ft_printf(const char *str, ...);
int		ft_printf_p(unsigned long long n);
int		ft_printf_dec(long i);
int		ft_printf_s(char *str);
int		ft_printf_hex(unsigned long i);
int		ft_hex_low(unsigned long i);
int		ft_hex_up(unsigned long i);

#endif
