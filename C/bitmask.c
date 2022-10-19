#include <stdio.h>
int main(void){
	printf("-2 & -3:\n");
	printf("%d\n",(-2&-3));
	printf("-2 & 1:\n");
	printf("%d\n",(-2&1));
	printf("-2 & -1:\n");
	printf("%d\n",(-2&-1));
	printf("-1 & -1:\n");
	printf("%d\n",(-1&-1));
	printf("-1 & 1:\n");
	printf("%d\n",(-1&1));
	printf("1 & -1:\n");
	printf("%d\n",(1&(-1)));
	printf("0 & -1:\n");
	printf("%d\n",(0&(-1)));
	printf("1 & 1:\n");
	printf("%d\n",(1&1));
	printf("1 & 0:\n");
	printf("%d\n",(1&0));
	printf("1 & 3:\n");
	printf("%d\n",(1&3));
	return(0);
}
