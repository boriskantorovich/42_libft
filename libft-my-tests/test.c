/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:12:59 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/17 14:51:45 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_change_content_once(t_list *elem)
{
	if (elem)
		ft_memset(elem->content, 'L', elem->content_size - 4);
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

/*
static void	ft_lstdel_elem(void *content, size_t content_size)
{
	if (content)
	{
		(void)content_size;
		free(content);
	}
}
*/
/*
t_list	*ft_change_content_once_and_return(t_list *elem)
{
	t_list 	*new_elem;

	if (!elem)
		return (NULL);
	if (!(new_elem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_elem->content = ft_memset(elem->content, 'B', elem->content_size - 4);
	new_elem->content_size = elem->content_size;
	return (new_elem);
}
*/

t_list	*ft_change_content_once_and_return(t_list *elem)
{
	if (elem)
		ft_memset(elem->content, 'B', elem->content_size - 4);
	return (elem);
}

t_list	*ft_lstmap_test(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*result;
	t_list		*ptr_list;
	t_list		*elem;

	if (!lst || !f)
		return (NULL);
	elem = f(lst);
	if (!(result = ft_lstnew(elem->content, elem->content_size)))
		return (NULL);
	lst = lst->next;
	ptr_list = result;
	while (lst)
	{
		elem = f(lst);
		if (!(result->next = ft_lstnew(elem->content, elem->content_size)))
		{
			ft_lstdel(&ptr_list, ft_bzero);
			return (NULL);
		}
		result = result->next;
		lst = lst->next;
	}
	return (ptr_list);
}

/*
t_list		*ft_lstmap_test(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;
	t_list		*ptr_list;
	t_list		*prev_list;

	if (!(lst) || !(f))
		return (NULL);
	if (!(list = ft_lstnew(f(lst), lst->content_size)))
		return (NULL);
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
*/


/*static int	ft_wordscounter(const char *s, char c)
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
*/
static size_t	ft_ln(const char *s, char c)
{
	int index;

	index = 0;
	while (*s && *(s++) != c)
		index++;
	return (index);
}

t_list		*ft_strsplit_lstmode_test(char const *s, char c)
{
	t_list	*result;
	t_list	*ptr_result;
	char	*temp;
	int		i;
	int		j;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	while (*s && *s != c)
	{
		printf("%c	\n", *s);
		printf("WHY AM I HERE ONCE\n");
		if (*s != c && *s)
		{
			j = 0;
			len = ft_ln(s, c) + 1;
			if (!(temp = (char *)malloc(len * sizeof(char))))
			{
				ft_lstdel(&result, ft_bzero);
				return (NULL);
			}
			if (!(result = ft_lstnew(temp, len)))
			{
				ft_lstdel(&ptr_result, ft_bzero);
				return (NULL);
			}
			while (*s != c && *s)
				*(temp + j++) = *(s++);
			*(temp + j) = '\0';
			result->content = temp;
		}
	}
	printf("Adress		%p\n", result);
	printf("CONTENT		%s\n", result->content);
	printf("SIZE		%zu\n", result->content_size);
	//printf("HERE MAIN\n");
	ptr_result = result;
	while (*s)
	{
		printf("%c	\n", *s);
		printf("HERE MAIN\n");
		if (*s != c && *s)
		{
			printf("WHY AM I HERE ONCE\n");
			j = 0;
			len = ft_ln(s, c) + 1;
			if (!(temp = (char *)malloc(len * sizeof(char))))
			{
				ft_lstdel(&ptr_result, ft_bzero);
				return (NULL);
			}
			if (!(result->next = ft_lstnew(temp, len)))
			{
				ft_lstdel(&ptr_result, ft_bzero);
				return (NULL);
			}
			while (*s != c && *s)
				*(temp + j++) = *(s++);
			*(temp + j) = '\0';
			result = result->next;
			result->content = temp;
			s--;
		}
		s++;
	}
	printf("(((HERE)))\n");
	printf("Adress		%p\n", result);
	if (!result)
	{
		printf("((((((HERE)))\n");
		return (NULL);
	}
	else
	{
		printf("HMM\n");
		result->next = NULL;
	}
	return (ptr_result);
}



int	main(void)
{
	/* SIZE_T MAX TESTs */
	ft_putendl("STARTING SIZE_T MAX TEST");
	char *not_null = "i am not null";
	char not_null_sub = 'm';
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

	char *size_max_sub = ft_strsub(not_null, (unsigned int)not_null_sub, size_max);
	char *size_max_new = ft_strnew(size_max);

	ft_putendl(size_max_new);
	ft_putendl(size_max_sub);
	ft_putendl("SIZE_T MAX TESTS PASSED");
	/* SIZE_T MAX TESTS PASSED */

	char *strset_test = ft_strnew(10);
	ft_putendl(strset_test);
	ft_strset(strset_test, 'x', 10);
	ft_putendl(strset_test);
	/* NULL TESTS */
	ft_putendl("Starting NULL test. If there's a segfault below, there's a promlem with NULL in part 2 functions.");
	ft_strset(NULL, -12, (size_t)NULL);
	ft_strset(strset_test, -12, (size_t)NULL);

	ft_memmove(NULL, NULL, (size_t)NULL);
	ft_memcpy(NULL, NULL, (size_t)NULL);
	ft_memalloc((size_t)NULL);
	ft_memdel(NULL);
	ft_strnew((size_t)NULL);
	ft_strnew(SIZE_T_MAX);
	ft_strdel(NULL);
	ft_strclr(NULL);
	ft_striter(NULL, NULL);
	ft_striter(NULL, ft_strclr);
	ft_striter(not_null, NULL);
	ft_striteri(NULL, NULL);
	ft_striteri(not_null, NULL);
	ft_strmap(NULL, NULL);
	ft_strmapi(NULL, NULL);
	ft_strequ(NULL, NULL);
	ft_strnequ(NULL, NULL, (size_t)NULL);
	ft_strsub(NULL, (unsigned int)NULL, (size_t)NULL);
	ft_strjoin(NULL, NULL);
	ft_strtrim(NULL);
	ft_strsplit(NULL, (char)NULL);
	ft_strsplit(NULL, 'a');
	ft_strsplit(not_null, (char)NULL);
	ft_itoa((int)NULL);
	ft_putchar((char)NULL);
	ft_putstr(NULL);
	ft_putendl(NULL);
	ft_putnbr((int)NULL);
	ft_putchar_fd((char)NULL, (int)NULL);
	ft_putstr_fd(NULL, (int)NULL);
	ft_putendl_fd(NULL, (int)NULL);
	ft_putnbr_fd((int)NULL, (int)NULL);
	ft_lstnew(NULL, (size_t)NULL);
	ft_lstdelone(NULL, NULL);
	ft_lstdel(NULL, NULL);
	ft_lstadd(NULL, NULL);
	ft_lstiter(NULL, NULL);
	ft_lstmap(NULL, NULL);
	ft_putendl("");
	ft_putendl("ALL IS GOOD ENOUGH WITH NULL");
	/* NULL TESTS PASSED */

	/* ATOI CHECK */
	ft_putendl("Checking atoi");
	printf("T1:\t[%d]\t[%d]\n", ft_atoi("�M-^HM-^R9223372036854775828"), atoi("�M-^HM-^R9223372036854775828"));
	printf("T2:\t[%d]\t[%d]\n", ft_atoi("�M-^HM-^R9223372036854775028"), atoi("�M-^HM-^R9223372036854775028"));
	printf("T3:\t[%d]\t[%d]\n", ft_atoi("9223372036854775828"), atoi("9223372036854775828"));
	printf("T4:\t[%d]\t[%d]\n", ft_atoi("9223372036854775808"), atoi("9223372036854775808"));
	printf("T666:\t[%d]\t[%d]\n", ft_atoi("22222222222222222222"), atoi("22222222222222222222"));

	printf("\n");

	printf("T11:\t[%d]\t[%d]\n", ft_atoi("9223372036854775806"), atoi("9223372036854775806"));
	printf("T12:\t[%d]\t[%d]\n", ft_atoi("9223372036854775807"), atoi("9223372036854775807"));
	printf("T13:\t[%d]\t[%d]\n", ft_atoi("9223372036854775808"), atoi("9223372036854775808"));
	printf("T14:\t[%d]\t[%d]\n", ft_atoi("9223372036854775809"), atoi("9223372036854775809"));
	printf("T15:\t[%d]\t[%d]\n", ft_atoi("-9223372036854775807"), atoi("-9223372036854775807"));
	printf("T16:\t[%d]\t[%d]\n", ft_atoi("-9223372036854775808"), atoi("-9223372036854775808"));
	printf("T17:\t[%d]\t[%d]\n", ft_atoi("-9223372036854775809"), atoi("-9223372036854775809"));
	printf("T18:\t[%d]\t[%d]\n", ft_atoi("-9223372036854775810"), atoi("-9223372036854775810"));
	ft_putendl("atoi check done");
	/* ATOI CHECK DONE*/

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
	ft_lstiter(test, ft_change_content_once);
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
	ft_change_content_once(test->next);
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
	printf("TESTING LST_MAP\n");
	printf("LIST TO WORK WITH\n");
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
	printf("OLD LIST MAP DEL\n");
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

	//char *new = "asdffadshjk*****fsd ajj 7&&***coucou***dddd****dfklkfsdl***sfdk";
	//char *new1 = "";
	//char *new2 = "***dddd****";
	char *new3 = "***";
	/*char	**arr = ft_strsplit(new, '*');
	while (*arr)
	{
		ft_putendl(*arr);
		arr++;
	}

	t_list *strsplit;*/
	/*strsplit = ft_strsplit_lstmode_test(new, '*');
	while (strsplit)
	{
		printf("Adress		%p\n", strsplit);
		printf("CONTENT		%s\n", strsplit->content);
		printf("SIZE		%zu\n", strsplit->content_size);
		strsplit = strsplit->next;
	}
	*/
	t_list *strsplit2;
	strsplit2 = ft_strsplit_lstmode_test(new3, '*');
	while (strsplit2)
	{
		printf("Adress		%p\n", strsplit2);
		printf("CONTENT		%s\n", strsplit2->content);
		printf("SIZE		%zu\n", strsplit2->content_size);
		strsplit2 = strsplit2->next;
	}
	t_list *strsplit3;
	strsplit3 = ft_strsplit_lstmode_test(new3, '*');
	while (strsplit3)
	{
		printf("Adress		%p\n", strsplit3);
		printf("CONTENT		%s\n", strsplit3->content);
		printf("SIZE		%zu\n", strsplit3->content_size);
		strsplit3 = strsplit3->next;
	}
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
