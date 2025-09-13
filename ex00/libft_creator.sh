#!/bin/sh

cc -Wall -Wextra -Werror -c ft_putchar.c
cc -Wall -Wextra -Werror -c ft_swap.c
cc -Wall -Wextra -Werror -c ft_putstr.c
cc -Wall -Wextra -Werror -c ft_strlen.c
cc -Wall -Wextra -Werror -c ft_strcmp.c
ar rc libft.a *.o
ranlib libft.a
