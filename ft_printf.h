/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenteno <rcenteno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:56:39 by rcenteno          #+#    #+#             */
/*   Updated: 2025/01/09 15:46:07 by rcenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

int		ft_print_char(char c);
int		ft_print_hex(unsigned long n, char format);
int		ft_print_int(int n);
int		ft_print_ptr(void *ptr);
int		ft_print_str(char *str);
int		ft_print_unsigned(unsigned int n);
size_t	ft_strlen(const char *str);

#endif