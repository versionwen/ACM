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
	char input[21];//�����������
	char read[200];//��Ŵ��ֵ��ж�����ַ���
	int key[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,0};//�ֻ��������ֶ��ձ�
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	scanf("%s",input);
	int length=strlen(input);
	int flag=0;//������ֵ�����û���ҵ�
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