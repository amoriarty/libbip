/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bip_uncommit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:20:56 by alegent           #+#    #+#             */
/*   Updated: 2017/03/27 11:49:04 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bip.h"

void			bip_uncommit(t_bip *bip, size_t size)
{
	++size;
	bip->reg_a->ptr += size;
	bip->reg_a->size -= size;
	if (!bip->reg_a->size && bip->reg_b->size)
	{
		bip->reg_a->ptr = bip->reg_b->ptr;
		bip->reg_a->size = bip->reg_b->size;
		bip->reg_b->ptr = bip->buffer;
		bip->reg_b->size = 0;
	}
	bip->read = bip->reg_a->ptr;
}
