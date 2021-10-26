/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojoo <sojoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:46:48 by sojoo             #+#    #+#             */
/*   Updated: 2021/10/24 21:13:41 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

char	*find_value(int nb)
{
	int	i;

	i = 0;
	while (g_dict[i].key != -1)
	{
		if (g_dict[i].key == nb)
			return (g_dict[i].value);
		i++;
	}
	return (0);
}

void	deal_field(long long num)
{
	char	*value;

	if (find_value(num / 100) && num / 100 > 0)
	{
		print_num(num / 100);
		write(1, " ", 1);
		print_num(100);
		if (num % 100 != 0)
			write(1, " ", 1);
	}
	num %= 100;
	if (find_value((num / 10) * 10) && num / 10 > 1)
	{
		print_num((num / 10) * 10);
		if (num % 10 == 0)
			return ;
		else
		{
			write(1, " ", 1);
			print_num(num % 10);
		}
	}
	else if (num > 0)
		print_num(num);
}

void	convert_num(long long num, int cnt)
{
	char	*value;
	int		i;
	int		count;

	count = cnt;
	i = 1;
	if (num >= 1000)
	{
		convert_num(num / 1000, count + 1);
		if (num % 1000 > 0)
			write(1, " ", 1);
		convert_num(num % 1000, count);
		return ;
	}
	else
		deal_field(num);
	if (count > 0 && num > 0)
	{
		while (count-- != 0)
			i *= 1000;
		write(1, " ", 1);
		value = find_value(i);
		if (value != 0)
			write(1, value, ft_strlen(value));
	}
}

void	check_zero(long long num)
{
	char	*value;

	if (num == 0)
	{
		value = find_value(0);
		if (value == 0)
		{
			write(1, "Dict Error\n", 11);
			return ;
		}
		write(1, value, ft_strlen(value));
		write(1, "\n", 1);
		return ;
	}
	if (is_convertable(num, 0))
	{
		convert_num(num, 0);
		write(1, "\n", 1);
	}
	else
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
}
