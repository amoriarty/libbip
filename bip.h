/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bip.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:38:31 by alegent           #+#    #+#             */
/*   Updated: 2017/04/20 15:26:00 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIP_H
# define BIP_H
# include "libft.h"
# define BIP_ENDBUF (self->buffer + self->buf_size)

/*
** Thanks to Simon Cooke for his article.
** https://www.codeproject.com/articles/3479/the-bip-buffer-the-circular-buffer-with-a-twist
*/

/*
** Bip Buffer Region structure.
*/

typedef struct s_reg	t_reg;
struct					s_reg
{
	char				*ptr;
	size_t				size;
};

/*
** Bip Buffer structure.
*/

typedef struct s_bip	t_bip;
struct					s_bip
{
	char				*buffer;
	char				*write;
	char				*read;
	size_t				buf_size;
	t_reg				*current;
	t_reg				*reg_a;
	t_reg				*reg_b;
	void				(*free)(t_bip *);
	size_t				(*reserve)(t_bip *);
	void				(*commit)(t_bip *, size_t);
	void				(*uncommit)(t_bip *, size_t);
	void				(*clear)(t_bip *);
};

/*
** Bip Buffer prototypes.
*/

t_bip					*bip(size_t buf_size);
void					bip_free(t_bip *bip);
size_t					bip_reserve(t_bip *bip);
void					bip_commit(t_bip *bip, size_t size);
void					bip_uncommit(t_bip *bip, size_t size);
void					bip_clear(t_bip *bip);

#endif
