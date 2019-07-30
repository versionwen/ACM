#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 5100
typedef struct time{
	int begin,end;
}time;
time f[N];
bool cmp(time a,time b){
	if(a.begin>b.begin)
		return false;
	else
		return true;
}
int main(){
	int n;
	freopen("D:\\test.in","r",stdin);
	//freopen("milk2.out", "w", stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>f[i].begin>>f[i].end;
	}
	//sort(f,f+n,cmp);
	printf("%d",f[0].begin);
	return 0;
}