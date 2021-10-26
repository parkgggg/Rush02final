/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojoo <sojoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:51:36 by sojoo             #+#    #+#             */
/*   Updated: 2021/10/24 20:43:44 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

int	count_byte(char *name)
{
	int		size;
	int		i;
	int		fd;
	char	temp[1024];

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		i = read(fd, temp, 1024);
		size += i;
		if (i < 1024)
			break ;
	}
	close(fd);
	return (size);
}

char	*read_file(char *name)
{
	int		size;
	int		fd;
	char	*buf;

	size = count_byte(name);
	if (size < 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (size + 1));
	if (!buf)
		return (0);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (0);
	read(fd, buf, size + 1);
	buf[size] = '\0';
	close(fd);
	return (buf);
}

int	space_check(char *curr)
{
	int	i;
	int	co;

	i = 0;
	co = 0;
	while (1)
	{
		if (curr[i] == ':' || curr[i] == ' ')
		{
			if (curr[i] == ':')
				co++;
			i++;
		}
		else
			break ;
	}
	if (co != 1)
		return (0);
	return (i);
}

long long	check_line(char *curr, int *dict_i)
{
	long long	num;
	int			space;
	char		*str;

	num = -1;
	if (*curr == '\n')
		return (0);
	if (*curr >= '0' && *curr <= '9')
	{
		num = ft_atoi(curr);
		space = space_check(curr + ft_nbrlen(curr));
		if (space == 0)
			num = -1;
		else
		{
			space += ft_nbrlen(curr);
			str = get_value(curr + space, num, dict_i, &space);
			num = space;
			if (!str)
				num = -1;
		}
	}
	if (num == -1)
		write(1, "Dict Error\n", 11);
	return (num);
}

int	set_dict(char *buf)
{
	long long	i;
	int			dict_i;
	char		*curr;

	i = 0;
	curr = buf;
	while (*curr != '\0')
	{
		if (*(curr++) == '\n')
			i++;
	}
	g_dict = (t_entry *)malloc(sizeof(t_entry) * (i + 1));
	if (!g_dict)
		return (0);
	dict_i = 0;
	curr = buf;
	while (*curr != '\0')
	{
		i = check_line(curr, &dict_i);
		if (i == -1)
			return (0);
		curr += i + 1;
	}
	g_dict[dict_i].key = -1;
	return (1);
}
