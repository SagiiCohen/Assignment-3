#define size 50
#include <stdio.h>
#include "isort.h"
int main()
{
	int arr[size];
	int i = 0; 
	int* pointerArr=arr;	
	while((scanf("%d", pointerArr+i)!= EOF)&&(i < size)) i++; //Filling up the array.		
	insertion_sort(pointerArr,size);
  	my_print(pointerArr,size); 
  	return 0;
}
