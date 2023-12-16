int ft_fibonacci(int idx) {

    if (idx < 0) {
        return -1;
    }

    if (idx == 1){
        return 1;
    }

    if (idx == 0){
        return 0;
    }

    int first_member = ft_fibonacci(idx - 1);
    int second_member = ft_fibonacci(idx - 2);

    return first_member + second_member;
}

int main() {

    int idx = 6;
    int res = ft_fibonacci(idx);

    return 0;
}