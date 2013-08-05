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

	//TODO: loop to copy remaining elements from either L or R

	return 1;
}