/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenteno <rcenteno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:57:44 by rcenteno          #+#    #+#             */
/*   Updated: 2024/12/05 16:22:12 by rcenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	test(char *str, ...)
{
	va_list	args;
	int		n;

	// char	*start;
	// int		index;
	va_start(args, str);
	// start = str;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				printf("soy caracter\n");
			}
			else if (*str == 's')
			{
				printf("soy string\n");
			}
			else if (*str == 'p')
			{
				printf("soy hexa\n");
			}
			else if (*str == 'd')
			{
				n = va_arg(args, int);
				printf("numero: %d\n", n);
			}
			else if (*str == 'i')
			{
				printf("soy entero base 10\n");
			}
			else if (*str == 'u')
			{
				printf("soy decimal sin signo\n");
			}
			else if (*str == 'x')
			{
				printf("soy hexadecimal en min\n");
			}
			else if (*str == 'X')
			{
				printf("soy hexadecimal en mayus\n");
			}
			else if (*str == '%')
			{
				printf("soy porcentaje\n");
			}
			else
			{
				printf("done\n");
			}
			// index = str - start;
			// printf("Posicion: %d", index);
			// break ;
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}

int	main(void)
{
	char str[] = "hola %d chao";
	test(str, 1234);
}