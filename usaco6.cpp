/*
���⣺����һ���ַ��������Ŀ���ַ������顣 
1: 90��˳ʱ����ת 
2: 180��˳ʱ����ת 
3: 270��˳ʱ����ת 
4: ��������Ϊ�ᷭת 
5: ��������Ϊ�ᷭת�����1-3��������һ�ֲ��� 
6: ���� 
7: ����ת����ȥ 
��ͨ����Щ�����е�����һ�������Ƿ��ܹ��ɸ����ַ�������ת����Ŀ���ַ������顣������ֲ��������ԣ���ô��������С�Ĳ����ı�š�

��⣺�����롣

˼���� 
1��ÿ�ֲ���֮������ϵ������ֻ��дһ��90����ת������һ���ԳƷ��ۺ�������һ����麯���Ϳ����ˡ�����Ҫ��������С�ģ����Դ�1-6��������ö�٣������ɲ����ԣ�������Ծ�break��ȥ������������Ծ����7��
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 15;
int n;
char s[maxn][maxn], r[maxn][maxn];

int rot()//90����ת�����Ǹ�����һ����ʱ�����е�
{
    char t[maxn][maxn];
    memset (t, '\0', sizeof(t));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t[i][j] = s[n - j - 1][i];
        }
    }
    memcpy (s, t, sizeof(t));
}

int refl()//����һ��������Ϊ�Գ���Ķ��۽�������
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap (s[i][j], s[i][n - j - 1]);
        }
    }
}

int ck()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != r[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int work(int op)
{
    if (op == 1) rot ();
    if (op == 2) rot ();
    if (op == 3) rot ();
    if (op == 4) {
        rot ();
        refl ();
    }
    if (op == 5) {
        for (int i = 0; i < 3; i++) {
            rot ();
            if (ck ()) {
                return 1;
            }
        }
        return 0;
    }
    if (op == 6) {
        rot ();
        refl ();
    }
    return ck ();
}

int main() {
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    scanf ("%d", &n);
    memset (s, '\0', sizeof(s));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>s[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>> r[i][j];
        }
    }
    int op;
    for (op  = 1; op < 7; op++) {
        if (work (op)) {
            printf ("%d\n", op);
            break;
        }
    }
    if (op == 7) {
        printf ("7\n");
    }
    return 0;
}
