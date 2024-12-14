#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	powerset(int power, int *set, int idx, int *sub, int sub_idx, int size)
{
	int	sum;

	sum = 0;
	for (int i = 0; i < sub_idx; i++)
	{
		sum += sub[i];
	}
	if (sum == power)
	{
		print_nums(sub, sub_idx);
	}
}

void	powerset_setup(int power, int *set, int size)
{
	int	print[size];

	powerset(power, set, 0, print, 0, size);
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
