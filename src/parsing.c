/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 05:29:06 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/08/18 08:50:47 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"


void	print_path_list(t_path *cur)
{
	int i;

	i = 0;
	while (cur)
	{

		ft_printf("N%d: %s\n",i,  cur->name);
		cur = cur->next;
		i++;
	}

}

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

void	add_to_second_p_list(t_meta *data, t_path *link)
{
	t_path *next_node;
	next_node = data->second_p_list;
	
	link->next = next_node;
	data->second_p_list = link;
}

void	split_path_list(t_meta *data)
{
	t_path	*cur;	
	t_path 	*previous_node;	
	struct stat filestat;
	
	cur = data->main_p_list;
	previous_node = NULL;
	while (cur)
	{	
		ft_bzero(&filestat, sizeof(struct stat));
		stat(cur->name, &filestat);
		if (S_ISDIR(filestat.st_mode))
		{
			if (!previous_node)
				data->main_p_list = cur->next;
			else
				previous_node->next = cur->next;
			add_to_second_p_list(data, cur);
		}
		else
			previous_node = cur;
		cur = previous_node->next;;

	}
}

void	add_to_path_list(t_meta *data, char *name)
{
	t_path 	*next_node;
	t_path	*new_node;

	next_node = data->main_p_list;
	if (!(new_node = ft_memalloc(sizeof(t_path))))
			free_and_exit(data, "Malloc exploded");
	new_node->next = next_node;
	new_node->name = name;
	data->main_p_list = new_node;
}

void	parsing(t_meta *data, int ac, char **av)
{
	int i;
	int end_of_options;

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
			add_to_path_list(data, av[i]);
		}
		i++;
	}
	ft_printf("before split\n");
	print_path_list(data->main_p_list);
	split_path_list(data);
	ft_printf("\n\nafter split\n");
	ft_printf("\nfirst\n");
	print_path_list(data->main_p_list);
	ft_printf("\nsecond\n");
	print_path_list(data->second_p_list);
}


