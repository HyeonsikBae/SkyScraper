/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hybae <gustlr0217@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:44:30 by hybae             #+#    #+#             */
/*   Updated: 2020/07/12 22:26:12 by hybae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "check2.h"

int		moveresult(int row, int col, int rowzero, int colzero);
int		duplicate(int row, int col, int guess);
int		movecheck(int row, int col, int rowzero, int colzero);
int		move(int row, int col);
int		*g_top;
int		*g_bottom;
int		*g_left;
int		*g_right;
int		g_size;
int		**g_board;
int		*g_coltorow;

int		checkconflict(int **board, int row, int col, int guess)
{
	int	a;
	int	b;

	g_board = board;
	a = duplicate(row, col, guess);
	b = move(row, col);
	if ((a == -1) && (b == -1))
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}

int		duplicate(int row, int col, int guess)
{
	int	i;

	i = 0;
	while (i < g_size)
	{
		if (i == col)
			continue;
		if (g_board[row][i] == guess)
			return (1);
		i++;
	}
	i = 0;
	while (i < g_size)
	{
		if (i == row)
			continue;
		if (g_board[i][col] == guess)
			return (1);
		i++;
	}
	return (-1);
}

int		move(int row, int col)
{
	int rowzero;
	int colzero;
	int i;

	g_coltorow = (int*)malloc(sizeof(int) * g_size);
	i = 0;
	while (i < g_size)
	{
		g_coltorow[i] = g_board[i][col];
		i++;
	}
	rowzero = 0;
	colzero = 0;
	return (movecheck(row, col, rowzero, colzero));
}

int		movecheck(int row, int col, int rowzero, int colzero)
{
	int	i;

	i = 0;
	while (i < g_size)
	{
		if (g_board[row][i] == 0)
		{
			rowzero = 1;
			break ;
		}
		i++;
	}
	i = 0;
	while (i < g_size)
	{
		if (g_board[i][col] == 0)
		{
			colzero = 1;
			break ;
		}
		i++;
	}
	return (moveresult(row, col, rowzero, colzero));
}

int		moveresult(int row, int col, int rowzero, int colzero)
{
	int a;
	int b;

	if ((rowzero == 1) && (colzero == 1))
		return (1);
	else if (!(rowzero == 1) && (colzero == 1))
		return (checkrow(g_left[g_size - 1 - row], g_right[row], g_board[row]));
	else if ((rowzero == 1) && !(colzero == 1))
		return (checkrow(g_top[col], g_bottom[g_size - 1 - col], g_coltorow));
	a = checkrow(g_top[col], g_bottom[g_size - 1 - col], g_coltorow);
	b = checkrow(g_left[g_size - 1 - row], g_right[row], g_board[row]);
	if ((a == 1) && (b == 1))
		return (1);
	else
		return (-1);
}
