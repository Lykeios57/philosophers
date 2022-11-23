/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcacoilo <mcacoilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:31:18 by mcacoilo          #+#    #+#             */
/*   Updated: 2022/11/22 16:48:30 by mcacoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	put(int nth, int job)
{
	static pthread_mutex_t	p;
	static pthread_mutex_t	*pen = NULL;

	if (pen == NULL)
	{
		pen = &p;
		pthread_mutex_init(pen, NULL);
	}
	pthread_mutex_lock(pen);
	if (job == FORK)
		printf("%llu %d has taken a fork\n", runtime_to_ms(), nth);
	else if (job == EAT)
		printf("%llu %d is eating\n", runtime_to_ms(), nth);
	else if (job == SLEEP)
		printf("%llu %d is sleeping\n", runtime_to_ms(), nth);
	else if (job == THINK)
		printf("%llu %d is thinking\n", runtime_to_ms(), nth);
	else
	{
		printf("%llu %d died\n", runtime_to_ms(), nth);
		return ;
	}
	pthread_mutex_unlock(pen);
}
