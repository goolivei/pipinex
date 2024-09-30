/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:21:43 by goolivei          #+#    #+#             */
/*   Updated: 2023/11/22 14:21:45 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
	else
		ft_print_char(n + '0');
}

int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 1;
	ft_putnbr_u(n);
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}
