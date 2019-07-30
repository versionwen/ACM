/*#include <iostream>
#include <cstring>
#include <cmath>
bool isprime(int num){
	int wx=num;
	int k=(int)sqrt(wx);
	for(int i=2;i<num;i++){
		if(num%i==0)
			return false;
	}
	return true;
}
int isPalindromes(int num){
	int res=num/10,out=num;
	while(out>0){
	res=res*10+out%10;
	out=out/10;
	}
	return res;
}
int main(){
	int a,b;
	freopen("D:\\test.in","r",stdin);
	freopen("D:\\test.out","w",stdout);
	scanf("%d%d",&a,&b);
	if(a%2==0){
		a++;
	}
	if(a<12){
		for(int i=a;i<12;i++){
			if(isprime(i)){
				printf("%d\n",i);
			}
		}
	}
	for(int i=10;i<=10000;i++){
		int temp=isPalindromes(i);
		if(temp<a){
			continue;
		}
		if(temp>b){
			break;
		}
		if(isprime(temp)){
			printf("%d\n",temp);
		}
	}
	return 0;
}
*/