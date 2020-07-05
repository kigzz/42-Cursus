int ft_strlen(char *str);

void *ft_memcpy(void *dest, void *src, unsigned int size)
{
    char *dest2 = (char *)dest;
    char *src2 = (char *)src;
    int i;
    int size_d;

    i = 0;
    size = ft_strlen(src2);
    size_d = ft_strlen(dest);
    while (i < size) {
        dest2[i] = src2[i];
        i++;
    }
    if (size_d > i) {
        while (i < size_d) {
            dest2[i] = '\0';
            i++;
        }
    }
    return (dest2);
}