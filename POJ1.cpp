/**#include<cstdio>
#include<stack> 
#include<cstring>
using namespace std;
//���ֺ����⣺
const int maxn = 22;
stack<int>v;
int a[maxn];
int n, m, i, j, k;
bool dfs(int i = 0, int sum = 0)     //�Ѿ���ǰi��õ��˺�sum,Ȼ�����i��֮��Ľ��з�֧
{
    //ֹͣ���� �����ǰn�������ˣ��򷵻�sum�Ƿ���k��� 
    if (i == n) return sum == k;
    //ѡ��ӻ򲻼�a[i]
    //����a[i]����� 
    if (dfs(i + 1, sum)) return true;
    //����a[i]����� 
    if (dfs(i + 1, sum + a[i])) 
    {
        //��ִ�и���������˵����a[i]�������� 
        v.push(a[i]);//ѹջ 
        return true;
    }
    return false;           //�����Ƿ����a[i]�����ܴճ�k�ͷ���false;
}
int main() {
    while (~scanf("%d%d", &n, &k)) 
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        if (dfs()) 
        {
            printf("YES\n");
            while (!v.empty()) //�� ����dfs�����е��� ȫ��ȡ�����������£�
            {
                int x = v.top();
                printf("%d ", x);
                v.pop();
            }
            printf("\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}*/