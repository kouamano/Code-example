#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	int i = 0;
	for(;;){
	i = i;
	usleep(1000000);
	printf("%d",i);
	}
	return(0);
}
