#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	print_numbers(int *print, int size, int mask)
{
	for (int i = 0; i < size; i++)
	{
		fprintf(stdout, "%i", print[i]);
		if (i < size - 1)
			fprintf(stdout, " ");
	}
	fprintf(stdout, "\n");
}

void	powerset(int power, int *set, int *print, int size)
{
	int	mask;

	
}

void	powerset_setup(int power, int *set, int size)
{
	int	print[size];

	powerset(power, set, print, size);
}

int	*parse(char **argv, int size)
{
	int	*set;

	set = malloc(sizeof(int) * size);

	for (int i = 0; argv[i]; i++)
		set[i] = atoi(argv[i]);
	return (set);
}

int	main(int argc, char **argv)
{
	int	*set;

	set = parse(&argv[1], argc - 1);
	if (!set)
		return (0);
	powerset_setup(set[0], &set[1], argc - 2);
}
