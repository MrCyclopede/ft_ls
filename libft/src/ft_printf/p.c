/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:58:33 by rcourtoi          #+#    #+#             */
/*   Updated: 2019/09/19 03:42:49 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	padding(t_conv *conv, t_buff *buff)
{
	int i;

	i = conv->width - (conv->len + conv->acc);
	if (conv->hashtag)
		i = i - 2;
	while (i-- > 0)
	{
		if (conv->zero)
			buff_insert_char(buff, '0');
		else
			buff_insert_char(buff, ' ');
	}
	return (0);
}

static int	hashtag(t_conv *conv, t_buff *buff)
{
	if (conv->hashtag)
	{
		buff_insert_char(buff, '0');
		buff_insert_char(buff, 'x');
	}
	else
		return (-1);
	return (0);
}

static int	precision(t_conv *conv, t_buff *buff)
{
	int i;

	i = conv->acc;
	while (i-- > 0)
		buff_insert_char(buff, '0');
	return (0);
}

static void	adapt_conv(t_conv *conv)
{
	if (conv->acc == 0
			&& ((int)ft_strlen(conv->str) == 1 && conv->str[0] == '0'))
	{
		conv->len = 0;
		conv->str[0] = '\0';
	}
	conv->hashtag = 1;
	conv->len = ft_strlen(conv->str) + (conv->space || conv->plus);
	conv->acc = conv->acc - ft_strlen(conv->str);
	if (conv->acc < 0)
		conv->acc = 0;
}

int			p(t_conv *conv, t_buff *buff)
{
	int j;

	j = buff->flushed + buff->index;
	if (!conv->from_tab)
		dispatch_cast(conv);
	adapt_conv(conv);
	if (conv->zero)
		hashtag(conv, buff);
	if (!conv->minus
			&& !(conv->zero && (conv->minus || conv->space || conv->plus)))
		padding(conv, buff);
	if (!conv->zero)
		hashtag(conv, buff);
	if (conv->zero && (conv->minus || conv->space || conv->plus))
		padding(conv, buff);
	precision(conv, buff);
	buff_insert_str(buff, conv);
	if (conv->minus)
		padding(conv, buff);
	return ((buff->flushed + buff->index) - j);
}
