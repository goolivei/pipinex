/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:25:26 by goolivei          #+#    #+#             */
/*   Updated: 2023/10/23 15:25:44 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			len;
	const char	*nmrs;

	len = ft_len(n);
	result = malloc(sizeof(char) * (len + 1));
	nmrs = "0123456789";
	if (!result)
		return (0);
	result[len] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	while (n)
	{
		if (n > 0)
			result[--len] = nmrs[n % 10];
		else
			result[--len] = nmrs[n % 10 * -1];
		n /= 10;
	}
	return (result);
}
