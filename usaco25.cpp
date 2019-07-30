/*#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[1001],n,n1=0,n2=0,n3=0,res=0,ans1=0,ans2=0;
	freopen("D:\\test.in","r",stdin);
	freopen("D:\\test.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1){
			n1++;
		}
		else if(a[i]==2){
			n2++;
		}
		else
			n3++;
	}
	for(int j=0;j<n1;j++){
		if(a[j]!=1){
			res++;
		}
	}
	for(int j=n1;j<n1+n2;j++){
		if(a[j]==3){
			ans1++;
		}
	}
	for(int j=n1+n2;j<n;j++){
		if(a[j]==2){
			ans2++;
		}
	}
	res=res+max(ans1,ans2);
	printf("%d\n",res);
	return 0;
}
*/