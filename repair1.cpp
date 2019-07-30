#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int cot[103],hod[201];
bool cmp(int a,int b){ return a>b;};
int main(void){

    freopen("barn1.out","w",stdout);
    freopen("barn1.in","r",stdin);
    int m,s,c,k;
    cin>>m>>s>>c;

    int cur,h,t,pre;
    for(int i=0;i<c;i++){
        cin>>cur;
        hod[cur]++;
    }

    h = 0 , t = 0, k = 0;
    for(int i=1;i<=200;i++){
        if(hod[i] == 1){
            cur = i;
            if(h == 0) { h = i; pre = i;}// mark start point as h
            if(i>t) t = i; // mark end point as t

            if(cur - pre > 1){
                cot[k++] = cur - pre - 1;
            }
            pre = cur;
        }
    }

    sort(cot,cot+k,cmp);

    int sum = t - h + 1;
    for(int i=0;i<m-1;i++){// m-1 stands for (m-1) gaps
        sum -= cot[i];
    }

    cout<<sum<<endl;
    return 0;
}
