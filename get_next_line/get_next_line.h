/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <emaigne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:20:38 by emaigne           #+#    #+#             */
/*   Updated: 2025/11/24 18:16:42 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

size_t		ft_strlen(char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *source );
char		*ft_strdup_free(char *temp);
ssize_t		find_nl(const char *s);
char		*fillthetemp(char *buff, char *temp, int howmuch);
char		*ft_copy_nl(char *tocopy);
char		*keep_after_nl(char *s);
char		*ft_concat(char *s1, char*s2);
char		*get_next_line(int fd);

#endif
