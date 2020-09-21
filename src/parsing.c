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


void	print_path_list(t_path *list)
{
	t_path *cur;
	int i;

	i = 0;
	cur = list;
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

void	add_to_plist(t_path **plist, t_path *link)
{
	link->next = *plist;
	*plist = link;
}

void	split_parsing_list(t_meta *data, int split)
{
	t_path *cur;
	t_path *next;
	struct stat filestat;
	
	cur = data->parsing_list;
	next = cur->next;
	while (cur)
	{

		ft_bzero(&filestat, sizeof(struct stat));
		stat(cur->name, &filestat);
		printf("currently seing: %s, isdir? %d \n", cur->name, S_ISDIR(filestat.st_mode));
		if (split && S_ISDIR(filestat.st_mode))
			add_to_plist(&data->second_p_list, cur);
		else
			add_to_plist(&data->main_p_list, cur);
		cur = next;
		if (cur)
			next = cur->next;
	}
}

void	add_to_parsing_list(t_meta *data, char *name)
{
	t_path 	*next_node;
	t_path	*new_node;

	next_node = data->parsing_list;
	if (!(new_node = ft_memalloc(sizeof(t_path))))
			free_and_exit(data, "Malloc exploded");
	new_node->next = next_node;
	new_node->name = name;
	data->parsing_list = new_node;
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
			add_to_parsing_list(data, av[i]);
		}
		i++;
	}

	ft_printf("parsing_list\n");
	print_path_list(data->parsing_list);
	
	
		split_parsing_list(data, 1);
	
		ft_printf("MAIN\n");
		print_path_list(data->main_p_list);
		
		ft_printf("SECND\n");
		print_path_list(data->second_p_list);
}
