/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:06:46 by goolivei          #+#    #+#             */
/*   Updated: 2023/10/18 15:06:58 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	i;
	size_t	le1;
	size_t	le2;
	char	*jed;

	le1 = ft_strlen(str1);
	le2 = ft_strlen(str2);
	jed = malloc(le1 + le2 + 1);
	if (!jed)
		return (NULL);
	i = 0;
	while (i < le1)
	{
		jed[i] = str1[i];
		i++;
	}
	i = 0;
	while (i < le2)
	{
		jed[le1 + i] = str2[i];
		i++;
	}
	jed[le1 + le2] = '\0';
	return (jed);
}
