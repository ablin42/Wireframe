#include "../include/wire.h"
#include <stdio.h>

void		testlist(t_read *gnl)
{
	while (gnl->next != NULL)
	{
		ft_putstr(gnl->line);
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

t_point		**getcoord(t_read *gnl, int nbline)
{
	t_point		**p;
	int			i;
	int			j;
	int			k;
	int			x;//
	int			y;//
	y = 50;//

	if ((p = (t_point **)malloc(sizeof(t_point*) * (nbline + 1))) == NULL)
		return (0);
	i = 0;
	while (gnl->next != NULL)
	{
		j = 0;
		k = 0;
		x = 50;//
		if ((p[i] = (t_point *)malloc(sizeof(t_point) * (gnl->len + 1))) == NULL)
				return (p);
		while (gnl->line[j] != '\0')
		{
			if (ft_isdigit(gnl->line[j]) == 1)
			{
				p[i][k].z = ft_atoi(&gnl->line[j]);
				p[i][k].x = k + x;//
				x += 50;//
				p[i][k].y = gnl->nbline + y;//
				k++;
				while (gnl->line[j] != '\0' && ft_isdigit(gnl->line[j]) == 1)
					j++;
			}
			while (gnl->line[j] != '\0' && ft_isdigit(gnl->line[j]) == 0)
					j++;
		}
		i++;
		y += 50;//
		gnl = gnl->next;
	}
	return (p);
}

t_point		**readfile(char *file, t_map *map)
{
	t_read		*gnl;
	int			nbline;
	//int	i;
	//int	j;
	//j = 0;
	//i = 0;

	gnl = NULL;
	nbline = 0;
	if ((map->fd = open(file, O_RDONLY)) < 0)
		return (0);
	while (get_next_line(map->fd, &map->line) > 0)
	{
		gnl = addlist(gnl, map->line, nbline);
		nbline++;
	}
	gnl = addlist(gnl, map->line, nbline);
	close(map->fd);
	testlist(gnl);
	return (getcoord(gnl, nbline));
/*	while (i <= 10)
	{
		j = 0;
		while (j < 19)
		{
		//	printf("x = %d y = %d z = %d]\n",(int)p[i][j].x, (int)p[i][j].y, (int)p[i][j].z);
			ft_putnbr((int)p[i][j].z);
				ft_putstr("  ");
			j++;
		}
		ft_putchar('\n');
		i++;
	}*/
}
