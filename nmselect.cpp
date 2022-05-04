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

int acc[12] = { 0 };
char str[12] = {0};

int n, m;

int cnt = 0;

//next_permutation

void dfs(int num, int dep)
{
    for (int i = 1; i < num+1; i++) {
        if (dep == m) {
            printf("%s\n", str);
            return;
        }
        if (acc[i] == 1) {
            continue;
        }
        str[dep] = '0' + i;

        acc[i] = 1;
        dfs(num, dep + 1);
        acc[i] = 0;
    }
}

int main(int argc, char* argv[])
{
    scanf("%d", &n);
    scanf("%d", &m);

    dfs(n, 0);
    return 0;
}
