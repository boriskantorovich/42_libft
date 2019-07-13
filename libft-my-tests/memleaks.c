/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memleaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:12:59 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 22:08:21 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_change_content_once(t_list *elem)
{
	if (elem)
		elem->content = "new content";
}

void	ft_change_content(t_list *elem)
{
	printf("....Hmm.....\n");
	if (elem)
		printf("%s\n", elem->content);
		elem->content = "AAAAAA";
		printf("%s\n", elem->content);
	printf("....Hmm.....\n");
}
/*
void	ft_lstdelone_test(t_list **alst, void (*del)(void *, size_t))
{
	printf("alst adress		%p\n", alst);
	printf("*alst adress (it is == to &of main list)	%p\n", *alst);
	printf("alst content		%s\n", (*alst)->content);
	printf("alst content_size		%zu\n", (*alst)->content_size);
	printf("alst content_adress	%p\n", (**alst).content);
	printf("alst content_size		%zu\n", (*alst)->content_size);

	printf("L2 adress		%p\n", test->next);
	printf("L2 content		%s\n", test->next->content);
	printf("L2 content_size		%zu\n", test->next->content_size);
	printf("L3 adress		%p\n", test->next->next);
	printf("L3 content		%s\n", test->next->next->content);
	printf("L3 content_size		%zu\n", test->next->next->content_size);
	if (alst && *alst)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
*/

void	ft_lstdelone_test2(t_list *alst, void (*del)(void *, size_t))
{
	printf("....Hmm.....\n");
	if (alst)
		printf("%s\n", alst->content);
		alst->content = "AAAAAA";
		printf("%s\n", alst->content);
	printf("....Hmm.....\n");
	printf("alst adress		%p\n", alst);
	printf("*alst adress (it is == to &of main list)	%p\n", alst);
	printf("alst content		%s\n", alst->content);
	printf("alst content_size		%zu\n", alst->content_size);
	/*printf("alst content_adress	%p\n", (**alst).content);
	printf("alst content_size		%zu\n", (*alst)->content_size);

	printf("L2 adress		%p\n", test->next);
	printf("L2 content		%s\n", test->next->content);
	printf("L2 content_size		%zu\n", test->next->content_size);
	printf("L3 adress		%p\n", test->next->next);
	printf("L3 content		%s\n", test->next->next->content);
	printf("L3 content_size		%zu\n", test->next->next->content_size);*/
	if (!alst)
	{
		del((alst)->content, (alst)->content_size);
		free(alst);
		alst = NULL;
	}
}

void	*ft_lst_bzero(void *s, size_t n)
{
	printf("COME ON here\n");
	return(ft_memset(s, 0, n));
}


int	main(void)
{
	size_t size_max;
	void *result;
	size_max = 18446744073709551615UL;
	printf("%lu \n", size_max);
	printf("%lu \n", size_max + 1);
	printf("%lu \n", size_max + 2);
	printf("%lu \n", size_max + 3);

	if (!(result = malloc(2147483640)))
	{
		printf("CANNOT ALLOCATE\n");
	}
	free(result);

	size_t content_size = 10;
	void *sample_content = ft_memalloc(content_size);
	ft_memset(sample_content, 'x', content_size);
	printf("%s\n", sample_content);
	printf("TESTING LST_NEW\n");
	t_list *test = ft_lstnew(sample_content, content_size);
	printf("test adress		%p\n", test);
	printf("test content		%s\n", test->content);
	printf("test content_size	%zu\n", test->content_size);
	printf("TESTING LST NEW NULL and changing content\n");
	t_list *test_null = ft_lstnew(NULL, content_size);
	printf("test_null adress	%p\n", test_null);
	printf("test_null->content	%s\n", test_null->content);
	printf("test_null->content_size	%zu\n", test_null->content_size);
	ft_change_content_once(test);
	printf("test content after ft_lst_change_content	%s\n", test->content);
	printf("CREATING AND ADDING NEW ELEMENTS\n");
	t_list *test_new_elem = ft_lstnew(sample_content, content_size);
	printf("test_new_elem adress		%p\n", test_new_elem);
	printf("test_new_elem content		%s\n", test_new_elem->content);
	printf("test_new_elem content_size	%zu\n", test_new_elem->content_size);
	ft_lstadd(&test, test_new_elem);
	printf("test adress		%p\n", test);
	printf("test content		%s\n", test->content);
	printf("test content_size	%zu\n", test->content_size);
	printf("test->next adress	%p\n", test->next);
	printf("test->next content	%s\n", test->next->content);
	printf("test->next content_size	%zu\n", test->next->content_size);
	printf("iterating  list\n");
	ft_lstiter(test, ft_change_content);
	printf("test adress		%p\n", test);
	printf("test content		%s\n", test->content);
	printf("test content_size	%zu\n", test->content_size);
	printf("test->next adress	%p\n", test->next);
	printf("test->next content	%s\n", test->next->content);
	printf("test->next content_size	%zu\n", test->next->content_size);
	printf("NOW LIST HAS 3 levels!\n");
	t_list *test_new_elem_2 = ft_lstnew(sample_content, content_size);
	ft_lstadd(&test, test_new_elem_2);
	printf("L1 adress		%p\n", test);
	printf("L1 content		%s\n", test->content);
	printf("L1 content_size		%zu\n", test->content_size);
	printf("L2 adress		%p\n", test->next);
	printf("L2 content		%s\n", test->next->content);
	printf("L2 content_size		%zu\n", test->next->content_size);
	printf("L3 adress		%p\n", test->next->next);
	printf("L3 content		%s\n", test->next->next->content);
	printf("L3 content_size		%zu\n", test->next->next->content_size);
	printf("L4 adress		%p\n", test->next->next->next);
	printf("NOW ALL LEVELS HAVE DIFFERENT CONTENT\n");
	ft_change_content_once(test->next->next);
	printf("L1 adress		%p\n", test);
	printf("L1 content		%s\n", test->content);
	printf("L1 content_size		%zu\n", test->content_size);
	printf("L2 adress		%p\n", test->next);
	printf("L2 content		%s\n", test->next->content);
	printf("L2 content_size		%zu\n", test->next->content_size);
	printf("L3 adress		%p\n", test->next->next);
	printf("L3 content		%s\n", test->next->next->content);
	printf("L3 content_size		%zu\n", test->next->next->content_size);
	printf("L4 adress		%p\n", test->next->next->next);
	printf("NOW ALL LEVELS HAVE DIFFERENT CONTENT\n");
	ft_lstdelone_test2(test, ft_lst_bzero(test, content_size));
	/*printf("L1 adress		%p\n", test);
	printf("L1 content		%s\n", test->content);
	printf("L1 content_size		%zu\n", test->content_size);
	printf("L2 adress		%p\n", test->next);
	printf("L2 content		%s\n", test->next->content);
	printf("L2 content_size		%zu\n", test->next->content_size);
	printf("L3 adress		%p\n", test->next->next);
	printf("L3 content		%s\n", test->next->next->content);
	printf("L3 content_size		%zu\n", test->next->next->content_size);*/
	//ft_lstiter(test, tolower(l));
	//printf("%s", sample_content);
	//printf("%s", sample_content);
	return (0);
	//ft_bzero(result, size);
	//return (result);
	//ft_memalloc(size_max);
}
