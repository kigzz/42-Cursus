#include <stdio.h>

char	*ft_strnstr(char *str, char *to_find, unsigned int n)
{
    int i;
    int j;
    int size_find;

    i = 0;
    size_find = 0;
    while (to_find[size_find] != '\0')
        size_find++;
    if (size_find == 0)
        return (str);
    while (str[i] != '\0' && n > i)
    {
        j = 0;
        while (to_find[j] != '\0' && str[i + j] == to_find[j] && n > i + j)
        {
            j++;
        }
        if (to_find[j] == '\0') {
            return (&str[i]);
        }
        else {
            i++;
        }
//        printf("n = %d\n", n);
    }
    return (0);
}