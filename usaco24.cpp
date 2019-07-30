/*#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int need[21],sum;
int ans=2147483647;
int a[101][101],now[101];
int n,m,da[101],b[101];
void dfs(int k)
{
    int i;
    if(k>n)
    {
        if(ans<sum)
			return;
        for(i=1;i<=m;i++)
            if(now[i]<need[i])
				return;
        for(i=1;i<=n;i++)
            da[i]=b[i];
        ans=sum;
    }
    else
    {
        b[k]=0; 
		dfs(k+1);
        b[k]=1; 
		sum++;
        for(i=1;i<=m;i++)
            now[i]+=a[k][i];
        dfs(k+1); 
		sum--; 
		b[k]=0;
        for(i=1;i<=m;i++)
            now[i]-=a[k][i]; 
    }
}
int main()
{
    freopen("holsteins.in","r",stdin);
    freopen("holsteins.out","w",stdout);
    int i,j;
    scanf("%d",&m);
    for(i=1;i<=m;i++)
        scanf("%d",&need[i]);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    dfs(1);
    ans=0;
    for(i=1;i<=n;i++)
        if(da[i])ans++;
    cout<<ans<<" ";
    for(i=1;i<=n;i++)
        if(da[i])printf("%d ",i);
    return 0;
} 
*/