/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_end.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 19:00:48 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/12 14:34:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_end(char const *s)
{
	int	end;

	end = ft_strlen(s);
	while (end > 0 && (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] \
		== '\t'))
		end--;
	return (end);
}
