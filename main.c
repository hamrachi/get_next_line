#include "get_next_line.h"
// int main ()
// {
//     char str[] = "hamza";
//     int a = read(1,str,5);
//     printf("%d",a);
// }
#include <stdio.h>
#include <stdlib.h>

// int ft_check(char *str)
// {
//     int i = 0;

//     while(str[i])
//     {
//         if (str[i] == '\n')
//             return (1);
//         i++;
//     }
//     return (0);
// }
// char *get_line(char *buffer)
// {
//     int i;
//     int j;
//     char *tmp;

// 	i = 0;
//     while (buffer[i] == '\n' && buffer[i])
//         i++;
// 	j = i;
//     while (buffer[j] != '\n' && buffer[j])
//         j++;
//     tmp = malloc((j - i + 1) * sizeof(char));
//     if (!tmp)
//         return (NULL);
// 	j = 0;
//     while (buffer[i] != '\n')
//         tmp[j++] = buffer[i++];
//     tmp[i] = '\0';
//     return (tmp);
// }

char    *ft_remainder(char *buffer)
{
    int i;
    int j ;
    int x;
    char *remainder;

    i = 0;
    while (buffer[i])
    {
        if (buffer[i] == '\n')
        {
            break;
        }
        i++;
    }
    j = i + 1;
    x = ft_strlen(buffer) - j;
    remainder = malloc((x + 1) * sizeof(char));
    if (!remainder)
        return(NULL);
    i = 0;
    while (buffer[j])
        remainder[i++] = buffer[j++];
    remainder[i] = '\0';
    return(remainder);
}
int main()
{
    char s1[] = "tttddkdiddjjfiugiurtuytygtyasjhhhhhhhhhhhhhhhhhhhhhhhhdo\nshs";
    printf("%s",ft_remainder(s1));
}