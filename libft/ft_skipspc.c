/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_skipspc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 22:23:09 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/12 14:34:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_skipspc(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		++i;
	return (i);
}
