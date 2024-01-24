/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebitrus <jebitrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:27:27 by jebitrus          #+#    #+#             */
/*   Updated: 2023/07/13 18:00:37 by jebitrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return ((int)ft_strlen(str));
}
