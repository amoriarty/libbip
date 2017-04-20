/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 13:04:22 by alegent           #+#    #+#             */
/*   Updated: 2017/04/20 15:21:05 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bip.h"

/*
** Allocate region in bip buffer.
** @bip: Bip Buffer where allocating regions.
*/

static int			reg_new(t_bip *bip)
{
	if (!(bip->reg_a = (t_reg *)malloc(sizeof(t_reg))))
	{
		free(bip);
		free(bip->buffer);
		return (FALSE);
	}
	if (!(bip->reg_b = (t_reg *)malloc(sizeof(t_reg))))
	{
		free(bip);
		free(bip->buffer);
		free(bip->reg_a);
		return (FALSE);
	}
	return (TRUE);
}

/*
** Allocate a new bip buffer.
** @buf_size: size of the circular buffer.
*/

t_bip				*bip(size_t size)
{
	t_bip			*self;

	if (!(self = (t_bip *)malloc(sizeof(t_bip))))
		return (NULL);
	self->buf_size = size;
	if (!(self->buffer = ft_strnew(size)))
	{
		free(self);
		return (NULL);
	}
	if (reg_new(self) == FALSE)
		return (NULL);
	self->free = bip_free;
	self->commit = bip_commit;
	self->uncommit = bip_uncommit;
	self->reserve = bip_reserve;
	self->clear = bip_clear;
	self->clear(self);
	return (self);
}
