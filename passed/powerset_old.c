#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	print_numbers(int *print, int size)
{
	for (int i = 0; i < size; i++)
	{
		fprintf(stdout, "%i", print[i]);
		if (i < size - 1)
			fprintf(stdout, " ");
	}
	fprintf(stdout, "\n");
}

void	find_subset(int *set, int size, int *subs, int subset_size, int index, int target)
{
	int	sum = 0;
	for (int i = 0; i < subset_size; i++)
		sum += subs[i];
	if (sum == target)
		print_numbers(subs, subset_size);

	if (index == size)
		return ;

	subs[subset_size] = set[index];
	find_subset(set, size, subs, subset_size + 1, index + 1, target);

	find_subset(set, size, subs, subset_size, index + 1, target);
}

int	powerset(int power, int *set, int *print, int size)
{
	find_subset(set, size, print, 0, 0, power);
}

int	*parse(char **argv, int argc)
{
	int	*buff;
	int	i;

	buff = malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (argv[i])
	{
		buff[i] = atoi(argv[i]);
		i++;
	}
	return (buff);
}

int	main(int argc, char **argv)
{
	int	*numbers;

	numbers = parse(&argv[1], argc);
	int	to_print[argc - 2];;
	powerset(numbers[0], &numbers[1], to_print, argc - 2);
	free(numbers);
}
