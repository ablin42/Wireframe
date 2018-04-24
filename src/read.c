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

/*
 * this function add each line read to a list with different informtions
*/

t_read	*addlist(t_read *gnl, char *line, int nbline)
{
	t_read	*element;
	t_read	*tmp;

	if ((element = malloc(sizeof(t_read))) == NULL)
		return (NULL) ;
	tmp = gnl;
	element->line = line;
	element->len = ft_strlen(line);
	element->nbline = OFFSET_Y + (nbline * OFFSET_Y);
	element->next = NULL;
	if (gnl == NULL)
		return (element);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (gnl);
}

/*
 * this function applies an offset to the X values
*/

t_point		**apply_offset(t_point **p)
{
	int		i;
	int		j;

	i = 0;
	while (p[i] != NULL)
	{
		j = 0;
		while (j < p[i]->len)
		{
			p[i][j].x = OFFSET_X + (OFFSET_X * j);
			j++;
		}
		i++;
	}
	return (p);
}

/*
 * ths function allocates the board and place the X Y Z values in it
*/

t_point		**getcoord(t_read *gnl, int nbline)
{
	t_point		**p;
	int			i;
	int			j;
	int			k;

	if ((p = (t_point **)malloc(sizeof(t_point*) * (nbline + 1))) == NULL)
		return (0);
	p[nbline] = NULL;
	i = 0;
	while (gnl->next != NULL)
	{
		j = 0;
		k = 0;
		if ((p[i] = (t_point *)malloc(sizeof(t_point) * (gnl->len + 1))) == NULL)
				return (p);
		while (gnl->line[j] != '\0')
		{
			if (ft_isdigit(gnl->line[j]) == 1)
			{
				p[i][k].z = ft_atoi(&gnl->line[j]);
				p[i][k].x = k;
				p[i][k].y = gnl->nbline;
				k++;
				while (gnl->line[j] != '\0' && ft_isdigit(gnl->line[j]) == 1)
					j++;
			}
			while (gnl->line[j] != '\0' && ft_isdigit(gnl->line[j]) == 0)
					j++;
		}
		p[i]->len = k;
		p[0]->nbline = gnl->nbline; //this is for the top and left corner but disgusting
		i++;
		gnl = gnl->next;
	}
	return (apply_offset(p));
}

/*
 * this function read the file and call to the other functions
*/

t_point		**readfile(char *file)
{
	t_read		*gnl;
	t_map		*map;
	int			nbline;

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
}
