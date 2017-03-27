/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bip_reserve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:56:05 by alegent           #+#    #+#             */
/*   Updated: 2017/03/27 11:49:27 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bip.h"

/*
** Return the size of the writable zone and set pointers.
** @bip: Bip structure to set.
*/

size_t			bip_reserve(t_bip *bip)
{
	size_t		free_space;

	free_space = 0;
	if (bip->reg_b->size)
	{
		bip->current = bip->reg_b;
		free_space = bip->reg_a->ptr - (bip->reg_b->ptr + bip->reg_b->size);
	}
	else if (bip->reg_a->ptr - bip->buffer \
		<= BIP_ENDBUF - (bip->reg_a->ptr + bip->reg_a->size))
	{
		bip->current = bip->reg_a;
		free_space = BIP_ENDBUF - (bip->reg_a->ptr + bip->reg_a->size);
	}
	else
	{
		bip->current = bip->reg_b;
		free_space = bip->reg_a->ptr - bip->buffer;
	}
	if ((int)free_space > 0)
	{
		bip->write = bip->current->ptr + bip->current->size;
		return (free_space);
	}
	return (0);
}
