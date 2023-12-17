int ft_sqrt(int nb){

    if (nb<=0) {
        return 0;
    }

    int x_n = nb/2;
    int lo = 0;
    int hi = nb;
    int x_n_minus_1 = 0;
    int times_x_n_didnt_change = 0;

    while (x_n*x_n != nb) {

        if (x_n == x_n_minus_1) {
            times_x_n_didnt_change++;
        }
        else {
            times_x_n_didnt_change = 0;
        }

        if (times_x_n_didnt_change == 1) {
            x_n = 0;
            break;
        }

        int sqr = x_n*x_n;
        if (sqr>nb) {
            hi = x_n;
        }
        else {
            lo = x_n;
        }

        x_n_minus_1 = x_n;
        x_n = (hi + lo)/2;
        
    }

    return x_n;

}

int main() {
    int nb = 5185;
    int res = ft_sqrt(nb);
    return 0;
}