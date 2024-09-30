/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:12:16 by goolivei          #+#    #+#             */
/*   Updated: 2023/10/11 16:12:18 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*source;
	unsigned char	*destination;

	source = (unsigned char *)src;
	destination = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		if (source[i] != '\0')
			destination[i] = source[i];
		else
			destination[i] = '\0';
		i++;
	}
	return (destination);
}

/*int	main()
{
	printf("%s", memcpy(NULL, NULL, 1));
}*/
