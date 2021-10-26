/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojoo <sojoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:40:06 by sojoo             #+#    #+#             */
/*   Updated: 2021/10/24 21:04:42 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

char	*argc_check(int argc, char **argv, long long *num)
{
	if (argc == 2)
	{
		*num = numbers_check(argv[1]);
		if (*num < 0)
			return (0);
		return ("numbers.dict");
	}
	else if (argc == 3)
	{
		*num = numbers_check(argv[2]);
		if (*num < 0)
			return (0);
		return (argv[1]);
	}
	else
		return (0);
}

int	main(int argc, char **argv)
{
	long long	num;
	char		*file_name;
	char		*buf;

	file_name = argc_check(argc, argv, &num);
	if (file_name)
	{
		buf = read_file(file_name);
		if (!buf)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (set_dict(buf) == 0)
			return (0);
		check_zero(num);
		free(buf);
		free_g_dict();
	}
	else
		write(2, "Error\n", 6);
	return (0);
}

void	free_g_dict(void)
{
	int	i;

	while (1)
	{
		if (g_dict[i].key == -1)
			break ;
		free(g_dict[i].value);
		i++;
	}
	free(g_dict);
}
