/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:43:32 by eshintan          #+#    #+#             */
/*   Updated: 2024/04/22 17:55:40 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_size_t.h>
#include <unistd.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(const char *str)
{
	int	i;
	int	sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void ft_putendl_fd(char *s, int fd)
{
	int    i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

size_t ft_strlen(const char *s)
{
	size_t    i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}