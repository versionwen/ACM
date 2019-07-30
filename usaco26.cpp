#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
void Fractions(int a, int b,int c,int d,int n){
	if(b+d>n){
		return ;
	}
	Fractions(a,b,a+c,b+d,n);
	printf("%d/%d\n",a+c,b+d);
	Fractions(a+c,b+d,c,d,n);

}
int main(){
	int n;
	freopen("D:\\test.in","r",stdin);
	freopen("D:\\test.out","w",stdout);
	scanf("%d",&n);
	printf("%d/%d\n",0,1);
	Fractions(0,1,1,1,n);
	printf("%d/%d\n",1,1);
	return 0;
}