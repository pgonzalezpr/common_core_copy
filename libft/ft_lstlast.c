/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:11:04 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/13 14:43:49 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current->next)
		current = current->next;
	return (current);
}
