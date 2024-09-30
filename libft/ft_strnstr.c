/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:15:52 by goolivei          #+#    #+#             */
/*   Updated: 2023/10/17 16:16:04 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char *)str);
	while (str[i] && i < n)
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0' && (i + j) < n)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *)(str + i));
		}
		i++;
		j = 0;
	}
	return (0);
}
