/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenteno <rcenteno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:57:44 by rcenteno          #+#    #+#             */
/*   Updated: 2024/12/12 17:08:44 by rcenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	index;
	size_t	length;

	index = 0;
	length = ft_strlen(s);
	while (index < length)
	{
		write(fd, &s[index], 1);
		index++;
	}
}

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*ptr;
	size_t			index;

	ptr = (unsigned char *)s;
	index = 0;
	while (index < len)
		ptr[index++] = 0;
}

void	handle_char(char c)
{
	ft_putchar_fd(c, 1);
}

void	handle_string(char *str)
{
	ft_putstr_fd(str, 1);
}

void	handle_pointer(void *p)
{
	unsigned long	ptr;
	char			hex_digits[] = "0123456789abcdef";
	char			hex[16];
	int				i;

	write(1, "0x", 2);
	ptr = (unsigned long)p;
	if (ptr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	i = 15;
	while (ptr > 0)
	{
		hex[i--] = hex_digits[ptr % 16];
		ptr /= 16;
	}
	write(1, hex + i + 1, 16 - i - 1);
}

// void	handle_int(int n)
// {
// }

// void	handle_unsigned_int(unsigned int n)
// {
// }

// void	handle_hex_lower(unsigned int n)
// {
// }

// void	handle_hex_upper(unsigned int n)
// {
// }

void	test(char *str, ...)
{
	va_list	args;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				handle_char(va_arg(args, int));
			}
			else if (*str == 's')
			{
				handle_string(va_arg(args, char *));
			}
			else if (*str == 'p')
			{
				handle_pointer(va_arg(args, void *));
			}
			// else if (*str == 'd' || *str == 'i')
			// {
			// 	handle_int(va_arg(args, int));
			// }
			// else if (*str == 'u')
			// {
			// 	handle_unsigned_int(va_arg(args, unsigned int));
			// }
			// else if (*str == 'x')
			// {
			// 	handle_hex_lower(va_arg(args, unsigned int));
			// }
			// else if (*str == 'X')
			// {
			// 	handle_hex_upper(va_arg(args, unsigned int));
			// }
			// else if (*str == '%')
			// {
			// 	handle_percent();
			// }
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
	va_end(args);
}
int	main(void)
{
	char str[] = "string: %s char: %c puntero: %p";
	test(str, "hola mundo", "a", str);
	printf("\n%p", str);
}