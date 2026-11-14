// P1605 迷宫 —— 网格 DFS 数路径条数（模板二 + 回溯）
// 题意：N×M 网格，从起点走到终点，有 T 个障碍格不能走，问有多少条不同路线
#include <bits/stdc++.h>
using namespace std;

int N, M, T, fx, fy, total;
bool vis[10][10];
bool blocked[10][10];

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

void dfs(int r, int c) {
    if (r == fx && c == fy) {    // 到达终点，找到一条路
        total++;
        return;
    }
    vis[r][c] = true;            // 做选择：标记当前格
    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if (nr < 1 || nr > N || nc < 1 || nc > M) continue;
        if (vis[nr][nc] || blocked[nr][nc]) continue;
        dfs(nr, nc);
    }
    vis[r][c] = false;           // ★撤销：同一条路径数题必须回溯，否则路会互相堵死
}

int main() {
    cin >> N >> M >> T;
    int sx, sy;
    cin >> sx >> sy >> fx >> fy;
    memset(blocked, 0, sizeof(blocked));
    for (int i = 0; i < T; i++) {
        int x, y;
        cin >> x >> y;
        blocked[x][y] = true;
    }
    total = 0;
    dfs(sx, sy);
    cout << total << "\n";
    return 0;
}
