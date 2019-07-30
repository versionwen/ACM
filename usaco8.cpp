/*
    ID:scwswx2
    PROG:namenum
    LANG:C++
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <cstdio>
#include <algorithm>
int main(){
	int m;
	char input[21];//存放输入数字
	char read[200];//存放从字典中读入的字符串
	int key[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,0};//手机键盘数字对照表
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	scanf("%s",input);
	int length=strlen(input);
	int flag=0;//标记在字典中有没有找到
	freopen("D:\\dict.txt","r",stdin);
	while(scanf("%s",read)!=EOF){
		m=0;
		m=strlen(read);
		if(length==m){
			while(input[length-m]-48==key[read[length-m]-'A']&&m>0){
					m--;
					if(m==0){
						printf("%s\n",read);
						flag++;
					}
				}

			}
		}
	if(flag==0){
		printf("NONE\n");
	}
	return 0;
}
*/