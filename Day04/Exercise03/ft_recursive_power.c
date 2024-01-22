int ft_recursive_power(int nb, int pow) {

    if (pow < 0) {
        return 0;
    }

    if (pow == 0) {
        return 1;
    }

    if (pow == 1) {
        return nb;
    }

    return nb*ft_recursive_power(nb, pow-1); 
}

/*
int main() {
    int nb = 2;
    int pow = 4;

    int res = ft_recursive_power(nb, pow);

    return 0;
}
*/