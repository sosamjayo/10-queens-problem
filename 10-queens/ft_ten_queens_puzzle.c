#include <unistd.h>

int		ft_ten_queens_puzzle_helper(int *queens, int n);
int		can_put_queen(int *queens, int n, int position);
int		can_put_queen(int *queens, int n, int position);
void	str_println(int *arr);
int		abs(int n);

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];

	return (ft_ten_queens_puzzle_helper(queens, 0));
}

int	ft_ten_queens_puzzle_helper(int *queens, int n)
{
	int	position;
	int	count;

	if (n == 10)
	{
		str_println(queens);
		return (1);
	}
	position = 0;
	count = 0;
	while (position < 10)
	{
		if (can_put_queen(queens, n, position))
		{
			queens[n] = position;
			count += ft_ten_queens_puzzle_helper(queens, n + 1);
		}
		position++;
	}
	return (count);
}

int	can_put_queen(int *queens, int n, int position)
{
	int	i;

	// queensがすでに置かれたクイーンを表し、n-1がすでに置かれたクイーンの個数
	// queens[n-1]までが、すでに置かれたクイーン
	// position行、n列目に新しいクイーンを配置できる場合は1を
	// 配置できない場合は0を返す
	i = 0;
	while (i < n)
	{
		// if ((n + position) == i + queens[i])
		// 	return (0);
		// if ((n - position) == i - queens[i])
		// 	return (0);
		if (abs(n - i) == abs(position - queens[i]))
			return (0);
		if (position == queens[i])
			return (0);
		i++;
	}
	return (1);
}

void	str_println(int *arr)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

#include <stdio.h>

int	main(void)
{
	int res;

	res = ft_ten_queens_puzzle();
	printf("%d\n", res);
}