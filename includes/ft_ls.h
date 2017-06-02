/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 12:42:52 by oseng             #+#    #+#             */
/*   Updated: 2016/07/23 15:19:40 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include "./libft.h"


typedef struct		s_env
{
	struct dirent	info;
	struct stat		status;
	struct s_env 	*next;
}					t_env;

// struct dirent { reddir
//     ino_t          d_ino;       /* numéro d'inœud */
//     off_t          d_off;       /* décalage jusqu'à la dirent suivante */
//     unsigned short d_reclen;    /* longueur de cet enregistrement */
//     unsigned char  d_type;      /* type du fichier */
//     char           d_name[256]; /* nom du fichier */
// };

// struct stat { stat
//     dev_t     st_dev;      /* ID du périphérique contenant le fichier */
//     ino_t     st_ino;      /* Numéro inœud */
//     mode_t    st_mode;     /* Protection */
//     nlink_t   st_nlink;    /* Nb liens matériels */
//     uid_t     st_uid;      /* UID propriétaire */
//     gid_t     st_gid;      /* GID propriétaire */
//     dev_t     st_rdev;     /* ID périphérique (si fichier spécial) */
//     off_t     st_size;     /* Taille totale en octets */
//     blksize_t st_blksize;  /* Taille de bloc pour E/S */
//     blkcnt_t  st_blocks;   /* Nombre de blocs alloués */
//     time_t    st_atime;    /* Heure dernier accès */
//     time_t    st_mtime;    /* Heure dernière modification */
//     time_t    st_ctime;    /* Heure dernier changement état */
// };


//   struct passwd {
//     char   *pw_name;   /* Nom d'utilisateur             */
//     char   *pw_passwd; /* Mot de passe                  */
//     uid_t   pw_uid;    /* ID de l'utilisateur           */
//     gid_t   pw_gid;    /* ID du groupe de l'utilisateur */
//     char   *pw_gecos;  /* Nom réel de l'utilisateur     */
//     char   *pw_dir;    /* Répertoire de connexion       */
//     char   *pw_shell;  /* Programme Shell de connexion  */
//   };


#endif
