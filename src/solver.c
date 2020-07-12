/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hybae <gustlr0217@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:46:18 by hybae             #+#    #+#             */
/*   Updated: 2020/07/12 16:01:36 by hybae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		g_size;
int		*top;
int		*bottom;
int		*left;
int		*right;
int		**initcell(int size);
void	clueallocate(int *clue);

int		**solve(char *clue, int **answer, int size)
{
	int **board;
	int i;

	g_size = size;
	top = (int*)malloc(sizeof(int) * g_size);
	bottom = (int*)malloc(sizeof(int) * g_size);
	left = (int*)malloc(sizeof(int) * g_size);
	right = (int*)malloc(sizeof(int) * g_size);
	**board = initcell(g_size);
	answer = initcell(g_size);
	clueallocate(clue);
	i = 0;
	while (i < g_size)
	{
		backtracking(board);
		i++;
	}
	free(top);
	free(bottom);
	free(left);
	free(right);
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
		top[i] = (int)(clue[i] - '0');
		bottom[i] = (int)(clue[i + 4] - '0');
		left[i] = (int)(clue[i + 8] - '0');
		right[i] = (int)(clue[i + 12] - '0');
		i++;
	}
}
