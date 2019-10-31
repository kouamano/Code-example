#include <stdio.h>
#include <sys/time.h>

int main(void){
	int cnt;
	struct timespec req={0, 2000 * 1000000};
	for(cnt=0;cnt<5;cnt++){
		printf("%d\n",cnt);
		if(nanosleep(&req,NULL) == -1){
			perror("\n");
		}
	}
	return(0);
}
