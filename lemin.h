/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:49:11 by labelec           #+#    #+#             */
/*   Updated: 2018/03/07 17:56:59 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "./LibftXen/libft.h"

# define IANT info->fourmi
# define IBE info->base_entry
# define ITB info->tube
# define IMX info->matrix
# define IMSZ info->mxsize
# define IBOO info->boo
# define ILH info->list_house
# define ILC ((t_house *)info->list_house->content)
# define ILN info->list_house->next
# define IPAPA info->papa
# define ILT info->last
# define ISJ info->sj
# define ISI info->si

typedef struct	s_base
{
	char	*base_entry;
	char	*tube;
	int		**matrix;
	char	*end;
	t_list	*list_house;
	int		mxsize;
	int		fourmi;
	int		boo;
	int		index;
	int		a;
	int		**papa;
	int		*last;
	int		sj;
	int		si;
}				t_base;

typedef struct  s_house
{
	int		index;
	char	*name;
	int		ant;
}				t_house;

int		main(void);
int		get_base_entry(t_base *info, char *line);
int		get_room(t_base *info, char *line);
int		get_tube(t_base *info, char	*line);
int		check_room(t_base *info, char *line);
int		check_tube(t_base *info, char *line);
int		list_room(t_base *info, int index, char *name);
int		set_matrix(t_base *info, int a, int b);
int		create_matrix(t_base *info);
int		path_finder(t_base *info, int i, int j);
int		check_path(t_base *info, int i, int j);
int		get_tube_matrice(t_base *info, int	tube, int  *a, int *b);
int		path_finder(t_base *info, int	i, int j);
int		path_finder_sup(t_base *info, int i, int j);

#endif
