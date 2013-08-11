#include <stdio.h>
#include <stdlib.h>

void help(int **arr);


int main(int argc, char **argv){

	int a[] = {0,1,2,3,4,5};	
	int *p = NULL;
	int **q = &p;
	p = &argc;
	printf("%i\n", **q);
	
	p = a;
	printf("%i\n", **q);
	
	p = &(a[1]);
	printf("%i\n", **q);

	printf("%i\n", (*q)[1]);

	help(&a);
	help(&p);
	help(q);

	return 0;
}

void help(int **arr){
	printf("%i\n\n", **arr);
	return;
}