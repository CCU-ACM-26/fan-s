// P2392 kkksc03考前临时抱佛脚
// 思路：每一科内部把题目分成两堆（左脑/右脑），让较大的一堆尽量小
//      即用 DFS 枚举所有子集，最小化 max(left, sum-left)，四科答案相加
#include <bits/stdc++.h>
using namespace std;

int s[5];
int a[25];
int total;      // 当前科目的总时长
int best;       // 当前科目能达到的最小耗时

void dfs(int i, int left) {
    if (i == s[0] + 1) {                      // 这一科的题都分完了
        // s[0] 在这里临时存"当前科目的题目数"，见 solve()
        int right = total - left;
        best = min(best, max(left, right));
        return;
    }
    dfs(i + 1, left + a[i]);                  // 给左脑
    dfs(i + 1, left);                         // 给右脑
}

int solve(int cnt) {
    int sum = 0;
    for (int i = 1; i <= cnt; i++) sum += a[i];
    s[0] = cnt;                               // 复用 s[0] 传题目数给 dfs
    total = sum;
    best = sum;                               // 上界：全部给一个脑
    dfs(1, 0);
    return best;
}

int main() {
    for (int k = 1; k <= 4; k++) cin >> s[k];

    int ans = 0;
    for (int k = 1; k <= 4; k++) {
        for (int i = 1; i <= s[k]; i++) cin >> a[i];
        ans += solve(s[k]);
    }
    cout << ans << "\n";
    return 0;
}
