/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:06:33 by goolivei          #+#    #+#             */
/*   Updated: 2023/10/18 14:06:53 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t length)
{
	size_t	str_len;
	size_t	i;
	char	*sub;

	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_strdup(""));
	if (start + length > str_len)
		length = str_len - start;
	sub = malloc(length + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < length)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[length] = '\0';
	return (sub);
}
