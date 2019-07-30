/*#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <cstdio>
#include <algorithm>
#include<cmath>
using namespace std;
int n;
int password[3],depass1[3],depass2[3];
bool equal(int a,int b){
	if(abs(a-b)<=2)
		return true;
	else if((n - abs(a - b))%n <= 2)
		return true;
	else
		return false;
}
bool check(int i,int j,int k){
	bool d1=true,d2=true;
	password[0]=i;
	password[1]=j;
	password[2]=k;
	for(int i2=0;i2<3;i2++){
		if(!equal(password[i2],depass1[i2])){
			d1=false;
			break;
		}
	}
	for(int i1=0;i1<3;i1++){
		if(!equal(password[i1],depass2[i1])){
			d2=false;
			break;
		}
	}
		if(d1||d2){
			return true;
		}
	return false;
}
int main(){
	int num=0;
	freopen("D:\\test.in","r",stdin);
    freopen("D:\\test.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<3;i++){
		scanf("%d",&depass1[i]);
	}
	for(int i1=0;i1<3;i1++){
		scanf("%d",&depass2[i1]);
	}
	for(int i0=1;i0<=n;i0++){
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				if(check(i0,j,k))
					num++;
			}
	}
printf("%d\n",num);
return 0;
}
*/