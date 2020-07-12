/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hybae <gustlr0217@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 17:10:01 by hybae             #+#    #+#             */
/*   Updated: 2020/07/12 18:27:56 by hybae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*findemptycell(int **board);

int		g_size;
int		**g_answer;

int		backtracking(int **board, int **answer, int size)
{
	int	*emptycell;
	int	rowi;
	int	colj;
	int guess;
	int safe;

	g_answer = answer;
	g_size = size;
	emptycell = findemptycell(board);
	if(emptycell[0] == -1)
	{
		rowi = 0;
		while (rowi < g_size)
		{
			colj = 0;
			while (colj < g_size)
			{
				g_answer[rowi][colj] = board[rowi][colj];
				colj++;
			}
			rowi++;
		}
		free(emptycell);
		return (1);
	}
	rowi = emptycell[0];
	colj = emptycell[1];
	guess = 0;
	while (guess < g_size)
	{
		board[rowi][colj] = guess;
		safe = checkconflict(board, rowi, colj, guess);
		if (safe == 1)
		{
			if (backtracking(board, g_answer, g_size) == 1)
			{
				return (1);
			}
			else
			{
				board[rowi][colj] = 0;
			}
		}
		else
		{
			board[rowi][colj] = 0;
		}
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
		while(j < g_size)
		{
			if(board[i][j] == 0)
			{
				emptycell[0] = i;
				emptycell[1] = j;
				return (emptycell);
			}
			return (emptycell);
		}
	}
}
