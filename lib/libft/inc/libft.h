/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:10:10 by jzeybel           #+#    #+#             */
/*   Updated: 2021/04/21 19:12:58 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef FD
#  define FD 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define ABS(value) (value > 0) ? value : -value
# define SIGN(value) (value > 0) ? 1 : -1
typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void	*data);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void*));
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void    			ft_lstprint(t_list *lst);
void				ft_del(void *data);
int					ft_lstlencmp(t_list *lst);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t 				ft_tablen(char **tab);
void    			ft_free(void **data);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isrange(int i, int e, int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_ischarset(char c, char const *s);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_issetdiff(char *s, char *set, int len);

char				*ft_strchr(const char *s, int c);
int					ft_strchri(char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strnstr(const char *big, const char *find, size_t len);
long long			ft_atoll(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);

int					get_next_line(int fd, char **line);
int					ft_getdelim(int fd, char **line, int delim);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_substrfree(char *s, size_t start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char *s1, char *s2);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(long long int n, int fd);
void				ft_putbase_fd(unsigned long n, char *base, \
						size_t size, int fd);
char				*ft_foreach(char const *s, char (*f)(unsigned int, char));
char				*ft_lltoa(long long n);
char				*ft_ulltoa_base(unsigned long long n, char *base);
char				**ft_split(char const *s, char *c);
size_t 				ft_freetab(char **tab, size_t size);

long				ft_pow(int base, int exponent);
#endif
