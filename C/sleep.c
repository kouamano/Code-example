#include  <stdio.h>
#include  <time.h>

int slp(unsigned long x)
{
    clock_t  s = clock();
    clock_t  c;

    do {
        if ((c = clock()) == (clock_t)-1)    
            return (0);
    } while (1000UL * (c - s) / CLOCKS_PER_SEC <= x); 
    return (1);
}

int main(void)
{
    int  code;

    printf("start\n");

    code = slp(1000);                    

    printf("end(%d)\n", code);

    return (0);
}
