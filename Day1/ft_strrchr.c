char *ft_strrchr (const char *str, int c) {
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            j = i;
            i++;
        }
        else
            i++;
    }
    if (j != 0)
        return (&str[j]);
    else
        return (0);
}