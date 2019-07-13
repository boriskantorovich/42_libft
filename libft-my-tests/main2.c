/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 11:51:47 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/04 10:32:37 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
/*
static int	ft_number_of_words(const char *s, char c)
{
	int index;
	int flag;

	index = 0;
	flag = 0;
	while (*s != '\0')
	{
		if (*s != c && (flag == 0))
		{
			flag = 1;
			index++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (index);
}
*/


/*

[ -------STARTING ALL UNIT TESTS------- ]
>>>> 00_part1_ft_atoi.spec.c ----- [Ok !] ................................
>>>> 00_part1_ft_bzero.spec.c ---- [Ok !] ...
>>>> 00_part1_ft_isalnum.spec.c -- [Ok !] ...................
>>>> 00_part1_ft_isalpha.spec.c -- [Ok !] ...................
>>>> 00_part1_ft_isascii.spec.c -- [Ok !] ....................
>>>> 00_part1_ft_isdigit.spec.c -- [Ok !] ...................
>>>> 00_part1_ft_isprint.spec.c -- [Ok !] ...................
>>>> 00_part1_ft_memccpy.spec.c -- [Ok !] ..
>>>> 00_part1_ft_memchr.spec.c --- [Ok !] .
>>>> 00_part1_ft_memcmp.spec.c --- [Ok !] ......
>>>> 00_part1_ft_memcpy.spec.c --- [Ok !] .
>>>> 00_part1_ft_memmove.spec.c -- [Ok !] ..
>>>> 00_part1_ft_memset.spec.c --- [Ok !] ...
>>>> 00_part1_ft_strcat.spec.c --- [Ok !] .
>>>> 00_part1_ft_strchr.spec.c --- [Ok !] ....
>>>> 00_part1_ft_strcmp.spec.c --- [Ok !] .....
>>>> 00_part1_ft_strcpy.spec.c --- [Ok !] ..
>>>> 00_part1_ft_strdup.spec.c --- [Ok !] ...
>>>> 00_part1_ft_strlcat.spec.c -- [Ok !] .......
>>>> 00_part1_ft_strlen.spec.c --- [Ok !] ....
>>>> 00_part1_ft_strncat.spec.c -- [Ok !] ..
>>>> 00_part1_ft_strncmp.spec.c -- [Ok !] .....
>>>> 00_part1_ft_strncpy.spec.c -- [Ok !] ..
>>>> 00_part1_ft_strnstr.spec.c -- [Ok !] ....
>>>> 00_part1_ft_strrchr.spec.c -- [Ok !] ....
>>>> 00_part1_ft_strstr.spec.c --- [Ok !] ..........
>>>> 00_part1_ft_tolower.spec.c -- [Ok !] ...................
>>>> 00_part1_ft_toupper.spec.c -- [Ok !] ...................
>>>> 01_part2_ft_itoa.spec.c ----- [Ok !] ....
>>>> 01_part2_ft_memalloc.spec.c - [Ok !] ..
>>>> 01_part2_ft_memdel.spec.c --- [Ok !] .
>>>> 01_part2_ft_putchar.spec.c -- [Ok !] .
>>>> 01_part2_ft_putchar_fd.spec.c [Ok !] .
>>>> 01_part2_ft_putendl.spec.c -- [Ok !] .
>>>> 01_part2_ft_putendl_fd.spec.c [Ok !] .
>>>> 01_part2_ft_putnbr.spec.c --- [Ok !] .
>>>> 01_part2_ft_putnbr_fd.spec.c  [Ok !] .
>>>> 01_part2_ft_putstr.spec.c --- [Ok !] .
>>>> 01_part2_ft_putstr_fd.spec.c  [Ok !] .
>>>> 01_part2_ft_strclr.spec.c --- [Ok !] .
>>>> 01_part2_ft_strdel.spec.c --- [Ok !] .
>>>> 01_part2_ft_strequ.spec.c --- [Ok !] ...
>>>> 01_part2_ft_striter.spec.c -- [Ok !] .
>>>> 01_part2_ft_striteri.spec.c - [Ok !] .
>>>> 01_part2_ft_strjoin.spec.c -- [Ok !] ..
>>>> 01_part2_ft_strmap.spec.c --- [Ok !] .
>>>> 01_part2_ft_strmapi.spec.c -- [Ok !] .
>>>> 01_part2_ft_strnequ.spec.c -- [Ok !] ....
>>>> 01_part2_ft_strnew.spec.c --- [Ok !] ...
>>>> 01_part2_ft_strsplit.spec.c - [FAIL] ..F.F. [FAIL] test3 -> strcmp(tt[0], "coucou") == 0
>>>> 01_part2_ft_strsub.spec.c --- [FAIL] .F. [FAIL] test2 -> strcmp(ft_strsub(str, 8, 8), "je serai") == 0
>>>> 01_part2_ft_strtrim.spec.c -- [FAIL] TTBB [TIME] test1 -> strcmp(ft_strtrim("\t\n  \tAAA \t BBB\t\n  \t"), "AAA \t BBB") == 0
>>>> 02_bonus_ft_lstadd.spec.c --- [Ok !] .
>>>> 02_bonus_ft_lstdel.spec.c --- [Ok !] .
>>>> 02_bonus_ft_lstdelone.spec.c  [Ok !] .
>>>> 02_bonus_ft_lstiter.spec.c -- [Ok !] .
>>>> 02_bonus_ft_lstmap.spec.c --- [FAIL] S [SEGV] test1 -> !!map && map->content_size == 42
>>>> 02_bonus_ft_lstnew.spec.c --- [FAIL] S [SEGV] test1 -> (*(int*)(list->content)) == 42
[ ----------END OF UNIT TESTS---------- ]

--

>>>> Tests for libft
Source: github.com/yyang42/moulitest
Legend: (.) Ok / (F) Fail / (S) Segfault / (B) Bus error / (T) Timeout / (A) Abort

Notes: Errors should never pass silently! (That's why we don't handle NULL cases.)

[ -------STARTING ALL UNIT TESTS------- ]
>>>> 00_part1_ft_atoi.spec.c ----- [Ok !] ................................
>>>> 00_part1_ft_bzero.spec.c ---- [Ok !] ...
>>>> 00_part1_ft_isalnum.spec.c -- [Ok !] ...................
>>>> 00_part1_ft_isalpha.spec.c -- [Ok !] ...................
>>>> 00_part1_ft_isascii.spec.c -- [Ok !] ....................
>>>> 00_part1_ft_isdigit.spec.c -- [Ok !] ...................
>>>> 00_part1_ft_isprint.spec.c -- [Ok !] ...................
>>>> 00_part1_ft_memccpy.spec.c -- [Ok !] ..
>>>> 00_part1_ft_memchr.spec.c --- [Ok !] .
>>>> 00_part1_ft_memcmp.spec.c --- [Ok !] ......
>>>> 00_part1_ft_memcpy.spec.c --- [Ok !] .
>>>> 00_part1_ft_memmove.spec.c -- [Ok !] ..
>>>> 00_part1_ft_memset.spec.c --- [Ok !] ...
>>>> 00_part1_ft_strcat.spec.c --- [Ok !] .
>>>> 00_part1_ft_strchr.spec.c --- [Ok !] ....
>>>> 00_part1_ft_strcmp.spec.c --- [Ok !] .....
>>>> 00_part1_ft_strcpy.spec.c --- [Ok !] ..
>>>> 00_part1_ft_strdup.spec.c --- [Ok !] ...
>>>> 00_part1_ft_strlcat.spec.c -- [Ok !] .......
>>>> 00_part1_ft_strlen.spec.c --- [Ok !] ....
>>>> 00_part1_ft_strncat.spec.c -- [Ok !] ..
>>>> 00_part1_ft_strncmp.spec.c -- [Ok !] .....
>>>> 00_part1_ft_strncpy.spec.c -- [Ok !] ..
>>>> 00_part1_ft_strnstr.spec.c -- [Ok !] ....
>>>> 00_part1_ft_strrchr.spec.c -- [Ok !] ....
>>>> 00_part1_ft_strstr.spec.c --- [Ok !] ..........
>>>> 00_part1_ft_tolower.spec.c -- [Ok !] ...................
>>>> 00_part1_ft_toupper.spec.c -- [Ok !] ...................
>>>> 01_part2_ft_itoa.spec.c ----- [Ok !] ....
>>>> 01_part2_ft_memalloc.spec.c - [Ok !] ..
>>>> 01_part2_ft_memdel.spec.c --- [Ok !] .
>>>> 01_part2_ft_putchar.spec.c -- [Ok !] .
>>>> 01_part2_ft_putchar_fd.spec.c [Ok !] .
>>>> 01_part2_ft_putendl.spec.c -- [Ok !] .
>>>> 01_part2_ft_putendl_fd.spec.c [Ok !] .
>>>> 01_part2_ft_putnbr.spec.c --- [Ok !] .
>>>> 01_part2_ft_putnbr_fd.spec.c  [Ok !] .
>>>> 01_part2_ft_putstr.spec.c --- [Ok !] .
>>>> 01_part2_ft_putstr_fd.spec.c  [Ok !] .
>>>> 01_part2_ft_strclr.spec.c --- [Ok !] .
>>>> 01_part2_ft_strdel.spec.c --- [Ok !] .
>>>> 01_part2_ft_strequ.spec.c --- [Ok !] ...
>>>> 01_part2_ft_striter.spec.c -- [Ok !] .
>>>> 01_part2_ft_striteri.spec.c - [Ok !] .
>>>> 01_part2_ft_strjoin.spec.c -- [Ok !] ..
>>>> 01_part2_ft_strmap.spec.c --- [Ok !] .
>>>> 01_part2_ft_strmapi.spec.c -- [Ok !] .
>>>> 01_part2_ft_strnequ.spec.c -- [Ok !] ....
>>>> 01_part2_ft_strnew.spec.c --- [Ok !] ...
>>>> 01_part2_ft_strsplit.spec.c - [FAIL] ..F.F. [FAIL] test3 -> strcmp(tt[0], "coucou") == 0
>>>> 01_part2_ft_strsub.spec.c --- [FAIL] .F. [FAIL] test2 -> strcmp(ft_strsub(str, 8, 8), "je serai") == 0
>>>> 01_part2_ft_strtrim.spec.c -- [FAIL] TTBB [TIME] test1 -> strcmp(ft_strtrim("\t\n  \tAAA \t BBB\t\n  \t"), "AAA \t BBB") == 0
>>>> 02_bonus_ft_lstadd.spec.c --- [Ok !] .
>>>> 02_bonus_ft_lstdel.spec.c --- [Ok !] .
>>>> 02_bonus_ft_lstdelone.spec.c  [Ok !] .
>>>> 02_bonus_ft_lstiter.spec.c -- [Ok !] .
>>>> 02_bonus_ft_lstmap.spec.c --- [FAIL] S [SEGV] test1 -> !!map && map->content_size == 42
>>>> 02_bonus_ft_lstnew.spec.c --- [FAIL] S [SEGV] test1 -> (*(int*)(list->content)) == 42
[ ----------END OF UNIT TESTS---------- ]

>>>> Result: 53/58 test suites passed. 280/289 tests passed (dots).

*/
/*
static int	*ft_maxlen_and_wordcount(const char *s, char c)
{
	int *arr;
	int index;
	int flag;
	int temp;
	int maxlen;

	if (!(arr = (int *)malloc(2 * sizeof(int))))
		return (NULL);
	temp = 0;
	maxlen = 0;
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
			temp++;
		}
		else if (*s == c)
		{
			if (temp != 0)
			{
				maxlen = (maxlen < temp) ? temp : maxlen;
				temp = 0;
			}
			flag = 0;
		}
		s++;
	}
	if (!maxlen && temp)
		maxlen = temp;
	arr[0] = index + 1;
	arr[1] = maxlen + 1;
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		*memsize;

	memsize = ft_maxlen_and_wordcount(s, c);
	if (!s || !(result = \
	(char **)malloc(memsize[0] * sizeof(char *))))
		return (NULL);
	i = 0;
	while ((*s != '\0') && (i < memsize[0]))
	{
		if (*s != c)
		{
			j = 0;
			if (!(result[i] = \
			(char *)malloc(memsize[1] * sizeof(char))))
				return (NULL);
			while (*s != c)
			{
				*(*(result + i) + j++) = *(s++);
			}
			//ft_putendl(*(result + i));
			i++;
		}
		s++;
	}
	*(result + i) = NULL;
	return (result);
}
*/
int		main(void)
{
	ft_strnstr(((void *)0), "fake", 3);
	// *test_strtrim = "    	        ";
	//ft_putendl(test_strtrim);
	//ft_putendl(ft_strtrim(test_strtrim));
	//ft_putendl(strnstr(NULL, NULL, 10));
	//ft_putendl(ft_strnstr(NULL, NULL, 10));
	char *new = "coucou***dddd";
	//int *arr = ft_maxlen_and_wordcount(new, '*');
	//char	*str = "Un jour je serai, le meilleur dresseur !";
	char	**arr = ft_strsplit(new, '*');
	//int i = 0;
	while (*arr)
	{
		ft_putendl(*arr);
		arr++;
	}
	ft_putchar('\n');
	char *empty1 = "AAAAAA";
	char *empty2 = "";
	ft_putnbr(strncmp(empty1, empty2, 6));
	ft_putnbr(ft_strncmp(empty1, empty2, 6));
	ft_putchar('\n');
	//ft_strsplit(new, '*');
/*
	char c = '*';
	char result[10][100];

	int j;
	int i;
	i = 0;
	while (*new != '\0')
	{
		j = 0;
		if (*new != c)
		{
			while (*new != c)
			{
				result[i][j] = *new;
				new++;
				j++;
			}
			i++;
		}
		new++;
	}
	ft_putchar('\n');
	while (i--)
		ft_putendl(result[i]);
	*/
	/*
	ft_putnbr(ft_number_of_words(new, 'u'));
	ft_putchar('\n');
	char buf[10];

	bzero(buf, 10);
	ft_strlcpy(buf, "un deux 9", 10);
	ft_putendl(buf);
	ft_putendl(">>>");
	ft_putendl(strnstr(buf, "deux", 10));
	ft_putendl(ft_strnstr(buf, "deux", 10));
	ft_putendl(strnstr(buf, "9", 3));
	ft_putendl(ft_strnstr(buf, "9", 3));
	ft_putendl(strnstr(buf, "", 0));
	ft_putendl(ft_strnstr(buf, "", 0));
	ft_putendl(strnstr(buf, "deux", 5));
	ft_putendl(ft_strnstr(buf, "deux", 5));
	ft_putendl(strnstr(buf, "9", 10));
	ft_putendl(ft_strnstr(buf, "9", 10));
	ft_putendl(strnstr(buf, "9", 8));
	ft_putendl(ft_strnstr(buf, "9", 8));
	ft_putendl("TEST 2");
	*/
/*
	char	buf2[11];

	bzero(buf2, 11);
	strcpy(buf2, "un deux 9");
	buf2[9] = '6';
	ft_putendl(buf2);
	ft_putendl(">>>");

	ft_putendl(ft_strnstr(buf2, "deux", 10));
	ft_putendl(strnstr(buf2, "deux", 10));
	ft_putendl(ft_strnstr(buf2, "cinq", 10));
	ft_putendl(strnstr(buf2, "cinq", 10));
	ft_putendl(ft_strnstr(buf2, "9682", 10));
	ft_putendl(strnstr(buf2, "9682", 10));

	ft_putendl(ft_strnstr(buf2, "6", 10));
	ft_putendl(strnstr(buf2, "6", 10));
	//mt_assert(strcmp(ft_strnstr(buf2, "6", 10), "6") == 0);
	mt_assert(strcmp(ft_strnstr(buf, "deux", 10), "deux 9") == 0);
	mt_assert(ft_strnstr(buf, "9", 3) == NULL);
	mt_assert(strcmp(ft_strnstr(buf, "", 6), buf) == 0);
	mt_assert(ft_strnstr(buf, "deux", 5) == NULL);
	mt_assert(strcmp(ft_strnstr(buf, "9", 10), "9") == 0);
	mt_assert(ft_strnstr(buf, "9", 8) == NULL);
	*/
	/*
	char *insert = "abcdefghijkl";

	ft_putnbr(ft_strncmp("ab\0cde", "abcc\0e", 20));
	ft_putchar('|');
	ft_putnbr(strncmp("ab\0cde", "abcc\0e", 20));
	ft_putchar('\n');
	ft_putnbr(ft_strncmp("abc", "abc\0defg", 100));
	ft_putchar('|');
	ft_putnbr(strncmp("abc", "abc\0defg", 100));
	ft_putchar('\n');
	ft_putnbr(ft_strncmp("\200", "\0", 1));
	ft_putchar('|');
	ft_putnbr(strncmp("\200", "\0", 1));
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');*/
	/*
	ft_memset(buf, 'x', 7);
	buf[7] = '\0';
	ft_putendl(">>>1");
	ft_putendl(buf);
	ft_putnbr(ft_strlen(buf));
	ft_putchar('\n');
	ft_putnbr(ft_strlen(insert));
	ft_putchar('\n');
	ft_strlcat(buf, insert, 5);
	ft_putendl(">>>2");
	ft_putendl(buf);
	ft_putnbr(ft_strlcat(buf, insert, 5));
	ft_putchar('\n');
	*/
	//ft_putnbr(ft_strlcpy(buf, insert, 10));
	/*strlcat(buf, "abcdefghijklmnop", 10);
	ft_putendl(buf);
	strcpy(buf, "abc");
	ft_putendl(buf);
	ft_strlcat(buf, "abcdefghijklmnop", 10);
	ft_putendl(buf);*/
	//mt_assert(strcmp(buf, "abcabcdef") == 0);
	//mt_assert(ft_strlcat(buf, "abcd", 2) == 6);
	return (0);
}

