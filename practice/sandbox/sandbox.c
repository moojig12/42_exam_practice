/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:25:48 by root              #+#    #+#             */
/*   Updated: 2025/02/16 13:29:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

void	sig_handler(int signum)
{
	printf("%d\n", signum);
}

int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	struct sigaction sigma;

	sigma.sa_handler = &sig_handler;
	sigaction(SIGALRM, sigma, NULL);
	alarm(timeout);
	f();
}

int	main(int argc, char **argv)
{
	int	verbose;

	if (argc > 1)
		verbose = 1;
	else
		verbose = 0;

	sandbox(good, 5, verbose);
	sandbox(hang, 5, verbose);
	sandbox(bad, 5, verbose);
	sandbox(very_bad, 5, verbose);
	sandbox(naughty, 5, verbose);
	printf("%s\n", argv[0]);
}