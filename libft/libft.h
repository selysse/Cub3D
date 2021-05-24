/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 19:23:45 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/17 15:52:46 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H

# define FT_LIBFT_H
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1024

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef	struct		s_lists
{
	int				fd;
	char			*rest;
	struct s_lists	*next;
}					t_lists;

char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_atoi(const char *nptr);
int					ft_isalnum(int c);
int					ft_isspaces(int c);
int					ft_isspace(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					is_number(char *str);
int					ft_lstsize(t_list *lst);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list				*ft_lstnew(void *content);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_space(char **line);
void				space_ut(char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strnew(size_t size);

int					get_next_line(int fd, char **line);
t_lists				*ft_add(int fd);

char				*ft_strdup_gnl(char *src);
size_t				ft_strlen_gnl(const char *s);
char				*ft_strjoin_gnl(char **s1, char *s2);

#endif
