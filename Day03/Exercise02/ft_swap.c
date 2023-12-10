void ft_swap(int *a, int *b) {
	
	int temp = *a;
	*a = *b;
	*b = temp;

}

void main() {
	int a = 5;
	int b = 10;
	ft_swap(&a, &b);
	int c;
}
