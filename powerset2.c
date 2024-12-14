#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_nums(int *sub, int size)
{
	for (int i = 0; i < size; i++)
	{
		fprintf(stdout, "%i", sub[i]);
		if (i < size - 1)
			fprintf(stdout, " ");
	}
	fprintf(stdout, "\n");
}

void	powerset(int power, int *set, int idx, int *print, int s, int size)
{
	
}

void	powerset_setup(int power, int *set, int size)
{
	int	print[size];

	printf("size:%i\n", size);
	for (int i = 0; i < size; i++)
	{
		powerset(power, set, i, print, 0, size - i);
	}
}

int	*parse(char **argv, int size)
{
	int	*set;

	if (size <= 0)
		return (NULL);
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