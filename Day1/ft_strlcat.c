/*unsigned int	ft_strlen(char *str)
{
    unsigned int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
*/
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int i;
    unsigned int dest_size;
    unsigned int src_size;

    i = 0;
    dest_size = ft_strlen(dest);
    src_size = ft_strlen(src);
    if (size <= dest_size || size == 0)
        src_size = src_size + size;
    else
        src_size = src_size + dest_size;
    while (src[i] != '\0' && dest_size + 1 < size)
    {
        dest[dest_size] = src[i];
        dest_size++;
        i++;
    }
    dest[dest_size] = '\0';
    return (src_size);
}
