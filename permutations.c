#include <unistd.h>
#include <stdio.h>

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swap1(char *s, int i, int j)
{
	char	temp;

	if (i > j)
		ft_swap(&s[i], &s[j]);
	else
	{
		while (j > i)
		{
			temp = s[j];
			s[j] = s[j - 1];
			s[j - 1] = temp;
			j--;
		}
	}
}

void	ft_swap2(char *s, int i, int j)
{
	char	temp;

	if (i > j)
		ft_swap(&s[i], &s[j]);
	else
	{
		while (j > i)
		{
			temp = s[i];
			s[i] = s[i + 1];
			s[i + 1] = temp;
			i++;
		}
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	permute(char *s, int left, int right, int len)
{
	if (left == right)
	{
		puts(s);
		return ;
	}

	for (int i = left; i <= right; i++)
	{
		ft_swap1(s, left, i);
		permute(s, left + 1, right, len);
		ft_swap2(s, left, i);
	}
}

void	permute_wrapper(char *s)
{
	permute(s, 0, ft_strlen(s) - 1, ft_strlen(s));
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		permute_wrapper(argv[1]);
}