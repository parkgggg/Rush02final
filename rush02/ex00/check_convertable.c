/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_convertable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:08:19 by yejikim           #+#    #+#             */
/*   Updated: 2021/10/24 21:08:46 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	check_field(long long num)
{
	char	*value;

	if (num / 100 > 0 && !find_value(num / 100))
		return (0);
	num %= 100;
	if (num / 10 > 1 && !find_value((num / 10) * 10))
		return (0);
	else if (find_value((num / 10) * 10))
	{
		if (num % 10 != 0 && !find_value(num % 10))
			return (0);
	}
	else if (num > 0 && !find_value(num))
		return (0);
	return (1);
}

int	is_convertable(long long num, int cnt)
{
	char	*value;
	int		i;

	i = 1;
	if (num >= 1000)
	{
		if (!is_convertable(num / 1000, cnt + 1))
			return (0);
		if (!is_convertable(num % 1000, cnt))
			return (0);
	}
	else
	{
		if (!check_field(num))
			return (0);
	}
	if (cnt > 0 && num > 0)
	{
		while (cnt-- != 0)
			i *= 1000;
		if (find_value(i) == 0)
			return (0);
	}
	return (1);
}
