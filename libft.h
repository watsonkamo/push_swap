/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:45:21 by eshintan          #+#    #+#             */
/*   Updated: 2024/04/22 19:07:38 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/_types/_size_t.h>

int		ft_isdigit(int c);
long	ft_atol(const char *str);
void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif
