/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:20:58 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/28 15:42:36 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		get_end_room(t_base *info)
{
	info->end_up = 0;
	if (info->end && !(check_room(info, info->end)))
		return (0);
	else
		ft_strdel(&info->end);
	return (1);
}

int		get_tube(t_base *info, char *line)
{
	int		i;
	int		j;

	if (ft_strchr(line, ' ') || ft_count_char(line, '-') > 1)
		return (0);
	if (info->end && !get_end_room(info))
		return (0);
	if (info->a != 2)
		return (0);
	if ((i = check_tube(info, ft_str_nword(line, 0, '-'))) == -1)
		return (0);
	if ((j = check_tube(info, ft_str_nword(line, 1, '-'))) == -1)
		return (0);
	if (!IMX)
		create_matrix(info);
	if (IMX && !(set_matrix(info, i, j)))
		return (0);
	info->nbr_of_tube++;
	return (1);
}

int		check_tube(t_base *info, char *tocheck)
{
	t_list	*tempo;
	int		index;

	tempo = ILH;
	index = 0;
	if (!tocheck)
		return (-1);
	while (ILC->name || ILN != NULL)
	{
		if (!ft_strcmp(ILC->name, tocheck))
		{
			index = ILC->index;
			ILH = tempo;
			free(tocheck);
			return (index);
		}
		if (ILN != NULL)
			ILH = ILN;
		else
			break ;
	}
	ILH = tempo;
	free(tocheck);
	return (-1);
}
