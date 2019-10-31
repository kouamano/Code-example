#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	char c;
	c = malloc(sizeof(char)*128);
	c = 0;
	sprintf(c,"%s",strerror(11));
	//printf("%s",strerror(11));
	printf("--%s--",c);
	return(0);
}
