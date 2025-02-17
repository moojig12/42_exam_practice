/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:58:41 by root              #+#    #+#             */
/*   Updated: 2025/02/16 13:26:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SANDBOX_H
# define SANDBOX_H

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/errno.h>
#include <sys/wait.h>
#include <sys/types.h>

void	hang(void);
void	good(void);
void	bad(void);
void	very_bad(void);
void	naughty(void);

#endif