#include <stdio.h>
#include <stdlib.h>


//printf("main外のprint\n");
int a = 0;
void func0(void){
	printf("func0:関数外で定義した変数a(a=0)%d\n",a);
}
void func1(void){
	int a = 1;
	printf("func1:main外で定義した関数内変数a(a=1)%d\n",a);
}
int main(void){
	func0();
	func1();
	printf("main外で宣言したa(a=0):%d\n",a);
	a = 10;
	printf("main外で宣言したaに新しく代入(a=10):%d\n",a);
	func1();
	func0();
	printf("main外で宣言したa:%d\n",a);
	return(0);
}
