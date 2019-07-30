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
int i,mount[1001],res=INT_MAX;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	int n;
	freopen("D:\\test.in","r",stdin);
	freopen("D:\\test.out","w",stdout);
	scanf("%d",&n);
	for(int w=0;w<n;w++){
		scanf("%d",&mount[w]);
	}
	sort(mount,mount+n,cmp);
	for(i=mount[0];i<=mount[n-1];i++){
		int sum=0;
		for(int j=0;j<n;j++){
			if(mount[j]>i){
			sum+=(mount[j]-i)*(mount[j]-i);
			}
			else if(i-mount[j]>17){
				sum+=(i-mount[j]-17)*(i-mount[j]-17);
			}
		}
		res=min(res,sum);
	}
	printf("%d\n",res);
	return 0;
}
*/