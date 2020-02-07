/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_next_line.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 14:28:17 by mgross         #+#    #+#                */
/*   Updated: 2020/01/17 16:56:30 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function frees the content of an element of the list
*/

static void		ft_lstfree(t_list *lst)
{
	free(lst->content);
	lst->content = NULL;
}

/*
** This function first searches for a list with fd in it. If he doesn't find fd
** in any list it will create a new list which will be added to the begin of the
** list and returns 0.If he finds a list with fd it will check if there is a
** '\n' in the content. If so it creates a new string up to '\n' and points line
** to it and returnes 1. Then it checkes if the rest of the string is empty.
** If so it free's the memory and points the pointer to NULL.
*/

static int		ft_newline_list(t_list **head, int fd, char **line)
{
	t_list	*temp;
	char	*replace;

	temp = ft_lstfind_size(*head, fd);
	if (temp == NULL)
	{
		temp = ft_lstnew(temp, 0);
		temp->content_size = fd;
		ft_lstadd(head, temp);
	}
	else
	{
		if (ft_nchar(temp->content, '\n') != 0)
		{
			*line = ft_strcdup(temp->content, '\n');
			replace = temp->content;
			temp->content = ft_strdup(temp->content +
			(ft_nchar(temp->content, '\n')));
			free(replace);
			if (*((char*)temp->content) == '\0')
				ft_lstfree(temp);
			return (1);
		}
	}
	return (0);
}

/*
** This function gets a list element plus the string from read. It joins the
** rest of what's left inside the element with the new string, then checks if
** there's an '\n' in the string and points *line to either all of *new or only
** part of it and stores the rest in the element.
*/

static void		ft_point_line(t_list *lst, char *str, char **line)
{
	char	*new;

	new = ft_strjoin(lst->content, str);
	ft_strdel(&str);
	if (ft_nchar(new, '\n') == 0)
	{
		*line = ft_strdup(new);
		ft_lstfree(lst);
	}
	else
	{
		*line = ft_strcdup(new, '\n');
		str = lst->content;
		lst->content = ft_strdup(new + (ft_nchar(new, '\n')));
		if (*((char*)lst->content) == '\0')
			ft_lstfree(lst);
	}
	free(new);
	free(str);
}

/*
** This functions first finds *list with fd in it. I checks if there is a '\n'
** and content == NULL and *str is not empty it points the line to *str.
** Otherwise it unlinks the element and returns 0. If there the content == NULL
** but there is a '\n' in str, it points line. content != Null it calls the
** function ft_point_line.
*/

static int		ft_str_lst(t_list **head, char *str, int fd, char **line)
{
	t_list	*lst;

	lst = ft_lstfind_size(*head, fd);
	if (ft_nchar(str, '\n') == 0 && lst->content == NULL)
	{
		if (*str != '\0')
		{
			*line = ft_strdup(str);
			return (1);
		}
		ft_lstunlink(head, lst);
		free(str);
		return (0);
	}
	if (lst->content == NULL)
	{
		*line = ft_strcdup(str, '\n');
		lst->content = ft_strdup(str + (ft_nchar(str, '\n')));
		free(str);
		if (*((char*)lst->content) == '\0')
			ft_lstfree(lst);
	}
	else
		ft_point_line(lst, str, line);
	return (1);
}

/*
** This function gets the fd and *line, reads from the fd into string new until
** ret from read is 0 or until a '\n' is found in what has been read. The it
** calls the function ft_str_lst and sends the string from read to it. The
** return value from the function will be returned.
*/

int				ft_get_next_line(const int fd, char **line)
{
	static	t_list	*head;
	char			*new;
	char			*temp;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	buf[0] = '\0';
	ret = 1;
	if (ft_newline_list(&head, fd, line) == 1)
		return (1);
	new = ft_strnew(0);
	while (ret != 0 && ft_nchar(buf, '\n') == 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
		{
			free(new);
			return (-1);
		}
		buf[ret] = '\0';
		temp = new;
		new = ft_strjoin(new, buf);
		free(temp);
	}
	return (ft_str_lst(&head, new, fd, line));
}
