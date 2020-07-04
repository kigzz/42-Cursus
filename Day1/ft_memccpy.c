void *ft_memccpy(void *dest, void *src, int c, unsigned int n) {
    char *dest2 = (char *) dest;
    char *src2 = (char *) src;
    int i;

    i = 0;
    while (i < n && src2[i] != (char)c) {
        dest2[i] = src2[i];
        i++;
        if (src2[i] == (char)c) {
            dest2[i] = (char)c;
            return (dest2);
        }
    }
    return (dest2);
}