/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:25:42 by ttas              #+#    #+#             */
/*   Updated: 2024/09/05 11:33:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

typedef struct {
	int x;
	int y;
} Point;

int isValidMove(int x, int y, int rows, int cols, char** map, int** visited) {
	if (x >= 0 && x < rows && y >= 0 && y < cols && map[x][y] != '1' && !visited[x][y]) {
		return 1;
	}
	return 0;
}

int bfs(int startX, int startY, int endX, int endY, int rows, int cols, char** map) {
	int** visited = malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++) {
		visited[i] = malloc(cols * sizeof(int));
		memset(visited[i], 0, cols * sizeof(int));
	}

	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};

	Queue* queue = createQueue();
	enqueue(queue, (Point){startX, startY});
	visited[startX][startY] = 1;

	while (!isEmpty(queue)) {
		Point current = dequeue(queue);

		if (current.x == endX && current.y == endY) {
			freeQueue(queue);
			for (int i = 0; i < rows; i++) {
				free(visited[i]);
			}
			free(visited);
			return 1; // Path found
		}

		for (int i = 0; i < 4; i++) {
			int newX = current.x + dx[i];
			int newY = current.y + dy[i];

			if (isValidMove(newX, newY, rows, cols, map, visited)) {
				visited[newX][newY] = 1;
				enqueue(queue, (Point){newX, newY});
			}
		}
	}

	freeQueue(queue);
	for (int i = 0; i < rows; i++) {
		free(visited[i]);
	}
	free(visited);

	return 0; // Path not found
}
