#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
	float base;
	float exp;	
	float ans=0;
	int i;
	sscanf(argv[1],"%f",&base);
	sscanf(argv[2],"%f",&exp);
	//ans = pow(base,exp);
	ans = 1;
	for(i=0;i<exp;i++){
		ans *= base;
	}
	printf("%f\n",ans);
}
