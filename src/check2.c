/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hybae <gustlr0217@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 19:34:57 by hybae             #+#    #+#             */
/*   Updated: 2020/07/12 21:57:41 by hybae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		viewcount(int forward, int *buildings)
{
	int count;

	count = 0;
	if (forward == 1)
	{
		count = count1(buildings);
	}
	else
	{
		count = count2(buildings);
	}
	return (count);
}

int		count1(int *buildings)
{
	int	count;
	int	max;
	int	i;
	int	build;

	count = 0;
	if (buildings[0] != 0)
	{
		max = buildings[0];
		count++;
	}
	i = 0;
	while (i < g_size)
	{
		build = buildings[i];
		if (build > buildings[i - 1] && build > max)
		{
			count++;
			max = build;
		}
	}
	return (count);
}

int		count2(int *buildings)
{
	int count;
	int max;
	int i;
	int build;

	count = 0;
	if (buildings[g_size - 1] != 0)
	{
		max = buildings[g_size - 1];
		count++;
	}
	i = 0;
	while (i < g_size)
	{
		build = buildings[i];
		if (buildings[i] > buildings[i + 1] && build > max)
		{
			count++;
			max = build;
		}
	}
	return (count);
}

int		checkrow(int left, int right, int *buildings)
{
	if (left == 0 && right == 0)
		return (1);
	if (left == 0 && right != 0)
	{
		if (right == viewcount(-1, buildings))
			return (1);
		else
			return (-1);
	}
	if (left != 0 && right == 0)
	{
		if (left == viewcount(1, buildings))
			return (1);
		else
			return (-1);
	}
	if (left == viewcount(1, buildings) && right == viewcount(-1, buildings))
		return (1);
	else
		return (-1);
}
