/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:59:23 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/11/18 23:36:15 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int nbr, int baselen, char *base, int *count)
{
	int			remainder;
	char		numtable[100];
	int			j;

	j = 0;
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
        ft_putnbr_base(nbr / baselen, baselen, base, count);
        ft_putchar(base[nbr % baselen], count);
	}
    else
        ft_putchar(base[nbr % baselen], count);
}
