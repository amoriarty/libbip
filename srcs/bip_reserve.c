/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bip_reserve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:56:05 by alegent           #+#    #+#             */
/*   Updated: 2017/04/20 15:26:25 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bip.h"

/*
** Return the size of the writable zone and set pointers.
** @self: Bip structure to set.
*/

size_t			bip_reserve(t_bip *self)
{
	size_t		free_space;

	free_space = 0;
	if (self->reg_b->size)
	{
		self->current = self->reg_b;
		free_space = self->reg_a->ptr - (self->reg_b->ptr + self->reg_b->size);
	}
	else if (self->reg_a->ptr - self->buffer \
		<= BIP_ENDBUF - (self->reg_a->ptr + self->reg_a->size))
	{
		self->current = self->reg_a;
		free_space = BIP_ENDBUF - (self->reg_a->ptr + self->reg_a->size);
	}
	else
	{
		self->current = self->reg_b;
		free_space = self->reg_a->ptr - self->buffer;
	}
	if ((int)free_space > 0)
	{
		self->write = self->current->ptr + self->current->size;
		return (free_space);
	}
	return (0);
}
