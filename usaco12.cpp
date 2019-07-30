/*
ID: scwswx2
LANG: C++
PROG: crypt1
*/
/*#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
int table[10];
int check ( int x )
    {
        while (x)
            {
                if (!table[x%10]){
					return 1;
				}
                    x = x/10; 
            }
            return 0;
    }
 
int main()
{	int sum=0,n,t;
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout); 
	scanf("%d",&n);
    for ( int i = 0;i < n;i++ )
        {
            scanf("%d",&t);
            table[t] = 1;
        }
    for ( int i = 100;i < 1000;i++ )
        {
            if ( check(i))
                continue;
            for ( int j = 10;j < 100;j++ )
                {
                    int m = i*j;
                    if ( m>9999 )
						break;
                    if ( check(j)||check(m))
                        continue;
                    int fm = (j%10)*i;
                    if ( fm<100||fm>=1000 )
                        continue;
                    int sm = (j/10)*i;
                    if ( sm<100||sm>=1000 )
                        continue;
                    if ( check(sm)||check(fm) )
                        continue;
                        sum++;
 
                }
        }
 
    cout<<sum<<endl;
 
 
    return 0;
}
*/