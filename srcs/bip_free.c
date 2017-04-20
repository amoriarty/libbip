/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bip_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 13:23:41 by alegent           #+#    #+#             */
/*   Updated: 2017/04/20 15:23:00 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bip.h"

/*
** Unallocate a bip buffer.
*/

void		bip_free(t_bip *self)
{
	free(self->reg_b);
	free(self->reg_a);
	free(self->buffer);
	free(self);
}
