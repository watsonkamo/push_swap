/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:45:21 by eshintan          #+#    #+#             */
/*   Updated: 2024/04/18 18:47:01 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <libc.h>

int	ft_isdigit(int c);
int	ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);

#endif