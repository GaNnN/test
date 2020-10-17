#include<stdio.h>
#include "20209326_head.h"
int main(void){
	int a, b;
	printf("enter two numbers:");
	scanf("%d %d",&a,&b);
	for(int i=0;i<9326;i++){
	}
	printf("add:%d\n",add(a,b));
	printf("sub:%d\n",sub(a,b));
	printf("mul:%d\n",mul(a,b));
	printf("div:%lf\n",div(a,b));
	return 0;
}
