t_list		*ft_strsplit_lstmode_test(char const *s, char c)
{
	t_list	*result;
	t_list	*ptr_result;
	char	*temp;
	int		i;
	int		j;
	size_t	len;
	//int		flag;

	if (!s)
		return (NULL);
	i = 0;
	//flag = 0;
	if (*s != c && *s)
	{
		while (*s && *s != c)
		{
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
				free(temp);
			}
		}
	}
	else 
	{
		if (!(result = ft_lstnew(NULL, 0)))
			return (NULL);
	}
	ptr_result = result;
	while (*s)
	{
		if (*s != c && *s)
		{
			//flag = 1;
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
			free(temp);
		}
		/*else if (flag == 1 && *s == c)
		{
			if (!(result = ft_lstnew(NULL, 0)))
				return (NULL);
		}
		*/
		s++; 
	}
	return (ptr_result);
}
