/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojoo <sojoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:42:19 by sojoo             #+#    #+#             */
/*   Updated: 2021/10/24 19:47:34 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

long long	numbers_check(char *str)
{
	char	*temp;

	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	temp = str;
	if (*str == '+' || (*str >= '0' && *str <= '9'))
		str++;
	else
		return (-1);
	while (*str >= '0' && *str <= '9')
		str++;
	while (*str != '\0')
	{
		if (!(*str == ' ' || (*str > 8 && *str < 14)))
			return (-1);
		str++;
	}
	return (ft_atoi(temp));
}

long long	ft_atoi(char *str)
{
	long long	result;

	result = 0;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		if (result > MAX_INT)
			return (-1);
		str++;
	}
	return (result);
}
