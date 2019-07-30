/*
 ID:scwswx2
 PROG:namenum
 LANG:C++
 */
/*
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
int gap[201],stall[201];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int m,s,c,k=0,cur,h=0,t=0,pre,i=0;
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	//m代表木板，s代表牛棚，c代表牛的总数
	scanf("%d%d%d",&m,&s,&c);
	while(i<c){
		scanf("%d",&cur);
		stall[cur]++;
		i++;
	}
	for(i=0;i<=s;i++){
		if(stall[i]==1){
			cur=i;
			if(h==0){
				pre=i;
				h=i;
			}
			if(i>t){
				t=i;
			}
			if(cur - pre > 1){
                gap[k++] = cur - pre - 1;
            }
            pre = cur;
		}

	}
	sort(gap,gap+k,cmp);
	int board=t-h+1;//一块木板从头到尾的长度
	for(i=0;i<m-1;i++){
		board=board-gap[i];
	}
	printf("%d\n",board);
	return 0;
}
*/