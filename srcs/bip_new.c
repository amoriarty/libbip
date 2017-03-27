/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bip_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 13:04:22 by alegent           #+#    #+#             */
/*   Updated: 2017/03/27 11:49:09 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bip.h"

/*
** Allocate region in bip buffer.
** @bip: Bip Buffer where allocating regions.
*/

static int			reg_new(t_bip *bip)
{
	if (!(bip->reg_a = (t_reg *)malloc(sizeof(t_reg))))
	{
		free(bip);
		free(bip->buffer);
		return (FALSE);
	}
	if (!(bip->reg_b = (t_reg *)malloc(sizeof(t_reg))))
	{
		free(bip);
		free(bip->buffer);
		free(bip->reg_a);
		return (FALSE);
	}
	return (TRUE);
}

/*
** Allocate a new bip buffer.
** @buf_size: size of the circular buffer.
*/

t_bip				*bip_new(size_t buf_size)
{
	t_bip			*bip;

	if (!(bip = (t_bip *)malloc(sizeof(t_bip))))
		return (NULL);
	bip->buf_size = buf_size;
	if (!(bip->buffer = (char *)malloc(sizeof(char) * buf_size)))
	{
		free(bip);
		return (NULL);
	}
	if (reg_new(bip) == FALSE)
		return (NULL);
	bip_clear(bip);
	return (bip);
}
