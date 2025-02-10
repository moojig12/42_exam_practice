#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i]) i++;
	return i;
}

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swap1(char *s, int i, int j)
{
	if (i > j)
		ft_swap(&s[i], &s[j]);
	else
	{
		while(j > i)
		{
			ft_swap(&s[j], &s[j - 1]);
			j--;
		}
	}
}

void	ft_swap2(char *s, int i, int j)
{
	if (i > j)
		ft_swap(&s[i], &s[j]);
	else
	{
		while (j > i)
		{
			ft_swap(&s[i], &s[i + 1]);
			i++;
		}
	}
}

void	permute(char *set, int left, int right)
{
	if (left == right)
	{
		puts(set);
		return ;
	}

	for (int i = left; i < right; i++)
	{
		ft_swap1(set, left, i);
		permute(set, left + 1, right);
		ft_swap2(set, left, i);
	}
}

int	main(int argc, char **argv)
{
	permute(argv[1], 0, ft_strlen(argv[1]));
}
