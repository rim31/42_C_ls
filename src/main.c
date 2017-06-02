/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:33:34 by oseng             #+#    #+#             */
/*   Updated: 2016/07/23 16:15:17 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct dirent *dp;

void ft_la(char *path)
{
	struct stat fileStat;
	struct stat statbuf;
	struct group *grp;
	struct passwd *pwd;
	time_t t;
    struct tm *tb;


	if(stat(path, &fileStat) < 0)
	    exit(0);
	ft_putstr( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	ft_putstr( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr( (fileStat.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
	ft_putstr(" ");
	ft_putnbr(fileStat.st_nlink);//number of link
	ft_putstr(" ");
	if ((pwd = getpwuid(statbuf.st_uid)) != NULL)
		ft_putstr(pwd->pw_name);
	else
		ft_putnbr(statbuf.st_uid);
	ft_putstr(" ");
	if ((grp = getgrgid(statbuf.st_gid)) != NULL)
		ft_putstr(grp->gr_name);
	else
		ft_putnbr(statbuf.st_gid);
	ft_putstr(" ");
	ft_putnbr(fileStat.st_size);
	ft_putstr(" \n");
	ft_putnbr(statbuf.st_ctime);
	ft_putstr(" \n");
	time(&t);
    tb = localtime(&statbuf.st_ctime);
	printf("date et heure : %s*****\n", ctime(&t));
	printf("date et heure : %s", asctime(tb));
	//=======================
	printf("%u ",fileStat.st_rdev);
	printf("%u ",fileStat.st_mode);
	printf("Information for %s\n",path);
	printf("---------------------------\n");
	printf("File Size: \t\t%lld bytes\n",fileStat.st_size);

	printf("File inode: \t\t%llu\n",fileStat.st_ino);
		printf("File Permissions: \t");

	printf("\n\n");
		printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
}


// void	ft_stat(char *path)
// {
// 	struct stat fileStat;
//
// 	if(stat(path, &fileStat) < 0)
// 		exit(0);
// 	printf("Information for %s\n",path);
// 	printf("---------------------------\n");
// 	printf("File Size: \t\t%lld bytes\n",fileStat.st_size);
// 	printf("Number of Links: \t%d\n",fileStat.st_nlink);
// 	printf("File inode: \t\t%llu\n",fileStat.st_ino);
// 	printf("File Permissions: \t");
// 	printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
// 	printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
// 	printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
// 	printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
// 	printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
// 	printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
// 	printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
// 	printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
// 	printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
// 	printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
// 	printf("\n\n");
// 	printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
//
// }

void	open_directory(char *path)
{
	struct stat buffer;
	int 		status;
	DIR			*dirp;

	status = 1;
	dirp = opendir(path);
	if (dirp == NULL)
			exit(0);
	// len = strlen(path);
	while ((dp = readdir(dirp)) != NULL)
	{
		status = lstat(dp->d_name, &buffer);
		printf("%d ", status);
		printf("%s\n", dp->d_name);


		ft_la(path);

			// if (dp->d_namlen == len && strcmp(dp->d_name, name) == 0) {
			// 		(void)closedir(dirp);
			// 		return (FOUND);
			// }
	}
	(void)closedir(dirp);
}

int	main(int argc, char **argv)
{
	DIR	*rep;

	rep = NULL;
	if (argc == 2)
	{
		open_directory(argv[1]);
	}
	return (0);
}