/*

//https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/

void	test_create_2d_array_of_int(int r, int c)
{
	int *arr;
	int i;
	int j;
	int count;

	arr = (int *)malloc(r * c * sizeof(int));
	i = 0;
	count = 0;
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			*(arr + i * c + j) = ++count;
			j++;
		}
		i++;
	}

	i = 0;
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			ft_putnbr(*(arr + i * c + j));
			ft_putchar(' ');
			j++;
		}
		i++;
	}
	ft_putchar('\n');
}
void	test_create_2d_array_of_char(char *str1, char *str2)
{
	char *arr;
	int str1_size = ft_strlen(str1) + 1;
	int str2_size = ft_strlen(str2) + 1;
	int c = 2;
	int i;
	int j;
	int x_size = (str1_size >= str2_size) ? str1_size : str2_size;

	arr = (char *)malloc((x_size * c + c)*sizeof(char));
	i = 0;
	while (i < x_size)
	{
		j = 0;
		while (j < c)
		{
			*(arr + i * c + j) = *(str1++);
			j++;
		}
		i++;
	}

	i = 0;
	while (i < x_size)
	{
		j = 0;
		while (j < c)
		{
			ft_putchar(*(arr + i * c + j));
			j++;
		}
		i++;
	}
	ft_putchar('\n');

}
*/
