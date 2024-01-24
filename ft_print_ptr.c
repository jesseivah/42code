/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebitrus <jebitrus@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:18:28 by jebitrus          #+#    #+#             */
/*   Updated: 2023/07/17 14:20:06 by jebitrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long int nbr, int format)
{
	int	digits;

	if (nbr == 0)
		return (print_str("(nil)"));
	else
	{
		digits = write (1, "0x", 2);
		return (digits + print_hex(nbr, format));
	}
}
