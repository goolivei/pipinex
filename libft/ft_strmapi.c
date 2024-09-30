/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:45:34 by goolivei          #+#    #+#             */
/*   Updated: 2023/10/23 17:45:47 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mvl;
	int		len;

	len = ft_strlen(s);
	if (!s || !f)
		return (ft_strdup(""));
	mvl = malloc(len + 1);
	if (!mvl)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mvl[i] = f(i, s[i]);
		i++;
	}
	mvl[len] = '\0';
	return (mvl);
}
