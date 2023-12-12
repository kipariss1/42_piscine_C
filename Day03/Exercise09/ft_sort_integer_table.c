void ft_sort_integer_table(int *tab, int size) {

	// implement bubblesort
	for (int j=0; j<size-1; j++) {
		for (int i=0; i<size-j-1; i++){
			if (*(tab+i)>*(tab+1+i)) {
				int temp = *(tab+i);
				*(tab+i) = *(tab+1+i);
				*(tab+1+i) = temp;
			}
		}
	}	

}

int main() {

	int len = 10;
	int table[10] = {41, 22, 3, 55, 1, 54, 100, 54, 27, 9};
	ft_sort_integer_table(table, len);

	return 0;
}
