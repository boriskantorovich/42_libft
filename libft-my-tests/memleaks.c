/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memleaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:12:59 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/15 12:38:53 by dfisher          ###   ########.fr       */
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

void	ft_bzero_test(void *s, size_t n)
{
	printf("## START CLEANING\n");
	printf("## content_size =  %lu\n", n);
	unsigned char	*b_uc;

	b_uc = (unsigned char *)s;
	printf("## s == %s\n" , s);
	printf("## MIDDLE\n");
	while (n--)
		*b_uc++ = (unsigned char)0;
	printf("## ZEROING IS FINISHED\n");
}


void	ft_lstdel_test(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;

	printf("## BEFORE DEL\n");
	printf("## alst adress					%p\n", alst);
	printf("## *alst adress (it is == to &of main list)	%p\n", *alst);
	printf("## alst content adress				%p\n", (*alst)->content);
	printf("## alst content					%s\n", (*alst)->content);
	printf("## alst content_size				%zu\n", (*alst)->content_size);
	printf("## alst content_adress				%p\n", (**alst).content);
	printf("## alst content_size				%zu\n", (*alst)->content_size);
	if (alst && *alst && del)
	{
		printf("###### START IF\n");
		while (alst && *alst && del)
		{
			printf("#### START WHILE\n");
			next = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = next;
		}
		*alst = NULL;
	}
}


void	ft_lstdelone_test(t_list **alst, void (*del)(void *, size_t))
{
	printf("## BEFORE DEL\n");
	printf("## alst adress					%p\n", alst);
	printf("## *alst adress (it is == to &of main list)	%p\n", *alst);
	printf("## alst content adress				%p\n", (*alst)->content);
	printf("## alst content					%s\n", (*alst)->content);
	printf("## alst content_size				%zu\n", (*alst)->content_size);
	printf("## alst content_adress				%p\n", (**alst).content);
	printf("## alst content_size				%zu\n", (*alst)->content_size);
	if (alst && *alst)
	{
		printf("###### START IF\n");

		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
	printf("## FINISHED DEL\n");
	printf("AFTER DEL\n");
	printf("alst adress		%p\n", alst);
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
	printf("CHANGE L2\n");
	ft_change_content_once(test->next->next);
	printf("L1 adress		%p\n", test);
	printf("L1 content		%s\n", test->content);
	printf("L1 content adress	%p\n", test->content);
	printf("L1 content_size		%zu\n", test->content_size);
	printf("L1 content_size adress	%p\n", &test->content_size);
	printf("L2 adress		%p\n", test->next);
	printf("L2 content		%s\n", test->next->content);
	printf("L1 content adress	%p\n", test->next->content);
	printf("L2 content_size		%zu\n", test->next->content_size);
	printf("L3 adress		%p\n", test->next->next);
	printf("L3 content		%s\n", test->next->next->content);
	printf("L1 content adress	%p\n", test->next->next->content);
	printf("L3 content_size		%zu\n", test->next->next->content_size);
	printf("L4 adress		%p\n", test->next->next->next);
	printf("NOW ALL LEVELS HAVE DIFFERENT CONTENT\n");
	t_list *test_del = ft_lstnew(sample_content, content_size);
	t_list *test_del_new_elem = ft_lstnew(sample_content, content_size);
	t_list *test_del_new_elem_2 = ft_lstnew(sample_content, content_size);
	ft_lstadd(&test_del, test_del_new_elem);
	ft_lstadd(&test_del, test_del_new_elem_2);
	printf("LIST TO DEL\n");
	printf("L1 adress		%p\n", test_del);
	printf("L1 content		%s\n", test_del->content);
	printf("L1 content adress	%p\n", &test_del->content);
	printf("L1 content_size		%zu\n", test_del->content_size);
	printf("L1 content_size adress	%p\n", &test_del->content_size);
	printf("L2 adress		%p\n", test_del->next);
	printf("L2 content		%s\n", test_del->next->content);
	printf("L2 content adress	%p\n", &test_del->next->content);
	printf("L2 content_size		%zu\n", test_del->next->content_size);
	printf("L3 adress		%p\n", test_del->next->next);
	printf("L3 content		%s\n", test_del->next->next->content);
	printf("L3 content adress	%p\n", &test_del->next->next->content);
	printf("L3 content_size		%zu\n", test_del->next->next->content_size);
	printf("L4 adress		%p\n", test_del->next->next->next);
	ft_lstdelone_test(&test_del->next, ft_bzero_test);
	printf("AFTER DEL\n");
	printf("L1 adress		%p\n", test_del);
	printf("L1 content		%s\n", test_del->content);
	printf("L1 content adress	%p\n", &test_del->content);
	printf("L1 content_size		%zu\n", test_del->content_size);
	printf("L1 content_size adress	%p\n", &test_del->content_size);
	//printf("L2 adress		%p\n", test_del->next);
	printf("L3 adress		%p\n", test_del->next->next);
	printf("L3 content		%s\n", test_del->next->next->content);
	printf("L3 content adress	%p\n", &test_del->next->next->content);
	printf("L3 content_size		%zu\n", test_del->next->next->content_size);
	printf("L4 adress		%p\n", test_del->next->next->next);
	/*ft_lstdelone_test(&(test->next), ft_bzero);
	printf("AFTER DEL\n");
	printf("L1 adress		%p\n", test);
	printf("L1 content		%s\n", test->content);
	printf("L1 content_size		%zu\n", test->content_size);
	printf("L2 adress		%p\n", test->next);
	printf("L2 content		%s\n", test->next->content);
	printf("L2 content_size		%zu\n", test->next->content_size);
	printf("L3 adress		%p\n", test->next->next);
	printf("L3 content		%s\n", test->next->next->content);
	printf("L3 content_size		%zu\n", test->next->next->content_size);
*/
	//ft_lstiter(test, tolower(l));
	//printf("%s", sample_content);
	//printf("%s", sample_content);
	return (0);
	//ft_bzero(result, size);
	//return (result);
	//ft_memalloc(size_max);
}
