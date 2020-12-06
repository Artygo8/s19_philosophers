/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:51:40 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/16 16:51:40 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_put_action(size_t id, int e_action)
{
	if (pthread_mutex_lock(&((*get_data())->block)))
		return (ft_error(ERROR_MUTEX_LOCK));
	ft_put_abs_time();
	write(1, " ", 1);
	ft_putunbr(id);
	if (e_action == FORKING)
		ft_putstr_fd(" has taken fork\n", STDOUT_FILENO);
	if (e_action == EATING)
		ft_putstr_fd(" is eating\n", STDOUT_FILENO);
	if (e_action == SLEEPING)
		ft_putstr_fd(" is sleeping\n", STDOUT_FILENO);
	if (e_action == THINKING)
		ft_putstr_fd(" is thinking\n", STDOUT_FILENO);
	if (e_action == DYING)
	{
		ft_putstr_fd(" died\n", STDOUT_FILENO);
		(*get_data())->finish = 1;
	}
	if (pthread_mutex_unlock(&((*get_data())->block)))
		return (ft_error(ERROR_MUTEX_UNLOCK));
	return (0);
}
