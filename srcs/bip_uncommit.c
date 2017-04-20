/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bip_uncommit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:20:56 by alegent           #+#    #+#             */
/*   Updated: 2017/04/20 15:24:38 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bip.h"

/*
** Uncommit part of the bip buffer that can now be reuse.
** @self: Bip buffer to set.
** @size: Size to uncommit.
*/

void			bip_uncommit(t_bip *self, size_t size)
{
	++size;
	self->reg_a->ptr += size;
	self->reg_a->size -= size;
	if (!self->reg_a->size && self->reg_b->size)
	{
		self->reg_a->ptr = self->reg_b->ptr;
		self->reg_a->size = self->reg_b->size;
		self->reg_b->ptr = self->buffer;
		self->reg_b->size = 0;
	}
	self->read = self->reg_a->ptr;
}
