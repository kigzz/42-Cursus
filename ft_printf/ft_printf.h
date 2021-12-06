/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:52:49 by bpouchep          #+#    #+#             */
/*   Updated: 2021/12/06 15:52:50 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

unsigned int	ft_strlen(char *str);

int				ft_putchar(char c);
int				ft_putstr(char *str);

int				ft_putbase(long long int n, char *base);
int				ft_putbase_address(unsigned long int n, char *base);

int				ft_printf(const char *str, ...);

#endif
