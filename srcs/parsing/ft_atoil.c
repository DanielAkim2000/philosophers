/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:47:03 by demane            #+#    #+#             */
/*   Updated: 2026/02/06 15:36:09 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	mul;
	int	result;
	int	digit;

	i = 0;
	mul = -1;
	result = 0;
	while (str[i] == 32 || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		if (str[i++] == '-')
			mul = mul * (-1);
	while (str[i] && ft_isdigit(str[i]))
	{
		digit = str[i] - 48;
		if (result < (INT_MIN + digit) / 10)
			return (-1);
		result = result * 10 - (str[i++] - 48);
	}
	return (result * mul);
}

long	ft_atol(char *str)
{
	int		i;
	int		mul;
	long	result;
	int		digit;

	i = 0;
	mul = -1;
	result = 0;
	while (str[i] == 32 || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		if (str[i++] == '-')
			mul = mul * (-1);
	while (str[i] && ft_isdigit(str[i]))
	{
		digit = str[i] - 48;
		if (result < (LONG_MIN + digit) / 10)
			return (-1);
		result = result * 10 - (str[i++] - 48);
	}
	return (result * mul);
}
