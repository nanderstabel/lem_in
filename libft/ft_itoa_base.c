/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 12:33:09 by nstabel       #+#    #+#                 */
/*   Updated: 2019/04/29 12:53:34 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long long value, int base)
{
	char				*s;
	char				*hex;
	unsigned long long	tmp;
	int					i;

	i = 1;
	hex = "0123456789abcdef";
	tmp = value;
	while (tmp /= base)
		i++;
	s = (char *)malloc(sizeof(char) * i + 1);
	if (s == NULL)
		return (NULL);
	s[i] = 0;
	if (value == 0)
		s[0] = '0';
	while (value)
	{
		i--;
		s[i] = hex[value % base];
		value /= base;
	}
	return (s);
}
