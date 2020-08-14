/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 08:06:54 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/08/14 08:57:12 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H



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


typedef struct s_meta {

	t_elem *main_list;


	t_elem *sec_list;

	//options:
	
	int	l;
	int	R;
	int	r;
	int	t;
	int	a;

}				t_meta;

#endif
