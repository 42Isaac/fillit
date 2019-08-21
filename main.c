/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:32:05 by jlagos            #+#    #+#             */
/*   Updated: 2019/08/11 15:32:15 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrominoes.h"

/*
**	Frees the linked list used to store the terominos.
*/

void		free_llist(t_tetrom *head)
{
	t_tetrom	*tmp;
	int			i;

	while(head)
	{
		i = -1;
		while (head->piece[++i])
			ft_strdel(&head->piece[i]);
		free(head->piece);
		tmp = head->next;
		free(head);
		head = tmp;
		ft_
	}
}

/*
**	Jonny doesn't even know how to spell tetrominos.
*/

void		print_grid(char **grid)
{
	int	i;

	i = -1;
	while (grid[++i])
		ft_putendl(grid[i]);
	i = -1;
	while (grid[++i])
		ft_strdel(&grid[i]);
	free(grid);
}

/*
**	It's main. What do you expect.
**	It checks to make sure that the file is valid and creates a linked list
**	containing all the tetrominos (using assemble_tetrominoes) in the file
**	before calling fillit.
**
**	Returns 0 on success. Like a normal function should... Jonny.
*/

int			main(int ac, char **ag)
{
	t_tetrom	*head;
	int			fd;
	int			num_of_pieces;

	fd = open(ag[1], O_RDONLY);
	if (ac == 2 && fd != -1)
	{
		num_of_pieces = 0;
		head = (t_tetrom *)malloc(sizeof(*head));
		head->next = NULL;
		if (fd < 0 || !assemble_tetrominoes(head, &num_of_pieces, fd))
		{
			ft_putstr("error\n");
			free_llist(head);
			return (0);
		}
		print_grid(fillit(head, num_of_pieces));
		free_llist(head);
		close(fd);
		system("leaks fillit");
	}
	else
		ft_putstr("usage:\t./fillit source_file\n");
	return (0);
}
