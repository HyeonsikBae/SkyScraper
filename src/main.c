/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hybae <gustlr0217@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:28:03 by hybae             #+#    #+#             */
/*   Updated: 2020/07/12 22:04:55 by hybae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_print.h"
#include "solver.h"

int		g_size;

int		main(int argc, char *argv[])
{
	int	**answer;
	int size;
	int i;
	int j;

	size = ft_sqrt(argc - 1);
	g_size = size;
	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (j < g_size)
		{
			if (argv[i][j] <= 0)
				return (0);
			j++;
		}
		i++;
	}
	answer = solve(argv, g_size);
	print(answer);
	return (0);
}
