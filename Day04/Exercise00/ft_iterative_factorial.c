int ft_iterative_factorial(int nb) {

	int res = 1;

	if (nb == 0) {
		return 0;
	}

	if (nb == 1) {
		return 1;
	}

	for (int i=1; i<nb+1; i++) {
		res *= i;
	}
	
	return res;
}

int main() {

    int res = ft_iterative_factorial(12);

    return 0;
}
