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
int check(int a,int b){//算出相差一的个数
	int temp=a^b,res=0;
	while(temp>0){
		res++;
		temp-=temp&(-temp);
	}
	return res;
}
int main(){
	int a[65],n,b,d,num=0,test=0;
	freopen("D:\\test.in","r",stdin);
	freopen("D:\\test.out","w",stdout);
	scanf("%d%d%d",&n,&b,&d);
	bool flag=true;
	while(num<n){
		flag=true;
		for(int i=0;i<num;i++){//对每一个数字进行距离检查
			int dis=check(a[i],test);
			if(dis<d){
				flag=false;
			}
		}
		if(flag){
			a[num++]=test;
		}
		test++;
	}
	//进行输出格式控制
	for(int i=1;i<=n;i++){
		if(i!=n&&(i%10!=0)){
		printf("%d ",a[i-1]);
		if(i%10==0){
			printf("%d",a[i-1]);
			printf("\n");
			}
		}
		else{
			printf("%d\n",a[i-1]);
		}
	}
	return 0;
}
*/