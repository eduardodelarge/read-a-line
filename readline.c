char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *src, int c)
{
	size_t	i;

	i = 0;
	if (src == NULL)
		return (0);
	if (c == '\0')
		return ((char *)&src[ft_strlen(src)]);
	while (src[i] != '\0')
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
		i++;
	}
	return (0);
}

char	*ft_read_line(char *src)
{
	size_t	i;
	char	*str;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_save_line(char *src)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	if (src[i] == '\0')
	{
		free (src);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(src) - i + 1));
	if (str == NULL)
		return (NULL);
	i++;
	j = 0;
	while (src[i] != '\0')
		str[j++] = src[i++];
	str[j] = '\0';
	free (src);
	return (str);
}

char	*get_line(char *src, int fd)
{
	char	*buf;
	int		size;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free (buf);
		return (NULL);
	}
	size = 1;
	while (!ft_strchr(src, '\n') && size != 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[size] = '\0';
		src = ft_strjoin(src, buf);
	}
	free (buf);
	return (src);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next_line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_line = get_line(next_line, fd);
	if (next_line == NULL)
		return (NULL);
	line = ft_read_line(next_line);
	next_line = ft_save_line(next_line);
	if (line[0] == '\0')
	{
		free(next_line);
		free(line);
		return (NULL);
	}
	return (line);
}
