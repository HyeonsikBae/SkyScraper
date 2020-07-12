/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hybae <gustlr0217@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:46:18 by hybae             #+#    #+#             */
/*   Updated: 2020/07/12 16:07:53 by hybae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		g_size;
int		*g_top;
int		*g_bottom;
int		*g_left;
int		*g_right;
int		**initcell(int size);
void	clueallocate(int *clue);

int		**solve(char *clue, int **answer, int size)
{
	int **board;
	int i;

	g_size = size;
	g_top = (int*)malloc(sizeof(int) * g_size);
	g_bottom = (int*)malloc(sizeof(int) * g_size);
	g_left = (int*)malloc(sizeof(int) * g_size);
	g_right = (int*)malloc(sizeof(int) * g_size);
	**board = initcell(g_size);
	answer = initcell(g_size);
	clueallocate(clue);
	i = 0;
	while (i < g_size)
	{
		backtracking(board);
		i++;
	}
	free(g_top);
	free(g_bottom);
	free(g_left);
	free(g_right);
	return (answer);
}

int		**initcell(int size)
{
	int	**puzzle;
	int	i;
	int	j;

	puzzle = (int**)malloc(sizeof(int*) * size);
	i = 0;
	while (i < size)
	{
		puzzle[i] = (int*)malloc(sizeof(int) * size);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			puzzle[i][j] = 0;
			j++;
		}
		i++;
	}
	return (puzzle);
}

void	clueallocate(char *clue)
{
	int	i;

	i = 0;
	while (i < g_size)
	{
		g_top[i] = (int)(clue[i] - '0');
		g_bottom[i] = (int)(clue[i + 4] - '0');
		g_left[i] = (int)(clue[i + 8] - '0');
		g_right[i] = (int)(clue[i + 12] - '0');
		i++;
	}
}
