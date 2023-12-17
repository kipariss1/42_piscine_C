long long int ft_iterative_power(int nb, int power) {

	if (power == 0) {
		return 1;
	}

	if (power < 0) {
		return 0;
	}

	long long int res = nb;

	while (power>1) {
	
		res = res*nb;
		power--;	

	}

	return res;

}


int ft_is_prime(int nb) {

    if ((nb == 1) || (nb == 0)) {
        return 0;
    }
    
    if (nb == 2) {
        return 1;
    }

    // implementation of ferma little theorem (can handle only nb < 69 :(( )
    int a = 2;
    if (ft_iterative_power(a, nb - 1)%nb == 1) {
        return 1;
    }
    return 0;
}

int main() {

    int nb = 3571;
    int is_prime = ft_is_prime(nb);

    return 0;
}