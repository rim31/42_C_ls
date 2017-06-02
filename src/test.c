#include "ft_ls.h"

// void ft_print_folder(DIR* rep, dirent *file);
struct dirent *file;
void ft_print_folder(DIR* rep)
{
	if ((file = readdir(rep)) == NULL)
		return ;
	else
	{
		if (ft_strcmp(file->d_name, ".") != 0 && ft_strcmp(file->d_name, "..") != 0)
			printf("%s\n", file->d_name);
	}
	ft_print_folder(rep);
}

int	main(int argc, char **argv)
{
	DIR	*rep;
	// struct dirent *file;

	rep = NULL;
	if (argc == 2)
	{
		printf("%s\n", argv[1]);
		rep = opendir(argv[1]); /* Ouverture d'un dossier */
		if (rep == NULL) /* Si le dossier n'a pas pu être ouvert */
		exit(1); /* (mauvais chemin par exemple) */
		printf("Le dossier a ete ouvert avec succes\n");

		// file = readdir(rep);
		ft_print_folder(rep);
		// printf("\n%s\n%hhu\n\n", file->d_name, file->d_type);
		if (closedir(rep) == -1) /* S'il y a eu un souci avec la fermeture */
		exit(-1);
		printf("Le dossier a ete ferme avec succes\n");
	}
	return (0);
}
