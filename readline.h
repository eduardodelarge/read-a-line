#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#define BUFFER_SIZE 1

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *src, int c);
char	*ft_save_line(char *src);
char	*ft_read_line(char *src);
char	*get_line(char *src, int fd);
char	*get_next_line(int fd);

#endif
