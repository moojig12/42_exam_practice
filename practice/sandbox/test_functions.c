/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:59:04 by root              #+#    #+#             */
/*   Updated: 2025/02/16 13:28:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

void	good(void)
{
	printf("C'est moi! Je suis un processus!\n");
}

void	bad(void)
{
	char	*c;

	printf("%s", c);
}

void	hang(void)
{
	usleep(50);
}
void	very_bad(void)
{
	void	(*i)(void);

	while (1)
	{
		i++;
	}
}

void	naughty(void)
{
	struct sigaction sa;

	sigfillset(sa.sa_mask);
	usleep(10);
}