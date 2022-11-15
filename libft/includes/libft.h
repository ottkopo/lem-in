/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <koykka.atte@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:35:04 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/03 17:01:14 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct s_mnode
{
	void			*content;
	size_t			content_size;
	struct s_mnode	**next;
	size_t			next_size;
}					t_mnode;

int		ft_atoi(const char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_memdel(void **ap);
void	*ft_memalloc(size_t size);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char c));
char	*ft_strmapi(const char *s, char (*f)(unsigned int i, char c));
int		ft_strequ(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
void	ft_strdel(char **as);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	**ft_strsplit(char const *s, char c);
t_list	*ft_lst_new(void const *content, size_t content_size);
void	ft_lst_add(t_list **alst, t_list *new);
void	ft_lst_iter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lst_map(t_list *lst, t_list *(*f)(t_list *elem));
void	ft_lst_del_one(t_list **head, t_list *target, \
		void (*del)(void*, size_t));
void	ft_lst_del(t_list **alst, void (*del)(void *, size_t));
size_t	ft_lst_count(t_list *start);
void	ft_lst_move_to_top(t_list **head, t_list *target);
void	ft_lst_push_top(t_list **src, t_list **dest);
t_list	*ft_lst_get_tail(t_list *head);
void	ft_lst_move_one_to_tail(t_list **head, t_list *target);
void	ft_lst_reverse(t_list **head);
void	*ft_memrcpy(void *dst, const void *src, size_t n);
char	*ft_strndup(const char *s1, size_t n);
t_list	*ft_findtail(t_list *start);
t_mnode	*ft_mnode_new(void const *content, size_t content_size);
void	ft_mnode_destroy(t_mnode **root);
void	ft_mnode_insert(t_mnode *dst, t_mnode *new_mnode);
int		*ft_invert_int_array(int *array, size_t size);
int		ft_isint(char *str);
int		ft_array_len(char **array);
void	ft_free_array(char **array);
#endif