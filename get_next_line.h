
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t  ft_strlen(const char *str);
char    *ft_strdup(char *str);
int ft_check(char *str);
char	*ft_strjoin(char *s1, char *s2);
# endif