#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
	float base;
	float exp;	
	float ans=0;
	sscanf(argv[1],"%f",&base);
	sscanf(argv[2],"%f",&exp);
	ans = pow(base,exp);
	printf("%f\n",ans);
}
