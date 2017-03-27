/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bip_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 13:23:41 by alegent           #+#    #+#             */
/*   Updated: 2017/03/27 11:49:15 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bip.h"

/*
** Unallocate a bip buffer.
*/

void		bip_free(t_bip *bip)
{
	free(bip->reg_b);
	free(bip->reg_a);
	free(bip->buffer);
	free(bip);
}
