#include <unistd.h>

void	*ft_strcopy(char *d, char *s)
{
	int	i = 0;

	while (s[i])
	{
		d[i] = s[i];
		i++;
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

void	rip_wrapper(char *s)
{
	int	len = ft_strlen(s);
	char	print[len];

	int	remove = 0;
	int	open = 0;

	for (int i = 0; s[i]; i++)
	{
		if  (s[i] == '(')
			open++;
		else if (s[i] == ')')
		{
			if (open > 0)
				open--;
			else
				remove++;
		}
	}
	remove += open;

	ft_strcopy(print, s);
	rip(s, print, 0, 0, remove, size);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rip_wrapper(argv[1]);
}
