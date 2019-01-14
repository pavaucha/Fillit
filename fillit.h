/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:19:30 by lezhang           #+#    #+#             */
/*   Updated: 2017/11/29 10:52:15 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_tetri
{
	char	**tetri;
	char	letter;
	size_t	x[4];
	size_t	y[4];
	size_t	xy[2];
}				t_tetri;

int				ft_arg(int argc);
char			**ft_verif_total(char **argv);
t_tetri			**ft_creat_struct(char **str, t_tetri **stock);
void			ft_go_fillit(t_tetri **stock);
char			*ft_read_file(char *argv);
char			*ft_read(int fd, char *str);
int				ft_verif_form(char *str);
int				ft_check_around(char **tab, int i, int j);
char			**ft_test_valid(char **src, size_t i, size_t j, size_t point);
char			**ft_norme(char **src);
size_t			ft_count_tetri(size_t i);
char			**ft_verif_termi(char *str);
size_t			ft_nb_cara(char *str);
char			**ft_strnew_c(size_t size, char c);
char			**ft_fillit_in(char **result, t_tetri **stock, size_t size);
char			**ft_tab(char **result, t_tetri **stock, size_t size);
int				ft_existe(char **result, char c);
t_tetri			*ft_stock_termi(char *str);
t_tetri			*ft_stock_d(t_tetri *stock);
void			ft_strfree(char **str);
size_t			ft_size_map(t_tetri **stock);
size_t			ft_nb_tetri(t_tetri **stock);
char			**ft_del_tetri(char **result, char c);
char			**ft_place(char **result, t_tetri *stock);
int				ft_isvalid(char **result, t_tetri *stock, size_t size);

#endif
