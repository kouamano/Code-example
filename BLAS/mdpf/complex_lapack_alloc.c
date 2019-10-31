/*
** SIZE*SIZE型の複素行列の固有値と固有ベクトルを計算
** メモリーアロケーション版
**  (1  2i)
**  (i 1+i)
**/

#define SIZE 2   // 2*2型の行列
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
/*
#include "/usr/local/include/blas/3.8.0/CBLAS/cblas.h"
#include "/usr/local/include/lapack/3.8.0/CLAPACK/f2c.h"
#include "/usr/local/include/lapack/3.8.0/CLAPACK/clapack.h"
*/

int main(void)
{
  char            jobvl         = 'N'    ;// 左固有ベクトルは計算しない
  char            jobvr         = 'V'    ;// 右固有ベクトルは計算する
  int             n             = SIZE   ;// 対角化する正方行列のサイズ

  //double _Complex A[SIZE*SIZE]           ;// 対角化する行列
  double _Complex *A;
  A = malloc(sizeof(double _Complex) * 4);
  A[0]=1; A[2]=2*I;				// Mathematicaを行メジャーだとすれば
  A[1]=I; A[3]=1+I;				// 列メジャーで読み込む

  int             lda           = SIZE   ;// 対角化する正方行列のサイズ
  double _Complex wr[SIZE]               ;// 固有値が入る
  double _Complex vlDUMMY[1]             ;// 左固有ベクトルが入る(不必要なので[1])
  int             ldvlDUMMY     = 1      ;// vlDUMMY[1]の次元
  double _Complex vr[SIZE*SIZE]          ;// 右固有ベクトルが入る
  int             ldvr          = SIZE   ;// 右固有ベクトルの本数
  double _Complex work[2*SIZE]           ;// 対角化する際に使用するメモリ
  int             lwork         = 2*SIZE ;// workの次元
  double          rwork[2*SIZE]          ;// 2*SIZEで固定
  int             info                   ;// 成功すれば0 失敗すれば0以外を返す
    
  // LAPACKのzgeevサブルーチンを呼ぶ
  // 引数は全て参照渡し
  zgeev_(&jobvl, &jobvr, &n, A, &lda, wr, vlDUMMY, &ldvlDUMMY, vr, &ldvr, work, &lwork, rwork, &info);
  // 1番目の固有ベクトル : (vr[0] vr[1])
  // 2番目の固有ベクトル : (vr[2] vr[3])
  printf("1番目の固有値:%5.3lf %+5.3lf*I\n", creal(wr[0]), cimag(wr[0]));
  printf("1番目の固有ベクトル:(%5.3lf %+5.3lf*I, %5.3lf %+5.3lf*I)\n", creal(vr[0]), cimag(vr[0]), creal(vr[1]), cimag(vr[1]));
  printf("2番目の固有値:%5.3lf %+5.3lf*I\n", creal(wr[1]), cimag(wr[1]));
  printf("2番目の固有ベクトル:(%5.3lf %+5.3lf*I, %5.3lf %+5.3lf*I)\n", creal(vr[2]), cimag(vr[2]), creal(vr[3]), cimag(vr[3]));
  return 0;
}

/* 以下をprint */
/* 
** 1番目の固有値:1.000 -1.000*I
** 1番目の固有ベクトル:(0.894 +0.000*I -0.447 -0.000*I)
** 2番目の固有値:1.000 +2.000*I
** 2番目の固有ベクトル:(0.707 +0.000*I 0.707 -0.000*I)
*/

