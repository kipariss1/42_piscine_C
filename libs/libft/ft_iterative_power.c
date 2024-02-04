#include "libft.h"

int ft_iterative_power(int nb, int power) {

	if (power == 0) {
		return 1;
	}

	if (power < 0) {
		return 0;
	}

	int res = nb;

	while (power>1) {
	
		res = res*nb;
		power--;	

	}

	return res;

}

/*
int main() {

	int nb = 2;
	int power = 4;	
	int res = ft_iterative_power(nb, power);

	return 0;

}
*/
