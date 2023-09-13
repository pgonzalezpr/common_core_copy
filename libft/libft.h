/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:16:39 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/13 14:38:29 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	void	*content;
	struct	s_list *next;
} t_list;

t_list *ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
