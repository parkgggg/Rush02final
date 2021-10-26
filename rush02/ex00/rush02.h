/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojoo <sojoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:43:08 by sojoo             #+#    #+#             */
/*   Updated: 2021/10/24 21:16:09 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RUSH02_H
# define RUSH02_H
# define MAX_INT 4294967295

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_entry
{
	long long	key;
	char		*value;
}	t_entry;

t_entry	*g_dict;

char		*argc_check(int argc, char **argv, long long *num);
void		free_g_dict(void);

long long	numbers_check(char *str);
long long	ft_atoi(char *str);

int			count_byte(char *name);
char		*read_file(char *name);
int			space_check(char *curr);
long long	check_line(char *curr, int *dict_i);
int			set_dict(char *buf);

int			is_space(char x);
int			ft_nbrlen(char *curr);
char		*edit_str(char *curr, int size, int *space);
char		*get_value(char *curr, long long num, int *dict_i, int *space);

void		print_num(long long num);
int			ft_strlen(char *str);

char		*find_value(int nb);
void		deal_field(long long num);
void		convert_num(long long num, int cnt);
void		check_zero(long long num);

int			check_field(long long num);
int			is_convertable(long long num, int cnt);

#endif
