/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 04:19:58 by gbruscan          #+#    #+#             */
/*   Updated: 2024/10/23 03:08:30 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

int		ft_printf(const char *format, ...);
int		select_ft(va_list args, char c);
int		ft_putchar(va_list args);
int		ft_putstr(va_list args);
int		ft_printhex(va_list args);
int		ft_lower_printhex(va_list args);
int		ft_upper_printhex(va_list args);
int		ft_putnbr(int n);
int		ft_putnbr_scam(va_list args);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbru_scam(va_list args);
int		ft_percent(va_list args);
void	ft_putchar_fd(char c, int fd);