/*
LANG: C++
TASK: ariprog
*/
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
int n, m;
bool exist[126000];
int num[126000];
 
bool check(int a, int b)
{
        for (int i = 0; i < n; ++i){
                if (!exist[a]) return 0;
                a += b;
        }
        return 1;
}
 
int main()
{
        freopen("ariprog.in","r",stdin);
        freopen("ariprog.out","w",stdout);
        //while (scanf("%d%d", &n, &m) != EOF){
        //cin >> n >> m;
        scanf("%d%d", &n, &m);
        int numCnt = 0;
        for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= m; ++j) {
                if (!exist[i * i + j * j]){
                        num[numCnt++] = i * i + j * j;
                        exist[i * i + j * j] = 1;
                }
        }
 
        sort(num, num + numCnt);
        int a = num[0], b, pos;
        int cnt = 0;
        int bigB = (num[numCnt - 1] - num[0]) / (n - 1);
        for (b = 1; b <= bigB; ++b){
                for (int j = 0; j < numCnt; ++j){
                        if (check(num[j], b)) ++cnt, printf("%d %d\n", num[j], b);
                        if (num[j] + (n - 1) * b > num[numCnt - 1]) break;
                }
        }
        if (cnt == 0) puts("NONE");
        //}//fout << "NONE" << endl;//fout << "NONE" << endl;
        /*fin.close();
        fout.close();*/
 
        return 0;
}