/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenteno <rcenteno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:30:17 by rcenteno          #+#    #+#             */
/*   Updated: 2025/01/09 16:04:16 by rcenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	int	counter;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	counter = 0;
	if (n < 0)
	{
		counter += ft_print_char('-');
		n *= -1;
	}
	if (n > 9)
		counter += ft_print_int(n / 10);
	counter += ft_print_char((n % 10) + '0');
	return (counter);
}
