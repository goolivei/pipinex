/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:52:37 by goolivei          #+#    #+#             */
/*   Updated: 2023/10/13 14:52:39 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*str0;

	str0 = (char *)str;
	i = ft_strlen(str0);
	while (i > 0 && (char)c != str0[i])
		i--;
	if ((char)c == str0[i])
	{
		return (&str0[i]);
	}
	return (NULL);
}
