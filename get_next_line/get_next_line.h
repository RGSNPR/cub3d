/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiren <ksiren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:00:23 by ksiren            #+#    #+#             */
/*   Updated: 2021/04/26 16:19:38 by ksiren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_newstr(char *s);
int		ft_parse_es(char *s);
int		ft_strlen(const char *s);
char	*ft_strjoin_mod(char *s1, char *s2);
char	*ft_cutost(char *s);

# define BUFFER_SIZE 1

#endif
