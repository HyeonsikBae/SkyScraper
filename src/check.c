/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hybae <gustlr0217@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:44:30 by hybae             #+#    #+#             */
/*   Updated: 2020/07/12 19:22:52 by hybae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		moveresult(int row, int col, int rowzero, int colzero, int *rowtocol);
int		*g_top;
int		*g_bottom;
int		*g_left;
int		*g_right;
int		g_size;
int		**board;

int		checkconflict(int **board, int row, int col, int guess)
{
	int	a;
	int	b;

	a = duplicate(board, row, col, guess);
	b = move(board, row, col);
	if ((a == -1) && (b == -1))
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}

int		duplicate(int **board, int row, int col, int guess)
{
	int	i;

	i = 0;
	while (i < g_size)
	{
		if (i == col)
			continue;
		if (board[row][i] == guess)
			return (1);
		i++;
	}
	i = 0;
	while (i < g_size)
	{
		if (i == row)
			continue;
		if (board[i][col] == guess)
			return (1);
		i++;
	}
	return (-1);
}

int		move(int **board, int row, int col)
{
	int rowzero;
	int colzero;
	int i;
	int j;
	int *coltorow;

	coltorow = (int*)malloc(sizeof(int) * g_size);
	i = 0;
	while (i < g_size)
	{
		coltorow[i] = board[i][col];
		i++;
	}
	rowzero = 0;
	i = 0;
	while (i < g_size)
	{
		if (board[row][i] == 0)
		{
			rowzero = 1;
			break ;
		}
		i++;
	}
	colzero = 0;
	i = 0;
	while (i < g_size)
	{
		if (board[i][col] == 0)
		{
			colzero = 1;
			break ;
		}
		i++;
	}
	return (moveresult(row, col, rowzero, colzero, coltorow));
}

int		moveresult(int row, int col, int rowzero, int colzero, int *coltorow)
{
	int a;
	int b;

	if ((rowzero == 1) && (colzero == 1))
		return (1);
	else if (!(rowzero == 1) && (colzero == 1))
		return (checkrow(g_left[g_size - 1 - row], g_right[row], board[row]));
	else if ((rowzero == 1) && !(colzero == 1))
		return (checkrow(g_top[col], g_bottom[g_size - 1 - col], coltorow));
	a = checkrow(g_top[col], g_bottom[g_size - 1 - col], coltorow);
	b = checkrow(g_left[g_size - 1 - row], g_right[row], board[row]);
	if ((a == 1) && (b == 1))
		return (1);
	else
		return (-1);
}
