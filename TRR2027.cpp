#include <bits/stdc++.h>
using namespace std;

#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short n, timeDFS;
vector<short> adj[101];
bitset<101> vis;
short num[101], low[101];
vector<array<short, 2>> bridges;

inline void DFS(short u, short par) {
    num[u] = low[u] = ++timeDFS;
    vis[u] = 1;

    for (short& v : adj[u]) {
        if (!vis[v]) {
            DFS(v, u);

            low[u] = min(low[u], low[v]);

            if (low[v] > num[u]) bridges.push_back({min(u, v), max(u, v)});
        } else if (v != par) {
            low[u] = min(low[u], num[v]);
        }
    }
}

int main() {
    fastio();
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for (short u = 1; u <= n; ++u) {
        for (short v = 1; v <= n; ++v) {
            bitset<1> x;
            cin >> x;
            if (x.test(0)) adj[u].push_back(v);
        }
    }

    for (short u = 1; u <= n; ++u) 
        if (!vis[u]) DFS(u, -1);

    cout << bridges.size() << endl;
    sort(bridges.begin(), bridges.end());
    for (auto& [u, v] : bridges) cout << u << ' ' << v << endl;
    return 0;
}