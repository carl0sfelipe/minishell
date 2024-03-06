/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:05:18 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:05:20 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

//int	main(void)
//{
//	char	*s1;
//	char	*s2;
//	char	*s3;
//	char	*s4;
//	//int		arr[] = { 4, 2, 0, -1 };
//	t_list	*list;
//
//	s1 = "Hello!";
//	s2 = "lst";
//	s3 = "42";
//	s4 = "\tbonus\t";
//
//	ft_lstadd_back(&list, ft_lstnew(s4));
//	printf("%s\n", list->content);
//	return (0);
//}
