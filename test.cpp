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
    int x,y;//һ���ڵ㿪ʼ�ͽ���
};
Node p[maxn];//��¼ũ�������
bool cmp(Node a,Node b){//�ȽϿ�ʼ�ڵ�Ĵ�С����������
    return a.x<b.x;
}
int main()
{
    freopen("milk2.in", "r", stdin);  
    freopen("milk2.out", "w", stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>p[i].x>>p[i].y;//�����i��ũ��Ŀ�ʼ�ͽ���ʱ��
    sort(p,p+n,cmp);//����
    int ans=0;
    for(int i=0;i<n;i++){
        int left=p[i].x,right=p[i].y;//��¼һ��ũ������ұ�
        for(int j=i;j<n;j++){
            if(p[j].x>right){//��j��ũ�����ߴ��ڿ�ʼ�ұߣ�˵�����ֶϵ�
                break;
            }else{
                right=max(p[j].y,right);//�ϲ�һ������
            }
        }
        ans=max(ans,(right-left));//������������
    }

    int cnt=0;
    int r=p[0].y;
    for(int i=0;i<n;i++){
        if(p[i].x>r){//�ҵ��ϵ�����ط�
            cnt=max((p[i].x-r),cnt);//���¶ϵ���������
        }
        r=max(r,p[i].y);//���¶ϵ����ĵط�
    }
    cout<<ans<<" "<<cnt<<endl;
}
*/