/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:31:29 by pbompard          #+#    #+#             */
/*   Updated: 2016/05/12 10:31:30 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (*s2);
	if (s2 == NULL)
		return (*s1);
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (!str)
		return (0);
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
		if (ft_isdigit(*str) == 0)
			return (0);
	}
	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		result = result * 10 + *str++ - 48;
	return (sign * result);
}



void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_aff(t_list *l, char *pile)
{
	ft_putstr(pile);
	write(1, " : ", 3);
	while (l->next != NULL)
		l = l->next;
	while (l)
	{
		ft_putnbr(l->nb);
		l = l->prev;
		if (l)
			write(1, " ", 1);
	}
}

t_list	*ft_init(t_list *pile, int ac, char **av)
{
	int		i;

	i = ac - 1;
	printf("i = ac = %d\n", ac);
	printf("av[i] = %s\n", av[i]);
	pile = ft_creat_new_elem(ft_atoi(av[i]), NULL);
	i--;
	while (i != 0)
	{
		pile = ft_creat_new_elem(ft_atoi(av[i]), pile);
		i--;
	}
	return (pile);
}

void	ft_push_swap(int ac, char **av)
{
	t_list		*pile_a;

	pile_a = (t_list *)malloc(sizeof(t_list));
	pile_a = ft_init(pile_a, ac, av);
	ft_aff(pile_a, "pile_a");
	write(1, "\n", 1);
}

int		ft_is_int(char *nb)
{
	if (*nb == '-')
		nb++;
	while (*nb)
	{
		if (*nb < '0' || *nb > '9')
			return (0);
		nb++;
	}
	return (1);
}

int		ft_int_to_big(char *str)
{
	int		i;

	i = ft_strlen(str);
	if (str[0] == '-' && i == 10)
		return (0);
	if (i == 11 && str[0] == '-' && str[1] < '3' && str[2] < '2' \
		&& str[3] < '5' && str[4] < '8' && str[5] < '5' && str[6] < '9' \
		&& str[7] < '4' && str[8] < '7' && str[9] < '5' && str[10] < '8')
		return (0);
	if (i == 10 && str[0] < '3' && str[1] < '2' && str[2] < '5' \
		&& str[3] < '8' && str[4] < '5' && str[5] < '9' && str[6] < '4' \
		&& str[7] < '7' && str[8] < '5' && str[9] < '8')
		return (0);
	if (i < 10)
		return (0);
	else
		return (1);
}

int		main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (i != ac)
	{
		if (ft_is_int(av[i]) == 0)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (ft_int_to_big(av[i]) == 1)
		{
			write(2, "Error\n", 6);
			return (0);		}
		i++;
	}
	ft_push_swap(ac, av);
	return (0);
}