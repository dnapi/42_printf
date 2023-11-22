/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:57:57 by apimikov          #+#    #+#             */
/*   Updated: 2023/11/22 13:58:13 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	insert_args(const char *s, va_list *ap);
int	call_function(const char s, va_list *ap);

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, s);
	len = insert_args(s, &ap);
	va_end(ap);
	return (len);
}

int	insert_args(const char *s, va_list *ap)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s != '%')
		{
			write(1, s, 1);
			len++;
		}
		else if (ft_strchr("cspdiuxX%", *(s + 1)))
		{
			len += call_function(*(s + 1), ap);
			s++;
		}
		s++;
	}
	return (len);
}

int	call_function(const char type, va_list *ap)
{
	if (type == 'c')
		return (ft_printchar(va_arg(*ap, int)));
	else if (type == 's')
		return (ft_printstr(va_arg(*ap, char *)));
	else if (type == 'x')
		return (ft_printbase(va_arg(*ap, unsigned int), "0123456789abcdef"));
	else if (type == 'X')
		return (ft_printbase(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	else if (type == 'u')
		return (ft_printbase(va_arg(*ap, unsigned int), "0123456789"));
	else if (type == 'd' || type == 'i')
		return (ft_printbase(va_arg(*ap, int), "0123456789"));
	else if (type == 'p')
	{
		write(1, "0x", 2);
		return (ft_printbase_ulong((unsigned long long)va_arg(*ap, void *), \
			"0123456789abcdef") + 2);
	}
	else if (type == '%')
		return (ft_printchar('%'));
	return (0);
}
