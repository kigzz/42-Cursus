
int ft_atoi(char *str)
{
    int result;
    int i;
    int sign;

    i = 0;
    result = 0;
    sign = 1;

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result * sign);
}
