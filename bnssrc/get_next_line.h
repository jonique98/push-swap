/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:13:12 by sumjo             #+#    #+#             */
/*   Updated: 2023/05/23 17:47:09 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
int			ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2, int i, int j);
char		*free_arr(char **original);
int			is_line(char *arr);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif
#endif
