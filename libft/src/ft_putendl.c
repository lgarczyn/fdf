/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 22:27:09 by lgarczyn          #+#    #+#             */
/*   Updated: 2014/11/05 22:27:18 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
