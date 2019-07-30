/*
ID: scwswx2
LANG: C++
PROG: crypt1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
bool cmp(int a,int b){//判断是否相差小于2
	if(abs(a-b)<=2)
		return true;
	else if(n-abs(a-b)%n<=2)
		return true;
	return false;
}
int main(){
	int a1,b1,c1,a2,b2,c2;
	freopen("D:\\test.in","r",stdin);
	freopen("D:\\test.out","w",stdout);
	cin>>n;
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	if(a1==1)
	return 0;
}