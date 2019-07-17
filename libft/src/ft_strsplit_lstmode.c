/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lstmode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:51:39 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/17 13:51:59 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
** Allocates (with malloc(3)) and returns an array of “fresh” strings (all
** ending with ’\0’, including the array itself) ob- tained by spliting s using
** the character c as a delimiter. If the allocation fails the function returns
** NULL. Example : ft_strsplit("*hello*fellow***students*", ’*’) re- turns the
** array ["hello", "fellow", "students"].
*/

#include "libft.h"

static int	ft_wordscounter(const char *s, char c)
{
	int index;
	int flag;

	index = 0;
	flag = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (flag == 0)
			{
				flag = 1;
				index++;
			}
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (index);
}

static size_t	ft_ln(const char *s, char c)
{
	int index;

	index = 0;
	while (*s && *(s++) != c)
		index++;
	return (index);
}

t_list		*ft_strsplit_lstmode(char const *s, char c)
{
	t_list	*result;
	t_list	*ptr_result;
	char	*temp;
	int		i;
	int		j;
	size_t	words_count;

	if (!s || !(result = ft_lstnew(NULL, 0)))
		return (NULL);
	i = 0;
	ptr_result = result;
	words_count = ft_wordscounter(s, c);
	while (*s && words_count)
	{
		if (*s != c && *s)
		{
			j = 0;
			if (!(temp = (char *)malloc((ft_ln(s, c) + 1) * sizeof(char))))
			{
				ft_lstdel(&ptr_result, ft_bzero);
				return (NULL);
			}
			while (*s != c && *s)
				*(temp + j++) = *(s++);
			*(temp+ j) = '\0';
			if (!(result = ft_lstnew(temp, ft_ln(s, c))))
			{
				ft_lstdel(&ptr_result, ft_bzero);
				return (NULL);
			}
			result = result->next;
			words_count--;
			s--;
		}
		s++;
	}
	return (ptr_result);
}
