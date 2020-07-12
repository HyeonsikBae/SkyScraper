/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hybae <gustlr0217@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 17:10:01 by hybae             #+#    #+#             */
/*   Updated: 2020/07/12 20:23:17 by hybae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "check.h"

int		*findemptycell(int **board);
int		backagain(int **board, int row, int col);

int		g_size;
int		**g_answer;

int		backtracking(int **board, int **answer, int size)
{
	int	*emptycell;
	int	rowi;
	int	colj;

	g_answer = answer;
	g_size = size;
	emptycell = findemptycell(board);
	if (emptycell[0] == -1)
	{
		rowi = -1;
		while (rowi++ < g_size)
		{
			colj = -1;
			while (colj++ < g_size)
			{
				g_answer[rowi][colj] = board[rowi][colj];
			}
		}
		free(emptycell);
		return (1);
	}
	rowi = emptycell[0];
	colj = emptycell[1];
	return (backagain(board, rowi, colj));
}

int		backagain(int **board, int row, int col)
{
	int guess;
	int safe;

	guess = 0;
	while (guess < g_size)
	{
		board[row][col] = guess;
		safe = checkconflict(board, row, col, guess);
		if (safe == 1)
		{
			if (backtracking(board, g_answer, g_size) == 1)
				return (1);
			else
				board[row][col] = 0;
		}
		else
			board[row][col] = 0;
		guess++;
	}
	return (-1);
}

int		*findemptycell(int **board)
{
	int	*emptycell;
	int	i;
	int	j;

	emptycell = (int*)malloc(sizeof(int) * 2);
	emptycell[0] = -1;
	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (j < g_size)
		{
			if (board[i][j] == 0)
			{
				emptycell[0] = i;
				emptycell[1] = j;
				return (emptycell);
			}
			j++;
		}
		i++;
	}
	return (emptycell);
}
