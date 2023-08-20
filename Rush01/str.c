#include <unistd.h>

void	str_to_int_arr(int *arr, const char *str, int length) {
	int	i;

	i = 0;
	while (i < length) {
		arr[i] = str[i * 2] - '0';
		i++;
	}
}

int is_valid_input(const char *argv) {
	int i;

	i = 0;
	while (argv[i]) {
		if (i % 2 == 0 && !(argv[i] >= '1' && argv[i] <= '4'))
			return (0);
		else if (i % 2 == 1 && argv[i] != ' ')
			return (0);
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}
