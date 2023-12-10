void ft_ultimate_ft(int *********nbr) {
	
	int********* ppppppppp = nbr;
	int******** pppppppp = *ppppppppp;
	int******* ppppppp = *pppppppp;
	int****** pppppp = *ppppppp;
	int***** ppppp = *pppppp;
	int**** pppp = *ppppp;
	int*** ppp = *pppp;
	int** pp = *ppp;
	int* p = *pp;
	*p = 42;

}

void main() {

	int a;
	int* p = &a;
	int** pp = &p;
	int*** ppp = &pp;
	int**** pppp = &ppp;
	int***** ppppp = &pppp;
	int****** pppppp = &ppppp;
	int******* ppppppp = &pppppp;
	int******** pppppppp = &ppppppp;
	int********* ppppppppp = &pppppppp;
	ft_ultimate_ft(ppppppppp);
	int b;

}
