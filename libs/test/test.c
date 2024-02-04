#include "libstr.h"

int main(){
	
	int b = L_BIG;
	char test[] = " sadfasdf ";
	char test2[] = "huy";
	char a = 'A';

	int res1 = is_letter(a);
	int res2_5 = is_uppercase(a);
	int res2 = strcmp(test, test2);
	
	return (0);
}
