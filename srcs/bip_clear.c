/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bip_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:09:33 by alegent           #+#    #+#             */
/*   Updated: 2017/04/20 15:22:21 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bip.h"

void			bip_clear(t_bip *self)
{
	ft_bzero(self->buffer, self->buf_size);
	self->write = NULL;
	self->read = self->buffer;
	self->current = NULL;
	self->reg_a->ptr = self->buffer;
	self->reg_b->ptr = self->buffer;
	self->reg_a->size = 0;
	self->reg_b->size = 0;
}
