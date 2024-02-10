unsigned int ft_active_bits(int value){
    unsigned int count = 0;

    while (value != 0){
        value = value ^ (value & -value);
        count++;
    }

    return count;
}

int main(){

    unsigned int res = ft_active_bits(13);

    return (0);
}
