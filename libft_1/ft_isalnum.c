/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:05:22 by jlagos            #+#    #+#             */
/*   Updated: 2018/12/06 19:21:27 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if (c >= '0' && c <= 'z')
	{
		if ((c > '9' && c < 'A') || (c > 'Z' && c < 'a'))
			return (0);
		return (1);
	}
	return (0);
}