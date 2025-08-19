#include "cub3d.h"
int	ft_isdigit(int a)
{
	return ((a >= '0' && a <= '9'));
}

int	jumper(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	rgb_atoi(const char *str)
{
	int	isaret;
	int	basamak;
	int	i;

	isaret = 1;
	basamak = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isaret *= -1;
		i++;
	}
	while (str[i])
	{
        if(str[i] >= '0' && str[i] <= '9')
		    basamak = basamak * 10 + (str[i] - '0');
        else if(!jumper(str[i]))
            return(-1);
		i++;
    }
	return (isaret * basamak);
}


int main()
{
    char str[] = "  0  ";
    printf("-%d-\n", ft_atoi(str));

    return (0);

}