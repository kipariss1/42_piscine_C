unsigned int ft_collatz_conjecture(unsigned int base){
    if (base == 1){
        return 1;
    }

    if (base%2 == 0){
        base = base/2;
    }
    else {
        base = 3*base + 1;
    }

    return 1 + ft_collatz_conjecture(base);
} 

int main(){

    int res = ft_collatz_conjecture(15);

    return (0);
}
