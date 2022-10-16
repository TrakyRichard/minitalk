/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 01:37:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/16 02:06:03 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num_process(int n)
{
	int	chars_printed;

	chars_printed = 0;
	if (!n)
		return (chars_printed);
	if (n < 0)
	{
		chars_printed += ft_print_char('-');
		n = -n;
	}
	chars_printed += ft_print_num_process(n / 10);
	chars_printed += ft_print_char(n % 10 + '0');
	return (chars_printed);
}

int	ft_print_num(int n)
{
	int	chars_printed;

	chars_printed = 0;
	if (n == -2147483648)
	{
		chars_printed += ft_print_str("-2147483648");
		return (chars_printed);
	}
	if (n == 0)
	{
		chars_printed += ft_print_char('0');
		return (chars_printed);
	}
	else
	{
		chars_printed += ft_print_num_process(n);
		return (chars_printed);
	}
}
