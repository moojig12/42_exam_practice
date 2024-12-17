#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_print(int n, char **av, int *subset, int sub_size)
{
	int sum = 0;
	for (int i = 0; i < sub_size; i++)
		sum += atoi(av[subset[i]]);

	if (sum == n)
	{
		for (int i = 0; i < sub_size; i++)
		{
			fprintf(stdout, "%s", av[subset[i]]);
			if (i != sub_size - 1)
				fprintf(stdout, " ");
		}
		fprintf(stdout, "\n");
	}
}

int	main(int ac, char **av)
{
	if (ac < 3)
		exit(1);
	int power = atoi(av[1]);
	int	size = ac - 2;
	int total_subsets = 1 << (size); // Equivalent to total_subsets = 2 ^ size;

	for (int i = 1; i < total_subsets; i++)
	{
		int subsets[size];
		int subset_size = 0;

		// Loop for printing from "i" mask
		for (int j = 0; j < size; j++)
		{
			if (i & (1 << j))
			{
				// include j-th element of set av[2] to av[power]
				subsets[subset_size++] = j + 2;
			}
		}
		// Printing function using the subset mask
		check_print(power, av, subsets, subset_size);
	}
}