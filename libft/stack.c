/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:53:48 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/03 19:19:10 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct s_stack	*ft_stackinit(void)
{
	struct s_stack		*new;

	if (!(new = (struct s_stack *)malloc(sizeof(struct s_stack))))
		return (NULL);
	new->top = NULL;
	return (new);
}

void			*ft_pop(struct s_stack *stack)
{
	struct s_node	*tmp;
	void			*tptr;

	if (!stack || !stack->top)
		return (NULL);
	tmp = stack->top;
	stack->top = stack->top->next;
	tptr = tmp->content;
	free(tmp);
	return (tptr);
}

void			ft_push(struct s_stack *stack, void *content)
{
	struct s_node		*new;

	if (!stack)
		return ;
	if (!(new = (struct s_node *)malloc(sizeof(struct s_node))))
		return ;
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

void			*ft_stackpeek(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	return (stack->top->content);
}

int				ft_stackisempty(struct s_stack *stack)
{
	if (!stack)
		return (1);
	return (!stack->top);
}
