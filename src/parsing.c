/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 05:29:06 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/08/18 06:14:40 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"
void	get_option(t_meta *data, char *opt)
{
	int i;

	i = 1;
	while (opt[i])
	{
		if (opt[i] == 'l')
			data->l = 1;
		else if (opt[i] == 'R')
			data->R = 1;
		else if (opt[i] == 'r')
			data->r = 1;
		else if (opt[i] == 't')
			data->t = 1;
		else if (opt[i] == 'a')
			data->a = 1;
		else
			free_and_exit(data, "Illegal option");
		i++;
	}
}


//split_path_list()
void	add_to_path_list(char *item)
{

}

void	parsing(t_meta *data, int ac, char **av)
{
	int i;
	int end_of_options;
	
	t_path_list = plist;

	i = 1;
	end_of_options = 0;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-' && !end_of_options)
			end_of_options = 1;
		else if (av[i][0] == '-' && !end_of_options)
			get_option(data, av[i]);
		else
		{
			end_of_options = 1;
			add_to_path_list();

		}

//		else
//			add_to_path_list();
		i++;
	}
//	split_path_list();
}
