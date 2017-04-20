/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bip_commit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:01:47 by alegent           #+#    #+#             */
/*   Updated: 2017/04/20 15:22:39 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bip.h"

/*
** Commit the region actually writen.
** @bip: Bip structure to set.
** @len: Length to commit.
*/

void			bip_commit(t_bip *self, size_t size)
{
	++size;
	if (self->current->size)
		self->current->size += size;
	else
		self->current->size = size;
	self->write = NULL;
}
