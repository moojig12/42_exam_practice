#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_popen(const char *file, const char *argv[], char type)
{
	int	pipefd[2];
	pid_t	cpid;

	if (pipe(pipefd) == -1) {
		exit(EXIT_FAILURE);
	}

	cpid = fork();
	if (cpid == -1) {
		exit(EXIT_FAILURE);
	}

	if (cpid == 0) {
		if (type == 'r')
		{
			close(pipefd[0]);
			dup2(pipefd[1], STDOUT_FILENO);
			close(pipefd[1]);
		}
		else if (type == 'w')
		{
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
		}
		execvp(file, (char *const *)argv);
		return (-1);
	}
	else
	{
		if (type == 'r')
		{
			close(pipefd[1]);
			return(pipefd[0]);
		}
		else if (type == 'w')
		{
			close(pipefd[0]);
			return(pipefd[1]);
		}
	}
	return (-1);
}

int main()
{
    int fd = ft_popen("ls", (const char *[]) {"ls", NULL}, 'r');
    char *line;
    while ((line = getc(fd)))
        puts(line);
}

/* int	main(int argc, char **argv)
{
	
} */