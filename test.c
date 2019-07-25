#include <unistd.h>

int		ft_atoi(const char *s)
{
	int i;
	int sign;
	int push;

	i = 0;
	sign = 1;
	push = 0;
	while (s[i] == ' ' ||
			s[i] == '\t' ||
			s[i] == '\r' ||
			s[i] == '\n' ||
			s[i] == '\v' ||
			s[i] == '\f')
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		push = push * 10 + s[i] - '0';
		i++;
	}
	return (push * sign);
}

void	ft_putnbr(int n)
{
	char c;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n == -2147483648)
	{
		write(1, "2", 1);
		n %= 1000000000;
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

int			starting_board_size(int num)
{
    int     factors[10];
    int     num_of_factors;
    int     i;
    int     num_cpy;

    i = num;
    num_of_factors = -1;
    num_cpy = num;
    while (num_cpy != 1)
    {
        while ((i * i) > num_cpy)
            i--;
        if ((i * i) % num_cpy == 0)
        {
            factors[++num_of_factors] = i;
            num_cpy /= (i * i);
            i = num_cpy;
        }
        else
            num_cpy--;
    }
    i = factors[num_of_factors];
    while (--num_of_factors >= 0)
        i *= factors[num_of_factors];
    ft_putstr("i : ");
    ft_putnbr(i);
    ft_putstr("\nstarting_board_size returns : ");
    return ((i * i) == num ? i : i + 2 > num - 2 ? i + 1 : i + 2);
}

int     main(int ac, char **av)
{
    ft_putnbr(starting_board_size(ft_atoi(av[1])));
    write(1, &"\n", 1);
    return (0);
}