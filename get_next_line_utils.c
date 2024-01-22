/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamrachi <hamrachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:14:45 by hamrachi          #+#    #+#             */
/*   Updated: 2024/01/22 15:43:06 by hamrachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return(i);
}

int ft_check(char *str)
{
    int i = 0;

    while(str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}
char    *ft_strdup(char *str)
{
    char    *new;
    size_t  i;

    i = ft_strlen(str);
    new = (char *)malloc(i + 1);
    if (!new)
        return(NULL);
    i = 0;
    while (str[i] && i < ft_strlen(str))
    {
        new[i] = str[i];
        i++;
    }
    return (new);
}
char *ft_strjoin(char *s1, char *s2)
{
	char *res;
	int i,j;
	
	if (!s1)
		return (ft_strdup(s2));
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	return (res);
}

// char    *str_join(char *s1, char const *s2)
// {
//     static char    *result;
//     size_t ls1;
//     size_t ls2;
//     size_t lres;
//     size_t tmp;

//     ls1 = ft_strlen(s1);
//     ls2 = ft_strlen(s2);
//     lres = ls1 + ls2;
//     result = (char *)malloc(lres + 1);
//     if (!result)
//         return(NULL);
//     tmp = ft_strlcpy(result , s1, ls1);
//     tmp = ft_strlcat(result , s2, lres);
//     return (result);
// }