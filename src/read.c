#include "../include/wire.h"
#include <stdio.h>

void		ft_getvalues(t_map *map, int k, int linesize)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	j = 0;
	while (map->line[i] != '\0')
	{
		while (ft_isdigit(map->line[i]) == 1)
		{
			map->z[k][j] += ft_atoi(&map->line[i]);
			i++;
			if (map->line[i] == '\0' || ft_isdigit(map->line[i]) == 0)
			{
				ft_putstr(ft_itoa(map->z[k][j]));
				j++;
				break;
			}
		}
		i++;
	}
	map->z[k][j] = 'x';
	ft_putchar('\n');
}

void		testlist(t_read *gnl)
{
	while (gnl->next != NULL)
	{
		ft_putstr(gnl->line);
		ft_putnbr(gnl->len);
		ft_putchar('\n');
		gnl = gnl->next;
	}
}

t_read	*addlist(t_read *gnl, char *line, int nbline)
{
	t_read	*element;
	t_read	*tmp;

	if ((element = malloc(sizeof(t_read))) == NULL)
		return (NULL) ;
	tmp = gnl;
	element->line = line;
	element->len = ft_strlen(line);
	element->nbline = nbline;
	element->next = NULL;
	if (gnl == NULL)
		return (element);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (gnl);
}

t_read		*parseline(t_read *gnl)
{
	int		i;
	int		j;
	char	*str;


	if ((str = malloc(sizeof(char *) * (gnl->len + 1))) == NULL)
		return (0);
	i = 0;
	j = 0;
	while (gnl->next != NULL)
	{
		while (gnl->line[i] != '\0')
		{
			while (ft_isdigit(gnl->line[i]) == 1)
			{
				
			}
			i++;
		}
		gnl = gnl->next;
	}
	return (gnl);
}

t_point		**getcoord(t_read *gnl, int nbline)
{
	t_point		**p;
	int			i;
	int			j;
	int			k;

	if ((p = (t_point **)malloc(sizeof(t_point*) * (nbline + 1))) == NULL)
		return (0);
	i = 0;
	while (gnl->next != NULL)
	{
		j = 0;
		k = 0;
		while (gnl->line[j] != '\0')
		{
			if ((p[i] = (t_point *)malloc(sizeof(t_point) * (gnl->len + 1))) == NULL)
				return (p);
			if (ft_isdigit(gnl->line[j]) == 1)
			{
				p[i][k].z = ft_atoi(&gnl->line[i]);
				p[i][k].x = k;
				p[i][k].y = gnl->nbline;
				ft_putnbr((int)p[i][k].x);
				k++;
				while (gnl->line[j] != '\0' && ft_isdigit(gnl->line[j]) == 1)
					j++;
			}
			else
				j++;
		}
		ft_putchar('\n');
		i++;
		gnl = gnl->next;
	}
	j = 0;
		while (j < 19)
		{
			printf("x = %d y = %d z = %d] | ",(int)p[0][j].x, (int)p[0][j].y, (int)p[0][j].z);
			j++;
		}
		ft_putchar('\n');

	return (p);
}

void		readfile(char *file, t_map *map)
{
	t_read		*gnl;
	t_point		**p;
	int			nbline;
	int	i;
	int	j;
	j = 0;
	i = 0;

	gnl = NULL;
	nbline = 0;
	if ((map->fd = open(file, O_RDONLY)) < 0)
		return ;
	while (get_next_line(map->fd, &map->line) > 0)
	{
		gnl = addlist(gnl, map->line, nbline);
		nbline++;
	}
	close(map->fd);
	testlist(gnl);
	//gnl = parseline(gnl);
	p = getcoord(gnl, nbline);
	j = 0;
	/*	while (j < 19)
		{
			printf("x = %d y = %d z = %d] | ",(int)p[i][j].x, (int)p[i][j].y, (int)p[i][j].z);
			j++;
		}
		ft_putchar('\n');*/
}
