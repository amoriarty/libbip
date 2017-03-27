/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bip_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:09:33 by alegent           #+#    #+#             */
/*   Updated: 2017/03/27 11:48:46 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bip.h"

void			bip_clear(t_bip *bip)
{
	ft_bzero(bip->buffer, bip->buf_size);
	bip->write = NULL;
	bip->read = bip->buffer;
	bip->current = NULL;
	bip->reg_a->ptr = bip->buffer;
	bip->reg_b->ptr = bip->buffer;
	bip->reg_a->size = 0;
	bip->reg_b->size = 0;
}
