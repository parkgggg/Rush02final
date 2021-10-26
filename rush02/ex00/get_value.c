/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojoo <sojoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:51:06 by sojoo             #+#    #+#             */
/*   Updated: 2021/10/24 20:42:19 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

int	is_space(char x)
{
	if ((8 < x && x <= 14) || x == 32)
		return (1);
	else
		return (0);
}

int	ft_nbrlen(char *x)
{
	int	i;

	i = 0;
	while (*(x + i) && ('0' <= *(x + i) && *(x + i) <= '9'))
		i++;
	return (i);
}

char	*edit_str(char *curr, int size, int *space)
{
	char	*pnew;
	int		i;
	int		j;

	pnew = (char *)malloc(sizeof(char) * (size + 1));
	if (pnew == 0)
		return (0);
	i = 0;
	j = 0;
	while (curr[i] && curr[i] != '\n')
	{
		if (is_space(curr[i]) && curr[i + 1] && !is_space(curr[i + 1]))
			pnew[j++] = ' ';
		else if (!is_space(curr[i]))
			pnew[j++] = curr[i];
		i++;
		(*space)++;
	}
	pnew[j] = '\0';
	return (pnew);
}

char	*get_value(char *curr, long long num, int *dict_i, int *space)
{
	int		i;
	char	*pnew;

	i = 0;
	if (curr[i] == '\n')
		return (0);
	else
	{
		while (curr[i] && curr[i] != '\n')
		{
			if (curr[i] > 126 || curr[i] < 32)
				return (0);
			i++;
		}
		pnew = edit_str(curr, i, space);
		g_dict[*dict_i].key = num;
		g_dict[*dict_i].value = pnew;
		*dict_i += 1;
		return (pnew);
	}
}
