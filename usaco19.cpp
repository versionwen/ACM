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
int A,B,C;
int used[21][21][21],recorder[21];
void DFS(int a,int b,int c)
{
	if(used[a][b][c])
		return ;
	else
		used[a][b][c]=1;
	if(a==0&&!recorder[c])
		recorder[c]=1;
	if(c>=A-a){
		DFS(A,b,c-A+a);//把c倒入a；
	}
	else
		DFS(a+c,b,0);
	if(c>=B-b){
		DFS(a,B,c-B+b);//把c倒入b
	}
	else{
		DFS(a,b+c,0);
	}
	if(b>=A-a){
		DFS(A,b-(A-a),c);//把b倒入a
	}
	else{
		DFS(a+b,0,c);
	}
	if(b>C-c){
		DFS(a,b-(C-c),C);//#####把b倒入c
	}
	else{
		DFS(a,0,b+c);
	}
	if(a>B-b){
		DFS(a-(B-b),B,c);//把a倒入b
	}
	else{
		DFS(0,a+b,c);
	}
	if(a>=C-c){
		DFS(a-(C-c),b,C);//把a倒入c
	}
	else{
		DFS(0,b,a+c);
	}

}
int main(){
	freopen("D:\\test.in","r",stdin);
	freopen("D:\\test.out","w",stdout);
	scanf("%d%d%d",&A,&B,&C);
	DFS(0,0,C);
	int count=0;
	for(int i=0;i<=C;i++){
		if(recorder[i])
		{
			count++;
			if(count==1)
				printf("%d",i);
			else
				printf(" %d",i);
		}
	}
	printf("\n");
	return 0;
}
*/