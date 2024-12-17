#include <unistd.h>

int	put_char(char c)
{
	write(1, &c, 1);
	return (0);
}

int	str_len(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

void	str_copy(char *dest, char *origin)
{
	int	i = 0;

	while (origin[i])
	{
		dest[i] = origin[i];
		i++;
	}
	dest[i] = '\0';
}

int	rip(char *s, char *print, int idx, int open, int remove, int size)
{
	if (!s[idx]) {
		if (open == 0 && remove == 0)
		{
			write(1, print, str_len(print));
			write(1, "\n", 1);
		}
		return (0);
	}

	print[idx] = s[idx];
	if (s[idx] == '(')
		rip(s, print, idx + 1, open + 1, remove, size);
	else if (s[idx] == ')' && open > 0)
		rip(s, print, idx + 1, open - 1, remove, size);
	if (remove > 0)
	{
		print[idx] = ' ';
		rip(s, print, idx + 1, open, remove - 1, size);
	}

}

void	wrapper(char *brackets, int size)
{
	int	remove = 0;
	int	open = 0;
	char	print[size + 1];

	for (int i = 0; brackets[i]; i++)
	{
		if (brackets[i] == '(')
			open++;
		else if (brackets[i] == ')')
		{
			if (open > 0)
				open--;
			else
				remove++;
		}
	}
	remove += open;
	str_copy(print, brackets);
	rip(brackets, print, 0, 0, remove, size);
}

int	main(int argc, char **argv)
{
	wrapper(argv[1], str_len(argv[1]));
}
