/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:01:03 by apimikov          #+#    #+#             */
/*   Updated: 2023/11/23 10:54:14 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int		ft_printf(const char *s, ...);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_printbase(long nbr, const char *str_base);
int		ft_printbase_ulong(unsigned long long nb, const char *str_base);

#endif 
