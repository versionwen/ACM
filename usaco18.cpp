#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <cstdio>
#include <algorithm>
#include<cmath>
#include<limits.h>
#include<vector>
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
 //��c����a
 if(c>=A-a)
	 DFS(A,b,c-A+a);
 else DFS(a+c,b,0);
 //��c����b
 if(c>=B-b)
	 DFS(a,B,c-B+b);
 else DFS(a,b+c,0);
 //��b����a
 if(b>=A-a)
	 DFS(A,b-A+a,c);
 else DFS(a+b,0,c);
 //��b����c
 if(b>=C-c)
	 DFS(a,b-C+c,C);
 else 
	 DFS(a,0,b+c);
 //��a����b
 if(a>=B-b)
	 DFS(a-B+b,B,c);
 else 
	 DFS(0,a+b,c);
 //��a����c
 if(a>=C-c)
	 DFS(a-C+c,b,C);
 else
	 DFS(0,b,a+c);
 
}
int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    cin>>A>>B>>C;
    DFS(0,0,C);
    int count=0;
    for(int i=0;i<=C;i++)
    {
     if(recorder[i])
       {
         count++;
        if(count==1)
          cout<<i;
        else
          cout<<" "<<i;
       }
    }
    cout<<endl;
    return 0;
}