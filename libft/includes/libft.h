/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 18:39:18 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/16 19:58:48 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf.h"

# define BUFF_SIZE			1000
# define MAX_MALLOC_SIZE	2147483424
# define FORMAT_LEFT		"%-*s"
# define FORMAT_RIGHT		"%+*s"

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_adlist
{
	void			*address;
	struct s_adlist	*next;
}					t_adlist;

typedef struct		s_elem
{
	size_t			index;
	char			*name;
	size_t			hash;
	t_adlist		*body_content;
	t_list			*misc;
	void			*content;
}					t_elem;

typedef struct		s_hash_table
{
	char			*title;
	char			*format;
	t_list			*header_format;
	t_list			*header_content;
	t_list			*body_format;
	t_adlist		*width;
	size_t			size;
	char			mounted;
	t_elem			**elem;
}					t_hash_table;

size_t				ft_abs(int nb);
void				ft_addr_lstadd(t_adlist **alst, t_adlist *newlst);
void				ft_addr_lstapp(t_adlist **alst, t_adlist *newlst);
void				ft_addr_lstdel(t_adlist **alst);
void				ft_addr_lstdelone(t_adlist **alst);
void				ft_addr_lstiter(t_adlist *lst, void (*f)(t_adlist *elem));
t_adlist			*ft_addr_lstnew(void *address);
t_adlist			*ft_addr_lstrev(t_adlist *alst);
void				ft_addr_lstsrt(t_adlist **alst, \
					int (*method)(void *, void *));
char				*ft_append(char **str, char const *append);
size_t				ft_arsize(void **ar);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				ft_delnode(void *content, size_t content_size);
int					ft_end(char const *s);
void				ft_freezero(void *mem, size_t size);
void				ft_free_hash_table(t_hash_table **table, \
					void (*free_cont)(void *));
int					ft_get_next_line(const int fd, char **line);
size_t				ft_hash(char *key);
t_elem				*ft_hash_table_add(t_hash_table *hash_table, char *key, \
					void *content);
void				*ft_hash_table_append(t_hash_table *table, \
					void *(*columns)(t_hash_table *table));
void				*ft_hash_table_drop(t_hash_table *table, size_t cutoff);
t_elem				*ft_hash_table_get(t_hash_table *hash_table, char *key);
void				*ft_hash_table_print(t_hash_table *table, \
					void *(*columns)(t_hash_table *table));
void				*ft_hash_table_update(t_hash_table *table, \
					void *(*columns)(t_hash_table *table));
t_list				**ft_hsh_chain(void **ar, size_t size, \
					size_t hsh(void *));
t_list				**ft_hsh_linprob(void **ar, size_t size, \
					size_t hsh(void *));
t_list				**ft_hsh_quadprob(void **ar, size_t size, \
					size_t hsh(void *));
char				*ft_insert(char **str, char const *insert, size_t pos);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprime(size_t prime);
int					ft_isprint(int c);
int					ft_isprior(char *str, char prior, char rival);
int					ft_isupper(int c);
char				*ft_itoa(int n);
char				*ft_itoa_base(unsigned long long value, int base);
char				*ft_itoa_long(long long n);
void				ft_lstapp(t_list **alst, t_list *newlst);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstunlink(t_list **head, t_list *lst);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstfind_size(t_list *head, size_t size);
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstrev(t_list *alst);
t_hash_table		*ft_malloc_hash_table(size_t size, char *title, \
					char *format);
void				**ft_mem_array_alloc(size_t x_dim, size_t size_x,
					size_t size_y);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_nchar(const char *str, int c);
size_t				ft_ndigits(long long nbr);
double				ft_power(int nb, int b);
char				*ft_prepend(char **str, char const *prepend);
int					ft_dprintf(const int fd, const char *format, ...);
size_t				*ft_primetab(size_t n);
int					ft_printf(const char *format, ...);
void				ft_putadlst(t_adlist *lst, char *(*content)(void *item), \
					char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putnchar(char const *c, size_t len);
void				ft_putnchar_fd(const int fd, char const *c, size_t len);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putlst(t_list *lst, char *str);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putnstr(char const *str, size_t len);
void				ft_putnstr_fd(const int fd, char const *str, size_t len);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putstr(const char *str);
void				ft_putstrarr(const char **array);
void				ft_puttbl(t_hash_table *table);
char				*ft_replace(char **str, char const *insert, size_t pos, \
					size_t len);
char				*ft_select(char **str, size_t pos, size_t len);
void				ft_skip_line(char **str);
void				ft_strarrdel(char ***array, size_t size_x);
size_t				ft_strarrlen(const char **array);
char				*ft_strcalc_add(char **nb, const char *s2);
char				*ft_strcalc_mult(char **nb);
char				*ft_strcalc_div(char **nb);
char				*ft_strcalc_multexptwo(char **nb, int exponent);
int					ft_strcalc_valid(char *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcdup(const char *str, int c);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcpy_newline(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_stricdup(const char *str, int c);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strlwr(char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strndup(const char *src, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char
					*needle, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strnewfill(size_t len, char c);
char				**ft_strnsplit(char const *s, char c, size_t size);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strupr(char *s);
char				*ft_strtrim(char const *s);
void				ft_swap(void **ptr1, void **ptr2);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strcmp_delim(const char *s1, const char *s2, int c);
#endif
