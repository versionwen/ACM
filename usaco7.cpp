/*#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <cstdio>
#include <algorithm>
#define N 20
using namespace std;
int n;
char s[N][N], r[N][N];
void Rotation(){
	char temp[N][N];
	memset(temp,'\0',sizeof(temp));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			temp[i][j]=s[n-1-j][i];
		}
	memcpy(s,temp,sizeof(temp));
}
void reflected(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n/2;j++){
			swap(s[i][j],s[i][n-1-j]);
		}
	}
}
bool check(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[i][j]!=r[i][j])
				return false;
		}
	}
	return true;
}
bool option(int op){
	if(op==1)
		Rotation();
	else if(op==2)
		Rotation();
	else if(op==3)
		Rotation();
	else if(op==4){
		Rotation();//要转回去
		reflected();
	}
	else if(op==5){
		for(int i=0;i<3;i++){
			Rotation();
			if(check()){
				return true;
			}
		}
		return false;
	}
	else if(op==6){
		Rotation();
		reflected();
	}
	return check();
}
int main(){
	int choose;
	freopen("D:\\test.in","r",stdin);
	freopen("D:\\transform1.out","w",stdout);
	scanf("%d",&n);
	memset(s,'\0',sizeof(s));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>s[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>r[i][j];
	for(choose=1;choose<7;choose++){
		if(option(choose)){
			printf("%d\n",choose);
			break;
		}
	}
	if(choose==7){
		printf("%d\n",7);
	}
	return 0;
}
*/