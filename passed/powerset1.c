#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	check_print(char **set, int power, int *sub_mask, int mask_size)
{
	int	sum = 0;
	for (int i = 0; i < mask_size; i++)
		sum += atoi(set[sub_mask[i]]);
	
	if (sum == power)
	{
		for (int i = 0; i < mask_size; i++)
		{
			printf("%i", atoi(set[sub_mask[i]]));
			if (i + 1 < mask_size)
				printf(" ");
		}
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (0);

	int	size = argc - 2;
	int	total_subsets = 1 << (size);

	int	power = atoi(argv[1]);
	for (int i = 0; i < total_subsets; i++)
	{
		int	sub_mask[size];
		int	mask_size = 0;

		for (int j = 0; j < size; j++)
		{
			if (i & (1 << j))
			{
				// saving each unmasked number
				sub_mask[mask_size] = j;
				mask_size++;
			}
		}
		check_print(&argv[2], power, sub_mask, mask_size);
	}
}
