//nanosleep.c
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(void)
{
	struct timeval t0;
		struct timeval t1;
			struct timespec ts;

				ts.tv_sec = 1;
				ts.tv_nsec = 0;

	gettimeofday(&t0, NULL);

	nanosleep(&ts, NULL);

	gettimeofday(&t1, NULL);

	if (t1.tv_usec < t0.tv_usec) {
	printf("%d.%d\n", t1.tv_sec - t0.tv_sec - 1, 1000000 + t1.tv_usec - t0.tv_usec);
		}
		else {
	printf("%d.%d\n", t1.tv_sec - t0.tv_sec, t1.tv_usec - t0.tv_usec);
		}

	return 0;
		}
