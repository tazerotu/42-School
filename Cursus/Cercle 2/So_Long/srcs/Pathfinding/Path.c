/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:25:42 by ttas              #+#    #+#             */
/*   Updated: 2024/10/15 12:44:02 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

void	enqueue(t_queue *queue, t_pos pos)
{
	t_queue_node	*new_node;

	new_node = (t_queue_node *)malloc(sizeof(t_queue_node));
	new_node->pos = pos;
	new_node->next = NULL;
	if (queue->rear == NULL)
	{
		queue->front = new_node;
		queue->rear = new_node;
	}
	else
	{
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
}

t_pos	dequeue(t_queue *queue)
{
	t_queue_node	*temp;
	t_pos			pos;

	if (queue->front == NULL)
	{
		pos.x = -1;
		pos.y = -1;
		return (pos);
	}
	temp = queue->front;
	pos = temp->pos;
	queue->front = queue->front->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	free(temp);
	return (pos);
}

int	is_valid_move(int x, int y, t_map *map, int **visited)
{
	if (x >= 0 && x < map->x && y >= 0 && y < map->y && map->map[y][x] != '1'
		&& !visited[y][x])
	{
		return (1);
	}
	return (0);
}

int	**initialize_visited(t_map *map)
{
	int	**visited;
	int	i;

	i = 0;
	visited = (int **)malloc(map->y * sizeof(int *));
	while (i < map->y)
	{
		visited[i] = (int *)malloc(map->x * sizeof(int));
		ft_memset(visited[i], 0, map->x * sizeof(int));
		i++;
	}
	return (visited);
}

void	free_visited(int **visited, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	init_direction(t_pos *directions)
{
	directions[0] = (t_pos){0, 1};
	directions[1] = (t_pos){1, 0};
	directions[2] = (t_pos){0, -1};
	directions[3] = (t_pos){-1, 0};
}

int	bfs(t_pos *start, t_pos *goal, t_map *map)
{
	int		**visited;
	t_queue	queue;
	t_pos	directions[4];
	t_pos	current;
	t_pos	newPos;
	int		i;
	int		newX;
	int		newY;

	init_direction(directions);
	visited = initialize_visited(map);
	queue.front = NULL;
	queue.rear = NULL;
	enqueue(&queue, *start);
	visited[start->y][start->x] = 1;
	while (queue.front != NULL)
	{
		current = dequeue(&queue);
		if (current.x == goal->x && current.y == goal->y)
		{
			free_visited(visited, map->y);
			return (1); // Path found
		}
		for (i = 0; i < 4; i++)
		{
			newX = current.x + directions[i].x;
			newY = current.y + directions[i].y;
			if (is_valid_move(newX, newY, map, visited))
			{
				visited[newY][newX] = 1;
				newPos = (t_pos){newX, newY};
				enqueue(&queue, newPos);
			}
		}
	}
	free_visited(visited, map->y);
	return (0); // Path not found
}
