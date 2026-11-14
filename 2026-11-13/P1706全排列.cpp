// P1706 全排列问题 —— 模板三：回溯生成排列
// 题意：输出 1~n 的所有排列，数字间场宽 5
#include <bits/stdc++.h>
using namespace std;

int n;
bool used[15];
int path[15];

void dfs(int depth) {
    if (depth == n + 1) {                    // n 个位置都填满，输出
        for (int i = 1; i <= n; i++)
            cout << setw(5) << path[i];
        cout << "\n";
        return;
    }
    for (int v = 1; v <= n; v++) {
        if (used[v]) continue;               // 用过的数不能再用
        used[v] = true;                      // 做选择
        path[depth] = v;
        dfs(depth + 1);                      // 填下一个位置
        used[v] = false;                     // 撤销选择（回溯）
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}
