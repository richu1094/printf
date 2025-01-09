/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenteno <rcenteno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:30:38 by rcenteno          #+#    #+#             */
/*   Updated: 2025/01/09 18:04:33 by rcenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	long	n;
	int		counter;

	counter = 0;
	if (ptr == NULL)
	{
		counter += write(1, "(nil)", 5);
		return (counter);
	}
	n = (unsigned long)ptr;
	counter += ft_print_str("0x");
	counter += ft_print_hex(n, 'x');
	return (counter);
}
