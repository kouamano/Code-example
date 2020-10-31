#include<stdio.h>
#define N 3
 
double A[N*N];
double x[N];
 
int main(void)
{
  static int i;
  static long int n=N,inc=1,info,piv[N];
 
  A[0]=1.; A[1]=3.; A[2]=1.;
  A[3]=1.; A[4]=1.;A[5]=-2.;
  A[6]=1.; A[7]=-3.;A[8]=-5.;
  x[0]=3.; x[1]=1.; x[2]=-6.;
 
  printf("N = %d\n",N);
  dgesv_(&n,&inc,A,&n,piv,x,&n,&info);
  for(i=0; i<N; ++i) printf("%lf\n", x[i]);
  return(0);
}

