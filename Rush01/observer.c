/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkawai <tkawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:54:51 by tkawai            #+#    #+#             */
/*   Updated: 2023/08/20 11:36:40 by tkawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	from_top_correctly(int *hist, int *observed, int obs_loc);
int	from_bottom_correctly(int *hist, int *observed, int obs_loc);
int	from_left_correctly(int *hist, int *observed, int obs_loc);
int	from_right_correctly(int *hist, int *observed, int obs_loc);

// 箱の並びを表す hist と、外から見たときに見える箱の数を表す observed から、
// 外から見たときに条件と一致するかを返す関数。
int	observed_from_all_dircs_correctly(int *hist, int *observed)
{
	int	obs_loc;

	obs_loc = 0;
	while (obs_loc < 16)
	{
		if (!from_top_correctly(hist, observed, obs_loc))
			return (0);
		if (!from_bottom_correctly(hist, observed, obs_loc))
			return (0);
		if (!from_left_correctly(hist, observed, obs_loc))
			return (0);
		if (!from_right_correctly(hist, observed, obs_loc))
			return (0);
		obs_loc++;
	}
	return (1);
}

int	from_top_correctly(int *hist, int *observed, int obs_loc)
{
	int	hist_loc;
	int	max;
	int	count;

	if (!(0 <= obs_loc && obs_loc < 4))
		return (1);
	hist_loc = obs_loc;
	max = 0;
	count = 0;
	while (hist_loc < 4 * 4)
	{
		if (max < hist[hist_loc])
		{
			max = hist[hist_loc];
			count++;
		}
		hist_loc += 4;
	}
	if (count != observed[obs_loc])
		return (0);
	return (1);
}

int	from_bottom_correctly(int *hist, int *observed, int obs_loc)
{
	int	hist_loc;
	int	max;
	int	count;
	
	if (!(4 <= obs_loc && obs_loc < 8))
		return (1);
	hist_loc = (obs_loc - 4) + 4 * (4 - 1);
	max = 0;
	count = 0;
	while (0 <= hist_loc)
	{
		if (max < hist[hist_loc])
		{
			max = hist[hist_loc];
			count++;
		}
		hist_loc -= 4;
	}
	if (count != observed[obs_loc])
		return (0);
	return (1);
}

int	from_left_correctly(int *hist, int *observed, int obs_loc)
{
	int	hist_loc;
	int	max;
	int	count;

	if (!(8 <= obs_loc && obs_loc < 12))
		return (1);
	hist_loc = (obs_loc - 8) * 4;
	max = 0;
	count = 0;
	while (hist_loc < (obs_loc - 8) * 4 + 4)
	{
		if (max < hist[hist_loc])
		{
			max = hist[hist_loc];
			count++;
		}
		hist_loc++;
	}
	if (count != observed[obs_loc])
		return (0);
	return (1);
}

int	from_right_correctly(int *hist, int *observed, int obs_loc)
{
	int	hist_loc;
	int	max;
	int	count;

	if (!(12 <= obs_loc && obs_loc < 16))
		return (1);
	hist_loc = (obs_loc - 12) * 4 + 3;
	max = 0;
	count = 0;
	while ((obs_loc - 12) * 4 <= hist_loc)
	{
		if (max < hist[hist_loc])
		{
			max = hist[hist_loc];
			count++;
		}
		hist_loc--;
	}
	if (count != observed[obs_loc])
		return (0);
	return (1);
}
