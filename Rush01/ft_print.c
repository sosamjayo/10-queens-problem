#include <unistd.h>

void	print_hist(int *hist)
{
	int		i;
	char	c;

	i = 0;
	while (i < 4 * 4)
	{
		c = hist[i] + '0';
		write(1, &c, 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
}
