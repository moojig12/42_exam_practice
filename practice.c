#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i]) i++;
	return (i);
}

void	wrapper(char *set)
{
	printf("%i\n", ft_strlen(set));

	int	i = 0;

	int	nearest = i + 1;

	
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		wrapper(argv[1]);
}