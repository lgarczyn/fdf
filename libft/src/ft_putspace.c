/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:29:01 by lgarczyn          #+#    #+#             */
/*   Updated: 2014/11/27 19:29:03 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "unistd.h"

void	ft_putspace(int n)
{
	while (n--)
		ft_putchar(' ');
}