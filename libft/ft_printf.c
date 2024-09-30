/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:08:07 by goolivei          #+#    #+#             */
/*   Updated: 2023/11/20 12:08:09 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	formats(va_list args, const char key)
{
	int	printlen;

	printlen = 0;
	if (key == 'c')
		printlen += ft_print_char(va_arg(args, int));
	else if (key == 's')
		printlen += ft_print_str(va_arg(args, char *));
	else if (key == 'p')
		printlen += ft_print_ptr(va_arg(args, unsigned long long));
	else if (key == 'd' || key == 'i')
		printlen += ft_print_nbr(va_arg(args, int));
	else if (key == 'u')
		printlen += ft_print_unsigned(va_arg(args, unsigned int));
	else if (key == 'x' || key == 'X')
		printlen += ft_print_hex(va_arg(args, unsigned int), key);
	else if (key == '%')
		printlen += ft_print_percent();
	return (printlen); 
}

int	ft_printf(const char *sentence, ...)
{
	int		i;
	va_list	args;
	int		printlen;

	i = 0;
	printlen = 0;
	va_start(args, sentence);
	while (sentence[i])
	{
		if (sentence[i] == '%')
		{
			printlen += formats(args, sentence[i + 1]);
			i++;
		}
		else
			printlen += ft_print_char(sentence[i]);
		i++;
	}
	va_end(args);
	return (printlen);
}
