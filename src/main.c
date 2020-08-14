#include "ftls.h"

//int main(int ac, char **av)
//{
//	(void)ac;
//	(void)av;
//	if (ac > 1)
//		ft_printf("\033[0;31m%s[%s]\033[0m\n","test", av[1]);
//	DIR *dirtruc = NULL;
//	dirtruc = opendir(".");
//	struct dirent *dir = NULL;
//	struct stat filestat;
//	struct passwd * pass;
//	struct group * gr;
//	int total = 0;
//	while ((	dir = readdir(dirtruc)) != 0)
//		{
//		    stat(dir->d_name , &filestat);
//			if (dir->d_name[0] != '.')
//			{
//				total += filestat.st_blocks;
//				ft_printf("'%s'\n", dir->d_name);
//				pass = getpwuid(filestat.st_uid);
//				gr = getgrgid(filestat.st_gid);
//				ft_printf("perms = %o\n", filestat.st_mode);
//				ft_printf("user_name = %s\n", pass->pw_name);
//				ft_printf("group_name = %s\n", gr->gr_name);
//				ft_printf("links = %d\n", filestat.st_nlink);
//				ft_printf("time:%s \n",ctime(&filestat.st_atimespec.tv_sec));
//				ft_printf("size:%lld \n", filestat.st_size);
//			}
//		}
//		ft_printf("total: %d\n", total);
//		closedir(dirtruc);
//		return(1);
//}


void	free_and_exit(t_meta *data)
{
	(void)data;
	// Free tibet
	// free palestine
	//	free julian assange
	//	free box
	//	free to play


	exit(1);
}

int main(int ac, char **av)
{
	t_meta data;

	ft_bzero(&data, sizeof(t_meta));
	

	arg_parsing(&data, ac, av);
	

	
	ls(&data);
	
	
		
	return(1);
}
