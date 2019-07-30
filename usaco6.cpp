/*
题意：给定一个字符串方块和目标字符串方块。 
1: 90度顺时针旋转 
2: 180度顺时针旋转 
3: 270度顺时针旋转 
4: 以中心轴为轴翻转 
5: 以中心轴为轴翻转后进行1-3种中任意一种操作 
6: 不变 
7: 不能转换过去 
问通过这些操作中的任意一个操作是否能够由给定字符串方块转换到目标字符串方块。如果多种操作都可以，那么输出编号最小的操作的编号。

题解：看代码。

思考： 
1、每种操作之间有联系，所以只用写一个90度旋转函数，一个对称翻折函数还有一个检查函数就可以了。由于要输出编号最小的，所以从1-6操作依次枚举，看看可不可以，如果可以就break出去，如果都不可以就输出7。
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

int rot()//90°旋转，他是复制了一个临时数组中的
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

int refl()//这是一个以中心为对称轴的对折交换函数
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
