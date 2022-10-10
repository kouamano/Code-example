#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *array = NULL;
	int size = 10000000;
	int i = 0;
	array = malloc(sizeof(int) * size);
	for(i=0;i<1000000;i++){
		array[i] = 777;
		printf("%d\n",array[i]);
	}
	return(0);
}
