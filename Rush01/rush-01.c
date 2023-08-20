/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkawai <tkawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:48:32 by tkawai            #+#    #+#             */
/*   Updated: 2023/08/20 11:09:12 by tkawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid_input(char *argv);
void	str_to_int_arr(int *arr, char *str, int length);
int	recursive(int *hist, int loc, int *observed);
int		observed_from_all_dircs_correctly(int *hist, int *observed);
void	print_hist(int *hist);
int	can_put_box(int *hist, int loc, int box_height);
void initialize_int_arr(int *arr, int length);

int	main(int argc, char *argv[])
{
	int	hist[4 * 4];
	int observed[4 * 4];
	initialize_int_arr(hist, 4 * 4);
	initialize_int_arr(observed, 4 * 4);
	
	// 無効な入力をチェック
	if (argc <= 1 || !is_valid_input(argv[1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	// argv[1]をint arr のobservedに変換
	str_to_int_arr(observed, argv[1], 4 * 4);
	recursive(hist, 0, observed);
	return (0);
}

int	recursive(int *hist, int loc, int *observed)
{
	int	box_heigt;

	// ベースケースは loc = n * n の時で、
	// そのときは、外から見たときに条件と一致するかを返す。
	// 条件と一致すればhistを出力する
	if (loc == 4 * 4)
	{
		if (observed_from_all_dircs_correctly(hist, observed))
			print_hist(hist);
	}
	// box_heigt がcurr_positionに置こうとしている箱の高さ
	box_heigt = 1;
	while (box_heigt <= 4)
	{
		if (can_put_box(hist, loc, box_heigt))
		{
			hist[loc] = box_heigt;
			if (recursive(hist, loc + 1, observed))
				return (1);
		}
		box_heigt++;
	}
	return (0);
}

// *histのようにすでに箱が置かれていて、locに高さbox_heightの
// 箱を置けるかどうかを返す関数
int	can_put_box(int *hist, int crr_loc, int box_height)
{
	int hist_loc;

	hist_loc = 0;
	while (hist_loc < crr_loc)
	{
		if ((hist_loc / 4 == crr_loc / 4) || (hist_loc % 4 == crr_loc % 4))
		{
			if (hist[hist_loc] == box_height)
				return (0);
		}
		hist_loc++;
	}
	return (1);
}
