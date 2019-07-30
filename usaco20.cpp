/*#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <cstdio>
#include <algorithm>
#include<cmath>
#include<limits.h>
int a[1005][1005];
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int R,sum=0;
	freopen("D:\\test.in","r",stdin);
	freopen("D:\\test.out","w",stdout);
	scanf("%d",&R);
	for(int w=1;w<=R;w++){
		for(int x=1;x<=w;x++){
			scanf("%d",&a[w][x]);
		}
	}
	for(int i=R-1;i>0;i--)
		for(int j=1;j<=i;j++){
			a[i][j]=a[i][j]+max(a[i+1][j],a[i+1][j+1]);
			sum=a[i][j];
		}
	printf("%d\n",sum);
	return 0;
}
*/