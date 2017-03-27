/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bip_commit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:01:47 by alegent           #+#    #+#             */
/*   Updated: 2017/03/27 11:49:22 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bip.h"

/*
** Commit the region actually writen.
** @bip: Bip structure to set.
** @len: Length to commit.
*/

void			bip_commit(t_bip *bip, size_t size)
{
	++size;
	if (bip->current->size)
		bip->current->size += size;
	else
		bip->current->size = size;
	bip->write = NULL;
}
