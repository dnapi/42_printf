/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:50:00 by apimikov          #+#    #+#             */
/*   Updated: 2023/11/22 15:47:11 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printbase_pos(unsigned long nb, const char *str_base, \
		long base, int *len);

int	ft_printbase(long nbr, const char *str_base)
{
	long	base;
	int		len;
	long	nb;
	int flag;

	base = ft_strlen(str_base);
	len = 0;
	if (nbr < 0)
	{
		flag = write(1, "-", 1);
		if (flag != 1)
			return (-1);
		nb = -nbr;
		len++;
	}
	else
		nb = nbr;
	ft_printbase_pos((unsigned long long)nb, str_base, base, &len);
	return (len);
}

int	ft_printbase_pos(unsigned long nb, const char *str_base, \
		long base, int *len)
{
	char	c;
	int flag;

	if (nb > (unsigned long long)(base - 1))
		ft_printbase_pos(nb / base, str_base, base, len);
	c = str_base[nb % base];
//	write(1, &c, 1);
//	(*len)++;
	flag = write(1, &c, 1);
	if (flag != 1)
	{
		*len = -1;
		return (*len);
	}
	*len += flag;
//	if (write(1, &c, 1) == 1)
//		(*len)++;
//	else
//		return (-1);
	return (*len);
}

int	ft_printbase_ulong(unsigned long long nb, const char *str_base)
{
	long	base;
	int		len;

	base = (long)ft_strlen(str_base);
	len = 0;
	ft_printbase_pos(nb, str_base, base, &len);
	return (len);
}
