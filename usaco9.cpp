/*#include <iostream>
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
	freopen("D:\\test.in","r",stdin);
	freopen("D:\\test.out","w",stdout);
	//cin>>m>>s>>c;//m����ľ�壬s����ţ�c����ţ������
	scanf("%d%d%d",&m,&s,&c);
	while(i<c){
		//cin>>cur;
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
			else if(i>t){
				t=i;
			}
			else if(cur - pre > 1){
                gap[k++] = cur - pre - 1;
            }
            pre = cur;
		}

	}
	sort(gap,gap+k,cmp);
	int board=t-h-1;//һ��ľ���ͷ��β�ĳ���
	for(i=0;i<m-1;i++){
		board=board-gap[i];
	}
	printf("%d\n",board);
	return 0;
}