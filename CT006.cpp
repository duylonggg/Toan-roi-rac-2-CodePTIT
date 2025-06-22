#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int n, s, minVal = INT_MAX;
vector<array<int, 2>> adj[1005];
bool hamilton = false;
vector<int> path, bestPath;
bitset<1005> vis;

void Hamilton(int cnt, int cur, int minW) {
    if (cnt == n) {
        for (auto [v, w] : adj[cur]) {
            if (v == s) {
                if (minW + w < minVal) {
                    minVal = minW + w;
                    path.push_back(v);
                    bestPath = path;
                    path.pop_back();
                    hamilton = true;
                    break;
                }
            }
        }
        return;
    }

    for (auto [v, w] : adj[cur]) {
        if (!vis[v]) {
            vis[v] = 1;
            path.push_back(v);
            Hamilton(cnt + 1, v, minW + w);
            path.pop_back();
            vis[v] = 0;
        }
    }
}

int main() {
    fastio();

    cin >> n >> s;

    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            int w;
            cin >> w;

            if (w > 0 and w <= 50) adj[u].push_back({v, w});
        }
    }

    vis.reset();
    vis[s] = 1;
    path.push_back(s);
    Hamilton(1, s, 0);

    if (!hamilton) {
        cout << 0 << endl;
        return 0;
    }

    cout << minVal << endl;
    for (auto p : bestPath) cout << p << ' ';
    cout << endl;
    return 0;
}