/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:18:39 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/08/26 18:32:37 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*empty_string(void)
{
	char	*s;

	s = malloc(1);
	if (!s)
		return (NULL);
	s[0] = 0;
	return (s);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	begin;
	size_t	end;
	size_t	len;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	begin = 0;
	while (is_set(s1[begin], set))
		begin++;
	len = ft_strlen(s1);
	if (begin == len)
		return (empty_string());
	end = len - 1;
	while (is_set(s1[end], set))
		end--;
	res = malloc(end - begin + 2);
	if (!res)
		return (NULL);
	ft_strlcpy(res, (s1 + begin), (end - begin + 2));
	return (res);
}
/*
int main(void)
{
    char *str;
    char *set;
    char *result;

    str = "  bon jouarrr  ";
    set = " ";
    result = ft_strtrim(str, set);
    printf("Original string: '%s'\n", str);
    printf("Set to trim: '%s'\n", set);
    printf("Trimmed string: '%s'\n", result);
    free(result);

    str = "xxyouuu houuuxx";
    set = "x";
    result = ft_strtrim(str, set);
    printf("Original string: '%s'\n", str);
    printf("Set to trim: '%s'\n", set);
    printf("Trimmed string: '%s'\n", result);
    free(result);

    str = "abcweeesh alorsdabc";
    set = "abc";
    result = ft_strtrim(str, set);
    printf("Original string: '%s'\n", str);
    printf("Set to trim: '%s'\n", set);
    printf("Trimmed string: '%s'\n", result);
    free(result);

    str = "yarrfrrr";
    set = "";
    result = ft_strtrim(str, set);
    printf("Original string: '%s'\n", str);
    printf("Set to trim: '%s'\n", set);
    printf("Trimmed string: '%s'\n", result);
    free(result);

    str = "";
    set = " ";
    result = ft_strtrim(str, set);
    printf("Original string: '%s'\n", str);
    printf("Set to trim: '%s'\n", set);
    printf("Trimmed string: '%s'\n", result);
    free(result);

    return 0;
}
*/
