/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenteno <rcenteno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:57:44 by rcenteno          #+#    #+#             */
/*   Updated: 2024/12/19 16:27:17 by rcenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			index;

	ptr = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		ptr[index] = (unsigned char)c;
		index++;
	}
	return (s);
}

void	handle_char(char c, int *counter)
{
	ft_putchar_fd(c, 1);
	(*counter)++;
}

void	handle_string(char *str, int *counter)
{
	ft_putstr_fd(str, 1);
	(*counter) += ft_strlen(str);
}

void	handle_pointer(void *p, int *counter)
{
	unsigned long	ptr;
	char			hex_digits[] = "0123456789abcdef";
	char			hex[16];
	int				i;

	write(1, "0x", 2);
	(*counter) += 2;
	ptr = (unsigned long)p;
	if (ptr == 0)
	{
		write(1, "0", 1);
		(*counter)++;
		return ;
	}
	i = 15;
	while (ptr > 0)
	{
		hex[i--] = hex_digits[ptr % 16];
		ptr /= 16;
	}
	write(1, hex + i + 1, 16 - i - 1);
	(*counter) += 16 - i - 1;
}

void	handle_int(int n, int *counter, int *error)
{
	char	str[10];
	long	num;
	int		i;

	num = n;
	i = 9;
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			*error = 1;
		(*counter)++;
		return ;
	}
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			*error = 1;
		(*counter)++;
		n *= -1;
	}
	ft_memset(str, '\0', sizeof(str));
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (i < 9)
	{
		if (write(1, &str[i + 1], 9 - i) == -1)
			*error = 1;
		(*counter) += (9 - i);
	}
}

void	handle_unsigned_int(unsigned int n, int *counter)
{
	char	str[10];
	int		i;

	if (n == 0)
	{
		write(1, "0", 1);
		(*counter)++;
		return ;
	}
	i = 9;
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	write(1, &str[i + 1], 9 - i);
	(*counter) += (9 - i);
}

void	handle_hex_lower(unsigned int n, int *counter)
{
	char	hex_digits[] = "0123456789abcdef";
	char	hex[8];
	int		i;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	i = 7;
	while (n > 0)
	{
		hex[i--] = hex_digits[n % 16];
		n /= 16;
	}
	write(1, hex + i + 1, 7 - i);
	(*counter) += (7 - i);
}

void	handle_hex_upper(unsigned int n, int *counter)
{
	char	hex_digits[] = "0123456789ABCDEF";
	char	hex[8];
	int		i;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	i = 7;
	while (n > 0)
	{
		hex[i--] = hex_digits[n % 16];
		n /= 16;
	}
	write(1, hex + i + 1, 7 - i);
	(*counter) += (7 - i);
}

void	handle_percent(int *counter)
{
	write(1, "%", 1);
	(*counter)++;
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		counter;
	int		error;

	va_start(args, str);
	counter = 0;
	error = 0;
	while (*str && error == 0)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				handle_char(va_arg(args, int), &counter);
			}
			else if (*str == 's')
			{
				handle_string(va_arg(args, char *), &counter);
			}
			else if (*str == 'p')
			{
				handle_pointer(va_arg(args, void *), &counter);
			}
			else if (*str == 'd' || *str == 'i')
			{
				handle_int(va_arg(args, int), &counter, &error);
			}
			else if (*str == 'u')
			{
				handle_unsigned_int(va_arg(args, unsigned int), &counter);
			}
			else if (*str == 'x')
			{
				handle_hex_lower(va_arg(args, unsigned int), &counter);
			}
			else if (*str == 'X')
			{
				handle_hex_upper(va_arg(args, unsigned int), &counter);
			}
			else if (*str == '%')
			{
				handle_percent(&counter);
			}
		}
		else
		{
			write(1, str, 1);
			counter++;
		}
		str++;
	}
	return (counter);
	va_end(args);
}
// int	main(void)
// {
// 	char str[] = "string: %s\npuntero: %p upperhex: %X unsignedint: %u\n";
// 	printf("Count: %d", ft_printf(str, "hola mundo", str, 4294967296, 0));
// }