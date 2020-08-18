/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 08:06:54 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/08/18 06:39:10 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H

# include <stdio.h>/// 

# include <stdlib.h>
# include <dirent.h>
# include <time.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>

# include <unistd.h>
# include "../libft/include/libft.h"

typedef struct stat	t_stat;

typedef	struct	s_elem	{

	int		is_error; // if invalid file, just skip it ?!? iguess? idk


	char 	*path;
	t_stat	*stat;


	struct s_elem	*next;
}				t_elem;


typedef struct s_path {

	char *name;
	struct s_path *next;
}				t_path;

typedef struct s_meta {

	t_elem *main_list;
	t_elem *second_list;
	
	t_path *main_p_list;
	t_path *second_p_list;

	//options:
	
	int	l;
	int	R;
	int	r;
	int	t;
	int	a;

}				t_meta;


void	free_and_exit(t_meta *data, char *error_msg);
void	parsing(t_meta *data, int ac, char **av);

#endif
