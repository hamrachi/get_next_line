/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamrachi <hamrachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 08:59:22 by hamrachi          #+#    #+#             */
/*   Updated: 2024/01/22 17:59:51 by hamrachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_remainder(char *buffer)
{
    int i;
    int j ;
    char *remainder;

    i = 0;
    while (buffer[i])
    {
        if (buffer[i] == '\n')
            break;
        i++;
    }
    j = i + 1;
    remainder = malloc((ft_strlen(buffer) - j + 1) * sizeof(char));
    if (!remainder)
        return(NULL);
    i = 0;
    while (buffer[j])
        remainder[i++] = buffer[j++];
    remainder[i] = '\0';
    return(remainder);
}
char *get_line(char *buffer)
{
    int i;
    int j;
    char *tmp;

	i = 0;
    while (buffer[i] == '\n' && buffer[i])
        i++;
	j = i;
    while (buffer[j] != '\n' && buffer[j])
        j++;
    tmp = malloc((j - i + 1) * sizeof(char));
    if (!tmp)
        return (NULL);
	j = 0;
    while (buffer[i] != '\n')
        tmp[j++] = buffer[i++];
    tmp[i] = '\0';
    return (tmp);
}
char    *get_read_str(char *str, int fd)
{
    char    *buffer;
    ssize_t beyt;
    
    buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	
    if (!buffer)
        return(NULL);
    beyt = 1;
	
    while (beyt > 0)
    {
        beyt = read(fd, buffer, BUFFER_SIZE);
        if (beyt == -1)
        {
            free (buffer);
            return (NULL);
        }
		str = ft_strjoin(str, buffer);
    }
    free(buffer);
    return (str); 
}
char *get_next_line(int fd)
{
    static char     *line;
    char   *new;
	
	if (fd < 0)
        return(NULL);
	
	line = get_read_str(line, fd);
	new = get_line(line);
	line = ft_remainder(line);
    return (new);
}
int main ()
{
    int fd;
    fd = open("ttt.txt",O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}