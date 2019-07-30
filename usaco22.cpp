/*#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <cstdio>
#include <algorithm>
#include<cmath>
#include<limits.h>
using namespace std;
int first[]={2,3,5,7},other[]={1,3,7,9},res=0,ans[1000000],n;
bool isprime(int num){//判断是否是素数
	if(num==2){
		return true;
	}

	int temp=(int)sqrt(1.0*num);
	for(int i=2;i<=temp;i++){
		if(num%i==0){
			return false;
		}
	}
	return true;
}
void DFS(int num,int k){
	if(!isprime(num)){
		return;
	}
	if(k==-1){//跑完一个数字，进行存储
		ans[++res]=num;
	}
	if(k==n-1){
		for(int i=0;i<4;i++)
			DFS(num*10+first[i],k-1);
	}
	else
		for(int i=0;i<4;i++){
			DFS(num*10+other[i],k-1);
		}
}
int main(){
	freopen("D:\\test.in","r",stdin);
	freopen("D:\\test.out","w",stdout);
	scanf("%d",&n);
	DFS(0,n-1);
	for(int i=1;i<=res;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
*/