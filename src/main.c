/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hybae <gustlr0217@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:28:03 by hybae             #+#    #+#             */
/*   Updated: 2020/07/12 20:08:23 by hybae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_print.h"

int		g_size;

int		main(int argc, char *argv[])
{
	int	**answer;
	int size;

	size = ft_sqrt(argc - 1);
	g_size = size;
	answer = solve(argv, g_size);
	print(answer);
	return (0);
}
