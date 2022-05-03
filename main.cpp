/**
 * 题目： N选M
 * 输入： 两整数，N和M(0<m<=n<=10)
 * 输出： 字典序，从小带大输出全部排列。
 */

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int accFlag[12] = { 0 };
    char strShow[12] = {0};

int n, m;

int cnt = 0;

void dfs(int num, int depth)
{


    for (int i = 1; i < num+1; i++) {
        if (depth == m) {
            cnt++;
            printf("%s\n", strShow);
            return;
        }
        if (accFlag[i] == 1) {
            continue;
        }

        strShow[depth] = '0' + i;

        accFlag[i] = 1;
        dfs(num, depth + 1);
        accFlag[i] = 0;
    }
}

int main(int argc, char* argv[])
{
    scanf("%d", &n);
    scanf("%d", &m);

    dfs(n, 0);

    printf("%d\n", cnt);
    return 0;
}
