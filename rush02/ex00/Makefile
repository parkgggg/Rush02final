# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 21:06:58 by yejikim           #+#    #+#              #
#    Updated: 2021/10/24 21:07:18 by yejikim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFAGS = -Wall -Wextra -Werror
TARGET = rush-02
OBJECTS = main.o numbers_check.o read_dict.o convert_num.o get_value.o ft_util.o check_convertable.o

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

fclean :
	rm $(OBJECTS) $(TARGET)
