void *ft_memset(void *ptr, int x, unsigned int n) {
    int i;
    char *str;

    i = 0;
    str = ptr;
    while (i < n)
    {
        str[i] = (char)x;
        i++;
    }
    return (ptr);
}