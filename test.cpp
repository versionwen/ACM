/*
    ID:scwswx2
    PROG:milk2
    LANG:C++
*/
/*#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "algorithm"
using namespace std;
const int maxn=5001;
int n;
struct Node{
    int x,y;//一个节点开始和结束
};
Node p[maxn];//记录农民的人数
bool cmp(Node a,Node b){//比较开始节点的大小，用于排序
    return a.x<b.x;
}
int main()
{
    freopen("milk2.in", "r", stdin);  
    freopen("milk2.out", "w", stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>p[i].x>>p[i].y;//输入第i个农民的开始和结束时间
    sort(p,p+n,cmp);//排序
    int ans=0;
    for(int i=0;i<n;i++){
        int left=p[i].x,right=p[i].y;//记录一个农民的左右边
        for(int j=i;j<n;j++){
            if(p[j].x>right){//第j个农民的左边大于开始右边，说明出现断点
                break;
            }else{
                right=max(p[j].y,right);//合并一个区间
            }
        }
        ans=max(ans,(right-left));//更新最大的区间
    }

    int cnt=0;
    int r=p[0].y;
    for(int i=0;i<n;i++){
        if(p[i].x>r){//找到断点的最大地方
            cnt=max((p[i].x-r),cnt);//更新断点最大的区间
        }
        r=max(r,p[i].y);//更新断点最大的地方
    }
    cout<<ans<<" "<<cnt<<endl;
}
*/