/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojoo <sojoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:38:22 by sojoo             #+#    #+#             */
/*   Updated: 2021/10/24 19:46:29 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

void	print_num(long long num)
{
	char	*value;

	value = find_value(num);
	if (value != 0)
		write(1, value, ft_strlen(value));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}
