/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hybae <gustlr0217@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:46:18 by hybae             #+#    #+#             */
/*   Updated: 2020/07/12 14:57:29 by hybae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
