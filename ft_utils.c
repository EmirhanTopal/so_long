/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:33:01 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 17:33:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	i = 0;
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < count * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char )s1[i] - (unsigned char )s2[i]);
		i++;
	}
	return ((unsigned char )s1[i] - (unsigned char )s2[i]);
}
