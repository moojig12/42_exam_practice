#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	print_nums(int *sub, int size)
{
	printf("Result:");
	for (int i = 0; i < size; i++)
	{
		fprintf(stdout, "%i", sub[i]);
		if (i < size - 1)
			fprintf(stdout, " ");
	}
	fprintf(stdout, "\n");
}

void	powerset(int power, int *set, int idx, int *sub, int sub_idx, int size)
{
	int	sum;

	sum = 0;
	for (int i = 0; i < sub_idx; i++)
		sum += sub[i];
	if (sum == power)
		print_nums(sub, sub_idx);

	if (idx == size)
		return ;
	
	sub[sub_idx] = set[idx];
	powerset(power, set, idx + 1, sub, sub_idx + 1, size);
	printf("sub: %i %i\n", sub_idx, idx);
	powerset(power, set, idx + 1, sub, sub_idx, size);
}

void	powerset_setup(int power, int *set, int size)
{
	int	print[size];

	printf("size:%i\n", size);
	powerset(power, set, 0, print, 0, size);
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
