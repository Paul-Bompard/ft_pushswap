/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:48:37 by pbompard          #+#    #+#             */
/*   Updated: 2016/05/12 10:48:38 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PUSH_SWAP
# define	PUSH_SWAP
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct 			s_list
{
	int					nb;
	struct s_list		*prev;
	struct s_list		*next;
}						t_list;

t_list		*ft_creat_new_elem(int nb, t_list *prev)
{
	t_list		*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	new_elem->prev = prev;
	new_elem->next = NULL;
	new_elem->nb = nb;
	return (new_elem);
}

t_list		*ft_goto_next(t_list *cur)
{
	if (cur->next == NULL)
		cur->next = ft_creat_new_elem(0, cur);
	cur = cur->next;
	return (cur);
}

t_list		*ft_goto(int j, t_list *first)
{
	while (j != 0)
	{
		if (first->next == NULL)
			first->next = ft_creat_new_elem(0, first);
		first = first->next;
		j--;
	}
	return (first);
}

#endif