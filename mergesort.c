/*******************************************************************************
An implementation of mergesort in C by Goobyalus
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*
 *Header declarations
 */

int mergesort_int(int **arr, int len);







int main(int argc, char **argv){
	
	int a = {90,4,78,2,1,4,5,8,6,1,7};
	print_int_arr(a, 11);

	mergesort_int(&a, 11);
	print_int_arr(a, 11);
	
	return 0;
}


/*
 *Sort the first 'len' elements of integer array pointed to by 'arr'.
 *
 *'arr' is a pointer to the integer array to sort.
 *'len' is the number of elements to sort, and must be >= 1.
 */
int mergesort_int(int **arr, int len){
	
	int buffer[len];
	int temp = 0;
	int l = 0;
	int r = len/2;


	//Check for valid length	
	if(len < 0)
		return NULL;


	//Base cases
	switch(len){
	case 0:
	case 1:	return 1;

	case 2:	temp = (*arr)[0];
		if( (*arr)[1] < temp){
			(*arr)[0] = (*arr)[1];
			(*arr)[1] = temp;
		}
		return 1;
	}

	//Recursive calls
	temp = len/2;
	mergesort(arr, temp);
	mergesort(&((*arr)[temp]), len-temp);

	//Merge
	temp = 0;	//temp is the index of buffer
	while(l < len/2 && r < len){
		if((*arr)[l] <= (*arr)[r]){
			buffer[temp] = (*arr)[l];
			l++;
		} else {
			buffer[temp] = (*arr)[r];
			r++;
		}
			
		temp++;	
	}

	//Merge cont: copy remaining elements from either L or R
	if(r < len)
		l = r;
	while(temp < len){
		buffer[temp] = (*arr)[l];
		temp++;
	}
	
	//Copy from buffer to *arr
	temp = 0;
	while(temp < len){
		(*arr)[temp] = buffer[temp];
		temp++;
	}
	

	return 1;
}

/*
 *utility to print array of ints
 */
void print_int_arr(int a[], n){
	int i = 0;
	while(i++ < n){
		printf("%i, ",a[i]);
	}
	printf("\n");

	return;
}






