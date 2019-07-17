/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memleaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boriskantorovich <boriskantorovich@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:12:59 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/16 16:06:56 by boriskantor      ###   ########.fr       */
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

static void	ft_lstdel_elem(void *content, size_t content_size)
{
	if (content)
	{
		(void)content_size;
		free(content);
	}
}

t_list	*ft_change_content_once_and_return(t_list *elem)
{
	if (elem)
		elem->content = "new content";
	return (elem);
}

t_list		*ft_lstmap_test(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;
	t_list		*ptr_list;
	t_list		*prev_list;

	if (!(lst) || !(f))
		return (NULL);
	list = f(lst);
	ptr_list = list;
	prev_list = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(prev_list->next = f(lst)))
		{
			ft_lstdel(&ptr_list, &ft_lstdel_elem);
			return (NULL);
		}
		prev_list = prev_list->next;
	}
	return (ptr_list);
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
	t_list *test_child_alive_after_parent_death = test_del->next->next;
	printf("DELETING LEVEL 2, BUT NOT LEVEL 3\n");
	ft_lstdelone(&test_del->next, ft_bzero);
	printf("L1 adress		%p\n", test_del);
	printf("L1 content		%s\n", test_del->content);
	printf("L1 content adress	%p\n", &test_del->content);
	printf("L1 content_size		%zu\n", test_del->content_size);
	printf("L1 content_size adress	%p\n", &test_del->content_size);
	printf("L2 adress (test_del->next == NULL)	%p\n", test_del->next);
	printf("But it's child still alive. Here is the adress		%p\n", test_child_alive_after_parent_death);
	printf("test_child_alive_after_parent_death content 	%s\n", test_child_alive_after_parent_death->content);
	printf("test_child_alive_after_parent_death content_size		%zu\n", test_child_alive_after_parent_death->content_size);
	printf("test_child_alive_after_parent_death next		%p\n", test_child_alive_after_parent_death->next);
	t_list *test_mapped = ft_lstmap_test(test, ft_change_content_once_and_return);
	printf("NEW LIST MAP DEL\n");
	printf("L1 adress		%p\n", test_mapped);
	printf("L1 content		%s\n", test_mapped->content);
	printf("L1 content_size		%zu\n", test_mapped->content_size);
	printf("L2 adress		%p\n", test_mapped->next);
	printf("L2 content		%s\n", test_mapped->next->content);
	printf("L2 content_size		%zu\n", test_mapped->next->content_size);
	printf("L3 adress		%p\n", test_mapped->next->next);
	printf("L3 content		%s\n", test_mapped->next->next->content);
	printf("L3 content_size		%zu\n", test_mapped->next->next->content_size);
	/*printf("DELETING THE WHOLE LIST\n");
	printf("BEFORE DEL\n");
	printf("L1 adress		%p\n", test);
	printf("L1 content		%s\n", test->content);
	printf("L1 content_size		%zu\n", test->content_size);
	printf("L2 adress		%p\n", test->next);
	printf("L2 content		%s\n", test->next->content);
	printf("L2 content_size		%zu\n", test->next->content_size);
	printf("L3 adress		%p\n", test->next->next);
	printf("L3 content		%s\n", test->next->next->content);
	printf("L3 content_size		%zu\n", test->next->next->content_size);
	ft_lstdel(&test, ft_bzero);
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
	//ft_lstiter(test, tolower(l));
	//printf("%s", sample_content);
	//printf("%s", sample_content);
	
	//ft_bzero(result, size);
	//return (result);
	//ft_memalloc(size_max);
	*/
	return (0);
}
